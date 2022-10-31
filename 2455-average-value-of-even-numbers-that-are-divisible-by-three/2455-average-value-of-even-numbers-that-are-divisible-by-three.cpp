class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0,count=0;
        for(auto i:nums) {
            if(i%6==0) {
                sum+=i;
                count++;
            }
        }
        return count==0?0:sum/count;
    }
};