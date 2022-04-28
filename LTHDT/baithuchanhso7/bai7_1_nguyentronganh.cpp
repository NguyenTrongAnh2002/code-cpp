#include <iostream>
#include <fstream>

using namespace std;

class TAMGIAC
{
private:
    float a, b, c;

public:
    float CV()
    {
        return (a + b + c);
    }
    friend istream &operator>>(istream &in, TAMGIAC &Q)
    {
        cout << "nhap 3 canh cua tam giac: ";
        in >> Q.a >> Q.b >> Q.c;
        return in;
    }
    friend ostream &operator<<(ostream &out, TAMGIAC Q)
    {
        out << "a= " << Q.a << endl;
        out << "b= " << Q.b << endl;
        out << "c= " << Q.c << endl;
        return out;
    }
};
int main()
{
    TAMGIAC P, Q;
    cout << "nhap thong tin tam giac P: " << endl;
    cin >> P;
    cout << P;
    cout << "nhap thong tin tam giac Q: " << endl;
    cin >> Q;
    cout << Q;
    cout << "\nChu vi tam giac P la: " << P.CV() << endl;
    cout << "\nChu vi tam giac Q la: " << Q.CV() << endl;
    ofstream f("INOUT.txt");
    f << "tam giac P:\n " << P << endl;
    f << "tam giac Q:\n " << Q << endl;
    f << "Chu vi tam giac P: " << P.CV() << endl;
    f << "Chu vi tam giac Q: " << Q.CV() << endl;
    f.close();
}