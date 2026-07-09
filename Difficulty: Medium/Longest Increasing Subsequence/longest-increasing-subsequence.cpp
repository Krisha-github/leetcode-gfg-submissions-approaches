class Solution {
	public:
	int lis(vector<int>& arr) {
		int n = arr.size();
		//vector<vector<int>>dp(n,vector<int>(n,-1));
		// dp[i] = length of LIS ending at i
		vector<int>dp(n, 1);
		int len=1;
		int maxi=1;
		for (int i = 1; i<n; i++) {
			for (int j = 0; j<i; j++) {
			    if(arr[j] < arr[i]){
			        dp[i]=max(dp[i] , dp[j] +1);
			        
			    }
			    maxi=max(maxi,dp[i]);
			}
		}
		return maxi;
	}
};
