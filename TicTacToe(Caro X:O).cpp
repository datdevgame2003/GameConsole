#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>

enum class Player {
    None,
    X,
    O
};

struct Move {
    int row;
    int col;
};

class CaroGame {
private:
    const int boardSize = 3;
    std::vector<std::vector<Player>> board;

public:
    CaroGame() : board(boardSize, std::vector<Player>(boardSize, Player::None)) {}

    int getBoardSize() const {
        return boardSize;
    }

    void drawBoard() {
        system("cls");
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                char mark = ' ';
                if (board[i][j] == Player::X) mark = 'X';
                else if (board[i][j] == Player::O) mark = 'O';
                std::cout << mark;
                if (j < boardSize - 1) std::cout << '|';
            }
            std::cout << std::endl;
            if (i < boardSize - 1) {
                std::cout << "------" << std::endl;
            }
        }
    }

    bool makeMove(Player player, Move move) {
        if (move.row >= 0 && move.row < boardSize && move.col >= 0 && move.col < boardSize &&
            board[move.row][move.col] == Player::None) {
            board[move.row][move.col] = player;
            return true;
        }
        return false;
    }

    bool isGameOver() {
        // Check rows, columns, and diagonals
        for (int i = 0; i < boardSize; ++i) {
            if (board[i][0] != Player::None && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
            if (board[0][i] != Player::None && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
        }
        if (board[0][0] != Player::None && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[0][2] != Player::None && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
        return false;
    }
};

int main() {
    bool playAgain = true;

    while (playAgain) {
        CaroGame game;
        std::string playerXName, playerOName;
        Player currentPlayer = Player::X;
        int moves = 0;
        int totalMoves = 0;
        std::cout << "Enter name for Player X: ";
        std::cin >> playerXName;
        std::cout << "Enter name for Player O: ";
        std::cin >> playerOName;

        std::clock_t startTime = std::clock();

        while (!game.isGameOver() && moves < game.getBoardSize() * game.getBoardSize()) {
            game.drawBoard();
            std::cout << "Player " << (currentPlayer == Player::X ? playerXName : playerOName) << "'s turn." << std::endl;

            int row, col;
            while (true) {
                std::cout << "Enter row (0-2): ";
                std::cin >> row;
                std::cout << "Enter column (0-2): ";
                std::cin >> col;
                if (game.makeMove(currentPlayer, {row, col})) {
                    break;
                }
                std::cout << "Invalid move. Try again." << std::endl;
            }

            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
            ++moves;
            ++totalMoves;
        }

        game.drawBoard();

        std::clock_t endTime = std::clock();
        double totalTime = (endTime - startTime) / (double)CLOCKS_PER_SEC;

        if (game.isGameOver()) {
            std::cout << "Congratulations!Player " << (currentPlayer == Player::X ? playerOName : playerXName) << " is the winner!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }
         std::cout << "Total moves played: " << totalMoves << std::endl;
        std::cout << "Total time: " << totalTime << " seconds" << std::endl;

        char playAgainInput;
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgainInput;
        playAgain = (playAgainInput == 'Y' || playAgainInput == 'y');
    }

    return 0;
}
