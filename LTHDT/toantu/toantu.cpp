#include <iostream>

using namespace std;

class PS{
    private:
       float TS,MS;
    public:
       void nhap();
       void xuat();
       PS operator + (PS y); // cong 2 phan so
       PS operator - (PS y); // tru 2 phan so
       PS operator - (); //doi dau 2 phan so
};
void PS::nhap(){
    cout<<"nhap tu so: "; cin>>TS;
    cout<<"nhap mau so: "; cin>>MS;
}
void PS::xuat(){
    cout<<TS<<"/"<<MS<<endl;
}
PS PS:: operator+(PS y){
    PS z;
    z.TS= TS*y.MS + MS*y.TS;
    z.MS= MS*y.MS;
    return z;
}
PS PS:: operator-(PS y){
    PS h;
    h.TS= TS*y.MS - MS*y.TS;
    h.MS= MS*y.MS;
    return h;
}
PS PS:: operator-(){
    PS z;
    z.TS= -TS;
    z.MS= MS;
    return z;
}
int main(){
    PS x,y;
    cout<<"nhap phan so thu nhat "<<endl;
    x.nhap();
    cout<<"nhap phan so thu hai "<<endl;
    y.nhap();
    PS z=x+y;
    PS h=x-y;
       z=-z;
    cout<<"cong 2 phan so "<<endl;
    z.xuat();
    cout<<"tru 2 phan so "<<endl;
    h.xuat();
}