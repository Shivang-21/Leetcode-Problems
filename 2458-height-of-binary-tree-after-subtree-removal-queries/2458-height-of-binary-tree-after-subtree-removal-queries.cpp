/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* root,unordered_map<int,int>& l,unordered_map<int,int>& r) {
        if(!root)
            return 0;
        int Left=find(root->left,l,r);
        int Right=find(root->right,l,r);
        l[root->val]=Left;
        r[root->val]=Right;
        return 1+max(Left,Right);        
    }
    void find2(TreeNode* root,int a,int d,unordered_map<int,int>& l,unordered_map<int,int>& r,unordered_map<int,int>& q) {
        if(!root)
            return;
        q[root->val]=a;
        find2(root->left,max(a,d+r[root->val]),d+1,l,r,q);
        find2(root->right,max(a,d+l[root->val]),d+1,l,r,q);        
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int,int> l,r,q;
        int n=queries.size();
        vector<int> ans(n);
        find(root,l,r);
        find2(root->left,r[root->val],1,l,r,q);
        find2(root->right,l[root->val],1,l,r,q);
        for(int i=0;i<n;i++) {
            ans[i]=q[queries[i]];
        }
        return ans;
    }
};