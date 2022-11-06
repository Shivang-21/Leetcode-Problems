class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++) {
            if(nums[i]==nums[i+1]) {
                nums[i+1]=0;
                nums[i]<<=1;
            }            
        }
        int start=0,end=n-1;
        while(end<n) {
            while(nums[start]!=0)
                start++;
            for(end=start+1;end<n;end++) {
                if(nums[end]!=0) {
                    swap(nums[start],nums[end]);
                    break;
                }
                //start++
            }
        }
        return nums;
    }
};