class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size(),prev=-1,curr,Max=0;
        map<int,int> mp;
        for(auto i:nums) {
            mp[i]++;            
        }
        for(auto i:mp) {
            curr=i.first;
            if(prev==-1) {
                prev=curr;
            }
            else {
                Max=max(Max,curr-prev);
                prev=curr;
            }
        }
        return Max;
    }
};