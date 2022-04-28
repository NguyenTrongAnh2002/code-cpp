#include <iostream>

using namespace std;

class HANG;
class NSX{
    private:
       int mansx;
       char tennsx[20];
       char dcnsx[20];
    friend class HANG;
};
class HANG{
    private:
       int mahang;
       char tenhang[20];
       long dongia;
       long trongluong;
       NSX x;
    public:
       void nhap(){
           cout<<"nhap ma san xuat: "; cin>>x.mansx;
           cout<<"nhap ten nha san xuat: "; fflush(stdin);gets(x.tennsx);
           cout<<"nhap dia chi nha san xuat: "; fflush(stdin);gets(x.dcnsx);
           cout<<"nhap ma hang: "; cin>>mahang;
           cout<<"nhap ten hang: "; fflush(stdin);gets(tenhang);
           cout<<"nhap don gia: "; cin>>dongia;
           cout<<"nhap trong luong: "; cin>>trongluong;
       }
        void xuat(){
           cout<<"\n\n\t------thong tin mat hang---------\n"<<endl;
           cout<<"ma san xuat: "<<x.mansx<<endl;
           cout<<"ten nha san xuat: "<<x.tennsx<<endl;
           cout<<"dia chi nha san xuat: "<<x.dcnsx<<endl;
           cout<<"ma hang: "<<mahang<<endl;
           cout<<"ten hang: "<<tenhang<<endl;
           cout<<"don gia: "<<dongia<<endl;
           cout<<"trong luong: "<<trongluong<<endl;
        }
};
int main(){
    HANG a;
    cout<<"\n\n\t------nhap thong tin-----\n"<<endl;
    a.nhap();
    a.xuat();
}