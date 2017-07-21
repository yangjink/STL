#pragma once

template<class K,class T>
struct BSTreeNode
{
	BSTreeNode* _left;
	BSTreeNode* _right;

	K _key;
	T _value;
	int count = 1;//³öÏÖ´ÎÊý

	BSTreeNode(const K& key, const T& value)
		:_key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class K,class T>
class BSTree
{
	typedef BSTreeNode<K, T> Node;
public:
	BSTree()
		:_root(NULL)
	{}
	BSTree(const K* a,size_t size)
	{
		Insert(a[0], "");
		size = size - 1;
		while (size)
		{
			if (Insert(a[size], "") == false)
			{
				Find(a[size])->count++;
			}
			
			size--;
		}
		
	}
	bool Insert(const K& key,const T& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key,value);
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
				//count++;
				return false;
			}
		}
		if (parent->_key > key)
		{
			parent->_left = new Node(key,value);
		}
		if (parent->_key < key)
		{
			parent->_right = new Node(key, value);
		}
		return true;
	}
	bool InsertR(const K& key,const T& value)
	{
		return _InsertR(_root, key,value);
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
		cout << root->_value << "     ";
		_Inorder(root->_right);
	}
	bool _InsertR(Node*& root, const K& key,const T& value)
	{
		if (root == NULL)
		{
			root = new Node(key,value);
			return true;
		}
		if (root->_key > key)
		{
			return _InsertR(root->_left, key,value);
		}
		else if (root->_key < key)
		{
			return _InsertR(root->_right, key,value);
		}
		else
		{
			return false;
		}
	}
	bool _RemoveR(Node*& root, const K& key)
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
	BSTree<string, string> dict;
	dict.Insert("sort","ÅÅÐò");
	dict.Insert("tree","Ê÷");
	dict.Insert("string","×Ö·û´®");
	dict.Insert("sss","xxx");
	dict.Inorder();

	BSTreeNode<string, string>* ret = dict.Find("sort");
	cout << ret->_value << endl;

	ret = dict.Find("string");
	ret->_value = "×Õ×Õ×Õ";

	dict.Inorder();
	string file[] = { "string", "string", "aaa", "bbb","string" };
	BSTree<string,string> s(file, 5);
}