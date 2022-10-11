class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),start=0,end=n-1;
        int M=min(height[0],height[n-1])*(n-1);
        while(start<end) {
            if(height[start]<height[end]) {
                start++;
            }
            else {
                end--;
            }
            M=max(M,min(height[start],height[end])*(end-start));
        }
        return M;
    }
};