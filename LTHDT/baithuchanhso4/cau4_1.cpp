#include <iostream>
#include <iomanip>

using namespace std;

class SINHVIEN{
    private:
       char Masv[10];
       char hoten[20];
       float dtoan;
       float dly;
       float dhoa;
    public:
       void nhap(){
           cout<<"nhap ma sinh vien: ";fflush(stdin);gets(Masv);
           cout<<"nhap ho ten sinh vien: ";fflush(stdin);gets(hoten);
           cout<<"nhap diem toan: "; cin>>dtoan;
           cout<<"nhap diem ly: "; cin>>dly;
           cout<<"nhap diem hoa: "; cin>>dhoa;
       }
       long tongdiem(){
           return dtoan+dly+dhoa;
       }
       void xuat(){
           cout<<left<<setw(20)<<Masv<<setw(20)<<hoten<<setw(20)<<dtoan<<setw(20)<<dly<<setw(20)<<dhoa<<setw(20)<<tongdiem()<<endl;
       }
       friend void sapxep(SINHVIEN *sv,int n);
};
void nhapds(SINHVIEN *&sv, int &n){
    cout<<"nhap so sinh vien: "; cin>>n;
    sv=new SINHVIEN[n];
    for(int i=0;i<n;i++){
        cout<<"nhap sinh vien thu "<<i+1<<endl;
        sv[i].nhap();
    }
}
void xuatds(SINHVIEN *sv, int n){
    cout<<left<<setw(20)<<"ma sinh vien"<<setw(20)<<"ho ten"<<setw(20)<<"diem toan"<<setw(20)<<"diem ly"<<setw(20)<<"diem hoa"<<setw(20)<<"tong diem"<<endl;
    for(int i=0;i<n;i++){
        sv[i].xuat();
    }
}
void sapxep(SINHVIEN *sv,int n){
    for(int i=0;i<n-1;i++){
        for(int j=n+1;j<n;j++){
            if(sv[i].tongdiem()>sv[j].tongdiem()){
                swap(sv[i],sv[j]);
            }
        }
    }
}
int main(){
    SINHVIEN *sv;
    int n;
    cout<<"\n\n------nhap thong tin-------"<<endl;
    nhapds(sv,n);
    sapxep(sv,n);
    cout<<"\n---------danh sach sinh vien---------"<<endl;
    xuatds(sv,n);
}
