class Solution {
public:
    int rob(vector<int>& nums) {
        return robber(nums, 0, nums.size()-1);
    }
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};