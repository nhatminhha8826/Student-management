#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    float cpa;
    bool gender;   // true = Nam, false = Nu
    string gmail;
};

struct Node {
    int mssv;
    Student sv;
    Node* next;
};

Node* findNode(Node* head, int mssv) {
    while (head) {
        if (head->mssv == mssv) return head;
        head = head->next;
    }
    return NULL;
}

void addStudent(Node* &head) {
    int mssv;
    cout << "Nhap MSSV: ";
    cin >> mssv;
    cin.ignore(); // xoa '\n' sau cin

    if (findNode(head, mssv)) {
        cout << "MSSV da ton tai!\n";
        return;
    }

    Student sv;
    cout << "Nhap ten: ";
    getline(cin, sv.name);

    cout << "Nhap CPA: ";
    cin >> sv.cpa;

    cout << "Gioi tinh (1 = Nam, 0 = Nu): ";
    cin >> sv.gender;
    cin.ignore();

    cout << "Nhap Gmail: ";
    getline(cin, sv.gmail);

    Node* newNode = new Node;
    newNode->mssv = mssv;
    newNode->sv = sv;
    newNode->next = head;
    head = newNode;

    cout << "Them thanh cong!\n";
}

void removeStudent(Node* &head) {
    int mssv;
    cout << "Nhap MSSV can xoa: ";
    cin >> mssv;

    Node *cur = head, *prev = NULL;

    while (cur) {
        if (cur->mssv == mssv) {
            if (prev) prev->next = cur->next;
            else head = cur->next;

            delete cur;
            cout << "Xoa thanh cong!\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << "Khong tim thay MSSV!\n";
}

void findStudent(Node* head) {
    int mssv;
    cout << "Nhap MSSV can tim: ";
    cin >> mssv;

    Node* p = findNode(head, mssv);
    if (!p) {
        cout << "Khong ton tai MSSV\n";
        return;
    }

    cout << "\n--- THONG TIN SINH VIEN ---\n";
    cout << "MSSV: " << p->mssv << "\n";
    cout << "Ho ten: " << p->sv.name << "\n";
    cout << "CPA: " << p->sv.cpa << "\n";
    cout << "Gioi tinh: " << (p->sv.gender ? "Nam" : "Nu") << "\n";
    cout << "Gmail: " << p->sv.gmail << "\n";
}

void updateStudent(Node* head) {
    int mssv;
    cout << "Nhap MSSV can cap nhat: ";
    cin >> mssv;
    cin.ignore();

    Node* p = findNode(head, mssv);
    if (!p) {
        cout << "MSSV khong ton tai!\n";
        return;
    }

    string tmp;

    cout << "Nhap ten moi (bo trong de giu nguyen): ";
    getline(cin, tmp);
    if (!tmp.empty()) p->sv.name = tmp;

    cout << "Nhap CPA moi (-1 de giu nguyen): ";
    float cpa;
    cin >> cpa;

    // don '\n' de getline o duoi khong bi skip
    cin.ignore();

    if (cpa >= 0) p->sv.cpa = cpa;

    cout << "Nhap gioi tinh moi (1/0, -1 de giu nguyen): ";
    int gt;
    cin >> gt;
    cin.ignore();

    if (gt == 0 || gt == 1) p->sv.gender = (gt == 1);

    cout << "Nhap Gmail moi (bo trong de giu nguyen): ";
    getline(cin, tmp);
    if (!tmp.empty()) p->sv.gmail = tmp;

    cout << "Cap nhat thanh cong!\n";
}

void printAll(Node* head) {
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    if (!head) {
        cout << "(Danh sach rong)\n";
        cout << "===============================\n";
        return;
    }

    while (head) {
        cout << "------------------------\n";
        cout << "MSSV: " << head->mssv << "\n";
        cout << "Ho ten: " << head->sv.name << "\n";
        cout << "CPA: " << head->sv.cpa << "\n";
        cout << "Gioi tinh: " << (head->sv.gender ? "Nam" : "Nu") << "\n";
        cout << "Gmail: " << head->sv.gmail << "\n";
        head = head->next;
    }
    cout << "===============================\n";
}

void clearList(Node* &head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Node* head = NULL;
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
            case 1: addStudent(head); break;
            case 2: removeStudent(head); break;
            case 3: findStudent(head); break;
            case 4: updateStudent(head); break;
            case 5: printAll(head); break;
            case 0:
                clearList(head);
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }
}
