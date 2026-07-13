1class Solution {
2public:
3    int totalFruit(vector<int>& fruits) {
4        map<int,int> mp;
5
6        int l = 0;
7        int ans = 0;
8
9        for(int r = 0; r < fruits.size(); r++) {
10            mp[fruits[r]]++;
11
12            while(mp.size() > 2) {
13                mp[fruits[l]]--;
14
15                if(mp[fruits[l]] == 0)
16                    mp.erase(fruits[l]);
17
18                l++;
19            }
20
21            ans = max(ans, r - l + 1);
22        }
23
24        return ans;
25    }
26};