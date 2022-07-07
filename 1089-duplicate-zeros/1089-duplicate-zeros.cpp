class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp;
        int i=0,x=0;
        while(i<arr.size()){
            if(arr[x]==0){
                temp.push_back(0);
                i++;
                if(i<arr.size()){
                    temp.push_back(0);
                    i++;
                }
                x++;
            }
            else{
                temp.push_back(arr[x]);
                x++;
                i++;
            }
        }
        arr=temp;
    }
};