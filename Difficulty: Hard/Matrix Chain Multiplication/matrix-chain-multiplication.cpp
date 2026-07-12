class Solution {
    int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
        if(i>j || i==0 || j==arr.size()) return 0;
        if(i==j) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int oper=(arr[i-1]*arr[k]*arr[j])+f(i,k,arr,dp) + f(k+1,j,arr,dp) ;
            mini=min(oper,mini);
        }
        return dp[i][j]=mini;
    }
    //f(i, j)

//dp[i][j]=minimum cost to multiply matrices from Aito Aj   
//A1=arr[0] * arr[1]
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,n-1,arr,dp);
    }
};