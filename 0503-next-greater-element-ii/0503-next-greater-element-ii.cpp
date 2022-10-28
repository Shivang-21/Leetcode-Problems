class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() and st.top().second<nums[i]) {
                ans[st.top().first]=nums[i];
                st.pop();
            }
            st.push({i,nums[i]});            
        }  
        for(int i=0;i<n;i++) {
            while(!st.empty() and st.top().second<nums[i]) {
                ans[st.top().first]=nums[i];
                st.pop();
            }
            st.push({i,nums[i]});            
        }  
        return ans;
    }
};