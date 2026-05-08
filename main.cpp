#include "NhanVien.h" 
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
bool opAge(int a, int b) {
    return a > b;
}
bool opLuong(double a, double b) {
    return a < b;
}

int main() {
    vector<NhanVien*> ds;
    int n1, n2;
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n1;
    cout << "\n";
    for (int i = 0; i < n1; i++) {
        NhanVien* nv = new NVSanXuat();
        cout << "Nhap nhan vien san xuat thu " << i + 1 << ": " << endl;
        nv->nhap();
        nv->tinhLuong();
        ds.push_back(nv);
    }
    cout << "\nNhap so luong nhan vien van phong: ";
    cin >> n2;
    cout << '\n';
    for (int i = 0; i < n2; i++) {
        NhanVien* nv = new NVVanPhong();
        cout << "Nhap nhan vien van phong thu " << i + 1 << ": \n";
        nv->nhap();
        nv->tinhLuong();
        ds.push_back(nv);
    }

    cout << "\nDanh sach nhan vien\n";
    int stt = 0;
    for (NhanVien* nv : ds) {
        stt++;
        cout << "STT " << stt << ": " ;
        nv->xuat();
    }
    double tongLuong = 0;

    for (NhanVien* nv : ds) {
        tongLuong += nv->getLuong();
    }

    cout << "\nTong luong cong ty phai tra: " << tongLuong << "\n";

    NVSanXuat* minSX = nullptr;

    for (NhanVien* nv: ds) {
        NVSanXuat* sx = dynamic_cast<NVSanXuat*> (nv);

        if (sx != nullptr) {
            if (minSX == nullptr || sx->getLuong() < minSX->getLuong()) {
                minSX = sx;
            }
        }
    }
    if (!(minSX == nullptr)){
        cout << "\nNhan vien san xuat co luong thap nhat la: ";
        minSX->xuat();
    }

    NVVanPhong* maxAge = nullptr;

    for (NhanVien* nv: ds) {
        NVVanPhong* vp = dynamic_cast<NVVanPhong*>(nv);
        if (nv != nullptr) {
            if(maxAge == nullptr || maxAge->getAge() < vp->getAge()) {
                maxAge = vp;
            }
        }
    }
    if (!(maxAge == nullptr)) {
        cout << "\nNhan vien van phong co tuoi cao nhat la : ";
        maxAge->xuat();
    }
    for (NhanVien* nv: ds) {
        delete nv;
    }
}