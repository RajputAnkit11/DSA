// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.


// Hash Map - O(NlongN)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int,int> map;
    
    for(int i=0;i<n;i++){
        int temp = target - nums[i];

        if(map.count(temp)){
            vector<int> ans;
            ans.push_back(i);
            ans.push_back(map[temp]);
            return ans;
        }

        map[nums[i]] = i;
    }
    return {};
}
