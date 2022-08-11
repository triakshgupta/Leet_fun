class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        else if(n%2==0 && n){
            return isPowerOfTwo(n/2);
        }
        return false;
    }
};