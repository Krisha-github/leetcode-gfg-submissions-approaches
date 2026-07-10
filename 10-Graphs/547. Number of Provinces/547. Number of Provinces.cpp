1class Solution {
2public:
3    int findCircleNum(vector<vector<int>>& graph) {
4    int V=graph.size();    
5    vector<int> vis(V, 0);
6    int ans=0;
7    queue<int> q;
8    for(int i=0;i<V;i++){
9        if(vis[i]==0){
10        ans++;
11        q.push(i);
12        vis[i]=1;
13
14        while (!q.empty())
15        {   
16        int node = q.front();
17        q.pop();
18        
19        for (int j = 0; j < V; j++)
20        {
21            if (graph[node][j] == 1 &&
22                !vis[j])
23            {
24                vis[j] = 1;
25                q.push(j);
26            }
27        }
28        
29       }
30        }
31        
32    }
33
34    return ans;
35    }
36};