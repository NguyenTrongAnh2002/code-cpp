#include <iostream>
using namespace std;


class PhanSo{
private: 
int tuSo, mauSo;
public:
PhanSo(){
this->tuSo = 0; this->mauSo = 1;
}
PhanSo(int tuSo, int mauSo) {
this->tuSo = tuSo; this->mauSo = mauSo;
}
void xuat(){
cout<<tuSo<<"/"<<mauSo<<endl;
}
};
int main(){
PhanSo p1, p2(2,5);
cout<<"Phan so: p1 = "; p1.xuat();
cout<<"Phan so: p2 = "; p2.xuat();
}
