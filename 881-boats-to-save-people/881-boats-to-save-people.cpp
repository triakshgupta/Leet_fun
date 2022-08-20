class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.size()==1){
            return 1;
        }
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        int count=0;
        while(i<j){
            if(people[i]+people[j]<=limit){
                count++;
                i++;
                j--;
            }
            else{
                count++;
                j--;
            }
        }
        if(i==j){
            count++;
        }
        return count;
    }
};