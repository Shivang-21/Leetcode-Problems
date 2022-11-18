class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size(),m=part.size(),len=0;
        string ans;
        ans.resize(n);
        for(int i=0;i<n;i++) {
            ans[len++]=s[i];
            if(len>=m and ans.substr(len-m,m)==part) {
                len-=m;
            }
            
        }
        return ans.substr(0,len);
    }
};