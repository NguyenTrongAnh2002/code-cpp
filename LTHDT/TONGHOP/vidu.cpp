#include <iostream>
#include <string.h>
using namespace std;

class HS{
	private :
		char hoten[50];
		char ngsinh[20];
		char gioitinh[5];
		float dtb;
		char xeploai[10];
	public :
		char *gethoten(){
			return hoten;
		}
		void sethoten(char *ht){
			strcpy(hoten,ht);
		}
		float getdtb(){
			return dtb;
		}
		void setdtb(float d1){
			dtb=d1;
		}
};
int main(){
	HS hs1;
	hs1.sethoten("nguyen trong anh");
	cout<<"ho ten la: "<<hs1.gethoten()<<endl;
	hs1.setdtb(9.5);
	cout<<"diem trung binh: "<<hs1.getdtb();
	HS hs2;
	hs2.sethoten("\nnguyen van b");
	cout<<"ho ten la: "<<hs2.gethoten()<<endl;
	hs2.setdtb(9);
	cout<<"diem trung binh: "<<hs2.getdtb();
}
