1class Solution {
2    int f(int i, int canbuy, vector<int>& prices, vector<vector<int>>& dp) {
3        if (i >= prices.size())
4            return 0;
5
6        if (dp[i][canbuy] != -1)
7            return dp[i][canbuy];
8        int profit = 0;
9        if (canbuy) {
10            profit = max(f(i + 1, 0, prices, dp) - prices[i],
11                         f(i + 1, 1, prices, dp));
12        } else
13            profit = max(f(i + 2, 1, prices, dp) + prices[i],
14                         f(i + 1, 0, prices, dp));
15        return dp[i][canbuy] = profit;
16    }
17public:
18    int maxProfit(vector<int>& prices) {
19        int n = prices.size();
20        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
21        //return f(0,1,prices,dp);
22        dp[n][0] = 0;
23        dp[n][1] = 0;
24
25        for (int i = n - 1; i >= 0; i--) {
26            for (int canbuy = 0; canbuy <=1; canbuy++) {
27                int profit = 0;
28                if (canbuy) {
29                    profit = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
30                } else
31                    profit = max(dp[i + 2][1] + prices[i], dp[i + 1][0]);
32                dp[i][canbuy] = profit;
33            }
34        }
35        return dp[0][1];
36
37        
38    }
39};