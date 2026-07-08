1class Solution {
2    int f(int i, int canbuy, int num, vector<int>& prices,
3          vector<vector<vector<int>>> dp) {
4        if (i == prices.size())
5            return 0;
6        if (num > 2)
7            return 0;
8
9        if (dp[i][canbuy][num] != -1)
10            return dp[i][canbuy][num];
11        int profit = 0;
12        if (canbuy) {
13            int buys = 0;
14            if (num < 2)
15                buys = f(i + 1, 0, num, prices, dp) - prices[i];
16
17            profit = max(buys, f(i + 1, 1, num, prices, dp));
18        } else
19
20            profit = max(f(i + 1, 1, num + 1, prices, dp) + prices[i],
21                         f(i + 1, 0, num, prices, dp));
22        return dp[i][canbuy][num] = profit;
23    }
24
25public:
26    int maxProfit(vector<int>& prices) {
27        int n = prices.size();
28        vector<vector<vector<int>>> dp(
29            n + 1, vector<vector<int>>(2, vector<int>(4, 0)));
30//return f(0,1,0,prices,dp);
31        for (int i = n - 1; i >= 0; i--) {
32            for (int canbuy = 0; canbuy <= 1; canbuy++) {
33                for (int num = 0; num<=2; num++) {
34                    
35                    int profit = 0;
36                    if (canbuy) {
37                        int buys = 0;
38                        if (num < 2)
39                            buys = dp[i+1][0][num] - prices[i];
40
41                        profit = max(buys, dp[i+1][1][num]);
42                    } 
43                    else{
44                        profit =
45                            max(dp[i+1][0][num],dp[i+1][1][num+1] + prices[i]);
46                                
47
48                    }
49                    
50                    dp[i][canbuy][num] = profit;
51                }
52            }
53        }
54
55        return dp[0][1][0];
56    }
57};