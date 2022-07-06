class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        int prev=1;
        int prevprev=0;
        for(int i=2;i<=n;i++){
            int temp=prev+prevprev;
            prevprev=prev;
            prev=temp;
        }
        return prev;
    }
};