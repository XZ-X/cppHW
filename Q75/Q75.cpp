#include<iostream>
#include"xxzString.h"
#include"list.h"
#include"tree.h"
using namespace std;
bool isFirst = true;
void midOrder(treeNode<xxzString>* root){
	if (root->lc){
		midOrder(root->lc);
	}
	if (isFirst){
		cout << root->data;
		isFirst = false;
	}else{
		cout << " " << root->data;
	}
	if (root->rc){
		midOrder(root->rc);
	}
}

inline bool finish(){
	return cin.peek() == '\n';
}
#include<fstream>
int main(){
	ofstream s("file1");
	xxzString st;
	while (!finish()&&cin >> st){
		s << st;
	}
}

/*
int main(){
	xxzString str;
	treeNode<xxzString> root;
	list<treeNode<xxzString>> toAdd1,toAdd2;
	toAdd1.push(root);
	cin >> str;
	root.data = str;
	while (!cin.eof()&&!finish()){
		while (!toAdd1.empty()){
			if (!toAdd1.getFirst().lc&&!cin.eof()&&!finish()){
				cin >> str;
				auto tmp=new treeNode<xxzString>(str);
				tmp->parent = &toAdd1.getFirst();
				toAdd1.getFirst().lc = tmp;
				toAdd2.push(*tmp);
			}else if (!toAdd1.getFirst().rc){
				cin >> str;
				auto tmp = new treeNode<xxzString>(str);
				tmp->parent = &toAdd1.getFirst();
				toAdd1.getFirst().rc = tmp;
				toAdd2.push(*tmp);
			}
			else{
				toAdd1.dequeue();
			}
		}
		while (!toAdd2.empty()&&!cin.eof()&&!finish()){
			if (!toAdd2.getFirst().lc){
				cin >> str;
				auto tmp = new treeNode<xxzString>(str);
				tmp->parent = &toAdd2.getFirst();
				toAdd2.getFirst().lc = tmp;
				toAdd1.push(*tmp);
			}
			else if (!toAdd2.getFirst().rc){
				cin >> str;
				auto tmp = new treeNode<xxzString>(str);
				tmp->parent = &toAdd2.getFirst();
				toAdd2.getFirst().rc = tmp;
				toAdd1.push(*tmp);
			}
			else{
				toAdd2.dequeue();
			}
		}

	}
	
	midOrder(&root);


	return 0;
}
*/