1class Solution {
2    int f(int i, int j, string& w1, string& w2, vector<vector<int>>& dp) {
3        if(i<0 && j<0) return 0;
4        if (i < 0)
5            return j + 1;
6        if (j < 0)
7            return i + 1;
8        if (dp[i][j] != -1)
9            return dp[i][j];
10        if (w1[i] == w2[j])
11            return dp[i][j] =f(i - 1, j - 1, w1, w2, dp);
12        int insert = 0, replace = 0, del = 0;
13        insert = f(i, j - 1, w1, w2, dp) + 1;
14        replace = f(i - 1, j - 1, w1, w2, dp) + 1;
15        del = f(i - 1, j, w1, w2, dp) + 1;
16        return dp[i][j] = min(insert, min(del, replace));
17    }
18public:
19    int minDistance(string w1, string w2) {
20        int n = w1.size();
21        int m = w2.size();
22        //vector< vector<int> > dp(n,vector<int>(m,-1));
23        //return f(n-1,m-1,w1,w2,dp);
24        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
25        dp[0][0]=0;
26        for (int j = 1; j <= m; j++) {
27            dp[0][j] = j ;
28        }
29        for (int i = 1; i <= n; i++) {
30            dp[i][0] = i ;
31        }
32        for (int i = 1; i <= n; i++) {
33            for (int j = 1; j <= m; j++) {
34                if (w1[i-1] == w2[j-1])
35                    dp[i][j]= f(i - 1, j - 1, w1, w2, dp);
36                else{
37                int insert = f(i, j - 1, w1, w2, dp) + 1;
38                int replace = f(i - 1, j - 1, w1, w2, dp) + 1;
39                int del = f(i - 1, j, w1, w2, dp) + 1;
40                 dp[i][j] = min(insert, min(del, replace));
41                }
42            }
43        }
44        return dp[n][m];
45    }
46};