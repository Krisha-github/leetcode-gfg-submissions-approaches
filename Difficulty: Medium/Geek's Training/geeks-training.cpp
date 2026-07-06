class Solution {
	public:
	
	int maximumPoints(vector<vector<int>> & mat) {
	    int n=mat.size();
		vector<vector<int>> dp(n,vector<int> (3,0));
		dp[0][0]=mat[0][0];
		dp[0][1]=mat[0][1];
		dp[0][2]=mat[0][2];
		//dp[i][j]=max merit on day i given  we take activity j on day i
		for(int day=1;day<n;day++){
		   for(int i=0;i<3;i++){
		            int maxmerit=0;
		            for(int last=0;last<3;last++)
		            {
		            if(i!=last){
		                maxmerit=max( maxmerit , dp[day-1][last]);
		                
		            }
		        }
	            dp[day][i]=maxmerit + mat[day][i];

		    }
		}
		
		return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}	);

	}
};
