1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        vector<int> hash(256, -1);
5        int l=0;
6        int r=0;
7        int maxlen=0;
8        int n=s.size();
9        while(r<n){
10            if(hash[s[r]]!=-1){
11                l=max(hash[s[r]]+1, l);
12            }
13            int len = r - l + 1;
14            maxlen = max(len, maxlen);
15            
16            /* Store the index of the current
17            character in the hash table*/
18            hash[s[r]] = r;
19            
20            // Move right pointer to next position
21            r++;
22        }
23        return maxlen;
24    }
25};