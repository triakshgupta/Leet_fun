class Solution {
public:
    int arrangeCoins(int n) {
        long long int s=1,e=n;
        long long int mid=e+(s-e)/2;
        while(s<=e){
            mid=e+(s-e)/2;
            if((mid*(mid+1))/2==n || (((mid*(mid+1))/2)<n && (((mid+1)*(mid+2))/2)>n)){
                return mid;
            }
            else if((mid*(mid+1))/2<n){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
};