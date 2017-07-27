#pragma once

template<class K>
struct BinarySearchTreeNode
{
	BinarySearchTreeNode* _left;
	BinarySearchTreeNode* _right;

	K _key;

	BinarySearchTreeNode(const K& key)
		:_key(key)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class K>
class BinarySearchTree
{
	typedef BinarySearchTreeNode<K> Node;
public:
	BinarySearchTree()
		:_root(NULL)
	{}
	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node(key);
			return NULL;
		}
		Node* parent = NULL;
		Node* cur = _root;
		
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
		if (parent->_key > key)
		{
			parent->_left = new Node(key);
		}
		if (parent->_key < key)
		{
			parent->_right = new Node(key);
		}
		return true;
	}
	bool InsertR(const K& key)
	{
		return _InsertR( _root, key);
	}
	bool Remove(const K& key)
	{
		if (_root == NULL)
			return false;
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
				Node* del = cur;
				if (cur->_left == NULL && parent != NULL)
				{
					
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
				else if (cur->_right == NULL && parent != NULL)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
				else
				{
					if (cur->_right == NULL)
					{
						_root = cur->_left;
						delete cur;
						return true;
					}
					Node* subRight = cur->_right;
					Node* parent = cur;
					while (subRight->_left != NULL)
					{
						parent = subRight;
						subRight = subRight->_left;
					}
					swap(cur->_key, subRight->_key);

					if (parent->_left == subRight)
					{
						parent->_left = subRight->_right;
					}
					else
					{
						parent->_right = subRight->_right;
					}
					del = subRight;
				}
				delete del;
				return true;
			}
		}
		return false;
	}
	bool RemoveR(const K& key)
	{
		return _RemoveR(_root, key);
	}
	Node*  Find(const K& key)
	{
		
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return NULL;
	}
	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}
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
	bool _InsertR(Node*& root,const K& key)
	{
		if (root == NULL)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key > key)
		{
			return _InsertR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else
		{
			return false;
		}
	}
	bool _RemoveR(Node*& root,const K& key)
	{
		if (root == NULL)
			return false;
		if (root->_key > key)
		{
			return _RemoveR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _RemoveR(root->_right, key);
		}
		else
		{
			Node* del = root;
			if (root->_left == NULL)
			{
				root = root->_right;
			}
			else if (root->_right = NULL)
			{
				root = root->_left;
			}
			else
			{
				
				Node* cur = root;
				Node* subRight = root->_right;
				while (subRight->_left != NULL)
				{
					root = subRight;
					subRight = subRight->_left;
				}
				swap(cur->_key, subRight->_key);
				return _RemoveR(root, key);
			}
		}
		return false;
	}
	Node* _FindR(Node* root, const K& key)
	{
		if (root == NULL)
			return NULL;
		if (root->_key > key)
		{
			return _FindR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else
		{
			return root;
		}
	}
protected:
	Node* _root;
};


void Test1()
{
	BinarySearchTree<int> t1;
	t1.Insert(6);
	t1.Insert(4);
	t1.Insert(3);
	t1.Insert(3);
	t1.Insert(2);
	t1.Insert(9);
	t1.Insert(8);
	t1.Insert(7);
	t1.Insert(5);
	t1.Insert(1);
	t1.InsertR(22);
	t1.Inorder();
	cout << t1.FindR(22)->_key << endl;
	t1.Remove(1);
	t1.Remove(4);

	t1.RemoveR(1);
	t1.RemoveR(2);
	t1.RemoveR(3);
	t1.RemoveR(4);
	t1.RemoveR(5);
	t1.RemoveR(6);
	t1.RemoveR(7);
	t1.RemoveR(8);
	t1.RemoveR(9);
	t1.RemoveR(22);
	t1.Inorder();
}