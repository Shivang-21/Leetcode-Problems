class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size(),gap,Min=*min_element(nums.begin(),nums.end()),Max=*max_element(nums.begin(),nums.end());
        if(n<=1)
            return 0;
        int max_gap=0,prev=Min,index;
        gap=ceil((double)(Max-Min)/(n-1));
        vector<int> Min_bucket(n-1,INT_MAX),Max_bucket(n-1,INT_MIN);
        for(int i=0;i<n;i++) {
            if(nums[i]==Max or nums[i]==Min) {
                continue;
            }
            index=(nums[i]-Min)/gap;
            Min_bucket[index]=min(nums[i],Min_bucket[index]);
            Max_bucket[index]=max(nums[i],Max_bucket[index]);
        }
        for(int i=0;i<n-1;i++) {
            if(Min_bucket[i]!=INT_MAX and Max_bucket[i]!=INT_MIN) {
                max_gap=max(max_gap,Min_bucket[i]-prev);
                prev=Max_bucket[i];
            }
        }
        max_gap=max(max_gap,Max-prev);
        return max_gap;         
    }
};