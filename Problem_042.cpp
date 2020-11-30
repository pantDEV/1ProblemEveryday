// { Driver Code Starts
// driver code
// check if linked list has a loop or not

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

void loopHere(Node* head, Node* tail, int position)
{
	if (position == 0) return;

	Node* walk = head;
	for (int i = 1; i < position; i++)
		walk = walk->next;
	tail->next = walk;
}

bool detectLoop(Node* head);

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, num;
		cin >> n;

		Node *head, *tail;
		cin >> num;
		head = tail = new Node(num);

		for (int i = 0 ; i < n - 1 ; i++)
		{
			cin >> num;
			tail->next = new Node(num);
			tail = tail->next;
		}

		int pos;
		cin >> pos;
		loopHere(head, tail, pos);

		if ( detectLoop(head) )
			cout << "True\n";
		else
			cout << "False\n";
	}
	return 0;
}
// } Driver Code Ends


/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

bool detectLoop(Node* head)
{
	// your code here
	struct Node *ptr1 = head;
	struct Node *ptr2 = head;

	while (ptr1 && ptr2 && ptr2 -> next)
	{
		ptr1 = ptr1 -> next;
		ptr2 = ptr2 -> next -> next;
		if (ptr1 == ptr2)
			return true;

	}
	return false;
}
