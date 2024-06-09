class Solution {
public:
    int dp[2001][4000];
    
    int find(int i,int sum,vector<int>& nums){
        if(i == nums.size()){
            return 0;
        }
        
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int ans = -1;
        if(sum < nums[i]){
            ans = max(ans,nums[i] + find(i+1,sum+nums[i],nums));
            ans = max(ans,find(i+1,sum,nums));
        }
        
        ans = max(ans,find(i+1,sum,nums));
        
        return dp[i][sum] = ans;
    }
    
    int maxTotalReward(vector<int>& rv) {
        memset(dp, -1, sizeof(dp));
        set<int> s(rv.begin(), rv.end());
        vector<int> nums(s.begin(), s.end());
        return find(0, 0, nums); 
    }
};