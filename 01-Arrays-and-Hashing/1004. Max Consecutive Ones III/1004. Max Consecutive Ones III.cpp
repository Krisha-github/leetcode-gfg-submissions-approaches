1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int r=0;
5        int n=nums.size();
6        int l=0, maxlen=0;
7        int zeroes=0;
8        while(r<n){
9            
10            if(nums[r]==0){
11                zeroes++;
12            }
13            if(zeroes>k){
14                if(nums[l]==0){
15                    zeroes--;
16                }
17                l++;
18            }
19            
20            if(zeroes<=k){
21                maxlen=max(maxlen,r-l+1);
22
23            }
24            r++;
25        }  
26        return maxlen;                 
27
28    }
29};