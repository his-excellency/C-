
//#include "btree.h"

template <class dtype>
btree<dtype>::btree() {
	root = nullptr;
}

template <class dtype>
dtype btree<dtype>::getrootdat() {
	return root->getdata();
}

template<class dtype>
void btree<dtype>::setroot(node<dtype>* t) {
	root = t;
}

template <class dtype>
node<dtype>* btree<dtype>::getroot() {
	return root;
}


//YOU HAVE TO SET THE ROOT BEFORE RUNNING THIS FUNCTION
//OTHERWISE YOU MIGHT SCREW THINGS UP
template <class dtype>
node<dtype>* btree<dtype>::insert(dtype val,node<dtype>* rt)  {
	if (rt == nullptr) {
		//node<dtype>* rt = root;
		rt = new node<dtype>(val, nullptr, nullptr);
		//cout << rt->getdata()<<"\n";
		//root = rt;
		//return rt;
	}
	else {
		if (val <= rt->getdata()) {
			rt->setleft(insert(val, rt->getleft()));
			//cout << rt->getdata()<<"\n";
		}
		else {
			rt->setright(insert(val, rt->getright()));
			//cout << rt->getdata()<<"\n";
		}
	}
	return rt;
}

template <class dtype>
int btree<dtype>::treelength(node<dtype>* rt) {
	if (rt == nullptr) 
		return 0;
	else {
		if (treelength(rt->getleft()) > treelength(rt->getright()))
			return 1 + treelength(rt->getleft());
		else
			return 1 + treelength(rt->getright());
	}
}

template <class dtype>
string btree<dtype>::deltree(node<dtype>* rt) {
	if (rt != nullptr) {
		deltree(rt->getleft());
		deltree(rt->getright());
		//cout <<endl<< rt->getdata()<<" ";
		delete(rt);
		rt = nullptr;
		return "\nTree Delete Successful\n";
	}
	else
		return "\nTree Already Empty \n";
}

template <class dtype>
int btree<dtype>::numnodes(node<dtype>* rt) {
	if (rt == nullptr) return 0;
	if (rt != nullptr) {
		count = count + 1;
		numnodes(rt->getleft());
		numnodes(rt->getright());
	}
	return count;

}

template <class dtype>
void btree<dtype>::dfsTraverse(node<dtype>* rt, int s) {
	switch (s) {
	case 1:
		if (rt != nullptr) {
			cout << rt->getdata() << " ";
			dfsTraverse(rt->getleft(), 1);
			dfsTraverse(rt->getright(), 1);
		}
		break;
	case 2:
		if (rt != nullptr) {
			dfsTraverse(rt->getleft(), 2);
			cout << rt->getdata() << " ";
			dfsTraverse(rt->getright(), 2);
		}
		break;
	case 3:
		if (rt != nullptr) {
			dfsTraverse(rt->getleft(), 3);
			dfsTraverse(rt->getright(), 3);
			cout << rt->getdata() << " ";
		}
		break;
	default:
		cout << "Enter: (1)Pre-Order, (3)Post-Order, (2)In-Order";
		break;
	}
}

template <class dtype>
int btree<dtype>::balanceFactor(node<dtype>* r) {
	int hl,hr;
	hl = treelength(r->getleft());
	hr = treelength(r->getright());
	return (hl - hr);
}

template <class dtype>
node<dtype>* btree<dtype>::rotate(node<dtype>* r,string i) {
	node<dtype>* tmp;
	if (i == "ll") {
		tmp = r -> getleft();
		r->setleft(tmp->getright());
		tmp->setright(r);
		return tmp;
	}
	else if (i == "rr") {
		tmp = r->getright();
		r->setright(tmp->getleft());
		tmp->setleft(r);
		return tmp;
	}
	else if (i == "lr") {
		tmp = r->getleft();
		r->setleft(rotate(tmp, "rr"));
		return rotate(r, "ll");
	}
	else if (i == "rl") {
		tmp = r->getright();
		r->setright(rotate(tmp, "ll"));
		return rotate(r, "rr");
	}
	else {
		cout << "\nEnter ll,rr,lr or rl. No changes made.\n";
		return r;
	}

}

template <class dtype>
node<dtype>* btree<dtype>::balance(node<dtype>* r) {
	int bf = balanceFactor(r);
	if (bf > 1) {
		if (balanceFactor(r->getleft()) > 0)
			r = rotate(r, "ll");
		else
			r = rotate(r, "lr");
		return r;
	}
	else if (bf < -1) {
		if (balanceFactor(r->getleft()) < 0)
			r = rotate(r, "rr");
		else
			r = rotate(r, "rl");
		return r;
	}
	else {
		cout << "Tree is Already Balanced";
		return r;
	}
}

template <class dtype>
node<dtype>* btree<dtype>::insertBalanced(dtype val, node<dtype>* rt) {
	rt = insert(val, rt);
	return balance(rt);
}

template <class dtype>
void btree<dtype>::delnode(node<dtype>* r, int d) {

}