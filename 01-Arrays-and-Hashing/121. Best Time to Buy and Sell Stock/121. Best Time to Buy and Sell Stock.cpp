1class Solution {
2    
3public:
4    int maxProfit(vector<int>& p) {
5        int n=p.size();
6        int profit=0;
7        int mini=p[0];  //minimum guy
8        for(int i=0;i<n;i++){
9            if(p[i]<mini) {
10                mini=p[i];
11            } 
12            profit=max(profit,p[i]-mini);       
13
14        }
15    
16        return profit;
17    }
18};