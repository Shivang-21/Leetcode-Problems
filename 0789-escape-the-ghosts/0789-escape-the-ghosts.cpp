class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int pacman_distance=abs(target[0])+abs(target[1]),n=ghosts.size();        
        for(int i=0;i<n;i++) {
            if(pacman_distance>=abs(target[0]-ghosts[i][0])+abs(target[1]-ghosts[i][1])) {
                return false;
            }
        }
        return true;
    }
};