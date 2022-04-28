#include <iostream>
#include <iomanip>

using namespace std;

class DoanhNghiep{
    private:
       char tenDN[20];
       char diachi[20];
       int sonv;
       long double doanhthu;
    public:
       void nhap(){
           cout<<"nhap ten doanh nghiep: ";fflush(stdin);gets(tenDN);
           cout<<"nhap dia chi: ";fflush(stdin);gets(diachi);
           cout<<"nhap so nhan vien: ";cin>>sonv;
           cout<<"nhap doanh thu: "; cin>>doanhthu;
       }
       void xuat(){
           cout<<setw(15)<<tenDN<<setw(15)<<diachi<<setw(15)<<sonv<<setw(15)<<doanhthu<<endl;
       }
};
void nhapds(DoanhNghiep *&dn, int &n){
    cout<<"nhap so doanh nghiep: ";cin>>n;
    dn= new DoanhNghiep[n];
    for(int i=0; i<n; i++){
        cout<<"nhap doanh nghiep thu "<<i+1<<endl;
        dn[i].nhap();
    }
}
void xuatds(DoanhNghiep *dn, int n){
    cout<<setw(15)<<"ten doanh nghiep"<<setw(15)<<"dia chi"<<setw(15)<<"so nhan vien"<<setw(15)<<"doanh thu"<<endl;
    for(int i=0; i<n; i++){
        dn[i].xuat();
    }
}
int main(){
    DoanhNghiep *dn;
    int n;
    nhapds(dn,n);
    cout<<"\n\n-------danh sach doanh nghiep-------\n\n";
    xuatds(dn,n);
}