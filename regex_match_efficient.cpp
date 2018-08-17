//regex_match_efficient.cpp
class Solution {
public:
    /*RECURSIVE/BACKTRACKING
    void ismatchdfs(string s, string p, int i, int j, bool& f){
        if(i==s.size() && j==p.size()){
            f=true;
            return;
        }
        if(!f && i<s.size() && j==p.size())
            return;
        if(!f && i==s.size() && j<p.size()){
            if(p[j+1]=='*')
                ismatchdfs(s,p,i,j+2,f);
            return;
        }
        
        if( !f && j<=p.size()-1 && (s[i]==p[j] || p[j]=='.') && p[j+1]!='*' ){
            ismatchdfs(s,p,i+1,j+1,f);
        }else{
            if(!f && j<p.size()-1 && p[j+1]=='*'){
                ismatchdfs(s,p,i,j+2,f);
                if(s[i]==p[j]||p[j]=='.')
                    ismatchdfs(s,p,i+1,j,f);
            }    
        }    
    }*/
    
    
    bool isMatch(string s, string p) {
        
        vector<vector<bool>> f(s.size()+1, vector<bool>(p.size()+1,false));
        f[0][0]=true;
        for(int j=1;j<p.size()+1;j++){
            if(p[j-1]=='*')
                f[0][j]=f[0][j-2];
        }
        
        for(int i=1 ; i<s.size()+1 ; i++){
            for(int j=1 ; j<p.size()+1 ; j++){
                if((s[i-1]==p[j-1] || p[j-1]=='.') && p[j-1]!='*')
                    f[i][j]=f[i-1][j-1];
                else if(p[j-1]=='*'){
                    f[i][j]=f[i][j-2];
                    if(s[i-1]==p[j-2]||p[j-2]=='.')
                        f[i][j]=f[i][j]|f[i-1][j];
                }
            }
        }
                
        return f[s.size()][p.size()];
    }
};