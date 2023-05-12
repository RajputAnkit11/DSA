class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long int> dp;
        int n = q.size();
        dp.resize(n,-1);
        dp[n-1] = q[n-1][0];
        
        for(int i=n-2;i>=0;i--){
            long val = q[i][0];
            long idx =i+ q[i][1]+1;
            if(idx >= n){
                if(val > dp[i+1]) dp[i] = val;
                else dp[i] =dp[i+1];
            }
            else{
                if(dp[idx] + val > dp[i+1]) dp[i] = dp[idx] + val;
                else dp[i] = dp[i+1];
            }
        }
        
   
        
        return dp[0];
    }
};