#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class DATEOFBIRTH
{
    int date, month, year;

public:
    void input()
    {
        cout << "nhap ngay sinh: ";
        cin >> date;
        cout << "nhap thang sinh: ";
        cin >> month;
        cout << "nhap nam sinh: ";
        cin >> year;
    }
    void output()
    {
        cout << "ngay sinh: " << date << "/" << month << "/" << year << endl;
    }
};
class CUSTOMER
{
    int id;
    string name;
    string cccd;
    DATEOFBIRTH DATE;

public:
    void input()
    {
        cout << "nhap id: ";
        cin >> id;
        cin.ignore();
        cout << "nhap ten: ";
        getline(cin, name);
        cout << "nhap so cccd: ";
        getline(cin, cccd);
        DATE.input();
    }
    void output()
    {
        cout << "ID: " << id << endl;
        cout << "ten: " << name << endl;
        cout << "cccd: " << cccd << endl;
        DATE.output();
    }
};
class WITHDRAW
{
    string wd_num;
    float wd_money;
    string wd_note;

public:
    void addwithdraw()
    {
        cin.ignore();
        cout << "nhap wd_num: ";
        getline(cin, wd_num);
        cout << "nhap wd_money: ";
        cin >> wd_money;
        cin.ignore();
        cout << "nhap note: ";
        getline(cin, wd_note);
    }
    void displaywithdraw()
    {
        cout << "wd_num: " << wd_num << endl;
        cout << "wd_money: " << wd_money << endl;
        cout << "wd_note: " << wd_note << endl;
    }
};
class DEPOSIT
{
    string de_num;
    float de_money;
    string de_note;

public:
    void adddeposit()
    {
        cout << "nhap de_num: ";
        getline(cin, de_num);
        cout << "nhap de_money: ";
        cin >> de_money;
        cin.ignore();
        cout << "nhap note: ";
        getline(cin, de_note);
    }
    void displaydeposit()
    {
        cout << "de_num: " << de_num << endl;
        cout << "de_money: " << de_money << endl;
        cout << "de_note: " << de_note << endl;
    }
};
class ACCOUT : public CUSTOMER
{
private:
    string numac;
    float money;
    CUSTOMER CUS;
    vector<WITHDRAW> wd;
    WITHDRAW with;
    vector<DEPOSIT> de;
    DEPOSIT dep;
    int n;

public:
    void input()
    {
        CUS.input();
        cin.ignore();
        cout << "nhap numac: ";
        getline(cin, numac);
        cout << "nhap money: ";
        cin >> money;
        with.addwithdraw();
        dep.adddeposit();
    }
    void output()
    {
        CUS.output();
        cout << "numac: " << numac << endl;
        cout << "money: " << money << endl;
        with.displaywithdraw();
        dep.displaydeposit();
    }
};

int main()
{
    ACCOUT a[20];
    int n;
    cout << "nhap so luong khach hang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap khach hang thu " << i + 1 << endl;
        a[i].input();
    }
    cout << "======THONG TIN KHACH HANG======" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap khach hang thu " << i + 1 << endl;
        a[i].output();
    }
}