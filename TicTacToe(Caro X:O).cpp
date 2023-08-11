#include <iostream>
#include <vector>
#include <conio.h>

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
    CaroGame game;
    Player currentPlayer = Player::X;
    int moves = 0;

    while (!game.isGameOver() && moves < game.getBoardSize() * game.getBoardSize()) {
        game.drawBoard();
        std::cout << "Player " << (currentPlayer == Player::X ? 'X' : 'O') << "'s turn." << std::endl;
        
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
    }

    game.drawBoard();

    if (game.isGameOver()) {
        std::cout << "Player " << (currentPlayer == Player::X ? 'O' : 'X') << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}