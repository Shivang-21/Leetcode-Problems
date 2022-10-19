class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size(),count=0,ans=0;
        for(int j=0;j<32;j++) {
            count=0;
            for(int i=0;i<n;i++) {
                if(nums[i]&(1<<j)) {
                    count++;
                }
            }
            ans+=count*(n-count);
        }
        return ans;
    }
};