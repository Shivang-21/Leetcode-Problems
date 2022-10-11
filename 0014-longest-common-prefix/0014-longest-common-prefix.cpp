class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
            return "";
        for(int i=0;i<strs[0].size();i++) {
            for(int j=1;j<n;j++) {
                if(i==strs[j].size() or strs[j][i]!=strs[0][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};