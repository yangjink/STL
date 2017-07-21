#pragma once 


template <class T>
struct treeNode
{
	T _data;
	treeNode<T>* _left;
	treeNode<T>* _right;

};


template <class T>
class tree
{
	typedef treeNode<T> Node;

public:
	tree()
		:_root(NULL)
	{
	}

protected:
	Node* _root;
};