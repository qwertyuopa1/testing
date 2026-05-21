#include <iostream>
#include <vector>
void drawBoard(const std::vector<char>& board) {
    std::cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        std::cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
        if (i < 6) {
            std::cout << "---|---|---\n";
        }
    }
    std::cout << "\n";
}

bool checkWin(const std::vector<char>& board, char player) {
    const int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}
    };

    for (auto& condition : winConditions) {
        if (board[condition[0]] == player && 
            board[condition[1]] == player && 
            board[condition[2]] == player) {
            return true;
        }
    }
    return false;
}


int main() {

    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    int moves = 0;
    bool gameWon = false;

    std::cout << "===========================\n";
    std::cout << "    TIC-TAC-TOE IN C++     \n";
    std::cout << "===========================\n";

    while (moves < 9 && !gameWon) {
        drawBoard(board);
        int choice;
        std::cout << "Player " << currentPlayer << ", enter a cell number (1-9): ";
        std::cin >> choice;

        
        if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            std::cout << "Invalid move! Please try again.\n";
            continue;
        }

        
        board[choice - 1] = currentPlayer;
        moves++;

        
        if (checkWin(board, currentPlayer)) {
            gameWon = true;
            drawBoard(board);
            std::cout << "Congratulations! Player " << currentPlayer << " wins!\n";
            break;
        }


        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    
    if (!gameWon) {
        drawBoard(board);
        std::cout << "It's a tie game!\n";
    }

    return 0;
}
