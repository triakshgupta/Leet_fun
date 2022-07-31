class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       multiset<int> s;
        int count=0;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]==0){
                count++;
            }
            s.insert(arr[i]);
        }
        for(auto i:s){
            if(s.count((i)*2)>0 && (count==0 || count>1)){
                return true;
            }
            else if(s.count((i)*2)>0 && count==1){
                if(i==0){
                    continue;
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
};