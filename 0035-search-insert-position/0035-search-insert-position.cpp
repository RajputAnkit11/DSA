class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int left = 0;
        int right = n-1;
        
        while(left <= right){
            int mid = (left + right) >> 1;
            
            if(nums[mid] > target){
                right = mid-1;
            }
            else if(nums[mid] < target){
                left = mid+1;             
            }
            else{
                return mid;
            }
        }
        return left;
    }
};