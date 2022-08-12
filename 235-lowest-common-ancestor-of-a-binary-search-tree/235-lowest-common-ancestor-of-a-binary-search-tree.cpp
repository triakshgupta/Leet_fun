/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool lca(TreeNode* root, TreeNode* x,vector<TreeNode*>& p){
        if(root==NULL){
            return false;
        }
        if(root==x){
            return true;
        }
        p.push_back(root->left);
        if(lca(root->left,x,p)){
            return true;
        }
        p.pop_back();
        p.push_back(root->right);
        if(lca(root->right,x,p)){
            return true;
        }
        p.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        lca(root,p,a);
        lca(root,q,b);
        int x=0,y=0;
        TreeNode* ans=root;
        while(x<a.size() && y<b.size()){
            if(a[x]==b[y]){
                ans=a[x];
            }
            x++;
            y++;
        }
        return ans;
    }
};