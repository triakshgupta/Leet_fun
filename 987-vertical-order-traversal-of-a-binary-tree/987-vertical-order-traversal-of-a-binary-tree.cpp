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
    void solve(priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>& ans,TreeNode* root,int x,int y){
        if(root==NULL){
            return;
        }
        vector<int> temp={x,y,root->val};
        ans.push(temp);
        solve(ans,root->left,x-1,y+1);
        solve(ans,root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> ans;
        vector<vector<int>> a;
        solve(ans,root,0,0);
        while(!ans.empty()){
            int temp=ans.top()[0];
            vector<int> t;
            while(!ans.empty() && ans.top()[0]==temp){
                t.push_back(ans.top()[2]);
                ans.pop();
            }
            a.push_back(t);
        }
        return a;
    }
};