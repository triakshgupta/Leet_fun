class Solution {
public:
    int search(int s,int e,int t,vector<int> num){
        while(s<=e){
            int mid=e+(s-e)/2;
            if(num[mid]==t){
                return mid;
            }
            else if(num[mid]>t){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int> ans(2);
        set<int> s;
        for(int i=0;i<num.size();i++){
            if(s.count(num[i])==0){
                int b;
                if(target-num[i]>=num[i]){
                    b=search(i+1,num.size()-1,target-num[i],num);
                }
                else{
                    b=search(0,i-1,target-num[i],num);
                }
               if(b>=0 && b!=i){
                  if(i<b){
                    ans[0]=(i+1);
                    ans[1]=(b+1);
                  }
                  else{
                    ans[0]=(b+1);
                    ans[1]=(i+1);
                  }
                  break;
                }
                else{
                  s.insert(num[i]);
                }
            }
        }
        return ans;
    }
};