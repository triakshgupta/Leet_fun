class Solution {
public:
    bool solve(long long int n){
        if(n==1){
            return true;
        }
        if(n%4==0){
            return solve(n/4);
        }
        return false;
    }
    bool isPowerOfFour(int n) {
        if(n==0)
            return false;
        return solve(n);
    }
};