class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int pos=0;
        int fuel=startFuel;
        int count=0;
        for(int i=0;i<stations.size();i++){
            if(stations[i][0]-pos>fuel && pq.size()==0){
                return -1;
            }
            else{
                if(stations[i][0]-pos<=fuel){
                    fuel=fuel-stations[i][0]+pos;
                    pos=stations[i][0];
                    pq.push(stations[i][1]);
                    //cout<<fuel<<endl;
                }
                else{
                    while(fuel<stations[i][0]-pos && pq.size()!=0){
                        count++;
                        //cout<<'h'<<endl;
                        fuel+=pq.top();
                        //cout<<fuel<<endl;
                        pq.pop();
                    }
                    if(fuel<stations[i][0]-pos && pq.size()==0){
                        return -1;
                    }
                    else{
                        fuel=fuel-stations[i][0]+pos;
                        pos=stations[i][0];    
                        pq.push(stations[i][1]);
                        //cout<<fuel<<endl;
                    }
                }
            }
        }
        while(fuel<target-pos && pq.size()!=0){
            count++;
            fuel+=pq.top();
            pq.pop();
        }
        if(fuel<target-pos && pq.size()==0){
            return -1;
        }
        return count;
    }
};