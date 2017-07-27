#pragma once

template<class K, size_t M = 3>
struct BTreeNode
{
	//K _keys[M-1];			  // �ؼ��� ->2
	K _keys[M];			  // �ؼ��� ���һ���ռ䷽����ѵ��߼�
	//BTreeNode<K, M>* subs[M]; // ��ֽ->3
	BTreeNode<K, M>* _subs[M+1];
	BTreeNode<K, M>* _parent; // ����
	size_t _size;			  //ʵ��key�ĸ���

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
		// key�Ѿ�����
		if (ret.second >= 0)
			return false;

		// ����ؼ���
		Node* cur = ret.first;
		Node* sub = NULL;
		K newKey = key;
		while (1) // ��cur�ڵ��������һ��key������һ����ֽ
		{
			InsertKey(cur, newKey, sub);
			// �ؼ��ֵ��������㣬�򷵻�
			if (cur->_size < M)
				return true;

			// ��������--����
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

			// cur ���Ǹ�
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
				// �ڸ��ڵ������������Ժ�mid��newNode
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
				// �ұߺ�ֽŲ��
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

// M ���������
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