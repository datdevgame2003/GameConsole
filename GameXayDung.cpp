#include <iostream>
#include <vector>

using namespace std;

struct Building {
    string name;
    int cost;
    int income;
};

int main() {
    vector<Building> buildings;

    buildings.push_back({"Nha o", 100, 10});
    buildings.push_back({"Cua hang", 200, 20});
    buildings.push_back({"Van phong", 500, 50});

    int money = 1000;
    vector<int> ownedBuildings(buildings.size(), 0);

    cout << "Chao mung den voi tro choi Xay dung!\n";
    
    while (true) {
        cout << "Ban co " << money << " dong.\n";
        cout << "Cac toa nha co san:\n";
        
        for (size_t i = 0; i < buildings.size(); ++i) {
            cout << i + 1 << ". " << buildings[i].name << " (Gia: " << buildings[i].cost << " | Thu nhap: " << buildings[i].income << ")\n";
        }

        cout << "Chon toa nha de xay (0 de thoat): ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Cam on ban da choi!\n";
            break;
        }

        if (choice >= 1 && choice <= buildings.size()) {
            int index = choice - 1;
            if (money >= buildings[index].cost) {
                money -= buildings[index].cost;
                ownedBuildings[index]++;
                cout << "Ban da xay them mot " << buildings[index].name << "!\n";
            } else {
                cout << "Khong du tien de xay toa nha nay.\n";
            }
        } else {
            cout << "Lua chon khong hop le.\n";
        }

        for (size_t i = 0; i < ownedBuildings.size(); ++i) {
            money += ownedBuildings[i] * buildings[i].income;
        }
    }

    return 0;
}
