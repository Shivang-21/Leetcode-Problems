class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            sum%=k;
            if(mp.count(sum)>0) {
                if(i-mp[sum]>=2)
                    return 1;
            }
            else {
                mp[sum]=i;
            }
        }
        return 0;
    }
};