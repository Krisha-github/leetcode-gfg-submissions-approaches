1class Solution {
2public:
3    int findNumberOfLIS(vector<int>& nums) {
4        int n=nums.size();
5        vector<int> dp(n,1);
6        vector<int> cnt(n,1);
7        // LIS
8        int maxlen=1;
9        for(int i=0;i<n;i++){
10            for(int j=0;j<i;j++){
11
12                if(nums[j]<nums[i] && dp[i]< dp[j]+1){
13                    dp[i]= dp[j]+1;
14                    cnt[i]=cnt[j];
15                }
16                else if(nums[j]<nums[i] && dp[i]== dp[j]+1){
17                    cnt[i]+=cnt[j];
18                }
19            }
20            maxlen=max(maxlen,dp[i]);
21
22        }
23        int num=0;
24        for(int i=0;i<n;i++){
25            if(dp[i]==maxlen) num+=cnt[i];
26        }
27        return num;
28
29    }
30};