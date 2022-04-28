#include <iostream>
#include <math.h>

using namespace std;

class Mangnguyen{
    private:
       int a[20];
       int n;
    public:
       void nhap(){
           cout<<"nhap so phan tu: "; cin>>n;
           for (int i = 0; i < n; i++)
           {
               cout<<"a["<<i+1<<"]= "; cin>>a[i];
           }
           
       }
       void xuat(){
           cout<<"\n\n\t\t--------danh sach mang la---------"<<endl;
           for(int i=0; i<n; i++){
               cout<<a[i]<<" ";
           }
       }
       float phantumax(){
           int max = a[0];
           for(int i=0; i<n; i++){
               if(a[i]>max){
                   max = a[i];
               }
           }
           return max;
       }
       float phantumin(){
           int min = a[0];
           for(int i=0; i<n; i++){
               if(a[i]<min){
                   min=a[i];
               }
           }
           return min;
       }
};

int main(){
    Mangnguyen a;
    a.nhap();
    a.xuat();
    cout<<"\nphan tu lon nhat trong mang la: "<<a.phantumax();
    cout<<"\nphan tu nho nhat trong mang la: "<<a.phantumin();
}