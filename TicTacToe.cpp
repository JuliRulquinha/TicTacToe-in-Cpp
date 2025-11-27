#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;



string drawTicTacToeTable(char tttArr[]) {
    std::stringstream ss;


    ss << "    1   2   3\n";
    ss << "      |   |     \n";
    ss << "A   " << tttArr[0] << " | " << tttArr[1] << " | " << tttArr[2] << "\n";
    ss << "   ___|___|___\n";
    ss << "      |   |     \n";
    ss << "B   " << tttArr[3] << " | " << tttArr[4] << " | " << tttArr[5] << "\n";

    ss << "   ___|___|___\n";
    ss << "      |   |     \n";
    ss << "C   " << tttArr[6] << " | " << tttArr[7] << " | " << tttArr[8] << "\n";
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
    auto gameOn = true;
    auto isXTurn = true;
    char tttArr[] = {'1','2','3','4','5','6','7','8','9'};
    auto round = 1;
    bool hasWinner = false;

    cout << "-- TIC-TAC-TOE GAME --\n" << endl;

    cout << drawTicTacToeTable(tttArr) << endl;

    int slot;
    char playerXOrO;
    while (gameOn) {

        switch (isXTurn) {
        case true:
            playerXOrO = 'X';
            break;
        case false:
            playerXOrO = 'O';
            break;
        }

        cout << "-- Player " << playerXOrO << "'s turn" << endl;
        cout << "-- choose your slot\n" << endl;

        

        cin >> slot;
        cout << "\n";

        if(tttArr[slot-1] == 'X' || tttArr[slot-1] == 'O'){
            cout<<"Pick an empty slot\n"<<endl;
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
        }

        if (round >= 4) {
            hasWinner = isWinningSymbol(playerXOrO, tttArr);
        }

        if (hasWinner == true) {
            cout << "Player " << playerXOrO << " is the winner!!" << endl;
            return;
        }

        if (round == 8 && isWinningSymbol(playerXOrO, tttArr) == false) {
            cout << "Draw" << endl;
            return;
        }

        isXTurn = !isXTurn;

        cout << drawTicTacToeTable(tttArr) << endl;
        round++;
    }
}

int main(){ 

    playTicTacToe();

    /*char tttArr[] = { 'O','5','6','7','O','X','7','8','O' };

    cout<< isWinningSymbol('O', tttArr)<<endl;*/
}
