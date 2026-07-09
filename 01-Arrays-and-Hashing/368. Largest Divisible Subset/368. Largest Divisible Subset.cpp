1class Solution {
2public:
3    vector<int> largestDivisibleSubset(vector<int>& arr) {
4        int n = arr.size();
5		vector<int>dp(n, 1);
6		int len = 1;
7		int maxi = 1;
8		int lastindx = 0;
9        sort(arr.begin(),arr.end());
10		vector<int> par(n);
11		
12		for (int i = 0; i<n; i++)
13			par[i] = i;
14		for (int i = 1; i<n; i++) {
15			for (int j = 0; j<i; j++) {
16				if (arr[i] % arr[j]==0 && dp[j] + 1 > dp[i]) {
17					dp[i] = dp[j] + 1;
18					par[i] = j;
19				}
20			}
21			if (dp[i]>maxi) {
22				maxi = dp[i];
23				lastindx = i;
24			}
25		}
26		vector<int> lis;
27		while (par[lastindx] != lastindx) {
28			lis.push_back(arr[lastindx]);
29			lastindx = par[lastindx];
30		}
31		
32		lis.push_back(arr[lastindx]);
33		
34		reverse(lis.begin(), lis.end());
35		return lis;
36    }
37};