#include <iostream>

using namespace std;

struct node
{
    int data;
    node *Next;
};
struct stack
{
    node *Top;
};
stack s;

void KhoiTaoStack(stack &s)
{
    s.Top = NULL;
}

node *KhoiTaoNode(int x)
{
    node *p = new node;
    p->data = x;
    p->Next = NULL;
    return p;
}

int Empty(stack s)
{
    if (s.Top == NULL)
    {
        return 1;
    }
    return 0;
}

int Push(stack &s, node *p)
{
    if (p == NULL)
    {
        return 1;
    }
    if (Empty(s) == 1)
    {
        s.Top = p;
    }
    else
    {
        p->Next = s.Top;
        s.Top = p;
    }
    return 0;
}

int Pop(stack &s, int &x)
{

    if (Empty(s))
    {
        return 1;
    }
    node *p = s.Top;
    s.Top = s.Top->Next;
    x = p->data;
    return 0;
}

int Top(stack s, int &x)
{

    if (Empty(s) == 1)
    {
        return 1;
    }
    x = s.Top->data;
    return 0;
}

void Chuyen_Co_So(stack &s, int cosocandoi, int hethapphan)
{
    while (hethapphan != 0)
    {
        int x = hethapphan % cosocandoi;
        node *p = KhoiTaoNode(x);
        Push(s, p);
        hethapphan /= cosocandoi;
    }
}

void XuatStack(stack &s)
{
    while (Empty(s) == 0)
    {
        int x;
        Pop(s, x);
        if (x < 10)
        {
            cout << x;
        }
        else
        {
            if (x == 10)
            {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12)
            {
                cout << "C";
            }
            else if (x == 13)
            {
                cout << "D";
            }
            else if (x == 14)
            {
                cout << "E";
            }
            else if (x == 15)
            {
                cout << "F";
            }
        }
    }
}

int main()
{
    stack s;
    KhoiTaoStack(s);

    int hethapphan, cosocandoi;
    cout << "\nnhap gia tri thap phan can chuyen: ";
    cin >> hethapphan;
    do
    {
        cout << "\nnhap co so can chuyen (2, 8, 16):  ";
        cin >> cosocandoi;
    } while (cosocandoi != 2 && cosocandoi != 8 && cosocandoi != 16);

    Chuyen_Co_So(s, cosocandoi, hethapphan);
    cout << "\nket qua:\n";
    XuatStack(s);
    cout << endl;

    cout << "\n-------------------------\n";
}