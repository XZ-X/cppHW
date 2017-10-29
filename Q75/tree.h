#ifndef tree_h
#define tree_h

template <typename T>
struct treeNode{
	bool isLeft;
	T data;
	treeNode<T>* parent;
	treeNode<T>* lc=nullptr;
	treeNode<T>* rc=nullptr;
	treeNode<T>() = default;
	treeNode<T>(T a) : data(a){}
};
/* 
unfinished 
//TODO:
template <typename T>
class tree{
private:
	treeNode<T>* root;
	void initial(){
		root = new treeNode<T>;
		root->parent = root;
		root->lc = null;
		rott->rc = null;
	}
public:
	//constructor
	tree(){

	}
};
*/






#endif