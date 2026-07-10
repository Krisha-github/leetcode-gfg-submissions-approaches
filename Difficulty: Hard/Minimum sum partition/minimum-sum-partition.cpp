class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int n=arr.size();
        vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1 ,0));
        /*return f(arr.size()-1,sum,arr,dp);*/
        for(int i=0;i<arr.size();i++){
            dp[i][0]=1;
        }
        if(arr[0]<=sum)dp[0][arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            for(int tar=1;tar<=sum;tar++){
                bool nottake=dp[i-1][tar];
                bool take=0;
                if(arr[i]<=tar){
                    take=dp[i-1][tar-arr[i]];
                }
                dp[i][tar]=take || nottake;
            }
        }
        int maxi=0;
        for(int i=0;i<=sum/2;i++){
            if(dp[n-1][i]!=0){
                maxi=max(maxi,i);
            }
        }
        return sum-2*maxi;
    }
};
