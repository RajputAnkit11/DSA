class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
//         let x = nums[i] + c*space
//         x - nums[i] = c*space
//         (x - nums[i])/space = c
//         x/space = nums[i]/space [here c == 0]
        
//         now x exist in nums array only if nums[x] is divisible by space 
        
//         nums[j] % space == nums[i] % space
        
        int n = nums.size();
        unordered_map<int,int> map;
        
        int mxCount = INT_MIN;
        
        for(int i=0;i<n;i++){
            map[nums[i]%space]++;
            mxCount = max(mxCount,map[nums[i]%space]);
        }
        for(auto i: map){
            cout<<i.first<<" "<<i.second<<"\n";
        }
        cout<<mxCount;
        int ans = INT_MAX;
        
        for(auto i: nums){
            if(map[i%space] == mxCount){
                ans = min(ans,i);
            }
        }
        
        return ans;
    }
};