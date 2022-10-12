class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<3){
            return ans;
        }
        int i,j,k;
        
        for(i=0;i<n-1;i++){
            
            j = i+1;
            k = n-1;
            
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            
            while(j<k){  
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    
                    
                    int last_j = j, last_k = k;
                    
                    while(j<k and nums[j] == nums[last_j]){
                        j++;
                    }
                    while(j<k and nums[k] == nums[last_k]){
                        k--;
                    }
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        
        return ans;
    }
};