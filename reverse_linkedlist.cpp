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

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void print_linklist(node *head)
    {
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

   void print_reverse_linklist(node *temp){
            
            //base case
            if(temp==NULL){
                return;
            }
            print_reverse_linklist(temp->next);
            cout<<temp->val<<endl;
   }

int main()
{
    node *head = NULL;
    node *tail = NULL;
    node n(0);
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    print_reverse_linklist(head);

    return 0;
}