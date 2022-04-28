#include <iostream>

using namespace std;

class HANG;
class NSX{
    private:
       int mansx;
       char tennsx[20];
       char dcnsx[20];
    public:
       void nhap();
       void xuat();
    friend class HANG;
};
class HANG{
    private:
       int mahang;
       char tenhang[20];
       NSX x;
    public:
       void nhap(){
           cout<<"nhap ma san xuat: "; cin>>x.mansx;
           cout<<"nhap ten nha san xuat: "; fflush(stdin);gets(x.tennsx);
           cout<<"nhap ten nha san xuat: "; fflush(stdin);gets(x.dcnsx);
           cout<<"nhap ma hang: "; cin>>mahang;
           cout<<"nhap ten hang: "; fflush(stdin);gets(tenhang);
       }
        void xuat(){
           cout<<"\n\n\t------thong tin mat hang---------\n"<<endl;
           cout<<"nhap ma san xuat: "<<x.mansx<<endl;
           cout<<"nhap ten nha san xuat: "<<x.tennsx<<endl;
           cout<<"nhap ten nha san xuat: "<<x.dcnsx<<endl;
           cout<<"nhap ma hang: "<<mahang<<endl;
           cout<<"nhap ten hang: "<<tenhang<<endl;
        }
};
int main(){
    HANG a;
    cout<<"\n\n\t------nhap thong tin-----\n"<<endl;
    a.nhap();
    a.xuat();
}