class Solution {
public:
    int solve(int x){
        if(x<=1){
            return x;
        }
        return solve(x-1)+solve(x-2);
    }
    int fib(int n) {
        return solve(n);
    }
};