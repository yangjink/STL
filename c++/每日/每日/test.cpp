#include <iostream>
#include <assert.h>
#include <stack>
#include <stdlib.h>
#include <map>
#include <vector>
using namespace std;
bool isValid(string s) {//判断括号匹配
	if (s.length() == 0)
	{
		return true;
	}

	//0() 1{} 2[]
	int count = 0;
	int size = s.size();
	stack<int> stack;
	while (count < size)
	{
		if (s[count] == '(')
		{
			stack.push(0);
		}
		if (s[count] == ')')
		{
			if (!stack.empty() && stack.top() == 0)
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}
		if (s[count] == '{')
		{
			stack.push(1);
		}
		if (s[count] == '}')
		{
			if (!stack.empty() && stack.top() == 1)
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}
		if (s[count] == '[')
		{
			stack.push(2);
		}
		if (s[count] == ']')
		{
			if ( !stack.empty() && stack.top() == 2)
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}
		++count;
	}
	if (!stack.empty())
	{
		return false;
	}
	return true;
}
string longestCommonPrefix(vector<string>& strs) {//最长字符串前缀
	if (strs.empty())
	{
		return string();
	}
	if (strs[0].empty())
	{
		return strs[0];
	}
	int i = 1;
	int size = strs.size();
	if (size == 1)
	{
		return strs[0];
	}
	int j = 0;
	int sizestr = 0;
	string s(strs[0]);
	for (; i<size; ++i)
	{
		if (strs[i].empty())
		{
			return strs[i];
		}
		sizestr = strs[i].size();
		for (j = 0; j <= sizestr; ++j)
		{
			if (s[j] != strs[i][j])
			{
				s.erase(s.begin() + j, s.end());
				break;
			}

		}
	}
	return s;
}
int main()
{
	vector<string> v;
	string s1("aa");
	string s2("a");
	string s;
	v.push_back(s1);
	v.push_back(s2);
	s = longestCommonPrefix(v);
	string s3("]");
	isValid(s3);
	return 0;
}

//选择排序
//#include <iostream>
//#include <assert.h>
//#include <stack>
//#include <stdlib.h>
//#include <map>
//using namespace std;
//void PrintArray(int* a, int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}
////void SelectionSort(int *a,size_t n)
////{
////	if (a == NULL)
////	{
////		return;
////	}
////	int max = 0;
////	int min = 0;
////	size_t left = 0;
////	size_t right = n-1;
////	int i = 0;
////	while (left < right)
////	{
////		max = right;
////		min = left;
////		for (i = left; i <= right; ++i)
////		{
////			if (a[i] >= a[max])
////			{
////				max = i;
////			}
////			if (a[i] <= a[min])
////			{
////				min = i;
////			}
////		}
////		swap(a[left], a[min]);
////		if (max == left)
////		{
////			max = min;
////		}
////		swap(a[right], a[max]);
////		++left;
////		--right;
////		PrintArray(a, n);
////	}
////
////
////}
////void Adjust(int *a,size_t n,size_t root)
////{
////	size_t parent = root;
////	size_t child = parent * 2 + 1;
////	while (child < n)
////	{
////		if (child + 1 < n && a[child + 1] > a[child])
////		{
////			++child;
////		}
////		if (a[parent] < a[child])
////		{
////			swap(a[parent], a[child]);
////			parent = child;
////			child = parent * 2 + 1;
////		}
////		else
////		{
////			break;
////		}
////	}
////}
////void HeapSort(int *a, size_t n)//堆排序
////{
////	if (a == NULL)
////		return;
////	for (int i = (n >> 1) - 1; i >= 0; --i)
////	{
////		Adjust(a,n,i);
////	}
////	
////	for (int i = n - 1; i >= 1; --i)
////	{
////		swap(a[0], a[i]);
////		PrintArray(a, n);
////		Adjust(a, i, 0);
////	}
////
////}
////void TestSelectSort()
////{
////	int a[] = { 9, 5, 4, 0, 3, 6, 8, 7, 1, 2,9,0 };
////	SelectionSort(a, sizeof(a) / sizeof(a[0]));
////	PrintArray(a, sizeof(a) / sizeof(a[0]));
////}
////void TestHeapSort()
////{
////	int a[] = { 9, 5, 4, 0, 3, 6, 8, 7, 1, 2,0,9};
////	HeapSort(a, sizeof(a) / sizeof(a[0]));
////	PrintArray(a, sizeof(a) / sizeof(a[0]));
////}
////快排挖坑法
//int Partition(int *a,int left,int right)
//{
//	assert(a);
//	assert(left < right);
//	int index = a[right];
//	while (left < right)
//	{
//		while (left < right && a[left] <= index)
//		{
//			++left;
//		}
//		a[right] = a[left];
//		while (left < right && a[right] >= index)
//		{
//			right--;
//		}
//		a[left] = a[right];
//	}
//	a[left] = index;
//	return left;
//}
//
//void QuickSortR(int *a, int left,int right)//[]
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int div = Partition(a,left,right);
//	QuickSortR(a, left, div - 1);
//	QuickSortR(a, div + 1, right);
//}
//void QuickSort(int *a, int n)//[]
//{
//	assert(a);
//	if (n == 1 || n == 0)
//	{
//		return;
//	}
//	stack<int> s;
//	s.push(0);
//	s.push(n - 1);
//	int left = 0;
//	int right = n - 1;
//	while (!s.empty())
//	{
//		right = s.top();
//		s.pop();
//		left = s.top();
//		s.pop();
//		int div = Partition(a,left,right);
//
//		if (div-1 > left)
//		{
//			s.push(left);
//			s.push(div - 1);
//		}
//		if (div+1 < right)
//		{
//			s.push(div+1);
//			s.push(right);
//		}
//	}
//}
////冒泡排序
//void BubbleSort(int *a, int n)
//{
//	int i = 0;
//	int j = 0;
//	int tab = 1;
//	for (i = 0; i < n && tab; i++)
//	{
//		tab = 0;
//		for (j = 0; j < n - i-1; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				swap(a[j], a[j + 1]);
//				tab = 1;
//			}
//		}
//	}
//}
//void TestBubbleSort()
//{
//	int a[] = { 9, 5, 4, 0, 3, 6, 8, 7, 1, 2,0,9};
//	BubbleSort(a, sizeof(a) / sizeof(a[0]));
//	PrintArray(a, sizeof(a) / sizeof(a[0]));
//}
//void TestQuickSort()
//{
//	int a[] = { 9, 5, 4, 0, 3, 6, 8, 7, 1, 2, 0, 9 };
//	QuickSort(a, sizeof(a) / sizeof(a[0])-1);
//	PrintArray(a, sizeof(a) / sizeof(a[0]));
//}
//int main()
//{
//	//TestSelectSort();
//	//TestHeapSort();
//	//TestBubbleSort();
//	//TestQuickSort();2147483648
//	int a = 9646324351;
//	char buff[11];
//	_itoa_s(a,buff,10);
//	printf("%s",buff);
//	map<char, int> m;
//	//Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
//	m.insert(make_pair('I', 1));
//	m.insert(make_pair('X', 10));
//	m.insert(make_pair('C', 100));
//	m.insert(make_pair('M', 1000));
//	m.insert(make_pair('V', 5));
//	m.insert(make_pair('L', 50));
//	m.insert(make_pair('D', 500));
//	string s("123");
//	
//	int value = m[s[0]];
//}


//前序和中序确立二叉树
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//		val(x), left(NULL), right(NULL) {
//	}
//};
////int findNum(int num,vector<int>& v)
////{
////	int i = 0;
////	while (!v.empty())
////	{
////		if (v[i] != num)
////		{
////			++i;
////		}
////		else
////		{
////			break;
////		}
////	}
////	return i;
////}
////TreeNode* produce(vector<int>& pre, vector<int>& vin,int p,int vlength,int v,int plength)
////{
////	TreeNode* root = new TreeNode(pre[p++]);
////	if (p >= plength)
////	{
////		return root;
////	}
////	int vpre = findNum(pre[p], vin);
////	int v = 0;
////	int mid = vpre;
////	TreeNode* cur = root;
////	while (p < pre.size())
////	{
////		v = findNum(pre[p], vin);
////		if (v > vpre)
////		{
////			cur->right = new TreeNode(pre[p++]);
////			vpre = v;
////			cur = cur->right;
////		}
////		else
////		{
////			cur->left = new TreeNode(pre[p++]);
////			cur = cur->left;
////			vpre = v;
////		}
////	}
////	return root;
////}
////}
////TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
////	TreeNode* root = new TreeNode(pre[0]);
////	int p = 1;
////	int vpre = findNum(pre[0],vin);
////	int v = 0;
////	int mid = vpre;
////	TreeNode* cur = root;
////	while (p < pre.size())
////	{
////		v = findNum(pre[p],vin);
////		if (v > mid && vpre <= mid)
////		{
////			cur = root;
////		}
////		if (v > vpre)
////		{
////			cur->right = new TreeNode(pre[p++]);
////			vpre = v;
////			cur = cur->right;
////		}
////		else
////		{
////			cur->left = new TreeNode(pre[p++]);
////			cur = cur->left;
////			vpre = v;
////		}
////	}
////	return root;
////}
//////公共祖先
////
////
////
////bool creatPath(TreeNode* Node, TreeNode* root,stack<TreeNode*>& v)
////{
////	if (root == Node)
////	{
////		v.push(root);
////		return true;
////	}
////	v.push(root);
////	bool found = false;
////	if (root->left != NULL)
////		found = creatPath(Node,root->left,v);
////	if (!found && root->right != NULL)
////		found = creatPath(Node,root->right,v);
////	if (!found)
////		v.pop();
////	return found;
////}
////TreeNode* Ancestor(TreeNode* Node1, TreeNode* Node2, TreeNode* root)
////{
////	stack<TreeNode*> v1;
////	stack<TreeNode*> v2;
////	creatPath(Node1, root, v1);
////	creatPath(Node2, root, v2);
////	while (1)
////	{
////		if (v1.size() > v2.size())
////		{
////			v1.pop();
////		}
////		else if (v1.size() < v2.size())
////		{
////			v2.pop();
////		}
////		else
////		{
////			if (v1.top() == v2.top())
////			{
////				return v1.top();
////			}
////			else
////			{
////				v1.pop();
////				v2.pop();
////			}
////		}
////	}
////    return NULL;
////}
//void Inorder(TreeNode* root,TreeNode*& prev)
//{
//	if (root == NULL)
//		return;
//	
//	Inorder(root->left,prev);
//	if (prev != NULL)
//	{
//		prev->right = root;
//	}
//	root->left = prev;
//	prev = root;
//	Inorder(root->right,prev);
//	
//}
//TreeNode* Convert(TreeNode* pRootOfTree)
//{
//	TreeNode* prev = NULL;
//	TreeNode* cur = pRootOfTree;
//	while (cur->left != NULL)
//	{
//		cur = cur->left;
//	}
//	Inorder(pRootOfTree, prev);
//	return cur;
//}
//int main()
//{
//	TreeNode* cur = new TreeNode(1);
//	TreeNode* cur1 = new TreeNode(2);
//	TreeNode* cur2 = new TreeNode(3);
//	TreeNode* cur3 = new TreeNode(4);
//	TreeNode* cur4 = new TreeNode(5);
//	TreeNode* cur5 = new TreeNode(6);
//	TreeNode* cur6 = new TreeNode(7);
//	TreeNode* cur7 = new TreeNode(8);
//	TreeNode* cur8 = new TreeNode(9);
//	cur->left = cur1;
//	cur->right = cur2;
//
//	cur1->left = cur3;
//	cur1->right = cur4;
//
//	cur2->left = cur5;
//	cur2->right = cur6;
//
//	cur3->right = cur8;
//	cur3->left = cur7;
//	/*TreeNode* tmp;
//	tmp = Ancestor(cur2,cur3,cur);*/
//	//vector<int> v1;
//	//vector<int> v2;//前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
//	//v1.push_back(1);
//	//v1.push_back(2);
//	//v1.push_back(4);
//	//v1.push_back(7);
//	//v1.push_back(3);
//	//v1.push_back(5);
//	//v1.push_back(6);
//	//v1.push_back(8);
//	//v2.push_back(4);
//	//v2.push_back(7);
//	//v2.push_back(2);
//	//v2.push_back(1);
//	//v2.push_back(5);
//	//v2.push_back(3);
//	//v2.push_back(8);
//	//v2.push_back(6);
//	//cur = NULL;
//	//cur = reConstructBinaryTree(v1, v2);
//	TreeNode* prev = NULL;
//	prev=Convert(cur);
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int h;
//	int w;
//	int i, j;
//	vector<int> h1;
//	vector<int> w1;
//	cin >> h;
//	h1.resize(h);
//	for (i = 0; i < h;++i)
//	{
//		cin >> h1[i];
//	}
//	cin >> w;
//	w1.resize(w);
//	for (i = 0; i < w; i++)
//	{
//		cin >> w1[i];
//	}
//	vector<int>::iterator it1 = h1.begin();
//	sort(it1,h1.end());
//	vector<int>::iterator it2 = w1.begin();
//	sort(it2, w1.end());
//	int sum = 0;
//	i = 0;
//	for (j = 0; j < h; j++)
//	{
//		for (; i < w;i++)
//		{
//			if (w1[i] > h1[j])
//			{
//				sum++;
//				i++;
//				break;
//			}
//		}
//	}
//	cout << sum<<endl;
//	return 0;
//}
//#include <iostream>  
//#include <string>  
//#include <assert.h>  
//using namespace std;
//void r(string &data);
//void c(string lhs, string rhs, string &result)
//{
//	r(lhs);
//	r(rhs);
//	int i = 0, j = 0, res_i = 0;
//	int tmp_i = 0;
//	int carry = 0;
//
//	for (i = 0; i != lhs.size(); ++i, ++tmp_i)
//	{
//		res_i = tmp_i;
//		for (j = 0; j != rhs.size(); ++j)
//		{
//			carry += (result[res_i] - '0') + (lhs[i] - '0') * (rhs[j] - '0');
//			result[res_i++] = (carry % 10 + '0');
//			carry /= 10;
//		}
//		while (carry)
//		{
//			result[res_i++] = (carry % 10 + '0');
//			carry /= 10;
//		}
//	}
//	for (int i = result.size() - 1; i >= 0; i--)
//	{
//		if (result[i] != '0')
//			break;
//		else
//			result.pop_back();
//	}
//	r(result);
//}
//void r(string &data)
//{
//	char temp = '0';
//	int end = data.size() - 1;
//	int s = 0;
//	assert(data.size() && s <= end);
//	while (s < end)
//	{
//		temp = data[s];
//		data[s++] = data[end];
//		data[end--] = temp;
//	}
//}
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//	string result(a.size() + b.size(), '0');
//	c(a, b, result);
//	cout << result << endl;
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2;
//
//	return 0;
//}
//#include<stdio.h>  
//#include<string.h>  
//#define MAX 100  
//char a[MAX], b[MAX];//用字符串进行数字的输入   
//int x[MAX + 10], y[MAX + 10], z[MAX * 2 + 10];//积的位数最多是因数位数的两倍   
//int main()
//{
//	int len1, len2, i, j;
//	while (scanf("%s %s", a, b))
//	{
//		len1 = strlen(a);
//		len2 = strlen(b);
//		for (j = 0, i = len1 - 1; i >= 0; i--)//将字符串中字符转化为数字，并倒序储存   
//			x[j++] = a[i] - '0';
//		for (j = 0, i = len2 - 1; i >= 0; i--)
//			y[j++] = b[i] - '0';
//		for (i = 0; i<len1; i++)//将因数各个位上的数字与另一个各个位上的数字相乘   
//		{
//			for (j = 0; j<len2; j++)
//				z[i + j] = z[i + j] + x[i] * y[j];//先乘起来，后面统一进行进位   
//		}
//		for (i = 0; i<MAX * 2; i++)//进行进位   
//		{
//			if (z[i] >= 10)  //若>=10   
//			{
//				z[i + 1] = z[i + 1] + z[i] / 10;  //将十位上数字进位   
//				z[i] = z[i] % 10;  //将个位上的数字留下  
//			}
//		}
//		for (i = MAX * 2; i>0; i--)  //删除0的前缀   
//		{
//			if (z[i] == 0)
//				continue;
//			else
//				break;
//		}
//		for (; i >= 0; i--)  //倒序输出   
//			printf("%d", z[i]);
//		printf("\n");
//	}
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <assert.h>
//using namespace std;
//void Tiao(int& m1,int& m2,int& m3)
//{
//	if (m1 > m2)
//	{
//		if (m2 < m3)
//		{
//			if (m1 > m3)
//			{
//				swap(m1,m2);
//				swap(m1,m3);
//			}
//			else//m1<m3
//			{
//				swap(m1,m2);
//			}
//		}
//		else//m2 > m3
//		{
//			swap(m1, m3);
//		}
//	}
//	else//m1<m2
//	{
//		if (m2 < m3)
//		{
//		}
//		else//m2 > m3
//		{
//			if (m1 > m3)
//			{
//				swap(m1, m3);
//				swap(m3, m2);
//			}
//			else//m1<m3
//			{
//				swap(m3, m2);
//			}
//		}
//	}
//}
//int main()
//{
//	int m1 = 0;
//	int m2 = 0;
//	int m3 = 0;
//	int n = 0;
//	int x = 0;
//	cin >> n;
//	if (n < 3)
//		return 0;
//	cin >> x;
//	m1 = x;
//	cin >> x;
//	m2 = x;
//	cin >> x;
//	m3 = x;
//	Tiao(m1, m2, m3);
//	int i = 3;
//
//	for (; i < n; i++)
//	{
//		cin >> x;
//		if (x > m1)
//		{
//			m1 = x;
//			Tiao(m1, m2, m3);
//		}
//	}
//	cout << m1*m2*m3<<endl;
//	return 0;
//
//}
//已知集合A和B的元素分别用不含头结点的单链表存储，函数difference()用于求解集合A与B的差集，
//并将结果保存在集合A的单链表中。
//例如，若集合A={5,10,20,15,25,30}，集合B={5,15,35,25}，完成计算后A={10,20,30}
//#include <iostream>
//#include <vector>
//#include <string.h>
//#include <assert.h>
//using namespace std;
//struct node
//{
//	int elem;
//	node* next;
//};
//void difference(node** LA, node* LB)
//{
//
//}
////插入排序
//void PrintArray(int* a, size_t n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		cout << a[i] << " ";
//	}
//
//	cout << endl;
//}
//
////template<class T, class Compare = less<T>>
////void InsertSort()
//
//void InsertSort(int* a, size_t n)
//{
//	assert(a);
//
//	for (size_t i = 1; i < n ; ++i)
//	{
//		int end = i-1;
//		int tmp = a[i];
//		while (end >= 0 && a[end] > tmp)
//		{
//			a[end + 1] = a[end];
//			--end;
//		}
//
//		a[end + 1] = tmp;
//	}
//}
//
//void TestInsertSort()
//{
//	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
//	InsertSort(a, sizeof(a) / sizeof(a[0]));
//	PrintArray(a, sizeof(a) / sizeof(a[0]));
//}
//
//int main()
//{
//	TestInsertSort();
//	return 0;
//}
//矩阵求值

//bool Find(int target, vector<vector<int> > array) {
//	if (array.empty())
//	{
//		return false;
//	}
//
//	int line = 0;
//	int row = array[0].size() - 1;
//
//	while (row >= 0 && line<array.size())
//	{
//		if (array[line][row] == target)
//		{
//			return true;
//		}
//		else if (array[line][row] < target)
//		{
//			line++;
//		}
//		else{
//			row--;
//		}
//	}
//	return false;
//
//}
//int main()
//{
//	vector<vector<int>> v;
//	v.resize(3);
//	v[0].resize(3);
//	v[1].resize(3);
//	v[2].resize(3);
//	/*v[0].resize(4);
//	v[1].resize(4);
//	v[0][0] = 1;
//	v[0][1] = 2;
//	v[0][2] = 8;
//	v[0][3] = 9;
//	v[1][0] = 4;
//	v[1][1] = 7;
//	v[1][2] = 10;
//	v[1][3] = 13;*/
//	for (int i = 0; i < 3;i++)
//	for (int j = 0; j < 3; j++)
//	{
//		v[i][j] = i + j;
//	}
//	Find(3,v);
//	return 0;
//}


//一个数组中有一个数字的次数超过了数组的一半，求出这个字符。
//如：int a[]={2,3,2,2,2,2,2,5,4,1,2,3}，求出超过一半的数字是2
//#include <iostream>
//#include <vector>
//#include <string.h>
//using namespace std;
//
//int MoreThanHalfNum_Solution(vector<int> numbers) {
//	vector<int> v;
//	v.resize(10);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		v[i] = 0;
//	}
//	int len = numbers.size();
//	int mid = len >> 1;
//	for (i = 0; i < len; i++){
//		v[numbers[i]]++;
//		if (v[numbers[i]] > mid)
//			return numbers[i];
//	}
//	return 0;
//}
//int main()
//{
//	vector<int> v; 
//	v.resize(9);
//	v[0] = 1;
//	v[1] = 2;
//	v[2] = 3;
//	v[3] = 2;
//	v[4] = 2;
//	v[5] = 2;
//	v[6] = 5;
//	v[7] = 4;
//	v[8] = 2;
//	cout<<MoreThanHalfNum_Solution(v);
//}
//删除一个或多个后的最长偶串例如 abaababaab 输出6
//int main()
//{
//	char s[200];
//	vector<char> v;
//	while (cin >> s)
//	{
//		int len = strlen(s)-2;
//
//		int mid = (len >> 1);
//		int i = 0;
//		v.resize(mid);
//		while (i <mid)
//		{
//			v[i] = s[i];
//			i++;
//		}
//		s[len] = '/0';
//		char *m = &s[mid];
//		while (len)
//		{
//			i = 0;
//			while (*m != '0')
//			{
//				if (v[i] == *m)
//				{
//					i++;
//					m++;
//				}
//				else
//				{
//					break;
//				}
//			}
//			if (*m == '0')
//			{
//				cout << v.size() * 2;
//				cout << endl;
//				break;
//			}
//			len = len - 2;
//			mid = mid - 1;
//			m = &s[mid];
//			v.pop_back();
//			s[len] = '/0';
//		}
//
//
//	}
//}
// 给定一个整数N，那么N的阶乘N！末尾有多少个0呢？例如：N＝10，N！＝3 628 800，N！的末尾有两个0
//分解质因数实际就是求有多少个5

//int countFactorialZero(int N) {
//	int ret = 0, i, j;
//	for (i = 1; i <= N; i++)
//	{
//		j = i;
//		while (j % 5 == 0)
//		{
//			ret++;
//			j /= 5;
//		}
//	}
//	return ret;
//}

//层序遍历二叉树
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//		val(x), left(NULL), right(NULL) {
//	}
//}; 
//vector<int> PrintFromTopToBottom(TreeNode* root) {
//	queue<TreeNode*> q;
//	q.push(root);
//	vector<int> v;
//	while (q.size() != 0)
//	{
//		//cout << q.front()->val << " ";
//		v.push_back(q.front()->val);
//		if (q.front()->left != NULL)
//			q.push(q.front()->left);
//		if (q.front()->right != NULL)
//			q.push(q.front()->right);
//
//		q.pop();
//
//	}
//	return v;
//}
//int main()
//{
//	TreeNode* cur = new TreeNode(1);
//	TreeNode* cur1 = new TreeNode(2);
//	TreeNode* cur2 = new TreeNode(3);
//	TreeNode* cur3 = new TreeNode(4);
//	TreeNode* cur4 = new TreeNode(5);
//	TreeNode* cur5 = new TreeNode(6);
//	TreeNode* cur6 = new TreeNode(7);
//	TreeNode* cur7 = new TreeNode(8);
//	TreeNode* cur8 = new TreeNode(9);
//	cur->left = cur1;
//	cur->right = cur2;
//
//	cur1->left = cur3;
//	cur1->right = cur4;
//
//	cur2->left = cur5;
//	cur2->right = cur6;
//
//	cur3->right = cur8;
//	//cur3->left = cur7;
//	vector<int> v;
//	v=PrintFromTopToBottom(cur);
//	return 0;
//}

//二进制中1的个数
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
///*int  NumberOf1(int n) {
//	unsigned int num = 1;
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (n & num)
//			count++;
//
//		num = num << 1;
//	}
//	return count;
//}*/
//int  NumberOf1(int n) {
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = (n - 1) & n;
//	}
//	return count;
//}
//int main()
//{
//	//cout << NumberOf1(-1);
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.pop();
//	cout << q.front();
//	return 0;
//}

//--元素出栈、入栈顺序的合法性。如：入栈的序列（1,2,3,4,5），出栈序列为（4,5,3,2,1），则合法。
//入栈的序列（1,2,3,4,5），出栈序列为（4,5,2,3,1），则不合法。
//
//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
//bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//	int i = 0;
//	int j = 0;
//	stack<int> s1;
//	while (i < pushV.size() && j < popV.size())
//	{
//		if (pushV[i] != popV[j])
//		{
//			s1.push(pushV[i++]);
//		
//			continue;
//		}
//		else{
//			i++;
//			j++;
//		}
//	}
//
//	if (j == popV.size())
//		return true;
//	else{
//		while (j < popV.size())
//		{
//			if (popV[j] == s1.top())
//			{
//				j++;
//				s1.pop();
//			}
//			else{
//				return false;
//			}
//		}
//		return true;
//	}
//
//	return true;
//}
//int main()
//{
//	vector<int> v1, v2;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v2.push_back(5);
//	v2.push_back(4);
//	v2.push_back(3);
//	v2.push_back(2);
//	v2.push_back(1);
//	cout<<IsPopOrder(v1, v2);
//	return 0;
//}

//查找一个字符串中第一个只出现两次的字符。比如：“abcdefabcdefabc”
//中第一个只出现两次为‘d’，要求时间复杂度为O(N)，空间复杂度为O(1)
//#include <iostream>
//using namespace std;
//int main()
//{
//	char arr[128]; int i = 0;
//	for (i = 0; i < 128; i++)
//	{
//		arr[i] = 0;
//	}
//	char* str = "abcdefabcdefabc";
//	int len = strlen(str);
//	for (i = 0; i < len; i++)
//	{
//		arr[*str]++;
//		str++;
//	}
//	for (i = 0; i < 128; i++)
//	{
//		if (arr[i] == 2)
//		{
//			printf("%c", i);
//			break;
//		}
//	}
//}

//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
//#include <iostream>
//using namespace std;
//#include <string>
//#include <stack>
//class Solution {
//public:
//	void push(int value) {
//		int min = 0;
//		if (s1.empty())
//		{
//			min = value;
//			s1.push(make_pair(min, value));
//		}
//		else
//		{
//			if (value < s1.top().first)
//			{
//				s1.push(make_pair(value, value));
//			}
//			else
//			{
//				min = s1.top().first;
//				s1.push(make_pair(min,value));
//			}
//		}
//	}
//	void pop() {
//		s1.pop();
//	}
//	int top() {
//		return s1.top().second;
//	}
//	int min() {
//		return s1.top().first;
//	}
//	stack<pair<int,int>> s1;
//	
//};
//int main()
//{
//	Solution s;
//	s.push(6);
//	s.push(5);
//	s.push(4);
//	s.push(3);
//	s.push(2);
//	cout << s.min();
//	return 0;
//}


////替换空格O(1)
//#include <iostream>
//using namespace std;
//#include <string>
//void replaceSpace(char *str, int length) {
//	char* cur = str;
//	int spaceNum = 0;
//	while (*cur != '\0')
//	{
//		if (*cur == ' ')
//			spaceNum++;
//		cur++;
//	}
//	int i = length;
//	int j = i + (spaceNum * 2);
//
//	for (; i >= 0; i--)
//	{
//		if (spaceNum == 0)
//			return;
//		if (str[i] == ' ')
//		{
//			str[j--] = '0';
//			str[j--] = '2';
//			str[j--] = '%';
//			spaceNum--;
//		}
//		else
//		{
//			str[j--] = str[i];
//
//		}
//
//
//
//	}
//}
//int main()
//{
//	char a[12] = " abc de";
//	replaceSpace(a, strlen(a));
//	cout << a;
//	return 0;
//}


//1.判断两个链表是否相交，若相交，求交点。（假设链表不带环）//2.o（1）时间复杂度删除一个链表
//#include<iostream>
//#include<stack>
//#include<vector>
//using namespace std;
//
//typedef struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//}Node;
//Node* GetList()
//{
//	Node* prev = new Node(0);
//	Node* head = prev;
//	for (int i = 1; i < 5; i++)
//	{
//		Node* cur = new Node(i);
//		prev->next = cur;
//		prev = cur;
//	}
//	return head;
//}
//Node* Reversal(Node* left,Node* right)
//{
//	Node* cur = left;
//	Node* next = left->next;
//	while (next != right)
//	{
//		left = next;
//		next = next->next;
//		left->next = cur;
//
//		cur = left;
//	}
//	if (next != NULL)
//	{
//		next->next = cur;
//		cur = next;
//	}
//	return cur;
//}
//Node* RotateList(Node* list, size_t k)
//{
//	if (list == NULL && list->next == NULL)
//		return list;
//	Node* head = NULL;
//	Node* cur = list;
//	size_t count = 0;
//	Node* left = list;
//	Node* right = list;
//	Node* prev = NULL;
//	Node* next = NULL;
//	while (cur)
//	{
//		count++;
//		if (count == k)
//		{
//			right = cur;
//			next = cur->next;
//			if (prev != NULL)
//			{
//				prev->next = Reversal(left, right);
//			}
//			else
//			{
//				Reversal(left, right);
//				head = cur;
//			}
//			left->next = next;
//
//			left = next;
//			prev = cur->next;
//			count = 0;
//		}
//		else
//		{
//			next = cur->next;
//		}
//
//		
//		cur = next;
//	}
//	return head;
//}
//int main()//链表翻转。给出一个链表和一个数k，比如链表1→2→3→4→5→6，
////k=2，翻转后2→1→4→3→6→5，若k=3,翻转后3→2→1→6→5→4，若k=4，翻转后4→3→2→1→5→6
//{
//	Node* head = GetList();
//	RotateList(head,3);
//	//Reversal(head, NULL);
//}
//class List
//{
//	typedef ListNode Node;
//public:
//	Node* head;
//
//	void GetList()
//	{
//		Node* prev = new Node(0);
//		head = prev;
//		for (int i = 1; i < 5; i++)
//		{
//			Node* cur = new Node(i);
//			prev->next = cur;
//			prev = cur;
//		}
//	}
//		void Print()
//		{
//			ListNode* cur = head;
//			while (cur)
//			{
//				cout << cur->val << "   ";
//				cur = cur->next;
//			}
//		}
//
//		//ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {//利用两个栈从后往前的思想来
//		//	stack<ListNode*> p1;
//		//	stack<ListNode*> p2;
//
//		//	if (pHead1 == NULL || pHead2 == NULL)
//		//		return NULL;
//		//	ListNode* cur1 = pHead1;        ListNode* cur2 = pHead2;
//
//		//	while (cur1->next != NULL || cur2->next != NULL)
//		//	{
//		//		if (cur1->next != NULL)
//		//		{
//		//			p1.push(cur1);
//		//			cur1 = cur1->next;
//		//		}
//		//		if (cur2->next != NULL)
//		//		{
//		//			p2.push(cur2);
//		//			cur2 = cur2->next;
//		//		}
//		//	}
//		//	if (p1.top() != p2.top())
//		//		return NULL;
//		//	ListNode* prev = cur1;
//		//	while (1)
//		//	{
//		//		if (p1.top() != p2.top())
//		//			return prev;
//		//		prev = p1.top();
//		//		p1.pop();
//		//		p2.pop();
//
//		//	}
//
//		//}
//		//先求出两条链表的长度
//		//，再用长的链表走差值步，然后两个再一起走，第一个相同的就是交点
//		ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
//		{
//			int length1 = 0;
//			int length2 = 0;
//			ListNode* cur1 = pHead1;
//			ListNode* cur2 = pHead2;
//			while (1)
//			{
//				if (pHead1 != NULL)
//				{
//					length1++;
//					pHead1 = pHead1->next;
//				}
//				if (pHead2 != NULL)
//				{
//					length2++;
//					pHead2 = pHead2->next;
//				}
//				if (pHead1 == NULL && pHead2 == NULL)
//				{
//					break;
//				}
//			}
//			
//			int tmp = 0;
//			if (length1 > length2)
//			{
//				tmp = length1 - length2;
//				for (int i = 0; i < tmp; i++)
//				{
//					cur1 = cur1->next;
//				}
//				while (cur1 != NULL && cur2 != NULL)
//				{
//					if (cur1 == cur2)
//						return cur1;
//					cur1 = cur1->next;
//					cur2 = cur2->next;
//				}
//			}
//			else
//			{
//				tmp = length2 - length1;
//				for (int i = 0; i < tmp; i++)
//				{
//					cur2 = cur2->next;
//				}
//				while (cur1 != NULL && cur2 != NULL)
//				{
//					if (cur1 == cur2)
//						return cur1;
//					cur1 = cur1->next;
//					cur2 = cur2->next;
//				}
//			}
//		}
//
//		void DeleteNode(ListNode* node)//O(1)时间复杂度删除一个节点
//		{
//			if (node == NULL)
//			{
//				return;
//			}
//
//			if (head == NULL)
//			{
//				return;
//			}
//			ListNode* cur = head;
//			ListNode* next = head->next;
//			while (next != NULL)
//			{
//				if (cur == node)
//				{
//					swap(cur->val, next->val);
//					cur->next = next->next;
//					free(next);
//					return;
//				}
//				cur = next;
//				next = next->next;
//			}
//
//		}
//		//从头到尾打印链表
//		class Solution {
//		public:
//			vector<int> v1;
//			vector<int> printListFromTailToHead(ListNode* head) {
//				if (head == NULL)
//					return v1;
//				printListFromTailToHead(head->next);
//				v1.push_back(head->val);
//				return v1;
//			}
//		};
//};
//int main()
//{
//	//List s;
//	//s.GetList();
//	////s.Print();
//	//List s2;
//	//s2.GetList();
//	//ListNode* cur = s2.head;
//	//cur = cur->next;
//	//cur = cur->next;
//	//cur = cur->next;
//	//ListNode* cur1 = s.head;
//	//cur1 = cur1->next;
//	//cur1 = cur1->next;
//	//cur->next = cur1;
//	//s2.Print();
//	//cout << endl;
//	//s2.DeleteNode(cur1);
//	//s2.Print();
//	//cout << endl;
//	////cout<<s2.FindFirstCommonNode(s.head,s2.head)->val;
//
//	char* str = "qewruoi";
//	cout << str[2];
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
////输入一个链表，反转链表后，输出链表的所有元素。
//
//#include<iostream>
//#include<stack>
//using namespace std;
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
//class Solution {
//public:
//	ListNode* ReverseList(ListNode* pHead) {
//
//		if (pHead == NULL && pHead->next == NULL)
//			return pHead;
//		stack<ListNode*> s1;
//		while (pHead)
//		{
//			s1.push(pHead);
//			pHead = pHead->next;
//		}
//		ListNode* head = s1.top();
//		ListNode* tmp;
//		while (!s1.empty())
//		{
//			tmp = s1.top();
//			s1.pop();
//			tmp->next = s1.top();
//		}
//		return head;
//	}
//	void push(int x)
//	{
//		ListNode* tmp = new ListNode(x);
//		ListNode* head1 = head;
//		while (head1->next)
//		{
//			head1 = head1->next;
//		}
//		head1->next = tmp;
//
//	}
//	void ProduceList()
//	{
//		ListNode* t1 = new ListNode(1);
//		ListNode* t2 = new ListNode(2);
//		ListNode* t3 = new ListNode(3);
//		ListNode* t4 = new ListNode(4);
//		ListNode* t6= new ListNode(6);
//		ListNode* t5 = new ListNode(5);
//		ListNode* t7 = new ListNode(7);
//		ListNode* t8 = new ListNode(8);
//		ListNode* t9 = new ListNode(9);
//		
//		t1->next = t2;
//		t2->next = t3;
//		t3->next = t4;
//		t4->next = t5;
//		t5->next = t6;
//		t6->next = t7;
//		t7->next = t8;
//		t8->next = t9;
//		t9->next = t6;
//		head = t1;
//	}
//	void Print()
//	{
//		ListNode* cur = head;
//		while (cur)
//		{
//			cout << cur->val << "   ";
//			cur = cur->next;
//		}
//	}
//	ListNode* IsHaveLoop()//判断是否带环
//	{
//		ListNode* fast = head;
//		ListNode* slow = head;
//		ListNode* next = NULL;
//		while(fast != NULL)
//		{
//			next = fast->next;
//			if (next == NULL)
//				break;
//			fast = next->next;
//			slow = slow->next;
//			if (slow == fast)
//				return slow;
//		}
//
//		return NULL;
//	}
//	int LoopLength()//环的长度
//	{
//		ListNode* tmp;
//		int count = 1;
//		if ((tmp = IsHaveLoop()) != NULL)
//		{
//			ListNode* cur = tmp->next;
//			while (cur != tmp)
//			{
//				cur = cur->next;
//				count++;
//			}
//			return count;
//		}
//	}
//	ListNode* entrance()
//	{
//		ListNode *tmp;
//		if ((tmp = IsHaveLoop()) != NULL)
//		{
//			ListNode* cur = head;
//			while (1)
//			{
//				if (cur == tmp)
//					return cur;
//				cur = cur->next;
//				tmp = tmp->next;
//			}
//		}
//		return 0;
//	}
//	ListNode* head;
//};
//
//int main()
//{
//	
//	Solution l;
//	l.ProduceList();
//	cout << l.IsHaveLoop()->val << endl;
//	cout << l.LoopLength() << endl;
//	cout << l.entrance()->val << endl;
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//#include <math.h>
//using namespace std;
//// 请完成下面这个函数，实现题目要求的功能
//// 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^
//int result(int size,int max,int min) {
//
//	int maxmax = max + max;
//	int maxmin = min + min;
//
//	int minmax = max - min;
//	int minmin = min - max;
//
//	int dmax = maxmax - minmin;
//	int dmin = maxmin - minmax;
//	return dmax + dmin + size;
//	
//}
//
//int main() {
//	int size = 0;
//	cin >> size;
//	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
//	vector<int> points;
//	int max = 0;
//	int min = 0;
//	for (size_t i = 0; i<size; ++i) {
//		int item;
//		cin >> item;
//		//cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
//		//points.push_back(item);
//		if (item > max)
//			max = item;
//		if (i == 0)
//			min = item;
//		if (min > item)
//			min = item;
//	}
//	int res = result(size,max,min);
//	cout << res << endl;
//	return 0;
//}