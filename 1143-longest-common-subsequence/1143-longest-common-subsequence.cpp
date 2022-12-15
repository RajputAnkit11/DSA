class Solution {
public:
    int dp[1000 + 1][1000 + 1];
    
    int maxLen(string& s1, string& s2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        
        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + maxLen(s1, s2, n - 1, m - 1);
        else
            return dp[n][m] = max(0+maxLen(s1,s2,n-0,m -1),0+maxLen(s1,s2,n-1,m-0));
    }
        
    int longestCommonSubsequence(string s1, string s2) 
    {
        memset(dp, -1, sizeof(dp));        
        return maxLen(s1, s2, s1.length(), s2.length());
    }
//     int longestCommonSubsequence(string text1, string text2) {
// 		int n = text1.size(), m= text2.size(); 
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
//         for(int i=1; i <= n; i++){
//             for(int j=1; j <= m; j++){
//                 if(text1[i-1] == text2[j-1])
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 else
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[n][m];
//     }
};