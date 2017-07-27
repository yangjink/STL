#pragma once

template<class K, size_t M = 3>
struct BTreeNode
{
	//K _keys[M-1];			  // 关键字 ->2
	K _keys[M];			  // 关键字 多给一个空间方便分裂的逻辑
	//BTreeNode<K, M>* subs[M]; // 孩纸->3
	BTreeNode<K, M>* _subs[M+1];
	BTreeNode<K, M>* _parent; // 父亲
	size_t _size;			  //实际key的个数

	BTreeNode()
	{
		memset(_subs, 0, sizeof(_subs));
		_parent = NULL;
		_size = 0;
	}
};

template<class K, size_t M = 3>
struct BTree
{
	typedef BTreeNode<K, M> Node;
public:
	BTree()
		:_root(NULL)
	{}

	pair<Node*, int> Find(const K& key)
	{
		Node* parent = NULL;
		Node* cur = _root;
		while (cur)
		{
			size_t i = 0;
			for (;i < cur->_size;)
			{
				if (cur->_keys[i] < key)
				{	
					++i;
				}
				else if (cur->_keys[i] > key)
				{
					break;
				}
				else
				{
					return make_pair(cur, i);
				}
			}

			parent = cur;
			cur = cur->_subs[i];
		}

		return make_pair(parent, -1);
	}

	bool Insert(const K& key)
	{
		if(_root == NULL)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_size = 1;
			return true;
		}

		pair<Node*, int> ret = Find(key);
		// key已经存在
		if (ret.second >= 0)
			return false;

		// 插入关键字
		Node* cur = ret.first;
		Node* sub = NULL;
		K newKey = key;
		while (1) // 在cur节点里面插入一个key，插入一个孩纸
		{
			InsertKey(cur, newKey, sub);
			// 关键字的数量满足，则返回
			if (cur->_size < M)
				return true;

			// 不满规则--分裂
			Node* newNode = new Node;
			size_t mid = M/2;
			size_t index = 0;
			size_t i = mid+1;
			for (;i < cur->_size; ++i)
			{
				newNode->_keys[index] = cur->_keys[i];
				newNode->_subs[index] = cur->_subs[i];
				if (cur->_subs[i])
					cur->_subs[i]->_parent = newNode;

				++index;
				newNode->_size++;
			}
			newNode->_subs[index] = cur->_subs[i];
			if (cur->_subs[i])
				cur->_subs[i]->_parent = newNode;

			cur->_size = cur->_size - newNode->_size-1;

			// cur 就是根
			if (cur->_parent == NULL)
			{
				_root = new Node;
				_root->_keys[0] = cur->_keys[mid];
				_root->_subs[0] = cur;
				cur->_parent = _root;
				_root->_subs[1] = newNode;
				newNode->_parent = _root;
				_root->_size = 1;
				return true;
			}
			else
			{
				// 在父节点里面插入分裂以后mid和newNode
				newKey = cur->_keys[mid];
				cur = cur->_parent;
				sub = newNode;
			}
		}
	}

	void InsertKey(Node* cur, const K& key, Node* sub)
	{
		assert(cur);

		int end = cur->_size-1;
		for (; end >= 0; --end)
		{
			if (cur->_keys[end] < key)
			{
				break;
			}
			else
			{
				cur->_keys[end+1] = cur->_keys[end];
				// 右边孩纸挪走
				cur->_subs[end+2] = cur->_subs[end+1];
			}
		}

		cur->_keys[end+1] = key;
		cur->_subs[end+2] = sub;
		if (sub)
			sub->_parent = cur;

		cur->_size++;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		size_t i = 0;
		for (; i < root->_size; ++i)
		{
			_InOrder(root->_subs[i]);
			cout<<root->_keys[i]<<" ";
		}

		_InOrder(root->_subs[i]);
	}

protected:
	Node* _root;
};

// M 多叉搜索树
void TestBTree()
{
	int a[] = {53, 75, 139, 49, 145, 36, 101};
	BTree<int> t1;
	for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
	{
		t1.Insert(a[i]);
	}

	t1.InOrder();
}

template<class K, size_t M>
struct BPTreeNodeNonLeaf
{
	K _keys[M];
	void* subs[M];
	size_t _size;
	BPTreeNodeNonLeaf<K,M>* _parent;
};

template<class K, class V, size_t M>
struct  BPTreeNodeLeaf
{
	pair<K, V> _kvs[M];
	size_t _size;
	BPTreeNodeNonLeaf<K,M>* _parent;
};

template<class K, V, size_t M>
class BPTree
{
protected:
	BPTreeNodeNonLeaf<K, M>* _root;
	BPTreeNodeLeaf<K, V, M>* _head;
};