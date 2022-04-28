#include <iostream>
#include <string>
#include <vector>
using namespace std;

class withdraw
{
private:
    string wd_num;
    float wd_money;
    string wd_note;

public:
    void addwithdraw();
    void displaydraw();
};
void withdraw::addwithdraw()
{

    cout << "nhap num: ";
    getline(cin, wd_num);
    cout << "nhap money: ";
    cin >> wd_money;
    cin.ignore();
    cout << "nhap note: ";
    getline(cin, wd_note);
}
void withdraw::displaydraw()
{
    cout << "num: " << wd_num << endl;
    cout << "money: " << wd_money << endl;
    cout << "note: " << wd_note << endl;
}
class customer
{
    int id;
    string name;
    string cccd;
    vector<withdraw> a;
    int n;

public:
    void input();
    void output();
};
void customer ::input()
{
    cout << "nhap ho va ten: ";
    getline(cin, name);
    cout << "nhap stt: ";
    cin >> id;
    cout << "nhap cccd: ";
    cin >> cccd;
    cout << "nhpa so ban withdraw: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i].addwithdraw();
    }
}
void customer ::output()
{
    cout << "=======thong tin khach hang=======" << endl;
    cout << "stt: " << id << endl;
    cout << "ho va ten: " << name << endl;
    cout << "so cccd: " << cccd << endl;
}

int main()
{
    customer a;
    a.input();
    a.output();
}