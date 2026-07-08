1class Solution {
2    int f(int i, int canbuy,int fee, vector<int>& prices, vector<vector<int>>& dp) {
3        if (i == prices.size())
4            return 0;
5
6        if (dp[i][canbuy] != -1)
7            return dp[i][canbuy];
8        int profit = 0;
9        if (canbuy) {
10            profit = max(f(i + 1, 0, fee,prices, dp) - prices[i],
11                         f(i + 1, 1, fee,prices, dp));
12        } else
13            profit = max(f(i + 1, 1,fee, prices, dp) + prices[i]-fee,
14                         f(i + 1, 0, fee,prices, dp));
15        return dp[i][canbuy] = profit;
16    }
17
18public:
19    int maxProfit(vector<int>& prices, int fee) {
20        int n = prices.size();
21        //vector<vector<int>> dp(n + 1, vector<int>(2, -1));
22        //return f(0,1,fee,prices,dp);
23        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
24        dp[n][0] = 0;
25        dp[n][1] = 0;
26
27        for (int i = n - 1; i >= 0; i--) {
28            for (int canbuy = 0; canbuy <=1; canbuy++) {
29                int profit = 0;
30                if (canbuy) {
31                    profit = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
32                } else
33                    profit = max(dp[i + 1][1] + prices[i]-fee, dp[i + 1][0]);
34                dp[i][canbuy] = profit;
35            }
36        }
37        return dp[0][1];
38    }
39};