#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node (int data_, Node *next_) : data(data_), next(next_) {}
};

//带表头链表
Node *head = new Node(0, NULL);

//在链表末端插入元素
void insert(int data)
{
    Node *p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    Node *q = new Node(data, NULL);
    p->next = q;
}

//删除数值为data的元素
void erase(int data)
{
    Node *fp = head;
    Node *p = head->next;
    while(p && p->data != data)
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

//链表元素的遍历
void traverse()
{
    Node *p = head->next;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void rand_num(int n)
{
    for(int i = 0; i < n; i++)
    {
        insert(i);
    }
}

int main()
{
    srand(time(NULL));
    rand_num(10);
    traverse();
    insert(11);
    traverse();
    erase(5);
    traverse();
    return 0;
}