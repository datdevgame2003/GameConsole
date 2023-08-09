#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::vector<std::string> words = {"banana", "apple", "orange", "grape", "strawberry"};
    
    // Thiết lập seed cho số ngẫu nhiên dựa trên thời gian hệ thống
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    int randomIndex = std::rand() % words.size();
    std::string secretWord = words[randomIndex];
    int guessesLeft = 6;
    
    std::string guessedLetters = "";
    
    std::cout << "Chao mung den voi tro choi Doan Tu!\n";
    
    while (guessesLeft > 0) {
        std::cout << "Tu bi mat co " << secretWord.length() << " chu cai. Ban con " << guessesLeft << " luot doan.\n";
        std::cout << "Cac chu cai da doan: " << guessedLetters << "\n";
        
        std::string displayWord = "";
        for (char letter : secretWord) {
            if (guessedLetters.find(letter) != std::string::npos) {
                displayWord += letter;
            } else {
                displayWord += "_";
            }
        }
        
        std::cout << "Tu: " << displayWord << "\n";
        
        if (displayWord == secretWord) {
            std::cout << "Chuc mung! Ban da doan dung tu \"" << secretWord << "\".\n";
            break;
        }
        
        char guess;
        std::cout << "Nhap mot chu cai: ";
        std::cin >> guess;
        
        if (guessedLetters.find(guess) != std::string::npos) {
            std::cout << "Ban da doan chu cai nay roi. Hay thu mot chu cai khac.\n";
        } else {
            guessedLetters += guess;
            if (secretWord.find(guess) == std::string::npos) {
                std::cout << "Chu cai khong co trong tu bi mat. Ban con " << --guessesLeft << " luot doan.\n";
            }
        }
        
        if (guessesLeft == 0) {
            std::cout << "Ban da het luot doan. Tu bi mat la \"" << secretWord << "\".\n";
        }
    }
    
    return 0;
}
