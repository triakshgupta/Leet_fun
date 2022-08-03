class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        
        int min_sum = 0;
        int n=card.size()-k;
        for (int i = 0; i < n; i++)
        min_sum += card[i];

        int window_sum = min_sum;
        for (int i = n; i < card.size(); i++) {
          window_sum += card[i] - card[i - n];
          min_sum = min(min_sum, window_sum);
        }
        int t=0;
        for(int i=0;i<card.size();i++){
            t+=card[i];
        }
        return t-min_sum;
    }
};