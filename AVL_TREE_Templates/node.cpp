
//#include "node.h"

template <class dtype>
void node<dtype>::setright(node<dtype>* r) {
	right = r;
}

template <class dtype>
void node<dtype>::setleft(node<dtype>* l) {
	left = l;
}

template <class dtype>
node<dtype>::node(dtype d) {
	data = d;
}

template <class dtype>
node<dtype>* node<dtype>::getleft() {
	return left;
}

template <class dtype>
dtype node<dtype>::getdata() {
	return data;
}

template <class dtype>
node<dtype>* node<dtype>::getright() {
	return right;
}

template <class dtype>
node<dtype>::node(dtype d, node<dtype>* x, node<dtype>* y):data(d),left(x),right(y) {
}