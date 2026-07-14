class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        ans.push_back(arr[n-1]);
        int maxback=arr[n-1];
        for(int i=n-2;i>=0;i--){
            maxback=max(maxback,arr[i]);
            if(arr[i]>=arr[i+1] && arr[i]>=maxback){
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};