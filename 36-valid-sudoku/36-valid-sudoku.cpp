class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<char> x;
            set<char> y;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && x.count(board[i][j])>0){
                    return false;
                }
                else if(board[i][j]!='.'){
                    x.insert(board[i][j]);
                }
                if(board[j][i]!='.' && y.count(board[j][i])>0){
                    return false;
                }
                else if(board[j][i]!='.'){
                    y.insert(board[j][i]);
                }
            }
        }
        int x=0,y=0;
        while(y<9){
            set<char> s;
            for(int i=x;i<x+3;i++){
               for(int j=y;j<y+3;j++){
                  if(board[i][j]!='.' && s.count(board[i][j])>0){
                      return false;
                  }
                  else if(board[i][j]!='.'){
                      s.insert(board[i][j]);
                  }
               }
            }
            //cout<<x<<" "<<y<<endl;
            if(y<=6){
                if(x<6){
                    x+=3;
                }
                else{
                    x=0;
                    y+=3;
                }
            }
        }
        return true;
    }
};