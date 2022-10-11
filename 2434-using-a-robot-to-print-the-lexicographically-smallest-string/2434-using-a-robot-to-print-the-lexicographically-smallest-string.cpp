class Solution {
public:
    char find_low(vector<int>& f) {
        for(int i=0;i<26;i++) {
            if(f[i]!=0) {
                return 'a'+i;
            }
        }
        return 'a';
    }
    string robotWithString(string s) {
        vector<int> f(26,0);
        for(auto i:s) {
            f[i-'a']++;
        }
        string ans="";
        stack<char> st;
        for(auto ch:s) {
            st.push(ch);
            f[ch-'a']--;
            while(!st.empty() and st.top()<=find_low(f)) {
                ans+=st.top();
                st.pop();
            }
        }
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};