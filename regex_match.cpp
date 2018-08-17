//regex_match.cpp
class regexMatch {
public:
	void ismatchdfs(string,string,int,int,bool&);
	bool isMatch(string,string);
};

void regexMatch::ismatchdfs(string , string p, int i, int j, bool& f){
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
}

bool regexMatch::isMatch(string s, string p) {
        bool f=false;
        ismatchdfs(s,p,0,0,f);
        return f;
    }