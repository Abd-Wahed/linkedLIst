#include<bits/stdc++.h>
using namespace std;

class node
{

public:
     int val;
     node* next;
};

int main(){
    node a,b,c;//a,b,c individual node
    a.val=10;
    b.val=20;
    c.val=30;

    a.next=&b;//a er next direct address krbe b node k
    b.next=&c;
    c.next=NULL;

    cout<<(*a.next).next<<endl;//b node er next node er address
    cout<<(*a.next).next->val<<endl;//b node next address theke c node er value

}