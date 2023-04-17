class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        std::vector<bool> ans;
        int max = 0;
        for (int candy : candies) {
            max = std::max(candy, max);
        }
        for (int candy : candies) {
            ans.push_back(candy + extraCandies >= max);
        }
        return ans;
    }
};