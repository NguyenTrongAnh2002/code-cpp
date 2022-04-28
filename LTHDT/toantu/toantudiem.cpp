#include <iostream>

using namespace std;

class DIEM{
    private:
       float x,y,z;
    public:
       DIEM(){
           x=0; y=0; z=0;
       }
       DIEM(float x1,float y1,float z1){
           x=x1;
           y=y1;
           z=z1;
       }
       DIEM operator+(DIEM B){
           DIEM T;
           T.x= x + B.x;
           T.y= y+ B.y;
           T.z= z+ B.z;
           return T;
       }
       DIEM operator-(DIEM B){
           DIEM H;
           H.x= x- B.x;
           H.y= y- B.y;
           H.z= z- B.z;
           return H;
       }
       friend istream& operator>>(istream& in, DIEM &B){
           in>>B.x>>B.y>>B.z;
             return in;
       }
       friend ostream& operator<<(ostream& out, DIEM B){
           out<<B.x<<", "<<B.y<<", "<<B.z<<endl;
              return out;
       }
};
int main(){
    DIEM A(1,3,5);
    DIEM T,H,B;
    cout<<"nhap diem b: ";cin>>B;
    T= A+B;
    H=A-B;
    cout<<"tong la: "<<T;
    cout<<"hieu la: "<<H;
}