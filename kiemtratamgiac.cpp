#include <iostream>
#include<cmath>
using namespace std;
class Diem{
	friend void Nhap(Diem&);
 	friend void Xuat(Diem);
 	friend float TinhKhoangCach2Diem(Diem,Diem);
	private:
		int x,y;
};
 class LopTamGiac{
 	private:
 		Diem a,b,c;
 		float DoDaiCanh1,DoDaiCanh2,DoDaiCanh3;
 	public:
 		void NhapDinhTamGiac();
 		void XuatDinhTamGiac();
 		void KhoangCachCacDinh();
 		void NhapTamGiac();
 		void KiemTraCacTinhChatTamGiac();
 		float TinhChuVi();
 		float TinhDienTich();
 };
 void LopTamGiac::KiemTraCacTinhChatTamGiac(){
        if ((DoDaiCanh1 + DoDaiCanh2 > DoDaiCanh3) && (DoDaiCanh1 + DoDaiCanh3 > DoDaiCanh2) && (DoDaiCanh2 + DoDaiCanh3 > DoDaiCanh1) &&
                (DoDaiCanh1 > 0) && (DoDaiCanh2 > 0) && (DoDaiCanh3 > 0)) {
            if ((DoDaiCanh1 == DoDaiCanh2) && (DoDaiCanh2 == DoDaiCanh3)) {
                cout<<"Tam giac deu!";
            } else if ((DoDaiCanh1 == DoDaiCanh2) || (DoDaiCanh1 == DoDaiCanh3) || DoDaiCanh2 == DoDaiCanh3) {
               	cout<<"Tam giac can!";
            } else if ((DoDaiCanh1 * DoDaiCanh1 == DoDaiCanh2 * DoDaiCanh2 + DoDaiCanh3 * DoDaiCanh3) ||
                    (DoDaiCanh2 * DoDaiCanh2 == DoDaiCanh1 * DoDaiCanh1 + DoDaiCanh3 * DoDaiCanh3) ||
                    (DoDaiCanh3 * DoDaiCanh3 == DoDaiCanh1 * DoDaiCanh1 + DoDaiCanh2 * DoDaiCanh2)) {
                cout<<"Tam giac vuong!";
            } else if (((DoDaiCanh1 * DoDaiCanh1 + DoDaiCanh2 *DoDaiCanh2 == DoDaiCanh3 * DoDaiCanh3) && (DoDaiCanh1 == DoDaiCanh2)) ||
                    ((DoDaiCanh1 * DoDaiCanh1 + DoDaiCanh3 * DoDaiCanh3 == DoDaiCanh2 * DoDaiCanh2) && (DoDaiCanh1 == DoDaiCanh3)) ||
                    ((DoDaiCanh2 * DoDaiCanh2 + DoDaiCanh3 * DoDaiCanh3 == DoDaiCanh1 * DoDaiCanh1) && (DoDaiCanh2 == DoDaiCanh3))) {
                cout<<"Tam giac vuong can!";
            } else {
                cout<<"Tam giac thuong!";
            }
        } else {
           cout<<"3 canh cua tam giac khong thoa man dieu kien lap thanh tam giac!";
		}
}
float LopTamGiac::TinhChuVi(){
	return 	DoDaiCanh1+DoDaiCanh2+DoDaiCanh3;
}
float LopTamGiac::TinhDienTich(){
	float p=(DoDaiCanh1+DoDaiCanh2+DoDaiCanh3)/2;
	return 	sqrt(p*(p-DoDaiCanh1)*(p-DoDaiCanh2)*(p-DoDaiCanh3));
}
void Nhap(Diem &a){
		cout<<"Nhap diem x: ";
		cin>>a.x;
		cout<<"Nhap diem y: ";
		cin>>a.y;
}
void Xuat(Diem a){
		cout<<"("<<a.x<<","<<a.y<<")"<<endl;
}
float TinhKhoangCach2Diem(Diem d1,Diem d2){
	float kc;
	kc=sqrt(double(d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y));
	return kc;
}
void LopTamGiac::NhapDinhTamGiac(){
	cout<<"\tNhap dinh 1\n";
	Nhap(a);
	cout<<"\tNhap dinh 2\n";
	Nhap(b);
	cout<<"\tNhap dinh 3\n";
	Nhap(c);
}
void LopTamGiac::XuatDinhTamGiac(){
	cout<<"Dinh thu 1: ";
    Xuat(a);
    cout<<"Dinh thu 2: ";
    Xuat(b);
    cout<<"Dinh thu 3: ";
    Xuat(c);
}
void LopTamGiac::KhoangCachCacDinh(){
	cout<<"Khoang cach cua dinh 1 va dinh 2: "<<TinhKhoangCach2Diem(a,b)<<endl;
    cout<<"Khoang cach cua dinh 1 va dinh 3: "<<TinhKhoangCach2Diem(a,c)<<endl;
    cout<<"Khoang cach cua dinh 2 va dinh 3: "<<TinhKhoangCach2Diem(b,c)<<endl;	
}
void LopTamGiac::NhapTamGiac(){
	cout<<"Nhap canh thu 1: ";
	cin>>DoDaiCanh1;
	cout<<"Nhap canh thu 2: ";
	cin>>DoDaiCanh2;
	cout<<"Nhap canh thu 3: ";
	cin>>DoDaiCanh3;
}
int main()
{
	LopTamGiac a;
	cout<<"Nhap 3 dinh cua tam giac\n";
	a.NhapDinhTamGiac();
	cout<<"3 dinh cua tam giac\n";
	a.XuatDinhTamGiac();
	a.KhoangCachCacDinh();
    a.NhapTamGiac();
    a.KiemTraCacTinhChatTamGiac();
    cout<<"\nChu vi cua tam giac la: "<<a.TinhChuVi()<<endl;
    cout<<"Dien tich cua tam giac la: "<<a.TinhDienTich()<<endl;
    return 0;
}
