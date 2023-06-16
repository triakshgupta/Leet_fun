//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int down=0;
        int up=r-1;
        int rt=c-1;
        int lf=0;
        vector<int> ans;
        int i=0;
        int j=0;
        while(lf<=rt && down<=up){
            while(j<=rt){
                ans.push_back(matrix[down][j]);
                j++;
            }
            j=rt;
            down++;
            i=down;
            while(i<=up && lf<=rt && down<=up){
                ans.push_back(matrix[i][rt]);
                i++;
            }
            rt--;
            i=up;
            j=rt;
            while(j>=lf && lf<=rt && down<=up){
                ans.push_back(matrix[up][j]);
                j--;
            }
            up--;
            i=up;
            j=lf;
            while(i>=down && lf<=rt && down<=up){
                ans.push_back(matrix[i][lf]);
                i--;
            }
            lf++;
            i=down;
            j=lf;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends