#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Xehoi{
    private:
       char nhanhieu[10];
       char hangsx[15];
       char kieudang[10];
       char mau[10];
       char namsx[5];
       char xuatxu[15];
       long double giaban;
    public:
       void nhap(){
           cout<<"nhap nhan hieu xe: ";fflush(stdin);gets(nhanhieu);
           cout<<"nhap hang san xuat xe: ";fflush(stdin);gets(hangsx);
           cout<<"nhap kieu dang xe: ";fflush(stdin);gets(kieudang);
           cout<<"nhap mau xe: ";fflush(stdin);gets(mau);
           cout<<"nhap nam san xuat xe: ";fflush(stdin);gets(namsx);
           cout<<"nhap xuat xu xe: ";fflush(stdin);gets(xuatxu);
           cout<<"nhap gia ban xe: ";cin>>giaban;
       }
       void xuat(){
           cout<<setw(15)<<nhanhieu<<setw(15)<<hangsx<<setw(15)<<kieudang<<setw(15)<<mau<<setw(15)<<namsx<<setw(15)<<xuatxu<<setw(15)<<giaban<<endl;
       }
       friend void sapxepxe(Xehoi *xh, int n);
       friend void xetoyota(Xehoi *xh, int n);

};
void nhapds(Xehoi *&xh, int &n){
    cout<<"nhap so luong xe: "; cin>>n;
    xh= new Xehoi[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"nhap xe thu "<<i+1<<endl;
        xh[i].nhap();
    }
    
}
void xuatds(Xehoi *xh, int n){
     cout<<setw(15)<<"nhan hieu"<<setw(15)<<"hang sx"<<setw(15)<<"kieu dang"<<setw(15)<<"mau"<<setw(15)<<"nam sx"<<setw(15)<<"xuat xu"<<setw(15)<<"gia ban"<<endl;
     for (int i = 0; i < n; i++)
     {
        xh[i].xuat();
     }  
}
void sapxepxe(Xehoi *xh, int n){
    int hoanvi;
    for(int i=0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(xh[i].giaban>xh[j].giaban){
                hoanvi=xh[i].giaban;
                xh[i].giaban=xh[j].giaban;
                xh[j].giaban=hoanvi;
            }
        }
    }
}
void xetoyota(Xehoi *xh, int n){
    char a[10] = "toyota";
    cout<<"\n\n-----danh sach xe cua hang toyota-----\n"<<endl;
    cout<<setw(15)<<"nhan hieu"<<setw(15)<<"hang sx"<<setw(15)<<"kieu dang"<<setw(15)<<"mau"<<setw(15)<<"nam sx"<<setw(15)<<"xuat xu"<<setw(15)<<"gia ban"<<endl;
    for(int i=0; i<n;i++){
        if(strcmp(xh[i].hangsx, a)==0){
            xh[i].xuat();
        }
    } 
}
int main(){
    Xehoi *xh;
    int n;
    nhapds(xh,n);
    cout<<"\n\n------------danh sach xe hoi---------\n"<<endl;
    xuatds(xh,n);
    xetoyota(xh,n);
    sapxepxe(xh,n);
    cout<<"\n\n----------danh sach xe tang dan--------\n"<<endl;
    xuatds(xh,n);
    cout<<"\n\n\n";
}
