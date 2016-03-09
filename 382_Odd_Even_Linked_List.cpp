#include<cstdio>
#include<malloc.h>
using namespace::std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* oddEvenList(ListNode* head){
	if (!head || !head->next) 
	{
		return head;
	}
	ListNode *odd = head;
	ListNode *even = head->next;
	ListNode *even_head = even;
	//head->next = NULL;
	while (even->next&&even->next->next) 
	{
		odd->next = even->next;
		even->next = even->next->next;
		odd = odd->next;
		even = even->next;
	}
	if (even->next) 
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = NULL;
	}
	odd->next = even_head;
	return head;
}
ListNode* create(int n) {
	ListNode  *head, *p, *end;
	head = NULL;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &tmp, 1);
		p = (ListNode *)malloc(sizeof(ListNode));
		p->val = tmp;
		if (head == NULL) {
			
			head->next = p;
			end = p;
		}
		else
		{
			end->next = p;
			end = end->next;
		}
	}
}
void main() {
	int n, tmp;
	scanf_s("%d", &n,1);
	ListNode *head = create(n);
	

}