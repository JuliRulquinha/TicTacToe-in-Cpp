#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string drawTicTacToeTable(char tttArr[], string message = "") {
    system("clear");

    cout << "\n\033[35m-- TIC-TAC-TOE GAME --\033[0m\n" << endl;

    if(message != ""){
        cout << "\n\033[31m "<< message <<" \033[0m\n" << endl;
    }

    std::stringstream ss;

    ss << "      |   |     \n";
    ss << "    " << tttArr[0] << " | " << tttArr[1] << " | " << tttArr[2] << "\n";
    ss << "   ___|___|___\n";
    ss << "      |   |     \n";
    ss << "    " << tttArr[3] << " | " << tttArr[4] << " | " << tttArr[5] << "\n";

    ss << "   ___|___|___\n";
    ss << "      |   |     \n";
    ss << "    " << tttArr[6] << " | " << tttArr[7] << " | " << tttArr[8] << "\n";
    ss << "      |   |   \n";

    return ss.str();
}

bool isWinningSymbol(char symbol, char tttArr[]) {
    int possibleCombinations[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    for (int i = 0; i < 8; i++) {
        
        if (symbol == tttArr[possibleCombinations[i][0]] && symbol == tttArr[possibleCombinations[i][1]] && symbol == tttArr[possibleCombinations[i][2]]) {
            return true;
        }
            
    }

    return false;
}


    
void playTicTacToe() {
    
    string message = "";
    auto gameOn = true;
    auto isXTurn = true;
    char tttArr[] = {'1','2','3','4','5','6','7','8','9'};
    auto round = 1;
    bool hasWinner = false;

    

    int slot;
    char playerXOrO;
    while (gameOn) {

        cout << drawTicTacToeTable(tttArr, message) << endl;
        switch (isXTurn) {
            case true:
                playerXOrO = 'X';
                break;
            case false:
                playerXOrO = 'O';
                break;
        }

        cout << "\033[32m-- Player " << playerXOrO << "'s turn\033[0m\n" << endl;
        cout << "\033[33m-- choose your slot\033[0m\n\n" << endl;

        

        cin >> slot;
        cout << "\n";

        

        if(tttArr[slot-1] == 'X' || tttArr[slot-1] == 'O'){

            message = "-- Pick an empty slot --";
            continue;
        }

        

        switch (slot) {
            case 1:
                tttArr[0] = playerXOrO;
                break;
            case 2:
                tttArr[1] = playerXOrO;
                break;
            case 3:
                tttArr[2] = playerXOrO;
                break;
            case 4:
                tttArr[3] = playerXOrO;
                break;
            case 5:
                tttArr[4] = playerXOrO;
                break;
            case 6:
                tttArr[5] = playerXOrO;
                break;
            case 7:
                tttArr[6] = playerXOrO;
                break;
            case 8:
                tttArr[7] = playerXOrO;
                break;
            case 9:
                tttArr[8] = playerXOrO;
                break;
            default:
                message = "-- Invalid slot --";
                continue;
        }

        cout << drawTicTacToeTable(tttArr, message) << endl;

        if (round >= 4) {
            hasWinner = isWinningSymbol(playerXOrO, tttArr);
        }

        if (hasWinner == true) {
            string winner(1, playerXOrO);
            message = string("\033[34m-- PLAYER ") + winner + string(" IS THE WINNER !! --\033[0m");
            cout << drawTicTacToeTable(tttArr, message) << endl;
            return;
        }

        if (round == 9 && isWinningSymbol(playerXOrO, tttArr) == false) {
            cout << drawTicTacToeTable(tttArr, message) << endl;
            cout << "Draw" << endl;
            return;
        }

        isXTurn = !isXTurn;

        
        round++;

        
    }
}

int main(){ 

    playTicTacToe();

}
