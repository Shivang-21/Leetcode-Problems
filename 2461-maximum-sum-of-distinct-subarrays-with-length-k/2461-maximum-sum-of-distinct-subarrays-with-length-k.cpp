class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0,max_sum=0;
        int start=0,end=0,n=nums.size();
        unordered_map<int,int> mp;
        while(end<n) {
            mp[nums[end]]++;
            sum+=nums[end];
            while(mp[nums[end]]>1) {
                mp[nums[start]]--;
                sum-=nums[start];
                start++;
            }
            if(end-start+1>k) {
                mp[nums[start]]--;
                sum-=nums[start];
                start++;
            }
            if(end-start+1==k) {
                max_sum=max(max_sum,sum);
            }
            end++;
        }
        return max_sum;
    }
};