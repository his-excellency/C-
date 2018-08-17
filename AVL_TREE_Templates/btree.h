#pragma once

#ifndef _B_TREE
#define _B_TREE

#include "node.h"

template <class dtype>
class btree {
	node<dtype> *root;
	int count=0;//variable to keep the tree node count

public:
	btree();
	dtype getrootdat();			//ALWAYS GETROOT BEFORE PERFORMING ANY ACTIONS
	void setroot(node<dtype>*); //ALWAYS SETROOT BEFORE PERFORMING ANY ACTIONS
	node<dtype>* getroot();
	node<dtype>* insert(dtype, node<dtype>*); 	//YOU HAVE TO SET THE ROOT BEFORE RUNNING THIS FUNCTION
												//OTHERWISE YOU MIGHT SCREW THINGS UP
	int treelength(node<dtype>*);
	string deltree(node<dtype>*);//deletes the whole tree
	int numnodes(node<dtype>*);
	void dfsTraverse(node<dtype>*, int); //1- preorder 2- inorder 3- postorder

	//Functions to balance the tree- AVL tree
	int balanceFactor(node<dtype>*);
	node<dtype>* rotate(node<dtype>*,string); //1-left-left 2-right-right 3-left-right 4-right-left
	node<dtype>* balance(node<dtype>*);
	node<dtype>* insertBalanced(dtype, node<dtype>*);
	void delnode(node<dtype>*, int);

	
};

#include "btree.cpp"
#endif