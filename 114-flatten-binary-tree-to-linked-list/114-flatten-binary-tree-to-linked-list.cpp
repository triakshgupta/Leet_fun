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
    void pre(stack<TreeNode*>& s,TreeNode* x){
        if(x==NULL){
            return;
        }
        s.push(x);
        pre(s,x->left);
        pre(s,x->right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        stack<TreeNode*> s;
        pre(s,root);
        s.top()->left=NULL;
        s.top()->right=NULL;
        while(s.top()!=root){
            struct TreeNode* temp=s.top();
            s.pop();
            s.top()->right=temp;
            s.top()->left=NULL;
        }
        return;
    }
};