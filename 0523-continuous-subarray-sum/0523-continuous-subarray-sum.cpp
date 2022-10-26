class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1) return false;
        vector<long long> p;
        long long sum=0;
        //long long maxi=INT_MIN;
        multimap<long long,int> m;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum%k==0 && i>0) return true;
            p.push_back(sum);
            m.insert({sum,i});
            //maxi=max(maxi,sum);
        }
        for(int i=0;i<nums.size();i++){
            int j=0;
            while(j<=p[i]){
                if(m.count(p[i]-j)>0){
                    for(auto x=m.find(p[i]-j);x->first==p[i]-j && x!=m.end();x++){
                        if(x->second<i-1 || x->second>i+1) return true;
                    }
                }
                j+=k;
            }
        }
        return false;
    }
};