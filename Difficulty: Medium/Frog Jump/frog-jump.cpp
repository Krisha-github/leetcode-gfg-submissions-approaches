class Solution {
    int f(int i,vector<int>& h,vector<int> &dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int onestep=f(i-1,h,dp) + abs(h[i]-h[i-1]);
        int twostep=INT_MAX;
        if(i>=2) twostep=f(i-2,h,dp) + abs(h[i]-h[i-2]);
        return dp[i]=min(onestep,twostep);
    }
  public:
    int minCost(vector<int>& h) {
        int n=h.size();
        vector<int> dp(n,-1);
        return f(n-1,h,dp);
        
    }
};