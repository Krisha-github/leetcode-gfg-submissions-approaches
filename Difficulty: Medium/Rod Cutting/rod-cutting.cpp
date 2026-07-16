class Solution {
    int ubknapSack(vector<int>& p, vector<int>& wt, int capacity,vector<vector<int>>& dp) {
        
        for(int i=0;i<p.size();i++){
            dp[i][0]=0;
        }
        for(int w=1;w<=capacity;w++){
            dp[0][w]=(w / wt[0]) * p[0];
        }
        for(int i=1;i<p.size();i++){
            for(int w=1;w<=capacity;w++){
                int nottake=dp[i-1][w];
                int take=INT_MIN;
                if(wt[i]<=w){
                  take=dp[i][w-wt[i]] + p[i];
                }
                dp[i][w]=max(take,nottake);
            }
        }
        return dp[p.size()-1][capacity];
    }
  public:
    int cutRod(vector<int> &price) {
        vector<int>w(price.size(),0);
        vector<vector<int>> dp(price.size(),vector<int>(price.size()+1,-1));
        for(int i=0;i<price.size();i++){
            w[i]=i+1;
        }
        return ubknapSack(price,w,price.size(),dp);
    }
};