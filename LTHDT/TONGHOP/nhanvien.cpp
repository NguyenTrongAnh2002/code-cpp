#include <bits/stdc++.h>

using namespace std;
class NHANVIEN;
class DATE{
    public:
    int d,m,y;
    friend void xuattaichinh(NHANVIEN *nv, int n);
    friend void chenNV(NHANVIEN *&nv, int &n);
};
class PHONGBAN{
    public:
     int maPB;
     char tenPB[20];
     char truongphong[20];
     int sonv;
     friend void xuattaichinh(NHANVIEN *nv, int n);
     friend void chenNV(NHANVIEN *&nv, int &n);
     friend void xoaNV(NHANVIEN *nv, int &n);
};
class NHANVIEN{
    private:
       int maNV;
       char hoDEM[20];
       char ten[10];
       DATE ngaysinh;
       PHONGBAN phong;
    public:
       void nhap(){
           cout<<"nhap ma nhan vien: "; cin>>maNV;
           cout<<" nhap ho dem: "; fflush(stdin);gets(hoDEM);
           cout<<" nhap ten: "; fflush(stdin);gets(ten);
           cout<<" nhap ngay sinh: "; cin>>ngaysinh.d>>ngaysinh.m>>ngaysinh.y;
           cout<<" nhap ma phong ban: "; cin>>phong.maPB;
           cout<<" nhap ten phong ban: "; fflush(stdin);gets(phong.tenPB);
           cout<<" nhap ten truong phong: "; fflush(stdin);gets(phong.truongphong);
           cout<<" nhapso nhan vien: ";cin>>phong.sonv;
       }
       void xuat(){
           cout<<setw(5)<<maNV<<setw(15)<<hoDEM<<setw(10)<<ten<<setw(10)<<ngaysinh.d<<"/"<<ngaysinh.m<<"/"<<ngaysinh.y<<setw(15)<<phong.maPB<<setw(15)<<phong.tenPB<<setw(15)<<phong.truongphong<<endl;
       }
       friend void xuattaichinh(NHANVIEN *nv, int n);
       friend void sapxepten(NHANVIEN *nv, int n);
       friend void chenNV(NHANVIEN *&nv, int &n);
       friend void xoaNV(NHANVIEN *nv, int &n);
};
void nhapds(NHANVIEN *&nv,int &n){
    cout<<"nhap so nhan vien: "; cin>>n;
    nv = new NHANVIEN[n];
    for(int i=0;i<n;i++){
        cout<<"nhap nhan vien thu "<<i+1<<endl;
        nv[i].nhap();
    }
}
void xuatds(NHANVIEN *nv,int n){
     cout<<setw(5)<<"maNV"<<setw(15)<<"hoDEM"<<setw(10)<<"ten"<<setw(15)<<"ngay sinh"<<setw(15)<<"maPB"<<setw(15)<<"tenPB"<<setw(15)<<"truongphong"<<endl;
     for(int i=0;i<n;i++){
         nv[i].xuat();
     }
}
void xuattaichinh(NHANVIEN *nv, int n){
    cout<<setw(5)<<"maNV"<<setw(15)<<"hoDEM"<<setw(10)<<"ten"<<setw(15)<<"ngay sinh"<<setw(15)<<"maPB"<<setw(15)<<"tenPB"<<setw(15)<<"truongphong"<<endl;
    for(int i=0;i<n;i++){
        if(strcmp(nv[i].phong.tenPB,"tai chinh")==0){
            nv[i].xuat();
        }
    }
}
void sapxepten(NHANVIEN *nv, int n){
    for(int i=0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(nv[i].ten>nv[j].ten){
                swap(nv[i].ten,nv[j].ten);
            }
        }
    }
}
void chenNV(NHANVIEN *&nv, int &n)
{
     int k;
    do {
        cout<<"Nhap vi tri  muon chen: "; cin>>k;
    } while(k < 1 || k > n);
    cout<<"Nhap thong tin nhan vien muon chen vao: "<<endl;
    NHANVIEN nv1;
    nv1.nhap();
    for(int i = n; i > k; i--){
       nv[i] = nv[i-1];
    }
    nv[k] = nv1;
    n++;
}
void xoaNV(NHANVIEN *nv, int &n){
    for(int i=0;i<n;i++){
        while(nv[i].maNV==123){
            for(int j=i;j<n-1;j++){
                nv[j]=nv[j+1];
                n--;
            }
        }
    }
}
int main(){
    NHANVIEN *nv;
    int n;
    cout<<"---------nhap thong tin-----------"<<endl;
    nhapds(nv,n);
    cout<<"\n\n------------danh sach nhan vien---------\n"<<endl;
    xuatds(nv,n);
    sapxepten(nv,n);
    cout<<"\n--------danh sach ten tang dan-------"<<endl;
    xuatds(nv,n);
    cout<<"--------danh sach nhan vien thuoc phong tai chinh--------"<<endl;
    xuattaichinh(nv,n);
    chenNV(nv,n);
    cout<<"\n\n\t\t ---> Danh Sach nhan vien Sau Khi Chen  ---"<<endl;
    xuatds(nv,n); 
    xoaNV(nv,n);
    cout<<"\n\n\t\t ---> Danh Sach nhan vien Sau Khi xoa  ---"<<endl;
    xuatds(nv,n);
}
