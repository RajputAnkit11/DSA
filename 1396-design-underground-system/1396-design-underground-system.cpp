class UndergroundSystem {

public:

    //startStation:endStation -> {totalTime, numberOfTrips}

    unordered_map<string, pair<long long, int>> stationTimes;

    //customerId -> startStation

    unordered_map<int, pair<string,int>> inTransit;

    UndergroundSystem() {

        stationTimes.clear();

        inTransit.clear();

    }

    

    void checkIn(int id, string stationName, int t) {

        if(inTransit.find(id) != inTransit.end()) return;

        inTransit[id] = {stationName, t};

    }

    

    void checkOut(int id, string stationName, int t) {

        auto& info = inTransit[id];

        string startStation = info.first;

        int startTime = info.second;

        string key = startStation + ":" + stationName;

        int time = t - startTime;

        

        if(stationTimes.find(key) != stationTimes.end()) {

            auto& oldTimes = stationTimes[key];

            oldTimes.first += time;

            oldTimes.second++;

        } else {

            stationTimes[key] = {time, 1};

        }

        inTransit.erase(id);

        

    }

    

    double getAverageTime(string startStation, string endStation) {

        string key = startStation + ":" + endStation;

        auto& info = stationTimes[key];

        double avg = (double)info.first / (double)info.second;

        return avg;

    }

};
/*
Comments: 

 

Type comment here... (Markdown is supported)

cyder 0  2 hours ago

why have you used erase at the end of checkout function can you please tell me

0ShareReply

Vishal_Rajput 309  5 hours ago

Video Solution (using two hashmap), T.C: O(1):

Read More

0ShareReply

vds5344 1  10 hours ago

My Python Implementation:

class UndergroundSystem:

    def __init__(self):

        self.cin = defaultdict()

        self.cout = defaultdict(list)

    def checkIn(self, id: int, stationName: str, t: int) -> None:

        self.cin[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:

        self.cout[self.cin[id][0]+'_'+stationName].append(t - self.cin[id][1])

    def getAverageTime(self, startStation: str, endStation: str) -> float:

        return sum(self.cout[startStation+'_'+endStation])/len(self.cout[startStation+'_'+endStation])

Read More

0ShareReply

JiayingGao 0  14 hours ago

great!

0ShareReply

SHOW 1 REPLY

Dammshine 1  15 hours ago

void checkIn(int id, string stationName, int t) {

    // First, update ID_to_time

    ID_to_time[id] = make_pair(make_pair(t, -1), make_pair(stationName, NULL));

}

void checkOut(int id, string stationName, int t) {

    // Update ID_to_time

    pair<int, int> &info_time = ID_to_time[id].first;

    pair<string, string> &info_name = ID_to_time[id].second;

    info_time.second = t;

    info_name.second = stationName;

    

    // Update station_to_time

    // by knowing the interval and station, I can update the time

    int interval = info_time.second - info_time.first;

    station_to_time[make_pair(info_name.first, info_name.second)].push_back(interval);

    

    // Now, can erase the previous travel info

    // which I will just ignore

}

double getAverageTime(string startStation, string endStation) {

    int count = 0;

    double sum = 0;

    for (auto a : station_to_time[make_pair(startStation, endStation)]) {

        sum += (double) a;

        count++;

    }

    return sum / count;

}

map<int, pair<pair<int, int>, pair<string, string>>> ID_to_time;

map<pair<string, string>, vector<int>> station_to_time;

Hey, Simon, this is my solution. Also used unordered_map. This line, "string k
*/