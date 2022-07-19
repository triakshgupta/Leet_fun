class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<groupSizes.size();i++){
            pq.push({groupSizes[i],i});
        }
        while(pq.size()){
            int temp=pq.top().first;
            int count=0;
            vector<int> p;
            while(count!=temp){
                p.push_back(pq.top().second);
                pq.pop();
                count++;
            }
            ans.push_back(p);
        }
        return ans;
    }
};