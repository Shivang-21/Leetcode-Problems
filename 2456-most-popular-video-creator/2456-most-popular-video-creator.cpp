class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long long int> tviews;
        unordered_map<string,int> fid;
        vector<vector<string>> ans;
        int n=creators.size();
        long long int Max=0;
        for(int i=0;i<n;i++) {
            tviews[creators[i]]+=views[i];
            if(fid.find(creators[i])==fid.end()) {
                fid[creators[i]]=i;
            }
            else if(views[fid[creators[i]]]<=views[i]) {
                if(views[fid[creators[i]]]<views[i]) {
                    fid[creators[i]]=i;
                }                
                else {
                    if(ids[fid[creators[i]]]>ids[i]) {
                        fid[creators[i]]=i;
                    }
                }
            }
            Max=max(Max,tviews[creators[i]]);
        }
        for(auto i:tviews) {
            if(i.second==Max) {
                ans.push_back({i.first,ids[fid[i.first]]});
            }
        }
        return ans;
    }
};