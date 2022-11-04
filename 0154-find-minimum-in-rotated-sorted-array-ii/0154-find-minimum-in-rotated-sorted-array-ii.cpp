class Solution {
public:
    int findMin(vector<int>& nums) {
        return bruteforce(nums);
    }
    int bruteforce(vector<int>& nums) {
        int n=nums.size(),Min=INT_MAX;
        for(int i=0;i<n;i++) {
            Min=min(Min,nums[i]);
        }
        return Min;
    }
};