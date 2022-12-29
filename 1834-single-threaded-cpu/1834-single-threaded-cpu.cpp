class Solution {
public:
    
//     static bool cmp(vector<int> &a, vector<int> &b){
//         if(a[0] == b[0]){
//             return a[1] < b[1];
//         }
//         else {
//             return a[0] < b[0]; 
//         }
//     }
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(),tasks.end());
        
        vector<int> v;
        
        // for(int i=0;i<n;i++){
        //     cout<<tasks[i][0]<<" "<<tasks[i][1]<<" "<<tasks[i][2]<<endl;
        //     v.push_back(tasks[i][2]);
        // }
        priority_queue <pair<long,int>, vector<pair<long,int>>, greater<> > pq;
        
        long t = 0, i = 0;
        while(i<n || pq.size()){
            if (pq.empty()) {
                t = max(t,(long)tasks[i][0]); 
            }
            while(i<n and t >= tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            pair<int,int> x = pq.top();
            pq.pop();
            t += x.first;
            v.push_back(x.second);
        }
        return v;
    }
};