//����һ������N����ôN�Ľ׳�N��ĩβ�ж��ٸ�0�أ����磺N��10��N����3 628 800��N����ĩβ������0
//�ֽ�������ʵ�ʾ������ж��ٸ�5
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

//�������������
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

//��������1�ĸ���
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

//--Ԫ�س�ջ����ջ˳��ĺϷ��ԡ��磺��ջ�����У�1,2,3,4,5������ջ����Ϊ��4,5,3,2,1������Ϸ���
//��ջ�����У�1,2,3,4,5������ջ����Ϊ��4,5,2,3,1�����򲻺Ϸ���
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

//����һ���ַ����е�һ��ֻ�������ε��ַ������磺��abcdefabcdefabc��
//�е�һ��ֻ��������Ϊ��d����Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)
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

//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
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


////�滻�ո�O(1)
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


//1.�ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������//2.o��1��ʱ�临�Ӷ�ɾ��һ������
//#include<iostream>
//#include<stack>
//#include<vector>
//using namespace std;
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
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
//		//ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {//��������ջ�Ӻ���ǰ��˼����
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
//		//�������������ĳ���
//		//�����ó��������߲�ֵ����Ȼ��������һ���ߣ���һ����ͬ�ľ��ǽ���
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
//		void DeleteNode(ListNode* node)//O(1)ʱ�临�Ӷ�ɾ��һ���ڵ�
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
//		//��ͷ��β��ӡ����
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
////����һ��������ת�����������������Ԫ�ء�
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
//	ListNode* IsHaveLoop()//�ж��Ƿ����
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
//	int LoopLength()//���ĳ���
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
//// ������������������ʵ����ĿҪ��Ĺ���
//// ��Ȼ����Ҳ���Բ��������ģ����������ȫ�����Լ����뷨�� ^-^
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