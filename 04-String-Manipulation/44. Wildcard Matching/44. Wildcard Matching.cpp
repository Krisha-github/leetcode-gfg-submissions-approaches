1class Solution {
2    bool f(int i, int j,  string &p,string &s,vector<vector<int>>&dp) {
3        if(i < 0 && j < 0) return true;
4        if (i < 0) {
5            while (j >= 0) {
6                if (p[j] != '*')
7                    return false;
8                j--;
9            }
10            return true;
11        }
12        if ( j < 0)
13            return false;
14        if(dp[i][j]!=-1) return dp[i][j];    
15        if (s[i] == p[j] ||  p[j] == '?') {
16            return dp[i][j]=f(i - 1, j - 1, p,s,dp);
17        }
18        if ( p[j] == '*') {
19            return dp[i][j]=f(i - 1, j, p,s,dp) || f(i, j - 1, p,s,dp);
20        }
21        return dp[i][j]=false;
22    }
23
24public:
25    bool isMatch(string s, string p) {
26        int n = s.size();
27        int m = p.size();
28        vector<vector<int>>dp(n,vector<int>(m,-1));
29        return f(n - 1, m - 1, p,s,dp);
30    }
31};