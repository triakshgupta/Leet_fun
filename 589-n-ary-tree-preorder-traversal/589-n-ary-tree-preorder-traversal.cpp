/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void pre(vector<int>& ans,Node* x){
        if(x==NULL){
            return;
        }
        ans.push_back(x->val);
        for(int i=0;i<x->children.size();i++){
            pre(ans,x->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        pre(ans,root);
        return ans;
    }
};