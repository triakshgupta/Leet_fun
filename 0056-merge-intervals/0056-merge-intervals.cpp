class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
         return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(),intervals.end(),sortcol);
        int j=0;
        vector<vector<int>> ans;
            while(j<intervals.size()-1){
                if(intervals[j][1]>=intervals[j+1][0]){
                    if(intervals[j][1]>=intervals[j+1][1]){
                        intervals[j+1][1]=intervals[j][1];
                        intervals[j+1][0]=intervals[j][0];
                    }
                    else{
                        intervals[j][1]=intervals[j+1][1];
                        intervals[j+1][0]=intervals[j][0];
                    }
                }
                else{
                    ans.push_back(intervals[j]);
                }
                j++;
            }
            ans.push_back(intervals[j]);
        return ans;
    }
};