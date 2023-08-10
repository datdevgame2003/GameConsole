#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {
    string name;
    int quantity;
};

void displayInventory(const vector<Product> &inventory) {
    cout << "    \nDanh sach kho hang:\n";
    cout << "|-------------------------------|\n";
    cout << "|Ten san pham | So luong ton kho|\n";
    cout << "|-------------------------------|\n";

    for (const Product &product : inventory) {
        cout<<"|     " << product.name << "       |      " << product.quantity<<"          |" << endl;
    }

    cout << "|-------------------------------|\n";
}

int main() {
    vector<Product> inventory;

    while (true) {
        cout << "\nChon hanh dong:\n";
        cout << "1. Hien thi kho hang\n";
        cout << "2. Nhap hang\n";
        cout << "3. Xuat hang\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon cua ban: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayInventory(inventory);
                break;
            case 2: {
                string productName;
                int quantity;

                cout << "Nhap ten san pham: ";
                cin >> productName;
                cout << "Nhap so luong: ";
                cin >> quantity;

                // Kiểm tra nếu sản phẩm đã tồn tại trong kho
                bool found = false;
                for (Product &product : inventory) {
                    if (product.name == productName) {
                        product.quantity += quantity;
                        found = true;
                        break;
                    }
                }

                // Nếu sản phẩm chưa tồn tại, thêm sản phẩm mới vào kho
                if (!found) {
                    inventory.push_back({productName, quantity});
                }

                cout << "Da nhap hang thanh cong!\n";
                break;
            }
            case 3: {
                string productName;
                int quantity;

                cout << "Nhap ten san pham: ";
                cin >> productName;
                cout << "Nhap so luong: ";
                cin >> quantity;

                for (Product &product : inventory) {
                    if (product.name == productName) {
                        if (product.quantity >= quantity) {
                            product.quantity -= quantity;
                            cout << "Da xuat hang thanh cong!\n";
                        } else {
                            cout << "Khong du hang trong kho!\n";
                        }
                        break;
                    }
                }

                break;
            }
            case 4:
                cout << "Cam on ban da su dung chuong trinh!\n";
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    }

    return 0;
}
