class Solution {
public:
    int findMin(vector<int>& nums) {
        return bruteforce(nums);
        return binarysearch(nums);
    }
    int bruteforce(vector<int>& nums) {
        int n=nums.size(),Min=INT_MAX;
        for(int i=0;i<n;i++) {
            Min=min(Min,nums[i]);
        }
        return Min;
    }
    int binarysearch(vector<int>& a) {
        int l=0,u=a.size()-1,mid,n=a.size();
        while(l<=u) {
            mid=l+(u-l)/2;
            if(a[mid]>=a[u] and a[mid]<=a[l]) {
                l=mid+1;
            }
            else if(a[mid]<a[u] and a[mid]>a[l]){
                u=mid-1;
            }
            else if(a[mid]<a[l] and a[mid]<a[u]){
                return a[mid];
            }
        }
        return -1;
    }
};