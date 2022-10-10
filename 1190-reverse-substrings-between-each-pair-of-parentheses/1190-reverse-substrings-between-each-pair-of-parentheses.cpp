class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n=s.size();
        string temp="";
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
            temp=st.top()+temp;
            st.pop();
        }
        //reverse(temp.begin(),temp.end());
        return temp;
    }
};