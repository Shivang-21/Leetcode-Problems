class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        return bruteforce(nums,k);
    }
    int bruteforce(vector<int>& nums, int k) {
        int count=0;
        long long l,n=nums.size();
        for(int i=0;i<n;i++) {
            l=nums[i];
            if(l==k)
                count++;
            else if(l>k)
                continue;
            for(int j=i+1;j<n;j++) {
                l=lcm(l,nums[j]);
                if(l==k) {
                    count++;
                }
                else if(l>k)
                break;
            }            
        }
        return count;
    }    
};