#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main() {
    // Khởi tạo ngẫu nhiên dựa trên thời gian
    srand(time(0));

    const int gridSize = 4;
    std::vector<int> numbers;

    std::cout << "Chao mung ban den voi tro choi Choi Xep Hinh!" << std::endl;
    std::cout << "Ban hay xep cac so trong mien " << gridSize << "x" << gridSize << " theo thu tu tang dan." << std::endl;

    // Khởi tạo mảng số ngẫu nhiên
    for (int i = 0; i < gridSize * gridSize; ++i) {
        numbers.push_back(rand() % 100);
    }

    // Hiển thị mảng chưa xếp
    std::cout << "Day so truoc khi xep:" << std::endl;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            std::cout << numbers[i * gridSize + j] << "\t";
        }
        std::cout << std::endl;
    }

    // Sắp xếp mảng
    std::sort(numbers.begin(), numbers.end());

    // Yêu cầu người chơi nhập các số theo thứ tự tăng dần
    std::cout << "Hay nhap cac so theo thu tu tang dan:" << std::endl;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            int guess;
            std::cout << "[" << i * gridSize + j + 1 << "/" << gridSize * gridSize << "]: ";
            std::cin >> guess;

            if (guess != numbers[i * gridSize + j]) {
                std::cout << "Ban da nhap sai! Tro choi ket thuc." << std::endl;
                return 0;
            }
        }
    }

    std::cout << "Chuc mung! Ban da xep day so dung theo thu tu tang dan." << std::endl;

    return 0;
}
