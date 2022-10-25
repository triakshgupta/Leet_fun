class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX;
        int i=0,j=0;
        set<int> s;
        while(j<cards.size()){
            if(s.count(cards[j])>0){
                ans=min(ans,j-i+1);
                while(s.count(cards[j])>0){
                    s.erase(cards[i]);
                    i++;
                }
                ans=min(ans,j-i+2);
                s.insert(cards[j]);
                j++;
            }
            else{
                s.insert(cards[j]);
                j++;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};