class Solution {
public:
    int temp(int n){
        if(n==0 || n==1) return n;
        if(n%2!=0){
            return temp((n-1)/2) +temp((n+1)/2);
        }
        else{
            return temp(n/2);
        }
    }
    int getMaximumGenerated(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,temp(i));
        }
        return ans;
    }
};