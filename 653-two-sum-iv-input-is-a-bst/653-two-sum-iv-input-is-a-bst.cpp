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
    // void inorder(TreeNode* x,vector<int>& a){
    //     if(x==NULL){
    //         return;
    //     }
    //     inorder(x->left,a);
    //     a.push_back(x->val);
    //     inorder(x->right,a);
    // }
    // bool findTarget(TreeNode* root, int k) {
    //     vector<int> a;
    //     inorder(root,a);
    //     int i=0,j=a.size()-1;
    //     while(i<j){
    //         if(a[i]+a[j]==k){
    //             return true;
    //         }
    //         else if(k>a[i]+a[j]){
    //             i++;
    //         }
    //         else{
    //             j--;
    //         }
    //     }
    //     return false;
    // }
    
    
    void inorder(TreeNode* x,vector<int>& a){
        if(x==NULL){
            return;
        }
        inorder(x->left,a);
        a.push_back(x->val);
        inorder(x->right,a);
    }
    bool search(TreeNode* x,int a){
        if(x==NULL){
            return false;
        }
        if(x->val==a){
            return true;
        }
        else if(x->val>a){
            return search(x->left,a);
        }
        return search(x->right,a);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        inorder(root,a);
        for(int i=0;i<a.size();i++){
            if(k-a[i]!=a[i] && search(root,k-a[i])){
                return true;
            }
        }
        return false;
    }
};