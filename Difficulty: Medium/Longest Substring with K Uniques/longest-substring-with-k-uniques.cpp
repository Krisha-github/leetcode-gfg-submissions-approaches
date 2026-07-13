class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mp;

        int l = 0;
        int maxlen = 0;

        for(int r = 0; r < s.size(); r++) {
            mp[s[r]]++;

            while(mp.size() > k) {
                mp[s[l]]--;

                if(mp[s[l]] == 0)
                    mp.erase(s[l]);

                l++;
            }
            if(mp.size()==k)
            maxlen = max(maxlen, r - l + 1);
        }
        if(maxlen==0) return -1;
        return maxlen;
    }
};