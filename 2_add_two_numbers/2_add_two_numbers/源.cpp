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
	return help(l1, l2, 0);
}

ListNode* help(ListNode *l1, ListNode *l2,int add) {

	if ( l1 == NULL && l2 == NULL) {
		if (add == 0) {
			return NULL;
		}
		else
		{
			ListNode * p = new ListNode(add);
			return p;
		}
	}
	else {
		int sum = add;
		if (l1 != NULL) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			sum += l2->val;
			l2 = l2->next;
		}
		add = sum / 10;
		sum = sum %10;
			
		ListNode *p = new ListNode(sum);

		p->next = help(l1, l2, add);
		return p;
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