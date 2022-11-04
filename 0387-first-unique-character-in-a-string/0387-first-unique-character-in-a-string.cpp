class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size(),ans=INT_MAX;
        unordered_map<char,int> freq,index;
        for(int i=0;i<n;i++) {
            freq[s[i]]++;
            index[s[i]]=i;
        }
        for(auto i:freq) {
            if(i.second==1) {
                ans=min(ans,index[i.first]);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};