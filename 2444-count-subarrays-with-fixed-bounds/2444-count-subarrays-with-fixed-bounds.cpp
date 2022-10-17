class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int Min=INT_MAX,Max=INT_MIN,n=nums.size(),min_start=-1,max_start=-1,start=0;
        long long ans=0;
        for(int i=0;i<n;i++) {
            Min=min(Min,nums[i]);
            Max=max(Max,nums[i]);
            if(Min<minK or Max>maxK) {
                Min=INT_MAX;
                Max=INT_MIN;
                start=i+1;
            }
            if(nums[i]==minK) {
                min_start=i;
            }
            if(nums[i]==maxK) {
                max_start=i;
            }
            if(Min==minK and Max==maxK) {
                ans+=(min(min_start,max_start)-start+1);
            }                
        }
        return ans;
    }
};