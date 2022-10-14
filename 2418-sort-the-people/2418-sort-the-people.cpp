class Solution {
public:
    static bool comp(pair<int,string>& a,pair<int,string>& b) {
        return a.first>b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pair<int,string>> a(n);
        for(int i=0;i<n;i++) {
            a[i]={heights[i],names[i]};
        }
        sort(a.begin(),a.end(),comp);
        for(int i=0;i<n;i++) {
            names[i]=a[i].second;
        }
        return names;
    }
};