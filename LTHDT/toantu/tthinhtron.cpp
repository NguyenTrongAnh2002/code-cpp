#include <iostream>

#define pi 3.1459
using namespace std;

class HINHTRON{
    private:
       float R;
    public:
       HINHTRON(){
          R=0;
       }
       HINHTRON(float R1){
           R=R1;
       }
       float DT(){
           return pi*R*R;
       }
       friend float operator +(HINHTRON P, HINHTRON Q){
           return P.DT()+Q.DT();
       }
       friend istream& operator>>(istream& in, HINHTRON &Q){
           in>>Q.R;
             return in;
       }
       friend ostream& operator<<(ostream& out, HINHTRON Q){
           out<<Q.R<<endl;
              return out;
       }
       friend bool operator>(HINHTRON P, HINHTRON Q){
           if(P.DT()>Q.DT()){
               return true;
           }else{
               return false;
           }
       }
};
int main(){
    HINHTRON P(6);
    HINHTRON Q;
    cout<<"nhap ban kinh: "; cin>>Q;
    cout<<"\ndien tich hinh tron P la: "<<P.DT()<<endl;
    cout<<"\ndien tich hinh tron Q la: "<<Q.DT()<<endl;
    cout<<"\nTONG dien tich hinh tron P va Q la: "<<Q.DT()+P.DT()<<endl;
    if(P.DT()>Q.DT()){
        cout<<"\ndien tich hinh P lon hon Q\n";
    }else{
        cout<<"\ndien tich hinh P nho hon Q\n";
    }
}