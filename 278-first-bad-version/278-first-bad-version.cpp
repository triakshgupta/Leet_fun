// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1,e=n;
        while(s<=e){
            int mid=e+((s-e)/2);
            if(mid!=1 && isBadVersion(mid) && !isBadVersion(mid-1)){
                return mid;
            }
            else if(!isBadVersion(mid)){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return 1;
    }
};