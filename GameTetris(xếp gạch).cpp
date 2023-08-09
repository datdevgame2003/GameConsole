#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h> // Thư viện để sử dụng hàm _getch()

const int boardWidth = 10;
const int boardHeight = 20;

class Tetris {
private:
    std::vector<std::vector<bool>> board;
    int currentX, currentY;
    int score;

    void clearBoard() {
        for (int i = 0; i < boardHeight; ++i) {
            board[i].assign(boardWidth, false);
        }
    }

    bool isValidPosition(int x, int y) {
        return x >= 0 && x < boardWidth && y >= 0 && y < boardHeight;
    }

    void drawBoard() {
        system("cls"); // Xóa màn hình console
        for (int y = 0; y < boardHeight; ++y) {
            for (int x = 0; x < boardWidth; ++x) {
                if (board[y][x]) {
                    std::cout << "X";
                } else {
                    std::cout << ".";
                }
            }
            std::cout << "\n";
        }
        std::cout << "Diem so: " << score << "\n";
    }

    bool isGameOver() {
        for (int x = 0; x < boardWidth; ++x) {
            if (board[0][x]) {
                return true;
            }
        }
        return false;
    }

public:
    Tetris() : currentX(boardWidth / 2), currentY(0), score(0) {
        board.resize(boardHeight, std::vector<bool>(boardWidth, false));
    }

    void run() {
        char key;
        int fallingDelay = 300; // milliseconds

        while (true) {
            if (_kbhit()) { // Kiểm tra xem có phím được nhấn không
                key = _getch(); // Lấy phím được nhấn

                switch (key) {
                    case 'a':
                        moveLeft();
                        break;
                    case 'd':
                        moveRight();
                        break;
                    case 's':
                        moveDown();
                        break;
                    case 'q':
                        return;
                    default:
                        break;
                }
            }

            if (!moveDown()) {
                placeTetromino();
                clearRows();
                if (isGameOver()) {
                    std::cout << "Tro choi ket thuc!\nDiem so cua ban: " << score << "\n";
                    return;
                }
                generateNewTetromino();
            }

            drawBoard();
            std::this_thread::sleep_for(std::chrono::milliseconds(fallingDelay));
        }
    }

    void generateNewTetromino() {
        // Tạo một khối hình gạch ngẫu nhiên tại vị trí trên cùng của màn hình
        // (Được cắt ngang nửa để đơn giản hóa)
        currentX = boardWidth / 2;
        currentY = 0;
    }

    void placeTetromino() {
        // Đặt khối hình gạch lên bảng chơi
        // (Được cắt ngang nửa để đơn giản hóa)
        board[currentY][currentX] = true;
        ++score;
    }

    bool moveLeft() {
        if (isValidPosition(currentX - 1, currentY)) {
            --currentX;
            return true;
        }
        return false;
    }

    bool moveRight() {
        if (isValidPosition(currentX + 1, currentY)) {
            ++currentX;
            return true;
        }
        return false;
    }

    bool moveDown() {
        if (isValidPosition(currentX, currentY + 1)) {
            ++currentY;
            return true;
        }
        return false;
    }

    void clearRows() {
        // Xoá hàng nếu đầy
        for (int y = boardHeight - 1; y >= 0; --y) {
            bool rowIsFull = true;
            for (int x = 0; x < boardWidth; ++x) {
                if (!board[y][x]) {
                    rowIsFull = false;
                    break;
                }
            }
            if (rowIsFull) {
                for (int row = y; row > 0; --row) {
                    for (int x = 0; x < boardWidth; ++x) {
                        board[row][x] = board[row - 1][x];
                    }
                }
                ++score;
            }
        }
    }
};

int main() {
    Tetris tetris;
    tetris.run();
    return 0;
}
