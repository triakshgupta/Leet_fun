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
    bool solve(TreeNode* x,TreeNode* parent,int i){
        if(x==NULL){
            return true;
        }
        bool l=solve(x->left,x,0);
        bool r=solve(x->right,x,1);
        if(l && r){
            if(x->val==1){
                //s.insert(1);
                return false;
            }
            else{
                if(i==0){
                    parent->left=NULL;
                }
                if(i==1){
                    parent->right=NULL;
                }
                return true;
            }
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool x=solve(root,NULL,-1);
        if(x){
            return NULL;
        }
        return root;
    }
};