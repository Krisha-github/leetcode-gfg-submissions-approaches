1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        vector<vector<int>> dp(m, vector<int>(n, 0));
5        if(m==0 || n==0) return 1;
6        for(int i=0;i<m;i++){
7            for(int j=0;j<n;j++){
8                
9                if(i==0 && j==0){
10                    dp[0][0]=1;
11                    continue;
12                }
13                int up=0,left=0;
14                if(i>0) up=dp[i-1][j];
15                if(j>0) left=dp[i][j-1];
16                dp[i][j]=up+left;
17
18
19            }
20        }
21        return dp[m-1][n-1];
22    }
23};