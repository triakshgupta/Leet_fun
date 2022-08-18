class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        int s=0,e=l.size()-1;
        while(s<=e){
            int mid=e+((s-e)/2);
            if((mid==0 && int(l[mid])>int(target) && int(l[l.size()-1])<=int(target)) || (mid!=0 && int(l[mid])>int(target) && int(l[mid-1])<=int(target))){
                return l[mid];
            }
            else if(int(l[mid])>int(target)){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return l[0];
    }
};