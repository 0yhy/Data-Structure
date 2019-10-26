#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data (0), next (NULL) {}
    Node (int data_, Node *next_) : data (data_), next (next_) {}
};

Node *head = new Node (0, NULL);

void insert (int d)
{
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *q = new Node (d, NULL);
    p->next = q;
}

void erase (int d)
{
    Node *p = head->next, *fp = head;
    while (p && p->data != d)
    {
        fp = p;
        p = p->next;
    }
    if(p)
    {
        fp->next = p->next;
        delete p;
    }
}

void traverse()
{
    Node *p = head->next;
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

//int a(1);
//int b=2;

void f()
{
    int a[1000];
}

void gen (int k)
{
    for (int i = 0; i < k ; ++i)
    {
        insert (rand());
    }
}

int main()
{
    srand (time (NULL));
    // //for(int i=1; i<=100; ++i) f();
    // head = new Node;
    // delete head;
    // cout << head << endl;//此时head是一个野指针
    gen (5);
    traverse();
    return 0;
}