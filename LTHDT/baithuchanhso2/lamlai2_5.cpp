#include <iomanip>
#include <iostream>

using namespace std;

class OTO{
    private:
       int maOT;
       long double giamua;
       int sonamsd;
       float khauhao;
       long double giathat(){
           return (giamua - giamua*khauhao/100);
       }
    public:
       void nhap(){
           cout<<"nhap ma o to: "; cin>>maOT;
           cout<<"nhap gia mua: "; cin>>giamua;
           cout<<"nhap so nam su dung: "; cin>>sonamsd;
           cout<<"nhap khau hao: "; cin>>khauhao;
       }
       void xuat(){
           cout<<setw(15)<<left<<maOT<<setw(15)<<giamua<<setw(25)<<sonamsd<<setw(15)<<khauhao<<setw(15)<<giathat()<<endl;
       }
};
void nhapds(OTO *&ot, int &n){
    cout<<"nhap so luong o to: ";cin>>n;
    ot= new OTO[n];
    for(int i=0; i<n; i++){
        cout<<"nhap o to thu "<<i+1<<endl;
        ot[i].nhap();
    }
}
void xuatds(OTO *ot, int n){
    cout<<setw(15)<<left<<"ma o to"<<setw(15)<<"gia mua"<<setw(25)<<"so nam su dung"<<setw(15)<<"khau hao(%)"<<setw(15)<<"gia that"<<endl;
    for(int i=0; i<n; i++){
        ot[i].xuat();
    }
}
int main(){
    OTO *ot;
    int n;
    nhapds(ot,n);
    cout<<"\n\t\t-----danh sach o to------\n"<<endl;
    xuatds(ot,n);
}