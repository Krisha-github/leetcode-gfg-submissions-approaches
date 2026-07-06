1class Solution {
2    int lcs(string s1, string s2, vector<vector<int>>& dp) {
3        int n=s1.size();
4        int m=s2.size();
5        // dp[i][j]=lcs of [0..i-1] and [0..j-1]
6        for (int i = 0; i <= n; i++) {
7            dp[i][0] = 0;
8        }
9        for (int i = 0; i <= m; i++) {
10            dp[0][i] = 0;
11        }
12        for (int i = 1; i <= n; i++) {
13            for (int j = 1; j <= m; j++) {
14                if (s1[i - 1] == s2[j - 1]) {
15                    dp[i][j] = dp[i - 1][j - 1] + 1;
16                } else
17                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
18            }
19        }
20        return dp[n][m];
21    }
22public:
23    int minDistance(string word1, string word2) {
24        int n=word1.size();
25        int m=word2.size();
26        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
27        int deletefrom1=word1.size()-lcs(word1,word2,dp);
28        int deletefrom2=word2.size()-dp[n][m];
29        return deletefrom1+deletefrom2;
30
31        
32    }
33};