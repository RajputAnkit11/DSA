class Solution {
public:
    bool f(int i, vector<string> &wordDict, string &s, vector<int> &dp) {
        if (i == s.length()) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        bool result = false;

        for (const string &word : wordDict) {
            if (s.substr(i, word.length()) == word) {
                result = result || f(i + word.length(), wordDict, s, dp);
            }
        }

        dp[i] = result;
        return dp[i];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n, -1);
        return f(0, wordDict, s, dp);
    }
};