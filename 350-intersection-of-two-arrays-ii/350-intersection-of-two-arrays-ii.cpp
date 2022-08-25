class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> n2;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            n2[nums2[i]]++;
        }
        for(int i=0;i<nums1.size();i++){
            if(n2[nums1[i]]>0){
                ans.push_back(nums1[i]);
                n2[nums1[i]]--;
            }
        }
        return ans;
    }
};