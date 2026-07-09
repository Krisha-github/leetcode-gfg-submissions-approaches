class Solution {
	public:
// 	int lis(vector<int>& arr) {
// 		int n = arr.size();
// 		//vector<vector<int>>dp(n,vector<int>(n,-1));
// 		// dp[i] = length of LIS ending at i
// 		vector<int>dp(n, 1);
// 		vector<int> par(n,0);
// 		for(int i=0;i<n;i++) par[i]=i;
// 		int len=1;
// 		int maxi=1;
// 		for (int i = 1; i<n; i++) {
// 			for (int j = 0; j<i; j++) {
// 			    if(arr[j] < arr[i]){
// 			        dp[i]=max(dp[i] , dp[j] +1);
			        
// 			    }
// 			    maxi=max(maxi,dp[i]);
// 			}
// 		}
// 		return maxi;
// 	}

// vector<int> dp(n,1);

// for(int i=0;i<n;i++){
//     for(int prev=0;prev<i;prev++){

//         if(arr[prev]<arr[i]){
//             dp[i]=max(dp[i],dp[prev]+1);
//         }

//     }
// }

//int ans=*max_element(dp.begin(),dp.end());
	int lis(vector<int>& nums) {
	    vector<int> temp;

        for (int x : nums) {

            auto it = lower_bound(temp.begin(), temp.end(), x);

            if (it == temp.end())
                temp.push_back(x);
            else
                *it = x;
        }

        return temp.size();
	}
};
