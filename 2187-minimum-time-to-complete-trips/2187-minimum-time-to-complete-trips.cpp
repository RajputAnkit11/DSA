class Solution {
public:
    long long fun(long long mid,vector<int> time){
        long long sum = 0;
        
        for(int i=0;i<time.size();i++){
             
            sum += mid/time[i];
        }
        
        return sum;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips ) {
        
        long long left = 1;
        long long mx = -1;
        for(long long i=0;i<time.size();i++){
            mx = max(time[i]*1ll,mx);
        }
        long long right = mx*totalTrips;
        long long mid;
        long long ans;
        while(left<=right){
            mid = (left+right)/2;
            
            if(fun(mid , time) < totalTrips ){
                left = mid+1;
            }
            else{
                ans = mid;
                right = mid-1;
            }

        }
        return ans;
    }
};