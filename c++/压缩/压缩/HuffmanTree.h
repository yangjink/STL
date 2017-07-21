#pragma once


template <class T>
struct HuffmanTreeNode
{
	T _w;
	HuffmanTreeNode* _left;
	HuffmanTreeNode* _right;
	HuffmanTreeNode* _parent;

	HuffmanTreeNode(const T& x)
		:_w(x)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
	
};

template <class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;

public:
	HuffmanTree()
		:_root(NULL)
	{
	}
	HuffmanTree(T* a, size_t n,const T& invalid)
	{
		Heap<Node*> minHeap;
		for (size_t i = 0; i < n; i++)
		{
			if (a[i] != invalid)
				minHeap.Push(new Node(a[i]));
		}
		while (minHeap.Size() > 1)
		{
			Node* left = minHeap.Top();
			minHeap.Pop();
			Node* right = minHeap.Top();
			minHeap.Pop();

			Node* parent = new Node(left->_w + right->_w);
			parent->_left = left;
			left->_parent = parent;
			parent->_right = right;
			right->_parent = parent;

			minHeap.Push(parent);
		}
		_root = minHeap.Top();
	}
	~HuffmanTree()
	{
		_Destory(_root);
	}
	
	Node* Root()
	{
		return _root;
	}
protected:
	void _Destory(Node* root)
	{
		if (root == NULL)
			return;

		_Destory(root->_left);
		_Destory(root->_right);

		delete root;
	}
	HuffmanTree(const HuffmanTree<T>&);//·À¿½±´
	HuffmanTree& operator=(const HuffmanTree<T>&);
protected:
	Node* _root;
};