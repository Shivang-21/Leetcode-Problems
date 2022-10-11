class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size(),ans=0;
        unordered_map<char,vector<int>> mp;        
        for(int i=0;i<n;i++) {
            if(mp[s[i]].size()!=2)
                mp[s[i]].push_back(i);
            else {
                mp[s[i]][1]=i;
            }
        }
        for(auto i:mp) {
            if(mp[i.first].size()==2) {
                unordered_set<char> f;
                for(int j=mp[i.first][0]+1;j<mp[i.first][1];j++) {
                    f.insert(s[j]);
                } 
                ans+=f.size();
            }
        }
        return ans;
    }
};