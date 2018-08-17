#pragma once

#ifndef _NODE
#define _NODE
//#include "btree.h"
using namespace std;

template <class dtype>
class node {
	dtype data;
	node<dtype> *left;
	node<dtype> *right;
public:
//	node();
	node(dtype);
	node(dtype, node<dtype>*, node<dtype>*);
	dtype getdata();
	node<dtype>* getleft();
	node<dtype>* getright();
	void setleft(node<dtype>*);
	void setright(node<dtype>*);
};

#include "node.cpp"
#endif