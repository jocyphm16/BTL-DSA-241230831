#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

// ========================== CLASS SINHVIEN ==========================
class SinhVien {
private:
    string hoTen;
    string queQuan;
    string ngaySinh;
    int tienTro;

public:
    SinhVien() {}
    SinhVien(string h, string q, string n, int tt = 0)
        : hoTen{h}, queQuan{q}, ngaySinh{n}, tienTro{tt} {}

    void setTienTro(int tt) {
        tienTro = tt;
        return;
    }

    string getTen() {
        return hoTen;
    }

    friend ostream& operator<<(ostream& out, const SinhVien& sv) {
        out << "Ho ten: " << sv.hoTen << ", que quan: " << sv.queQuan
            << ", ngay sinh: " << sv.ngaySinh << ", tien tro: " << sv.tienTro << "d\n";
        return out;
    }

    friend istream& operator>>(istream& in, SinhVien& sv) {
        cout << "Nhap ho ten: ";
        getline(in >> ws, sv.hoTen);

        cout << "Nhap que quan: ";
        getline(in >> ws, sv.queQuan);

        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(in >> ws, sv.ngaySinh);

        return in;
    }


    bool operator<(const SinhVien& b) const {
        return hoTen < b.hoTen;
    }

    bool operator>(const SinhVien& b) const {
        return (hoTen.compare(b.hoTen) > 0);
    }

    bool operator==(const SinhVien& b) const {
        return (hoTen.compare(b.hoTen) == 0);
    }

    bool operator!=(const SinhVien& b) const {
        return (hoTen.compare(b.hoTen) != 0);
    }
};

// ========================== CLASS DANHSACHSINHVIEN ==========================
class DanhSachSinhVien {
private:
    int tienPhong;
    int soSinhVien;
    list<SinhVien> ds;

public:
    DanhSachSinhVien() {}
    DanhSachSinhVien(int tp, int ssv) : tienPhong{tp}, soSinhVien{ssv} {}

    void nhapDanhSachSinhVien() {
        for (int i = 0; i < soSinhVien; i++) {
            SinhVien temp;
            cin >> temp;
            temp.setTienTro(ceil((double)tienPhong / soSinhVien));
            ds.push_back(temp);
        }
        return;
    }

    void xuatDanhSachSinhVien() {
        if (soSinhVien == 0)
            cout << "Phong trong\n";
        else {
            for (auto& sv : ds) {
                cout << sv;
            }
        }
        return;
    }

    void xuatThongTinChung(int soPhong) {
        cout << "So phong: " << soPhong << ", tien phong: " << tienPhong
             << ", so sinh vien: " << soSinhVien << "\n";
        return;
    }

    list<list<SinhVien>::iterator> timTheoTen() {
        string ten;
        cout << "Nhap ten sinh vien: ";
        getline(cin >> ws, ten);
        list<list<SinhVien>::iterator> res{};
        list<SinhVien>::iterator found = ds.begin();
        while (found != ds.end()) {
            found = find_if(found, ds.end(), [&ten](SinhVien& a) {
                return a.getTen().find(ten) != string::npos;
            });
            if (found != ds.end()) {
                res.push_back(found);
                found++;
            }
        }
        return res;
    }

    void hienThiKetQuaTim() {
        list<list<SinhVien>::iterator> res = timTheoTen();
        for (list<SinhVien>::iterator it : res) {
            cout << *it;
        }
        return;
    }

    void xoaTheoTen() {
        if (soSinhVien == 0) {
            cout << "Phong trong\n";
            return;
        }
        list<list<SinhVien>::iterator> res = timTheoTen();
        if (res.empty()) {
            cout << "Khong tim thay sinh vien\n";
            return;
        }
        while (!res.empty()) {
            ds.erase(res.back());
            res.pop_back();
            soSinhVien--;
        }
        cout << "Xoa thanh cong\n";
        return;
    }

    void themSinhVien() {
        cout << "Nhap thong tin sinh vien:\n";
        SinhVien temp;
        cin >> temp;
        temp.setTienTro(tienPhong / soSinhVien);
        ds.push_back(temp);
        soSinhVien++;
        return;
    }

    void sapXepTheoTen() {
        ds.sort(); 
        cout << "Da sap xep danh sach sinh vien theo ten (A - Z).\n";
    }
};

// ========================== CLASS APP ==========================
class App {
private:
    list<DanhSachSinhVien> nhaTro;
    int soPhongTro;
    const int soChucNangNhaTro = 5;
    const int soChucNangPhongTro = 7;

public:
    App() {}

    void khoiTao() {
        cout << "Nhap so phong tro: ";
        cin >> soPhongTro;
        cout << "-HE THONG QUAN LY DAY NHA TRO-\n";
        for (int i = 0; i < soPhongTro; i++) {
            int tp{}, ssv{};
            cout << "Phong " << i + 1 << ":\n";
            cout << "Nhap tien phong: ";
            cin >> tp;
            cout << "Nhap so sinh vien: ";
            cin >> ssv;
            cin.ignore();
            DanhSachSinhVien temp{tp, ssv};
            cout << "Nhap danh sach sinh vien:\n";
            temp.nhapDanhSachSinhVien();
            nhaTro.push_back(temp);
        }
        return;
    }

    void themPhong() {
        int tp{}, ssv{};
        cout << "Nhap tien phong: ";
        cin >> tp;
        cout << "Nhap so sinh vien: ";
        cin >> ssv;
        DanhSachSinhVien temp{tp, ssv};
        cout << "Nhap danh sach sinh vien:\n";
        temp.nhapDanhSachSinhVien();
        nhaTro.push_back(temp);
        soPhongTro++;
        return;
    }

    void xoaPhong() {
        int num;
        cout << "Nhap so phong can xoa: ";
        cin >> num;
        int check = 0;
        int i = 1;
        for (list<DanhSachSinhVien>::iterator it = nhaTro.begin(); it != nhaTro.end(); it++, i++) {
            if (i == num) {
                nhaTro.erase(it);
                soPhongTro--;
                cout << "Xoa thanh cong phong " << num << '\n';
                check = 1;
                break;
            }
        }
        if (!check) {
            cout << "Phong khong ton tai\n";
        }
        return;
    }

    void xuatDanhSachPhongTro() {
        if (soPhongTro == 0)
            cout << "Hien khong co phong nao trong du lieu, vui long them it nhat 1 phong\n";
        else {
            int i = 1;
            for (list<DanhSachSinhVien>::iterator it = nhaTro.begin(); it != nhaTro.end(); it++, i++) {
                it->xuatThongTinChung(i);
            }
        }
        return;
    }

    void chonChucNangPhongTro(int input, int sp) {
        int check = 0;
        list<DanhSachSinhVien>::iterator phong{};
        int i = 1;
        for (list<DanhSachSinhVien>::iterator it = nhaTro.begin(); it != nhaTro.end(); it++, i++) {
            if (i == sp) {
                phong = it;
                check = 1;
                break;
            }
        }
        if (!check) {
            cout << "Phong khong ton tai\n";
            return;
        }
        switch (input) {
        case 1:
            phong->nhapDanhSachSinhVien();
            return;
        case 2:
            phong->xuatDanhSachSinhVien();
            return;
        case 3:
            phong->hienThiKetQuaTim();
            return;
        case 4:
            phong->xoaTheoTen();
            return;
        case 5:
            phong->themSinhVien();
            return;
        case 6:
            phong->sapXepTheoTen();
            phong->xuatDanhSachSinhVien(); 
            return;

        }
        return;
    }

    void quanLyPhongTro() {
        int soPhong{};
        cout << "Nhap so phong can chon: ";
        cin >> soPhong;
        int input{};
        while (true) {
            cout << "-HE THONG QUAN LY PHONG TRO-\n";
            cout << "1. Nhap danh sach sinh vien\n";
            cout << "2. Xuat danh sach sinh vien\n";
            cout << "3. Tim sinh vien theo ten\n";
            cout << "4. Xoa sinh vien theo ten\n";
            cout << "5. Them sinh vien vao phong\n";
            cout << "6. Sap xep sinh vien theo thu tu A - Z\n";
            cout << "7. Quay lai\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Vui long nhap mot so tu 1 den " << soChucNangPhongTro << "\n";
                continue;
            }
            if (input < 1 || input > soChucNangPhongTro) {
                cout << "Lua chon khong hop le, vui long nhap lai: \n";
                continue;
            }
            if (input == soChucNangPhongTro) {
                break;
            } else {
                chonChucNangPhongTro(input, soPhong);
            }
        }
        return;
    }

    void chonChucNangNhaTro(int input) {
        switch (input) {
        case 1:
            xuatDanhSachPhongTro();
            return;
        case 2:
            themPhong();
            return;
        case 3:
            xoaPhong();
            return;
        case 4:
            quanLyPhongTro();
            return;
        }
        return;
    }

    void quanLyNhaTro() {
        int input{};
        while (true) {
            cout << "-HE THONG QUAN LY DAY NHA TRO-\n";
            cout << "1. Xuat danh sach phong tro\n";
            cout << "2. Them phong tro\n";
            cout << "3. Xoa phong tro\n";
            cout << "4. Quan ly phong tro\n";
            cout << "5. Thoat\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //xoa bo nho rac
                cout << "Vui long nhap mot so tu 1 den " << soChucNangNhaTro << "\n";
                continue;
            }
            if (input < 1 || input > soChucNangNhaTro) {
                cout << "Lua chon khong hop le, vui long nhap lai: \n";
                continue;
            }
            if (input == soChucNangNhaTro) {
                cout << "Hen gap lai\n";
                break;
            } else {
                chonChucNangNhaTro(input);
            }
        }
        return;
    }

    void khoiDong() {
        khoiTao();
        quanLyNhaTro();
        return;
    }
};

// ========================== MAIN ==========================
int main() {
    App app;
    app.khoiDong();
    return 0;
}
