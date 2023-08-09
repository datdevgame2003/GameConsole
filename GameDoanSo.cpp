#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Thiết lập seed cho số ngẫu nhiên dựa trên thời gian hệ thống
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Sinh số ngẫu nhiên trong khoảng từ 1 đến 100
    int targetNumber = std::rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Chao mung den voi tro choi doan so!\n";
    
    do {
        std::cout << "Nhap mot so (1-100): ";
        std::cin >> guess;
        attempts++;

        if (guess < targetNumber) {
            std::cout << "So ban doan nho hon so can tim. Hay thu lai.\n";
        } else if (guess > targetNumber) {
            std::cout << "So ban doan lon hon so can tim. Hay thu lai.\n";
        } else {
            std::cout << "Chuc mung! Ban da doan dung so " << targetNumber << " sau " << attempts << " lan.\n";
        }
    } while (guess != targetNumber);

    return 0;
}
