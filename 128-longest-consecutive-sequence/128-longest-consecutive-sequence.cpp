class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int count=1;
        int max=1;
        int prev=*s.begin();
        for(auto i=s.begin();i!=s.end();i++){
            if(i==s.begin()){
                continue;
            }
            if(*i==prev+1){
                count++;
                if(count>max){
                    max=count;
                }
            }
            else{
                count=1;
            }
            prev=*i;
        }
        return max;
    }
};