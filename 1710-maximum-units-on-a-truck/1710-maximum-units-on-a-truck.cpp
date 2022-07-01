class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<boxTypes.size();i++){
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }
        int ans=0;
        while(truckSize && !pq.empty()){
            if(pq.top().second<=truckSize){
                ans+=(pq.top().second)*(pq.top().first);
                truckSize-=(pq.top().second);
                pq.pop();
            }
            else{
                ans+=((truckSize)*(pq.top().first));
                truckSize=0;
                
            }
        }
        return ans;
    }
};