class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string,vector<string>> mp;
        for(auto word:words) {
            string st="";
            for(int i=0;i<word.size()-1;i++) {
                st+=to_string(word[i+1]-word[i])+"*";
            }
            mp[st].push_back(word);
        }
        for(auto i:mp) {
            if(i.second.size()==1) {
                return i.second[0];
            }
        }
        return "";
    }
};