#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int val;
    node *next;

    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(node *&head, node *&tail, int val)
{
    node *newnode = new node(val);

    if (head== NULL)
    {
        head = newnode;
        tail = newnode; 
        return;
    }
    tail->next = newnode;
    tail= tail->next;
    // jeheto tail niye nisi tai eta r dorkar nei
    //  node *temp = head;
    //  while (temp->next != NULL)
    //  {
    //      // cout << temp->val << endl;
    //      temp = temp->next;
    //  }
    //  right now temp is at last node

    // temp->next = newnode; eikane akhn tail bosbe
}

void print_linked_list(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        // cout<<temp<<endl;
        temp = temp->next;
    }
}
int main()
{
    node *head = new node(10);
    node *a = new node(20);
    node *tail = new node(30);
    // node* tail= b; //optimized for best case

    head->next = a;
    a->next = tail;

    // insert_at_tail(head, 40);
    insert_at_tail(head, tail, 100);
    print_linked_list(head);

    cout<<"tail:"<<tail->val<<endl;
}