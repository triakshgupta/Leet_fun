class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0,j=tokens.size()-1;
        int ans=0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power-=tokens[i];
                i++;
                ans=max(ans,score);
            }
            else if(score!=0){
                power+=tokens[j];
                score--;
                ans=max(ans,score);
                j--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};