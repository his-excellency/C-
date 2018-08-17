//Boggle.cpp
class TrieNode{
public:
    unordered_map<char,TrieNode*> val;
    unordered_map<char,bool> chk;
    TrieNode(){
        val.insert({'\0',nullptr});
        chk.insert({'\0',false});
    }
};

class Trie{
    TrieNode* root;
public:
    Trie():root(new TrieNode()){}
    
    void insert(string word){
        TrieNode* tmp=root;
        int p=0;
        
        for(auto &i:word){
            if(p==word.size()-1)
                (tmp->chk)[i]=true;
            if((tmp->val).count(i)==0){
                (tmp->val)[i]=new TrieNode();
                tmp=(tmp->val)[i];
                
            }else{
                tmp=(tmp->val)[i];
            }
            p++;
        }
    }
    
    void setroot(TrieNode* s){
        root=s;
    }
    TrieNode* getroot(){
        return root;
    }
    
    bool search(string word){
        TrieNode* tmp=root;
        int i;
        for(i=0;i<word.size()-1;i++){
            if((tmp->val).count(word[i])==0)
                return false;
            else
                tmp=(tmp->val)[word[i]];
        }
        
        return (tmp->chk)[word[i]];
    }
    
    bool startsWith(string pref){
        TrieNode* tmp=root;
        for(auto &i:pref){
            if((tmp->val).count(i)==0)
                return false;
            else
                tmp=(tmp->val)[i];
        }
        return true;
    }
    
};


class Boggle {
public:
    
    void DFS(vector<vector<char>>& board, TrieNode* rt, int r, int c,string s,set<string>& res){
        //cout<<"I am in DFS "<<contained(board,r,c)<<endl;
        if(!contained(board,r,c) || board[r][c]=='*')
            return;
        
        if(rt!=nullptr && (rt->val).count(board[r][c])==1){
            s.push_back(board[r][c]);
            //cout<<s<<endl;
            if((rt->chk)[board[r][c]]==true)
                res.insert(s);
            rt=(rt->val)[board[r][c]];
            char tmp = board[r][c];
            board[r][c]='*';
            DFS(board,rt,r+1,c,s,res);
            DFS(board,rt,r-1,c,s,res);
            DFS(board,rt,r,c+1,s,res);
            DFS(board,rt,r,c-1,s,res);
            board[r][c]=tmp;
        }else
            return;
        
    }
    
    bool contained(vector<vector<char>>& board, int r,int c) {
        return (r>=0 && c>=0 && r<board.size() && c<board[0].size());
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tobj;
        TrieNode* rt=tobj.getroot();
        
        for(auto &i:words)
            tobj.insert(i);
        
        int r=board.size();
        int c=board[0].size();
        set<string> res;
        
        string s="";
        string p;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                p.push_back(board[i][j]);
                rt=tobj.getroot();
                if(tobj.startsWith(p)){
                    DFS(board,rt,i,j,s,res);
                }
                p="";
            }
        }
        
        vector<string> fres;
        for(auto &i:res)
            fres.push_back(i);
        
        return fres;
        
    }
};