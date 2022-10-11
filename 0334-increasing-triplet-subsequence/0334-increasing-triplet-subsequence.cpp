class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=INT_MAX,j=INT_MAX,k=INT_MAX,a=0,b=0,c=0;
        for(int l=0;l<nums.size();l++)
        {
            if(nums[l]<=i)
            {
                i=nums[l];
                a=1;
            }                
            else if(nums[l]<=j)
            {
                j=nums[l];
                b=1;
            }                
            else
            {
                k=nums[l];
                c=1;
            }                
        }
        if(a+b+c==3)
            return true;
        else
            return false;
    }
};