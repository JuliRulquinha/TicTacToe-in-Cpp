#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string drawTicTacToeTable(vector<vector<char>> tttArr) {
    std::stringstream ss;


    ss << "    1   2   3\n";
    ss << "      |   |     \n";
    ss << "A   " << tttArr[0][0] << " | " << tttArr[0][1] << " | " << tttArr[0][2] << "\n";
    ss << "   ___|___|___\n";
    ss << "      |   |     \n";
    ss << "B   " << tttArr[1][0] << " | " << tttArr[1][1] << " | " << tttArr[1][2] << "\n";
    
    ss << "   ___|___|___\n";
    ss << "      |   |     \n";
    ss << "C   " << tttArr[2][0] << " | " << tttArr[2][1] << " | " << tttArr[2][2] << "\n";
    ss << "      |   |   \n";

    return ss.str();
}


void playTicTacToe() {
    auto gameOn = true;
	auto isXTurn = true;
    vector<vector<char>> tttArr = { {'1','2','3'},{'4', '5', '6'},{'7', '8', '9'}};

    cout <<"-- TIC-TAC-TOE GAME --\n" << endl;

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
            
        switch (slot) {
            case 1:
                tttArr[0][0] = playerXOrO;

                break;
            case 2:
                tttArr[0][1] = playerXOrO;
                break;
            case 3:
                tttArr[0][2] = playerXOrO;
                break;
            case 4:
                tttArr[1][0] = playerXOrO;
                break;
            case 5:
                tttArr[1][1] = playerXOrO;
                break;
            case 6:
                tttArr[1][2] = playerXOrO;
                break;
            case 7:
                tttArr[2][0] = playerXOrO;
                break;
            case 8:
                tttArr[2][1] = playerXOrO;
                break;
            case 9:
                tttArr[2][2] = playerXOrO;
                break;
        }

        isXTurn = !isXTurn;

        cout << drawTicTacToeTable(tttArr) << endl;
    }
    }
        

int main(){ 

    playTicTacToe();

}
