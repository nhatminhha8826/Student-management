#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Student {
    string name;
    float cpa;
    bool gender;     // true = Nam, false = Nữ
    string gmail;
};

void addStudent(map<int, Student> &ds) {
    int mssv;
    Student sv;

    cout << "Nhap MSSV: ";
    cin >> mssv;

    if (ds.count(mssv)) {
        cout << "MSSV da ton tai!\n";
        return;
    }

    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, sv.name);

    cout << "Nhap CPA: ";
    cin >> sv.cpa;

    cout << "Gioi tinh (1 = Nam, 0 = Nu): ";
    cin >> sv.gender;

    cin.ignore();
    cout << "Nhap Gmail: ";
    getline(cin, sv.gmail);

    ds[mssv] = sv;
    cout << "✔ Them thanh cong!\n";
}

void removeStudent(map<int, Student> &ds) {
    int mssv;
    cout << "Nhap MSSV can xoa: ";
    cin >> mssv;

    if (ds.erase(mssv)) {
        cout << "Xoa thanh cong!\n";
    } else {
        cout << "Khong tim thay MSSV!\n";
    }
}

void findStudent(map<int, Student> &ds) {
    int mssv;
    cout << "Nhap MSSV can tim: ";
    cin >> mssv;

    if (!ds.count(mssv)) {
        cout << "Khong ton tai MSSV\n";
        return;
    }

    Student sv = ds[mssv];
    cout << "\n--- THONG TIN SINH VIEN ---\n";
    cout << "MSSV: " << mssv << "\n";
    cout << "Ho ten: " << sv.name << "\n";
    cout << "CPA: " << sv.cpa << "\n";
    cout << "Gioi tinh: " << (sv.gender ? "Nam" : "Nu") << "\n";
    cout << "Gmail: " << sv.gmail << "\n";
}

void updateStudent(map<int, Student> &ds) {
    int mssv;
    cout << "Nhap MSSV can cap nhat: ";
    cin >> mssv;

    if (!ds.count(mssv)) {
        cout << "MSSV khong ton tai!\n";
        return;
    }

    Student &sv = ds[mssv];
    cin.ignore();

    cout << "Nhap ten moi (bo trong de giu nguyen): ";
    string tmp;
    getline(cin, tmp);
    if (!tmp.empty()) sv.name = tmp;

    cout << "Nhap CPA moi (-1 de giu nguyen): ";
    float cpa;
    cin >> cpa;
    if (cpa >= 0) sv.cpa = cpa;

    cout << "Nhap gioi tinh moi (1/0, -1 de giu nguyen): ";
    int gt;
    cin >> gt;
    if (gt == 0 || gt == 1) sv.gender = gt;

    cin.ignore();
    cout << "Nhap Gmail moi (bo trong de giu nguyen): ";
    getline(cin, tmp);
    if (!tmp.empty()) sv.gmail = tmp;

    cout << "✔ Cap nhat thanh cong!\n";
}

void printAll(const map<int, Student> &ds) {
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    for (auto &p : ds) {
        cout << "------------------------\n";
        cout << "MSSV: " << p.first << "\n";
        cout << "Ho ten: " << p.second.name << "\n";
        cout << "CPA: " << p.second.cpa << "\n";
        cout << "Gioi tinh: " << (p.second.gender ? "Nam" : "Nu") << "\n";
        cout << "Gmail: " << p.second.gmail << "\n";
    }
    cout << "===============================\n";
}

int main() {
    map<int, Student> ds;
    int choice;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Tim sinh vien\n";
        cout << "4. Cap nhat sinh vien\n";
        cout << "5. In toan bo danh sach\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(ds); break;
            case 2: removeStudent(ds); break;
            case 3: findStudent(ds); break;
            case 4: updateStudent(ds); break;
            case 5: printAll(ds); break;
            case 0: return 0;
            default: cout << "Lua chon khong hop le!\n";
        }
    }
}
