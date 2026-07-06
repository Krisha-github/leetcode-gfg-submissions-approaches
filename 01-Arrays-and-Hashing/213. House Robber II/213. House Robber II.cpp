1
2class Solution {
3public:
4    int solve(vector<int>& nums, int start, int end) {
5        int prev2 = 0;
6        int prev1 = 0;
7
8        for(int i = start; i <= end; i++) {
9            int take = nums[i] + prev2;
10            int notTake = prev1;
11            int curr = max(take, notTake);
12            prev2 = prev1;
13            prev1 = curr;
14        }
15
16        return prev1;
17    }
18
19    int rob(vector<int>& nums) {
20        int n = nums.size();
21
22        if(n == 1) return nums[0];
23
24        return max(
25            solve(nums, 0, n - 2),
26            solve(nums, 1, n - 1)
27        );
28    }
29};
30