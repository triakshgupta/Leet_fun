class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int i=0;
        while(i*i<=c){
            int s=i,e=c;
            while(s<=e){
                long long int mid=e+(s-e)/2;
                if(i*i+mid*mid==c){
                    return true;
                }
                else if(i*i+mid*mid<c){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            i++;
        }
        return false;
    }
};