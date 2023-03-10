class Solution {
public:

    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        
        int left = 0, right = 1000;
        
        while (left < right) {
            int k = (left + right + 1) / 2;
            if (k * (k + 1) / 2 > n) {
                right = k - 1;
            } else {
                left = k;
            }
        }
        return left;
    }
};