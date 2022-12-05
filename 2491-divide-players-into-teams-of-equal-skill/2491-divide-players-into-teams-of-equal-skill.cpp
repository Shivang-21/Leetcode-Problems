class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        long long tskill=skill[0]+skill[n-1],c=skill[0]*skill[n-1];
        for(int i=1;i<=(n-2)/2;i++) {
            if((skill[i]+skill[n-i-1])!=tskill)
                return -1;
            c+=(skill[i]*skill[n-i-1]);
        }
        return c;
    }
};