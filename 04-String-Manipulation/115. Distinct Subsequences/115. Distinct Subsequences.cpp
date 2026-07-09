1class Solution {
2    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
3        if (j < 0)
4            return 1;
5        if (i < 0)
6            return 0;
7        if (dp[i][j] != -1)
8            return dp[i][j];
9
10        if (s1[i] == s2[j]) {
11            return dp[i][j] =
12                       f(i - 1, j - 1, s1, s2, dp) + f(i - 1, j, s1, s2, dp);
13        }
14        return dp[i][j] = f(i - 1, j, s1, s2, dp);
15    }
16
17public:
18    int numDistinct(string s1, string s2) {
19        int n = s1.size();
20        int m = s2.size();
21        // vector<vector<int>> dp(n , vector<int>(m , -1));
22        // return f(n-1,m-1,s1,s2,dp);
23        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1, 0));
24
25        for (int i = 0; i <= n; i++)
26            dp[i][0] = 1;
27        for (int j = 1; j <= m; j++)
28            dp[0][j] = 0;
29        for (int i = 1; i <= n; i++) {
30            for (int j = 1; j <= m; j++) {
31                if (s1[i-1] == s2[j-1]) {
32                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
33                }
34                else dp[i][j] = dp[i-1][j];
35            }
36        }
37
38        return (int)dp[n][m];
39    }
40};