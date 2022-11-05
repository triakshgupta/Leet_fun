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
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        queue<Node*> q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                for(int i=0;i<q.front()->children.size();i++){
                    q.push(q.front()->children[i]);
                }
                q.pop();
            }
            l++;
        }
        return l;
    }
};