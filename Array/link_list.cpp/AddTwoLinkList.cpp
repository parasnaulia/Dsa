#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node();
    temp->data = val;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
Node *reverse(Node *first)
{
    Node *prev = NULL;
    Node *cur = first;
    Node *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
Node *add(Node *first, Node *second)
{
    Node *head = NULL;
    Node *tail = NULL;
    int sum = 0;
    int carry = 0;
    int digit = 0;
    while (first != NULL && second != NULL)
    {
        sum = first->data + second->data + carry;
        digit = sum % 10;
        insertAtTail(head, tail, digit);
        carry = sum / 10;
        first = first->next;
        second = second->next;
    }
    while (first != NULL)
    {
        sum = first->data + carry;
        digit = sum % 10;
        insertAtTail(head, tail, digit);
        carry = sum / 10;
        first = first->next;
    }
    while (second != NULL)
    {
        sum = second->data + carry;
        digit = sum % 10;
        insertAtTail(head, tail, digit);
        carry = sum / 10;
        second = second->next;
    }
    while (carry != 0)
    {
        insertAtTail(head, tail, carry);
        carry--;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // Create 1st link list
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *forth = new Node();
    head->data = 3;
    head->next = second;
    second->data = 4;
    second->next = third;
    third->data = 4;
    third->next = forth;
    forth->data = 3;
    forth->next = NULL;
    // create second link list

    Node *head1 = new Node();
    Node *second1 = new Node();
    Node *third1 = new Node();
    Node *forth1 = new Node();
    head1->data = 9;
    head1->next = second1;
    second1->data = 4;
    second1->next = third1;
    third1->data = 9;
    third1->next = forth1;
    forth1->data = 3;
    forth1->next = NULL;
    cout << "List 1" << endl;
    print(head);
    cout << "List 2 :" << endl;
    print(head1);
    Node *l1 = reverse(head);
    Node *l2 = reverse(head1);

    Node *ans = add(l1, l2);

    Node *ans1 = reverse(ans);
    cout << "The Sum of Two link list is" << endl;
    print(ans1);

    return 0;
}