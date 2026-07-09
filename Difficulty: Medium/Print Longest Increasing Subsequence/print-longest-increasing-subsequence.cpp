class Solution {
	public:
	vector<int> getLIS(vector<int>& arr) {
		int n = arr.size();
		vector<int>dp(n, 1);
		int len = 1;
		int maxi = 1;
		int lastindx = 0;
		vector<int> par(n);
		
		for (int i = 0; i<n; i++)
			par[i] = i;
		for (int i = 1; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					par[i] = j;
				}
			}
			if (dp[i]>maxi) {
				maxi = dp[i];
				lastindx = i;
			}
		}
		vector<int> lis;
		while (par[lastindx] != lastindx) {
			lis.push_back(arr[lastindx]);
			lastindx = par[lastindx];
		}
		
		lis.push_back(arr[lastindx]);
		
		reverse(lis.begin(), lis.end());
		return lis;
	}
};
