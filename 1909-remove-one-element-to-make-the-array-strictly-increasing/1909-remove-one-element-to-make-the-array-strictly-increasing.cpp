class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n=nums.size(),count=0,prev=nums[0];
        for(int i=1;i<n;i++) {            
            if(nums[i]<=nums[i-1]) {
                count++;
                if(i!=1 and nums[i-2]>=nums[i]) {
                    nums[i]=nums[i-1];
                }
            }            
        }        
        return count<=1;
    }
};