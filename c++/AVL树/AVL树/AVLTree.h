#pragma once 



template <class K>
struct AVLTreeNode
{
	K _key;
	int _bf;//平衡因子
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;

	AVLTreeNode(const K& key)
		:_key(key)
		, _bf(0)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
};

template <class K>
class AVLTree
{
	typedef AVLTreeNode<K> Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		
		if (parent->_key > key)
		{
			parent->_left = cur;
			cur->_parent = parent;

			while (parent)
			{
				if (cur == parent->_left)

				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}
				if (parent->_bf == 0)
					break;
				if (parent->_bf == -2)
				{
					_RotateR(parent);
					return true;
				}
				else if (parent->_bf == 2)
				{
					_RotateL(parent);
					return true;
				}
				else
				{
					cur = parent;
					parent = cur->_parent;
				}
			}
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
			while (parent)
			{
				if (cur == parent->_left)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}
				if (parent->_bf == 0)
					break;
				Node* node;
				if (parent->_bf == -2)
				{
					node = parent->_left;
					if (node->_bf == -1)
					{
						_RotateR(parent);
						return true;

					}
					else
					{
						_RotateLR(parent);
						return true;

					}
					
				}
				else if (parent->_bf == 2)
				{
					node = parent->_right;
					if (node->_bf == 1)
					{
						_RotateL(parent);
						return true;

					}
					else
					{
						_RotateRL(parent);
						return true;
					}
				}
				else
				{
					cur = parent;
					parent = cur->_parent;
				}
				
			}
		}
	}
	int Hight(Node* root)
	{
		if (root == NULL)
			return 0;
		int l = Hight(root->_left);
		int r = Hight(root->_right);

		return l > r ? l++ : r++;
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	bool _IsBalance(Node* root)
	{
		if (root == NULL)
			return true;

		int l = Hight(root->_left);
		int r = Hight(root->_right);
		if ((r - l) != root->_bf)
		{
			cout << "平衡因子有问题" << root->_key <<root->_bf<< endl;
		}
		return abs(l - r) < 2 && _IsBalance(root->_left) &&_IsBalance(root->_right);
	}
	/*bool _IsBalance(Node*root)
	{
		if (root == NULL)
		{
			return true;
		}
		int left = Hight(root->_left);
		int right = Hight(root->_right);
		if ((right - left) != root->_bf)
		{
			cout << "平衡因子失常" << root->_key << endl;
		}
		return abs(right - left) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
	}*/
	//后序O(lgN)
	/*bool IsBalanceOr()
	{
		int hight = 1;
		return _IsBalanceOr(_root, hight);
	}
	bool _IsBalanceOr(Node*root, int &hight)
	{
		if (root == NULL)
		{
			hight = 0;
			return true;
		}
		int left, right;
		if (_IsBalanceOr(root->_left, left) && _IsBalanceOr(root->_right, right) && abs(right - left) < 2)
		{
			hight = left>right ? (left + 1) : (right + 1);
			return true;
		}
		return false;
	}*/
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
protected:
	void _Inorder(Node* root)
	{
		if (root == NULL)
			return;

		_Inorder(root->_left);
		cout << root->_key << " ";
		_Inorder(root->_right);
	}
	void _RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		
		Node* subRL = subR->_left;
		Node* ppNode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		if (ppNode == NULL)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			if (parent == ppNode->_left)
			{
				ppNode->_left = subR;
				subR->_parent = ppNode;
			}
			else
			{
				ppNode->_right = subR;
				subR->_parent = ppNode;
			}
		}
		subR->_bf = parent->_bf = 0;
	}
	void _RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		
		Node* subLR = subL->_right;
		Node* ppNode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (ppNode == NULL)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			if (parent == ppNode->_left)
			{
				ppNode->_left = subL;
				subL->_parent = ppNode;
			}
			else
			{
				ppNode->_right = subL;
				subL->_parent = ppNode;
			}
		}
		subL->_bf = parent->_bf = 0;
	}
	void _RotateRL(Node* parent)
	{
		_RotateR(parent->_right);
		_RotateL(parent);
	}
	void _RotateLR(Node* parent)
	{
		
		
		_RotateL(parent->_left);
		
		_RotateR(parent);
	}
protected:
	Node* _root;
};

void Test1()
{
	AVLTree<int> a1;
	a1.Insert(5);
	a1.Insert(3);
	a1.Insert(4);
	a1.Insert(1);
	a1.Insert(7);
	a1.Insert(8);
	a1.Insert(2);
	a1.Insert(6);
	a1.Insert(0);
	a1.Insert(9);
	//cout<<a1.IsBalanceOr();
	a1.Inorder();

	AVLTree<int> a2;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	a2.Insert(4);
	a2.Insert(2);
	a2.Insert(6);
	a2.Insert(1);
	a2.Insert(3);
	a2.Insert(5);
	a2.Insert(15);
	a2.Insert(7);
	a2.Insert(16);
	a2.Insert(14);

	a2.Inorder();
	cout<<a2.IsBalance()<<endl;
}