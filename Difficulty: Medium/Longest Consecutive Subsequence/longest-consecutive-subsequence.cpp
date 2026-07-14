class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st;
        for(int i=0;i<arr.size();i++) st.insert(arr[i]);
        int maxcnt=0;
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                maxcnt=max(maxcnt,cnt);
            }
        }
        return maxcnt;
    }
};