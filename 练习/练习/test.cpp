#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class List
{
	typedef ListNode Node;
public:
	Node* head;

	void GetList()
	{
		Node* prev = new Node(0);
		head = prev;
		for (int i = 1; i < 5; i++)
		{
			Node* cur = new Node(i);
			prev->next = cur;
			prev = cur;
		}
	}
	void Print()
	{
		ListNode* cur = head;
		while (cur)
		{
			cout << cur->val << "   ";
			cur = cur->next;
		}
	}

	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		stack<ListNode*> p1;
		stack<ListNode*> p2;

		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		ListNode* cur1 = pHead1;        ListNode* cur2 = pHead2;

		while (cur1->next != NULL && cur2->next != NULL)
		{
			p1.push(cur1);
			cur1 = cur1->next;
			p2.push(cur2);
			cur2 = cur2->next;
		}
		if (p1.top() != p2.top())
			return NULL;
		ListNode* prev = cur1;
		while (1)
		{
			if (p1.top() != p2.top())
				return prev;
			prev = p1.top();
			p1.pop();
			p2.pop();

		}

	}

};
int main()
{
	List s;
	s.GetList();
	//s.Print();
	List s2;
	s2.GetList();
	ListNode* cur = s2.head;
	cur = cur->next;
	cur = cur->next;
	cur = cur->next;
	ListNode* cur1 = s.head;
	cur1 = cur1->next;
	cur1 = cur1->next;
	cur->next = cur1;
	s2.Print();
	cout << endl;
	//cout<<s2.FindFirstCommonNode(s.head,s2.head)->val;

	return 0;
}