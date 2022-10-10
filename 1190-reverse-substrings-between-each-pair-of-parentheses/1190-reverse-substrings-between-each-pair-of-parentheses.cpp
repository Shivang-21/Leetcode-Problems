class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n=s.size();
        string temp="",temp1="";
        for(int i=0;i<n;i++) {
            if(s[i]==')') {
                while(st.top()!='(') {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                if(i!=n-1) {
                    for(auto ch:temp) {
                        st.push(ch);
                    }
                    temp="";
                }                
            }
            else {
                st.push(s[i]);
            }
        }        
        while(!st.empty()) {
            temp1+=st.top();
            st.pop();
        }
        reverse(temp1.begin(),temp1.end());
        return temp1+temp;
    }
};