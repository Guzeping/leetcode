#include<cstdio>
#include<malloc.h>
using namespace::std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x=0) : val(x), next(NULL) {}
};
ListNode * creat(int n) {
	int tmp;
	ListNode *head = NULL, *p, *end=head;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &tmp, 1);
		p = (ListNode *)malloc(sizeof(ListNode));
		p->val = tmp;
		if (head == NULL) {
			head = p;
			end = p;
		}
		else 
		{
			end->next = p;
			end = end->next;
		}
		end->next = NULL;
	}
	return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	ListNode  *result = NULL, *end, *p, *p1 = l1, *p2 = l2;
	p = new ListNode(0);
	result = p;
	end = p;
	int carry = 0;
	while (p1 != NULL && p2 != NULL) {
		p = new ListNode(0);
		if (p1->val + p2->val + carry >= 10) {
			p->val = p1->val + p2->val + carry - 10;
			carry = 1;
		}
		else
		{
			p->val = p1->val + p2->val + carry;
			carry = 0;
		}
		p1 = p1->next;
		p2 = p2->next;
		end->next = p;
		end = end->next;
	}
	result = result->next;
	if (p1 == NULL &&p2 == NULL) {
		if (carry == 0) {
			return result;
		}
		else
		{
			p = new ListNode(1);
			end->next=p;
			end = end->next;
			return result;
		}

	}
	if (p1 == NULL) {
		while (carry != 0) {
			if (p2 == NULL) {
				p = new ListNode(1);
				end->next = p;
				return result;
			}
			p = new ListNode(0);
			if (p2->val + carry >= 10) {
				p->val = p2->val + carry - 10;
				carry = 1;
			}
			else
			{
				p->val = p2->val + carry;
				carry = 0;
			}
			p2 = p2->next;
			end->next = p;
			end = end->next;
		}
		end->next = p2;
		return result;
	}
	if (p2 == NULL) {
		while (carry != 0) {
			if (p1 == NULL) {
				p = new ListNode(1);
				end->next = p;
				return result;
			}
			p = new ListNode(0);
			if (p1->val + carry >= 10) {
				p->val = p1->val + carry - 10;
				carry = 1;
			}
			else
			{
				p->val = p1->val + carry;
				carry = 0;
			}
			p1 = p1->next;
			end->next = p;
			end = end->next;
		}
		end->next = p1;
		return result;
	}
}

int main() {
	int m=0, n=0;
	scanf_s("%d %d", &m, &n, 2);
	ListNode *l1 = creat(m);
	ListNode *l2 = creat(n);
	ListNode *reslut= addTwoNumbers(l1, l2);

	return 0;
}