#include <iostream>
#include <string>
#include <stdio.h>
#include "btree.h"
using namespace std;


int main(char argc, int *argv[]) {

	/* Balanced Binary Search Tree */
									//INSERT
	btree<int> obj;
	int a[] = { 5,7,2,1,3,45,31,6,36,37,38,7 };
	node<int>* R =obj.getroot();
	for (int i = 0; i <= 11; i++) {
		R=obj.insert(a[i],R);
	}
	obj.setroot(R);
	node<int>* Q = obj.getroot();
	cout <<(Q)->getright()->getleft()->getright()->getdata()<<"\n"; //sweet.
	
								 //Tree Length
	cout << "Length of the tree is \n" << obj.treelength(Q)<<endl;//sweet

								 //Number of Nodes
	cout << "Number of Nodes in this tree are: " << obj.numnodes(R) << endl;//sweet

								//TRAVERSALS- Basic depth first searches
								//Postorder(2)/Preorder(1)/inorder(2)
	cout << "PreOrder-" << endl;
	obj.dfsTraverse(Q, 1);//Pre-order-sweet
	cout << endl << "InOrder-" << endl;
	obj.dfsTraverse(Q, 2);//Inorder-sweet
	cout << endl << "PostOrder-" << endl;
	obj.dfsTraverse(Q, 3);//postorder sweet

	/* Balanced BST */
								//BALANCE Factor 
	cout << endl <<"Balance Factor:"<< obj.balanceFactor(Q->getright()) << endl;
	
	btree<int> obj1;
	int b[] = { 5,7,2,1,3,45,31,6,36,37,38,7 };
	node<int>* Qb = obj1.getroot();
	/*for (int i = 0; i <= 11; i++) {
		Qb = obj1.insertBalanced(b[i],Qb);
	}
	/*							//Tree Length
	cout << "Length of the tree is \n" << obj1.treelength(Qb) << endl;//sweet

								//Number of Nodes
	cout << "Number of Nodes in this tree are: " << obj1.numnodes(Qb) << endl;//sweet
	cout << endl << "PreOrder-" << endl;
	obj1.dfsTraverse(Qb, 1);
	*/
																  
	cout << obj1.deltree(*&Qb);
	Qb = nullptr;
	
	cout << obj.deltree(*&Q);
	Q = nullptr;
	//sweet-note that R is also the root, thus will have same result as Q
								  //Root (still)no more has a fixed junk value/data.




	cout << "Press Enter to quit\n";
	cin.get();
	return 0;
}