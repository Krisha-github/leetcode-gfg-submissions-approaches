class Solution {
  public:
    int maxChocolate(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    if(n==1) return grid[0][0]+grid[0][m-1];
    
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    
    //dp[i][j][k]=max total chocklates when robo 1 is at(i,j) and robo 2 is at(i,k)
    int maxrow=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(i==0) {   //for i=0 only dp[0][0][m-1] valid
                    if(j!=0 || k!=m-1){
                        dp[i][j][k]=INT_MIN;
                        continue;
                    } 
                    dp[i][j][k]=grid[0][0]+grid[0][m-1];
                    continue;
                }
            //up //upleft //upright
            int uu=INT_MIN, ll=INT_MIN, rr=INT_MIN;
            int ul=INT_MIN, lu=INT_MIN, ru=INT_MIN;
            
            int ur=INT_MIN, lr=INT_MIN, rl=INT_MIN;
            
            if(i>0){
                uu=dp[i-1][j][k];
            }
            if(i>0 && j>0 && k>0) ll=dp[i-1][j-1][k-1];
            if(i>0 && j+1<m && k+1<m) rr=dp[i-1][j+1][k+1];
            if(i>0 && k>0 ) ul=dp[i-1][j][k-1];
            if(i>0 && j>0 ) lu=dp[i-1][j-1][k];
            if(i>0 && j+1<m ) ru=dp[i-1][j+1][k];
            if(i>0 && k+1<m) ur=dp[i-1][j][k+1];
            if(i>0 && j>0 && k+1<m) lr=dp[i-1][j-1][k+1];
            if(i>0 && j+1<m && k>0) rl=dp[i-1][j+1][k-1];
            
            int maxi=max({uu,ul,ur,lu,ll,lr,ru,rl,rr}); //very imp to check if parent states are valid
            if(maxi ==INT_MIN){
                dp[i][j][k]=INT_MIN;
                continue;
            }
            
            if(j==k) dp[i][j][k]=maxi + grid[i][j];
            else{
                dp[i][j][k]=maxi + grid[i][j] + grid[i][k];
            }
            if(i==n-1) maxrow=max(maxrow,dp[i][j][k]);
            }
        }
    }
     return maxrow;
    }
   
};