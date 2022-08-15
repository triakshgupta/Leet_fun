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
    void path(vector<string>& ans,string s,TreeNode* x){
        if(x==NULL){
            return;
        }
        if(x->left==NULL && x->right==NULL){
            ans.push_back(s + to_string(x->val));
            return;
        }
        if(x->left){
            path(ans,s+to_string(x->val)+"->",x->left);
        }
        if(x->right){
            path(ans,s+to_string(x->val)+"->",x->right);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        //string s="";
        path(ans,"",root);
        return ans;
    }
};