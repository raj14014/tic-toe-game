// TIC TOE GAME

#include<iostream>
using namespace std;

int currentPlayer;
char currentMarker;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawboard() {
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"---|---|---\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"---|---|---\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";
}

bool placemarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int winner() {
    // rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }
    // columns
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }
    // diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }
    return 0;
}

void swapPlayerandMarker() {
    if(currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    if(currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}

void game() {
    cout<<"Player 1 choose your marker : X or O : ";
    char markerP1;
    cin>>markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    drawboard();
    int playerwon = 0;

    for(int i=0; i<9; i++) {
        cout<<"It's player "<<currentPlayer<<"'s turn. Enter your slot: ";
        int slot;
        cin>>slot;

        if(slot<1 || slot>9) {
            cout<<"Invalid slot! Try again.\n";
            i--;
            continue;
        }
        if(!placemarker(slot)) {
            cout<<"Slot occupied! Try again.\n";
            i--;
            continue;
        }
        drawboard();

        playerwon = winner(); 
        if(playerwon == 1) {
            cout<<"Player 1 wins!\n";
            break;
        }
        if(playerwon == 2) {
            cout<<"Player 2 wins!\n";
            break;
        }
        swapPlayerandMarker();
    }

    if(playerwon == 0) {
        cout<<"It's a tie!\n";
    }
}

int main() {
    game();
    return 0;
}
