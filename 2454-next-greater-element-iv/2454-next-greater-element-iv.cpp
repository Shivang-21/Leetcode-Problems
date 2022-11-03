class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        //return bruteforce(nums);
        return solution1(nums);
    }
private:
    vector<int> bruteforce(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            int count=0;
            ans[i]=-1;
            for(int j=i+1;j<n;j++) {
                if(nums[j]>nums[i]) {
                    count++;
                }
                if(count==2) {
                    ans[i]=nums[j];
                    break;
                }
            }
        }
        return ans;
    }
    vector<int> solution1(vector<int>& nums) {
        stack<int> st,st1,st2;
        queue<int> q;
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++) {
            while(!st2.empty() and nums[st2.top()]<nums[i]) {
                ans[st2.top()]=nums[i];
                st2.pop();
            }
            while(!st.empty() and nums[st.top()]<nums[i]) {
                st1.push(st.top());                
                st.pop();
            }
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            st.push(i);
        }
        return ans;
    }
};