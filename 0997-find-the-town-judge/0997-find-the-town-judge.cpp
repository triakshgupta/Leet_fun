class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n,0);
        vector<int> outdegree(n,0);
        for(int i=0;i<trust.size();i++){
            indegree[trust[i][1]-1]++;
            outdegree[trust[i][0]-1]++;
        }
        int a=-1;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0 && indegree[i]==n-1){
                a=i+1;
            }
        }
        return a;
    }
};