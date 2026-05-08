#include "NhanVien.h"
#include <iostream>
#include <iomanip>
using namespace std;

NhanVien::NhanVien() {
    hoTen = "";
    ngay = thang = nam = 0;
    luong = 0;
}
NhanVien::~NhanVien() {

}
void NhanVien::nhap() {
    cin.ignore();
    cout << "Nhap ho va ten nhan vien: ";
    getline(cin, hoTen);
    cout << "\n";
    cout << "Nhap ngay sinh nhan vien (dd/mm/yy): ";
    cin >> ngay >> thang >> nam;
    cout << "\n"; 
}
void NhanVien::xuat() {
    cout << "Ho ten: " << hoTen << " . Ngay sinh " << ngay << "/" << thang << "/" << nam << ". Luong: " << fixed << setprecision(0) << luong << endl;
}
int NhanVien:: getAge() {
    return 2026 - this->nam;
}
double NhanVien:: getLuong() {
    return this->luong;
}
void NVSanXuat:: nhap() {
    NhanVien::nhap();
    cout << "Nhap luong co ban: "; cin >> luongCanBan;
    cout << "\n" << "Nhap so san pham da lam: " << soSanPham;
    cin >> soSanPham;
}
void NVSanXuat:: xuat() {
    NhanVien::xuat();
}
void NVSanXuat:: tinhLuong() {
    this->luong = luongCanBan + soSanPham * 5000;
}
void NVVanPhong:: nhap() {
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: "; 
    cin >> soNgayLamViec;
    cout << '\n';
}
void NVVanPhong:: tinhLuong() {
    this->luong = soNgayLamViec * 100000;
}
void NVVanPhong:: xuat() {
    NhanVien:: xuat();
}