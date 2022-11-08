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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> s;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int x=q.size();
            if(l%2==0){
                for(int i=0;i<x;i++){
                    if(q.front()->left) {
                        q.push(q.front()->left);
                        q.push(q.front()->right);
                        s.push_back(q.front()->left->val);
                        s.push_back(q.front()->right->val);
                    }
                    q.pop();
                }
                // for(int i=0;i<q.size();i++){
                //     int a=q.front()->val;
                //     s.push(a);
                //     TreeNode* temp=q.front();
                //     q.pop();
                //     q.push(temp);
                // }
            }
            else{
                for(int i=0;i<x;i++){
                    if(q.front()->left) {
                        q.push(q.front()->left);
                        q.push(q.front()->right);
                    }
                    q.front()->val=s[s.size()-1];
                    q.pop();
                    s.pop_back();
                }
            }
            l++;
        }
        return root;
    }
};