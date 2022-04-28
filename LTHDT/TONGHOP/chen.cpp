#include <iostream>
#include <iomanip>
using namespace std;

class SinhVien {
    private:
       char maSv[40], hoTen[50], ngaySinh[30], gioiTinh[10], nganhHoc[40];
       float diemTongKet;
    public:
       void Nhap();
       void Xuat();
    friend void svDiemLonNhat(SinhVien sv[], int n);
    friend void chenSV(SinhVien *&sv, int &n, int k);
};

void SinhVien::Nhap(){
    cout<<"Nhap ma sinh vien: "; fflush(stdin); gets(maSv);
    cout<<"Nhap ho ten: "; fflush(stdin); gets(hoTen);
    cout<<"Nhap ngay sinh: "; fflush(stdin); gets(ngaySinh);
    cout<<"Nhap gioi tinh: "; fflush(stdin); gets(gioiTinh);
    cout<<"Nhap nganh hoc: "; fflush(stdin); gets(nganhHoc);
    cout<<"Nhap diem tong ket: "; cin>>diemTongKet;
}
void SinhVien::Xuat(){
    cout<<setw(15)<<left<<maSv<<setw(15)<<hoTen<<setw(15)<<ngaySinh<<setw(15)<<gioiTinh<<setw(15)<<nganhHoc<<setw(15)<<diemTongKet<<endl;
}

void svDiemLonNhat(SinhVien sv[], int n){
    cout<<"\n\n\t\t ---> Danh Sach Sinh Vien Co Diem Lon Nhat ---"<<endl;
    float max = sv[0].diemTongKet;
    for(int i = 1; i < n; i++){
        if(sv[i].diemTongKet > max){
            max = sv[i].diemTongKet;
        }
    }
    cout<<setw(15)<<left<<"Ma sinh vien"<<setw(15)<<"Ho ten"<<setw(15)<<"Ngay sinh"<<setw(15)<<"Gioi tinh"<<setw(15)<<"Nganh hoc"<<setw(15)<<"Diem tong ket"<<endl;
    for(int i = 0; i < n; i++){
        if(sv[i].diemTongKet == max){
            sv[i].Xuat();
        }
    }
}
void chenSV(SinhVien *&sv, int &n)
{
     int k;
    do {
        cout<<"Nhap vi tri  muon chen: "; cin>>k;
    } while(k < 1 || k > n);
    cout<<"Nhap thong tin sinh vien muon chen vao: "<<endl;
    SinhVien temp;
    temp.Nhap();
    for(int i = n; i > k; i--){
        sv[i] = sv[i-1];
    }
    sv[k] = temp;
    n++;
}
void NhapDS(SinhVien *&sv,int &n)
{
    cout<<"Nhap so luong sinh vien: "; cin>>n;
    sv = new SinhVien[n];
    for(int i = 0; i < n; i++){
        cout<<"\n\t -> Nhap thong tin sinh vien thu "<<i+1<<endl;
        sv[i].Nhap();
    }
}
void XuatDS(SinhVien *sv, int n)
{
    cout<<setw(15)<<left<<"Ma sinh vien"<<setw(15)<<"Ho ten"<<setw(15)<<"Ngay sinh"<<setw(15)<<"Gioi tinh"<<setw(15)<<"Nganh hoc"<<setw(15)<<"Diem tong ket"<<endl;
    for(int i = 0; i < n; i++){
        sv[i].Xuat();
    }
}
int main()
{
    int n;
    SinhVien *sv;
    NhapDS(sv,n);
    cout<<"\n\t\t =========== Danh Sach Sinh Vien ==========="<<endl;
    XuatDS(sv,n);
    svDiemLonNhat(sv,n);
    chenSV(sv,n);
    cout<<"\n\n\t\t ---> Danh Sach Sinh Vien Sau Khi Chen  ---"<<endl;
    XuatDS(sv,n);
}
