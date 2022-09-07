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
    // void solve(string& s,TreeNode* x){
    //     if(x->left==NULL && x->right==NULL){
    //         s+=to_string(x->val);
    //         return;
    //     }
    //     s+=to_string(x->val);
    //     s.push_back('(');
    //     if(x->left){
    //         solve(s,x->left);
    //         s.push_back(')');
    //     }
    //     else{
    //         s.push_back(')');
    //     }
    //     if(x->right){
    //         s.push_back('(');
    //         solve(s,x->right);
    //         s.push_back(')');
    //     }
    // }
    string tree2str(TreeNode* root) {
        // string s;
        // solve(s,root);
        // return s;
        if(!root) return "";
        string ans;
        ans += to_string(root->val);
        
        if(root->left){
            ans += "(" + tree2str(root->left) + ")";
        }
        else if(root->right){
            ans += "()";
        }
        if(root->right){
            ans += "(" + tree2str(root->right) + ")";
        }
        return ans;
    }
};