1class Solution {
2public:
3    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
4        int n=obstacleGrid.size();
5        int m=obstacleGrid[0].size();
6        vector<vector<int>> dp(n, vector<int>(m,0));
7        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                if( obstacleGrid[i][j]==1){
11                    dp[i][j]=0;
12                    continue;
13                }
14                if(i==0 && j==0) {
15                    dp[0][0]=1; //already initialized
16                    continue;
17                }
18                int up=0,left=0;
19                if(i>0) up=dp[i-1][j];
20                if(j>0) left=dp[i][j-1];
21                dp[i][j]=up+left;
22            }
23        }
24        return dp[n-1][m-1];
25    }
26};