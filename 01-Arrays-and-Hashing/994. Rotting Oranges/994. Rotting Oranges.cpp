1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int m=grid.size();
5        int n=grid[0].size();
6        queue<pair<pair<int,int>,int>> q;
7        int countfresh=0;
8        vector<vector<int>> vis(m,vector<int>(n,0));
9        for(int i=0;i<m;i++){
10            for(int j=0;j<n;j++){
11                if(grid[i][j]==2){
12                    q.push({{i,j},0});
13                    vis[i][j]=2;
14                }
15                if(grid[i][j]==1) countfresh++;
16            }
17        }
18        int maxt=0;
19        int delrow[]={0,1,0,-1};
20        int delcol[]={1,0,-1,0};
21        int count=0;
22        while(!q.empty()){
23            int r=q.front().first.first;
24            int c=q.front().first.second;
25            int t=q.front().second;
26            // maxt = max(maxt, t);
27            q.pop();
28            for(int i=0;i<4;i++){
29                int newr=r+delrow[i];
30                int newc=c+delcol[i];
31                if(newr>=0 && newr<m && newc>=0 && newc<n && vis[newr][newc]==0 && grid[newr][newc]==1){
32                    vis[newr][newc]=2;
33                    count++;
34                    q.push({{newr,newc},t+1});
35                    maxt=max(maxt,t+1);
36                }
37            }
38        }
39        if(countfresh==count)
40        return maxt;
41        else return -1;
42        
43
44    }
45};