class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int m=queries.size(),n=dictionary.size(),s=queries[0].size();
        vector<string> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int count=0;
                for(int k=0;k<s;k++) {
                    if(queries[i][k]!=dictionary[j][k]) {
                        count++;
                    }
                }
                if(count<=2) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};