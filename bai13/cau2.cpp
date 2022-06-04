
#include <iostream>
#include <string>

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
void kiemtradaungoac(stack &s, string chuoi)
{
    int x;
    node *p = KhoiTaoNode(x);
    for (int i = 0; i < chuoi.size(); i++)
    {
        if (chuoi[i] == '(')
        {
            Push(s, p);
        }
        else if (chuoi[i] == ')')
        {
            if (Empty(s) == 1)
            {
                Pop(s, x);
            }
            else
            {
                Push(s, p);
            }
        }
    }
    if (Empty(s) == 0)
        cout << "chuoi dung quy dinh";
    else
    {
        cout << "chuoi sai dinh dang\n";
    }
}
int main()
{
    stack s;
    string chuoi;
    KhoiTaoStack(s);
    cout << "nhap chuoi: ";
    cin >> chuoi;
    kiemtradaungoac(s, chuoi);
}