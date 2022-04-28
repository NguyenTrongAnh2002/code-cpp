#include <iostream>
#include <math.h>

using namespace std;

class MangNguyen{
    private:
         int a[20];
         int n;
    public:
         void nhap(){
         	cout<<"nhap so phan tu cua mang: ";cin>>n;
            for(int i=0;i<n;i++){
              cout<<"a["<<i+1<<"]= ";cin>>a[i];
           }
		 }
         void xuat();
         void SapXep(){
         	int hoanvi;
         	for(int i=0; i<n; i++){
               for(int j=i+1; j<n; j++){
                  if(a[i]>a[j]){
                      hoanvi=a[i]; a[i]=a[j]; a[j]=hoanvi;
		              }
		       }
	      }
    }
};

void MangNguyen::xuat(){
    cout<<"mang da sap xep la: "<<endl;
    for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
    }
}
int main(){
    MangNguyen a;
    a.nhap();
    a.SapXep();
    a.xuat();
}
