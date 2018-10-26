class Sudoku {
public:

    void bktSudoku(vector<vector<char>>& S, bool& p){
        int k;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                for(k=1;k<=9;k++){
                    if(S[i][j]=='.'){
                        if(!colu(S,i,j,k) && !rowu(S,i,j,k) && !boxu(S,i,j,k)){
                            S[i][j]=char(k+'0');
                            bktSudoku(S,p);
                            if(!p){
                                p=true;
                                S[i][j]='.';    
                            }
                        }   
                    }    
                }
                if(k>9 && S[i][j]=='.'){
                    p=false;
                    return;
                }
                    
            }
        }
    }
    
    bool colu(vector<vector<char>> S,int i, int j, int k){
        for(int p=0;p<9;p++)
            if(S[p][j]==char(k+'0'))
                return true;
        return false;
    }
    
    bool rowu(vector<vector<char>> S,int i,int j,int k){
        for(int p=0;p<9;p++)
            if(S[i][p]==char(k+'0'))
                return true;
        return false;
    }
    
    bool boxu(vector<vector<char>> S,int i,int j,int k){
        int r,c;
        r = i<3 ? 0 : (i<6 ? 3: 6);
        c = j<3 ? 0 : (j<6 ? 3: 6);
        
        for(int x=r;x<r+3;x++){
            for(int y=c;y<c+3;y++){
                if(S[x][y]==char(k+'0'))
                    return true;
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool p=true;
        bktSudoku(board,p);
    }
};