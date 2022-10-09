class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size(),flag,mid,i=0,j=0,l,r,a,b;
        if(m==0 and n==0)
            return 0;
        mid=(m+n)/2;
        while(true) {
            l=i<m?nums1[i]:INT_MAX;
            r=j<n?nums2[j]:INT_MAX;
            if(l<=r) {
                a=l;
                i++;
            }
            else {
                a=r;
                j++;
            }            
            if((m+n)&1 and i+j==mid+1) {
                return a;
            }
            else if(!((m+n)&1)){
                if(i+j==mid) {
                    b=a;
                }
                else if(i+j==mid+1) {
                    return (a+b)/2.0;
                }
            }            
        }
        return 0;
    }
};