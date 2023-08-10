#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Question {
    std::string question;
    std::vector<std::string> options;
    int correctOption;
};

int main() {
    // Khởi tạo ngẫu nhiên dựa trên thời gian
    srand(time(0));

    std::vector<Question> questions = {
        {"C++ là ngôn ngữ lập trình nào?", {"A. Python", "B. C++", "C. Java", "D. Ruby"}, 1},
        {"C++ có phải ngôn ngữ hướng đối tượng không?", {"A. Có", "B. Không"}, 0},
        {"Trong C++, 'cout' được sử dụng để làm gì?", {"A. Đọc dữ liệu từ bàn phím", "B. Ghi dữ liệu ra màn hình", "C. Thực hiện tính toán số học", "D. Tạo một vòng lặp"}, 1},
        // Thêm các câu hỏi khác ở đây
    };

    int score = 0;

    std::cout << "Chao mung ban den voi tro choi Trac Nghiem Don Gian!" << std::endl;

    for (const Question& q : questions) {
        std::cout << q.question << std::endl;
        for (size_t i = 0; i < q.options.size(); ++i) {
            std::cout << i + 1 << ". " << q.options[i] << std::endl;
        }

        int answer;
        std::cout << "Nhap lua chon cua ban (1-" << q.options.size() << "): ";
        std::cin >> answer;

        if (answer - 1 == q.correctOption) {
            std::cout << "Dung roi!" << std::endl;
            score++;
        } else {
            std::cout << "Sai roi! Dap an dung la: " << q.correctOption + 1 << ". " << q.options[q.correctOption] << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "Tro choi ket thuc. Ban dat duoc " << score << " diem." << std::endl;

    return 0;
}
