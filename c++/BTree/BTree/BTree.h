#pragma once 

#include <iostream>
#include <assert.h>
using namespace std;


template <class K, size_t M = 3>
struct BTreeNode
{
	K _key[M];
	BTreeNode<K,M>* _sub[M + 1];
	BTreeNode<K,M>* _parent;
	size_t _size;

	BTreeNode()
		:_parent(NULL)
		,_size(0)
	{
		memset(_sub, 0, sizeof(_sub));
	}
};

template<class K,size_t M=3>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	BTree()
		:_root(NULL)
	{}

	pair<Node*,int> Find(const K& key)
	{
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			size_t i = 0;
			for (; i < cur->_size; )
			{
				if (cur->_key[i] < key)
				{
					++i;
				}
				else if (cur->_key[i] > key)
				{
					break;
				}
				else
				{
					return make_pair(cur,i);
				}
			}
			parent = cur;
			cur = cur->_sub[i];
		}
		return make_pair(parent, -1);
	}
	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node;
			_root->_key[0] = key;
			/*_root->_sub[0] = NULL;
			_root->_sub[1] = NULL;*/
			_root->_size = 1;
			return true;
		}

		pair<Node*, int> ret = Find(key);
		if (ret.second >= 0)
		{
			//已经存在
			return false;
		}
		
		Node* cur = ret.first;
		Node* sub = NULL;
		K newkey = key;
		while (1)
		{
			InsertKey(cur, newkey,sub);
			
			if (cur->_size >= M)//分裂
			{
				Node* newNode = new Node;
				Node* parent = cur->_parent;
				int middle = M >> 1;
				size_t i = middle;
				newNode->_sub[0] = cur->_sub[middle + 1];
				for (; i < cur->_size -1; i++)
				{
					sub = cur->_sub[i + 2];
					InsertKey(newNode, cur->_key[i + 1],sub);
					cur->_size--;
				}
				

				if (cur->_parent == NULL)
				{
					_root = new Node;
					_root->_key[0] = cur->_key[middle];
					_root->_size++;

					cur->_size--;

					_root->_sub[0] = cur;
					cur->_parent = _root;
					_root->_sub[1] = newNode;
					newNode->_parent = _root;

					return true;
				}
				sub = newNode;
				newkey = cur->_key[middle];
				cur->_size--;
				cur = cur->_parent;
				
			}
			else
			{
				return true;;
			}

			
		}
	}
	void Inorder()
	{
		_Inorder(_root);
	}
protected:
	void _Inorder(Node* root)
	{
		if (root == NULL)
			return;

		size_t i = 0;

		for (; i < root->_size; i++)
		{
			_Inorder(root->_sub[i]);
			cout << root->_key[i] << "  ";
		}

		_Inorder(root->_sub[i]);
		
	}
	void InsertKey(Node* cur ,const K& key,Node* sub)
	{
		assert(cur);
		int end = cur->_size - 1;

		for (; end >= 0; --end)
		{
			if (cur->_key[end] < key)
			{
				break;
			}
			else
			{
				cur->_key[end + 1] = cur->_key[end];
				cur->_sub[end + 2] = cur->_sub[end + 1];
			}
		}

		cur->_key[end + 1] = key;
		cur->_sub[end + 2] = sub;
		cur->_size++;
	}
protected:
	Node* _root;
};

int main()
{
	int a[] = { 53, 75, 139, 49, 145, 36, 101 };
	BTree<int> t1;

	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		t1.Insert(a[i]);
	}

	/*t1.Insert(1);
	t1.Insert(2);
	t1.Insert(3);
	t1.Insert(4);
	t1.Insert(5);*/
	t1.Inorder();
}