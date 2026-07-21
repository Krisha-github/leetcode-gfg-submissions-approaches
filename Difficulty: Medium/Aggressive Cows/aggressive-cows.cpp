class Solution {
    bool check(int dis,vector<int> &arr, int k){
        int last=arr[0];
        int cows=1;
        for(int i=1;i<arr.size();i++){
            if(cows==k) return true;
            
            if(arr[i]-last>=dis){
                last=arr[i];
                cows++;
            }
        }
        if(cows>=k) return true;
        return false;
    }
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,arr,k)){
                low=mid+1;
                
            }
            else high=mid-1;
        }
        return high;
        
    }
};