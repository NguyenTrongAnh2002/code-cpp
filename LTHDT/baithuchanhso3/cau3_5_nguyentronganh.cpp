#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class NHANSU;
class DATE{
    private:
       int d,m,y;
    public:
       void nhap();
       void xuat();
    friend class NHANSU;
    friend void sapxepten(NHANSU *ns, int n);
};
class NHANSU{
    private:
       char hoten[30];
       char sochungminh[20];
       DATE ngaysinh;
    public:
       void nhap(){
           cout<<"nhap ho ten: ";fflush(stdin);gets(hoten);
           cout<<"nhap so chung minh nhan dan: ";fflush(stdin);gets(sochungminh);
           cout<<"nhap ngay sinh: ";cin>>ngaysinh.d>>ngaysinh.m>>ngaysinh.y;
       }
       void xuat(){
           cout<<left<<setw(30)<<hoten<<setw(30)<<sochungminh<<setw(1)<<ngaysinh.d<<"/"<<ngaysinh.m<<"/"<<ngaysinh.y<<endl;
       }
    friend void sapxepten(NHANSU *ns, int n);
};
void nhapds(NHANSU *&ns,int &n){
    cout<<"nhap so luong nhan su: ";cin>>n;
    ns= new NHANSU[n];
    for(int i=0;i<n;i++){
        cout<<"nhap thong tin nhan su thu "<<i+1<<endl;
        ns[i].nhap();
    }
}
void xuatds(NHANSU *ns, int n){
    cout<<left<<setw(30)<<"ho ten"<<setw(30)<<"so chung minh"<<setw(20)<<"ngay sinh"<<endl;
    for(int i=0;i<n;i++){
        ns[i].xuat();
    }
}
void sapxepten(NHANSU *ns, int n){
    for(int i=0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(ns[i].hoten,ns[j].hoten)>0){
                swap(ns[i].hoten,ns[j].hoten);
            }
        }
    }
}
int main(){
    NHANSU *ns;
    int n;
    cout<<"\n\n\t------nhap thong tin--------"<<endl;
    nhapds(ns,n);
    sapxepten(ns,n);
    cout<<"\n\n\t------danh sach nhan su--------"<<endl;
    xuatds(ns,n);
}
