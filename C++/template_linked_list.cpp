#include <bits/stdc++.h>

using namespace std;

template<typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node *next;//T的默认构造函数
        Node(const T & t = T(), Node * n = nullptr):data(t), next(n) {}
    };
public:
    //struct Node;
    List():size(0), head(new Node) {}
    bool IsEmpty()
    {
        return size == 0;
    }
    int GetSize()
    {
        return size;
    }
    void PushFront(const T &val)
    {
        auto p = new Node(val, head->next);
        head->next = p;
        ++size;
    }
    void PushBack(const T &val)
    {
        auto p = head;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        auto q = new Node(val, nullptr);
        p->next = q;
        ++size;
    }
    void PopFront()
    {
        auto p = head->next;
        head->next = p->next;
        delete p;
        --size;
    }
    void PopBack()
    {
        auto p = head->next;
        auto fp = head;
        while(p->next != nullptr) 
        {
            fp = p;
            p = p->next;
        }
        fp->next = nullptr;
        delete p;
        --size;
    }
    T & Front()
    {
        return head->next->data;
    }
    T & Back()
    {
        auto p = head;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        return p->data;
    }
    void traverse()
    {
        auto p = head->next;
        while(p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
private:
    Node *head;
    int size;
};


// struct Point
// {
//     int x, y;
//     Point(int x = 0, int y = 0):x(x), y(y) {}
// };
// Point p(3,4);

int main()
{
    cout << "Enter 1 to pushFront:" << endl;
    cout << "Enter 2 to pushBack:" << endl;
    cout << "Enter 3 to popFront:" << endl;
    cout << "Enter 4 to popBack:" << endl;
    cout << "Enter 5 to getFront:" << endl;
    cout << "Enter 6 to getBack:" << endl;
    cout << "Enter 7 to empty:" << endl;
    cout << "Enter 8 to size:" << endl;
    List<int> L;
    while(true)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int y;
            cin >> y;
            // while(cin >> y)
            // {
                L.PushFront(y);
                L.traverse();
            // }
        }
        if(x == 2)
        {
            int y;
            cin >> y;
            // while(cin >> y) 
            // {
                L.PushBack(y);
                L.traverse();
            // }
        }   
        if(x == 3)
        {
            L.PopFront();
            L.traverse();
        }
        if(x == 4)
        {
            L.PopBack();
            L.traverse();
        }
        if(x == 5)
        {
            cout << "Front: " << L.Front() << endl;
        }
        if(x == 6)
        {
            cout << "Back: " << L.Back() << endl;
        }
        if(x == 7)
        {
            cout << "Size: " << L.GetSize() << endl;
        }
        if(x == 8)
        {
            cout << "Isempty: " << bool(L.IsEmpty()) << endl;
        }
    }
    return 0;
}
