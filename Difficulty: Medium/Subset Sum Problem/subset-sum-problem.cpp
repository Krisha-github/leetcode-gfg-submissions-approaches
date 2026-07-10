class Solution {
    /*bool f(int idx,int sum,vector<int>& arr,vector<vector<int>>& dp){
        if(sum==0) return true;
        if(idx==0){
            return arr[0]==sum;
        }
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool take=0, nottake=f(idx-1,sum,arr,dp);
        if(arr[idx]<=sum) take=f(idx-1,sum-arr[idx],arr,dp);
        
        return dp[idx][sum] = take || nottake;
    }*/
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
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
        return dp[arr.size()-1][sum];
    }
};