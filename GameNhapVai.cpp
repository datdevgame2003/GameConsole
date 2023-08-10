#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Character {
    string name;
    int health;
    int attack;
};

void battle(Character &player, Character &enemy) {
    while (player.health > 0 && enemy.health > 0) {
        cout << player.name << " (HP: " << player.health << ") vs " << enemy.name << " (HP: " << enemy.health << ")\n";
        int playerDamage = rand() % player.attack + 1;
        int enemyDamage = rand() % enemy.attack + 1;

        cout << player.name << " tan cong " << enemy.name << " gay " << playerDamage << " sat thuong.\n";
        enemy.health -= playerDamage;

        cout << enemy.name << " tan cong " << player.name << " gay " << enemyDamage << " sat thuong.\n";
        player.health -= enemyDamage;

        cout << endl;
    }

    if (player.health > 0) {
        cout << "Chien thang! " << player.name << " da danh bai " << enemy.name << ".\n";
    } else {
        cout << "That bai! " << player.name << " da bi " << enemy.name << " danh bai.\n";
    }
}

int main() {
    srand(time(0));

    Character player = {"Nguoi choi", 100, 15};
    Character enemy = {"Quai vat", 50, 10};

    cout << "Chao mung ban den voi tro choi nhap vai don gian!\n";
    cout << "Hay nhap ten nhan vat cua ban: ";
    cin >> player.name;

    cout << "Cuoc phieu luu cua ban bat dau!\n";
    cout << "Ban gap mot " << enemy.name << " xuat hien!\n";

    battle(player, enemy);

    cout << "Ket thuc tro choi. Cam on ban da tham gia!\n";

    return 0;
}

