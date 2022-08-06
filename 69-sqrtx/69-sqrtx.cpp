class Solution {
public:
    int mySqrt(int x) {
        long int s=0,e=x;
        while(s<=e){
            long int mid=e+(s-e)/2;
            long long int sq=mid*mid;
            if(sq==x || (sq<x && (mid+1)*(mid+1)>x)){
                return mid;
            }
            else if(sq>x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return 0;
    }
};