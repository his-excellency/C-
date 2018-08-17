//Least_Recently_Used_Cache.cpp
class lNode{
public:
    lNode(int n):val(n),front(nullptr),back(nullptr){}
    lNode* front;
    lNode* back;
    int val;
};

lNode* insert(lNode*& head,lNode*& latest, int v){
    if(head==nullptr){
        head=new lNode(v);
        latest=head;
    }
    else{
        latest->front=new lNode(v);
        latest->front->back=latest;
        latest=latest->front;
    }
    return latest;
}

void delback(lNode*& head,lNode*& latest){
    lNode* tmp=head;
    if(!tmp->back && !tmp->front){
        head=nullptr;
        latest=nullptr;
        delete tmp;
        tmp=nullptr;
    }else{
        head=head->front;
        head->back=nullptr;
        tmp->front=nullptr;
        delete tmp;
        tmp=nullptr;
    }
}

void moveTofront(lNode*& ptr, lNode*& latest, lNode*& oldest){
    if(ptr==latest)
        return;
    lNode* tmp=ptr->back;
    if(tmp!=nullptr){
        tmp->front=ptr->front;
        ptr->front->back=tmp;   
    }else{
        oldest=ptr->front;
        oldest->back=nullptr;
    }
    ptr->front=nullptr;
    ptr->back=latest;
    latest->front=ptr;
    latest=latest->front; 
}

class LRUCache {
    lNode* latest;
    lNode* oldest;
    int l;
    unordered_map<int,lNode*> lrucache;
    unordered_map<lNode*,int> nodetokey;
public:
    
    LRUCache(int capacity): l(capacity),latest(nullptr),oldest(nullptr) { }
    
    int get(int key) {
        if(lrucache.count(key)==0 || lrucache[key]==nullptr)
            return -1;
        else{
            moveTofront(lrucache[key],latest,oldest);
            return lrucache[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(lrucache.size()>=l && lrucache.count(key)==0){
            lrucache[nodetokey[oldest]]=nullptr;
            lrucache.erase(nodetokey[oldest]);
            nodetokey.erase(oldest);
            delback(oldest,latest);
       }
       if(lrucache.count(key)==1){
            lrucache[key]->val=value;
            moveTofront(lrucache[key],latest,oldest);
       }else{
            lrucache[key]=insert(oldest,latest,value);
            nodetokey[lrucache[key]]=key;    
        }
    }
};

/*
int main(){
	LRUCache obj = new LRUCache(capacity);
  	int param_1 = obj.get(key);
  	obj.put(key,value);	

  	cin.get();
  	return 0;
}
  
 */