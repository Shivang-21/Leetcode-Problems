class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n=s.size();
        vector<int> freq(26,-1);
        for(int i=0;i<n;i++) {
            if(freq[s[i]-'a']!=-1) {
                if(i-freq[s[i]-'a']!=distance[s[i]-'a']+1)
                    return false;
            }
            freq[s[i]-'a']=i;
        }
        return true;
    }
};