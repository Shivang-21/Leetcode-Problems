class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size(),Max=arr[n-1];
        vector<int> ans(n,-1);
        for(int i=n-2;i>=0;i--) {
            ans[i]=Max;
            Max=max(Max,arr[i]);
        }
        return ans;
    }
};