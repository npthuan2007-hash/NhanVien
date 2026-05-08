#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    int ngay, thang, nam;
    double luong;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void nhap();
    virtual void tinhLuong() = 0;
    virtual void xuat();

    double getLuong();
    int getAge();
};

class NVSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;

public:
    void nhap();
    void tinhLuong();
    void xuat();
};

class NVVanPhong : public NhanVien {
private:
    int soNgayLamViec;

public:
    void nhap();
    void tinhLuong();
    void xuat();
};

#endif