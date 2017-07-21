#pragma once 

template <class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	T _data;
	BinaryTreeNode(const T& x = T())
		:_left(NULL)
		, _right(NULL)
		, _data(x)
	{}
};

template <class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;

public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T* a, size_t size, const T& invalid)
	{
		assert(a);
		size_t index = 0;
		_root = _SetUpTree( a, size,index,invalid);
	}
	
	BinaryTree(const BinaryTree<T>& t)
	{
		_root =  _Copy(t._root);
	}
	BinaryTree<T>& operator=( BinaryTree t)
	{
		swap(_root, t._root);
		return *this;
	}
	~BinaryTree()
	{
		_Destory(_root);
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
	}//递归
	void PrevOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (!s.empty() || cur)
		{
			while (cur)
			{
				cout << cur->_data << " ";
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			s.pop();

			cur = top->_right;
		}
		
	}
	void InOrder()
	{
		_InOrder(_root);
	}//递归
	void InOrderNonR()
	{
		stack <Node*> s;
		Node* cur = _root;
		while (cur ||  !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			cout << top->_data << " ";
			s.pop();

			cur = top->_right;
		}
	}
	void PostOrder()
	{
		_PostOrder(_root);
	}//递归
	void PostOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		Node* prev = NULL;

		while (!s.empty() && cur)
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			
		
			Node* top = s.top();
			if (top->_right == NULL || top->_right == prev)
			{
				cout << top->_data << " ";
				s.pop();
				prev = cur;
			}
			else
			{
				cur = top->_right;
			}
	    }
	}
	void LevelOrder()
	{
		if (_root == NULL)
		{
			return;
		}
		queue<Node*> q;
		q.push(_root);
		Node* tmp = _root;
		while (!q.empty())
		{
			tmp = q.front();
			q.pop();
			cout << tmp->_data << " ";
			if (tmp->_left != NULL)
			{
				q.push(tmp->_left);
			}
			if (tmp->_right != NULL)
			{
				q.push(tmp->_right);
			}
		}
		
	}
	size_t Size()
	{
		return _Size(_root);
	}
	size_t GetLeafSize()
	{
		return _GetLeafSize(_root);
	}
	size_t GetKLeafSize(size_t k)
	{
		assert(k > 0);
		return _GetKLeafSize(_root,k);
	}
	Node* Find(const T& x)
	{
		return _Find(_root, x);
	}

	//求二叉树中最远的两个节点的距离
	size_t MaxLength()
	{
		size_t maxLength = 0;
		if (_root == NULL)
			return 0;
		_MaxLength(_root,maxLength);
		return maxLength-2;//因为空节点也默认+1，所以距离的两个节点多加了2
	}
protected:
	
	size_t _MaxLength(Node* root,size_t& maxLength)
	{
		if (root == NULL)
			return 0;

		size_t leftLength = _MaxLength(root->_left, maxLength) + 1;
		size_t rightLength = _MaxLength(root->_right, maxLength) + 1;

		size_t maxtmp = leftLength + rightLength;
		if (maxtmp > maxLength)
		{
			maxLength = maxtmp;
		}

		return leftLength > rightLength ? leftLength : rightLength;
		
	}
	Node* _SetUpTree(const T* a, size_t size,size_t& index, const T& invalid)
	{
		Node* tmp = NULL;
		if (index < size && a[index] != invalid)
		{
			tmp = new Node(a[index]);
			tmp->_left = _SetUpTree(a, size, ++index, invalid);
			tmp->_right = _SetUpTree(a, size, ++index, invalid);
		}
		return tmp;
	}

	Node* _Copy(Node* root)
	{
		if (root == NULL)
			return NULL;
		Node* newroot = new Node(root->_data);
		newroot->_left = _Copy(root->_left);
		newroot->_right = _Copy(root->_right);

		return newroot;
	}
	void _Destory(Node* root)
	{
		if (root != NULL)
		{
			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
			root = NULL;
		}
	}
	void _PrevOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);

	}

	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}

	size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	size_t _GetLeafSize(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->_left == NULL && root->_right == NULL)
		{
			return 1;
		}
		return _GetLeafSize(root->_left) + _GetLeafSize(root->_right);
	}

	size_t _GetKLeafSize(Node* root, size_t k)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (k == 1)
		{
			return 1;
		}
		return _GetKLeafSize(root->_left, k - 1) + _GetKLeafSize(root->_right, k - 1);
	}

	Node* _Find(Node* root, const T& x)
	{
		if (root == NULL)
			return NULL;
		if (root->_data == x)
			return root;
		Node* left = _Find(root->_left, x);
		if (left)
			return left;
		Node* right = _Find(root->_right, x);
		if (right)

			return right;
		return NULL;
	}
	

protected:
	Node* _root;

};

void Test1()
{
	int array[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(array, sizeof(array) / sizeof(array[0]), '#');
	/*t1.PrevOrder();
	cout << endl;
	t1.PrevOrderNonR();
	cout << endl;
	t1.InOrder();
	cout << endl;
	t1.InOrderNonR();
	cout << endl;
	t1.PostOrder();
	cout << endl;
	t1.PostOrderNonR();
	cout << endl;
	t1.LevelOrder();
	cout << endl;*/
	/*cout << t1.Size() << endl;
	cout << t1.GetLeafSize() << endl;
	cout <<t1.GetKLeafSize(3) << endl;
	cout << t1.Find(2)->_data << endl;
	cout << t1.Find(7) << endl;
	cout << t1.Find(6)->_data << endl;*/
	BinaryTree<int> t2 = t1;
	t2.InOrder();
	cout << endl;

	BinaryTree<int> t3;
	t3 = t1;
	t3.InOrder();
}
void Test2()
{
	/*int array[8] = { 1, 2, 3, '#', '#', 4,'#','#'};
	BinaryTree<int> t1(array, sizeof(array) / sizeof(array[0]), '#');
	t1.InOrder();
	
	cout << t1.MaxLength() << endl;*/
	BinaryTree<int> t1;
	int a[1] = { 1 };
	BinaryTree<int> t2(a,sizeof(a)/sizeof(a[0]),'#');
	cout << t1.MaxLength() << endl;
	cout << t2.MaxLength() << endl;
	
}
int main()
{
	//Test1();
	Test2();
	return 0;
}