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
    void sum(vector<string>& nums,string& t,TreeNode* x){
        if(x->left==NULL && x->right==NULL){
            t+=to_string(x->val);
            nums.push_back(t);
            t.pop_back();
            return;
        }
        t+=to_string(x->val);
        if(x->left){
            sum(nums,t,x->left);
        }
        if(x->right){
            sum(nums,t,x->right);
        }
        t.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<string> nums;
        string t;
        sum(nums,t,root);
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=stoi(nums[i]);
        }
        return ans;
    }
};