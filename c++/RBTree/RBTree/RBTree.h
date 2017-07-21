#pragma once

enum Color
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{

	K _key;
	V _value;
	Color _color;

	RBTreeNode<K,V>* _left;
	RBTreeNode<K,V>* _right;
	RBTreeNode<K,V>* _parent;

	RBTreeNode(const K& key,const V& value)
		: _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _color(RED)
		, _key(key)
		, _value(value)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}

	V& operator[](const K& key)
	{
		pair<Node*, bool> ret = Insert(key, V());
		return (ret.first)->_value;
	}
	//非递归
	pair<Node*, bool> Insert(const K& key, const V& value)
	{
		//1.树为空
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_color = BLACK;
			return make_pair(_root,true);
		}

		Node* parent = NULL;
		Node* cur = _root;
		while (1)
		{
			if (cur == NULL)
			{
				cur = new Node(key, value);
				cur->_parent = parent;
				if (cur->_key > parent->_key)
				{
					parent->_right = cur;
				}
				else
				{
					parent->_left = cur;
				}
					
				Node* gparent = parent->_parent;
				Node* uncle = NULL;

				while (parent)
				{
					if (parent->_color == BLACK)
					{
						break;
					}
					else
					{
						if (parent == gparent->_left)
						{
							uncle = gparent->_right;
							if (uncle && uncle->_color == RED)//3.插入节点的uncle存在且为红
							{
								uncle->_color = BLACK;
								parent->_color = BLACK;
								gparent->_color = RED;

								cur = gparent;
								parent = cur->_parent;
							}
							else
							{

								if (cur == parent->_right)//4-5.插入节点的uncle不存在或者为黑
								{
									RotateL(parent);
									swap(cur, parent);
								}
								parent->_color = BLACK;
								gparent->_color = RED;
								RotateR(gparent);


								break;
							}
						}
						else
						{
							uncle = gparent->_left;
							if (uncle && uncle->_color == RED)//3.插入节点的uncle存在且为红
							{
								uncle->_color = BLACK;
								parent->_color = BLACK;
								gparent->_color = RED;

								cur = gparent;
								parent = cur->_parent;
							}
							else
							{

								if (cur == parent->_left)//4-5.插入节点的uncle不存在或者为黑
								{
									RotateR(parent);
									swap(cur, parent);
								}
								parent->_color = BLACK;
								gparent->_color = RED;
								RotateL(gparent);

								break;
							}
						}
					}
				}
				_root->_color = BLACK;
				return  make_pair(_root, true);
			}
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if(cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return  make_pair(_root, false);
			}
		}



		_root->_color = BLACK;

	}
	//递归
	bool InsertR(const K& key, const V& value)
	{
		//1.树为空
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_color = BLACK;
			return true;
		}
		Node* parent =  _root;
		bool judge = _Insert(_root, key, value, parent);
		_root->_color = BLACK;
		return judge;
	}
	bool Balance()
	{
		if (_root == NULL)
			return true;

		if (_root->_color == RED)
			return false;

		int countBlack = 0;
		Node* left = _root;
		while (left)
		{
			if (left->_color == BLACK)
				countBlack++;

			left = left->_left;
		}

		int num = 0;
		return _Balance(_root, countBlack, num);
	}
protected:
	bool _Insert(Node*& root,const K& key,const  V& value,Node*& parent)
	{
		//2.插入节点的父节点为黑不用调整
		if (root == NULL)
		{
			root = new Node(key, value);
			root->_parent = parent;
			
			Node* gparent = parent->_parent;
			Node* uncle = NULL;
			Node* cur = root;//递归的时候循环会改变其值
			while (parent)
			{
				if (parent->_color == BLACK)
				{
					break;
				}
				else
				{
					if (parent == gparent->_left)
					{
						uncle = gparent->_right;
						if (uncle && uncle->_color == RED)//3.插入节点的uncle存在且为红
						{
							uncle->_color = BLACK;
							parent->_color = BLACK;
							gparent->_color = RED;
							
							cur = gparent;
							parent = cur->_parent;
						}
						else
						{
							

							if (root == parent->_right)//4-5.插入节点的uncle不存在或者为黑
							{
								RotateL(parent);
							}
							parent->_color = BLACK;
							gparent->_color = RED;
							RotateR(gparent);

							
							break;
						}
					}
					else
					{
						uncle = gparent->_left;
						if (uncle && uncle->_color == RED)//3.插入节点的uncle存在且为红
						{
							uncle->_color = BLACK;
							parent->_color = BLACK;
							gparent->_color = RED;

							cur = gparent;
							parent = cur->_parent;
						}
						else
						{
							
							if (root == parent->_left)//4-5.插入节点的uncle不存在或者为黑
							{
								RotateR(parent);
							}
							parent->_color = BLACK;
							gparent->_color = RED;
							RotateL(gparent);
							
							break;
						}
					}
				}
			}
			_root->_color = BLACK;
			return true;
		}

		if (root->_key > key)
		{
			return _Insert(root->_left, key, value,root);
		}
		else
		{
			return _Insert(root->_right, key, value,root);
		}
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* ppNode = parent->_parent;
		
		subR->_left = parent;
		parent->_parent = subR;
		subR->_parent = ppNode;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		if (ppNode)
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
				return;
			}
			else
			{
				ppNode->_right = subR;
				return;
			}
		}
		_root = subR;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		Node* ppNode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;
		subL->_parent = ppNode;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (ppNode)
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
				return;
			}
			else
			{
				ppNode->_right = subL;
				return;
			}
		}
		_root = subL;
	}
	bool _Balance(Node* root,int countBLACK,int num)
	{
		if (root == NULL)
		{
			if (num == countBLACK)
			{
				return true;
			}
			else
			{
				cout << "黑色节点不相同" << num;
				return false;
			}
		}
		Node* parent = root->_parent;

		if (parent && root->_color == RED)
		{
			if (parent->_color == RED)
			{
				cout << "有连续的红节点" << root->_key << endl;
				return false;
			}
		}

		if (root->_color == BLACK)
			num++;

		return _Balance(root->_left,countBLACK,num)
			&&_Balance(root->_right,countBLACK,num);
	}
protected:
	Node* _root;
};
void Test1()
{
	RBTree<int, int> t1;
	t1.Insert(5,0);
	t1.Insert(3,0);
	t1.Insert(4,0);
	t1.Insert(1,0);
	t1.Insert(7,0);
	t1.Insert(8,0);
	t1.Insert(2,0);
	t1.Insert(6,0);
	t1.Insert(0,0);
	t1.Insert(9,0);

	cout<<t1.Balance()<<endl;

	RBTree<string, string> dict;
	dict["插入"];
	dict["插入"] = "Insert";
}