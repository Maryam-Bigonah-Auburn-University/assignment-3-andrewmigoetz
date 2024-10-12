#include <iostream>

using namespace std;

bool isFull(char seatChart[7][5]);
void checkSeat(char seatChart[7][5],int row,char seat);
void printSeats(char seatChart[7][5]);

int main() {
    char seatChart[7][5] = {{'1','A','B','C','D'},
                {'2','A','B','C','D'},
                {'3','A','B','C','D'},
                {'4','A','B','C','D'},
                {'5','A','B','C','D'},
                {'6','A','B','C','D'},
                {'7','A','B','C','D'}};
    int row = 0;
    char seat = ' ',
         enterAgain = 'N';

    do {
        printSeats(seatChart);
        cout << "Enter row number: " << endl;
        cin  >> row;
        while (row < 1 || row > 7) {
            cout << "Enter a value between 1 and 7: " << endl;
            cin  >> row;
        }
        cout << "Enter seat letter: " << endl;
        cin  >> seat;
        // Use ASCII values for A - D to validate input
        while (seat < 'A' || seat > 'D') {
            cout << "Enter A, B, C, or D:";
            cin  >> seat;
        }

        checkSeat(seatChart,row,seat);
        cout << "Would you like to book another seat?" << endl
             << "Enter Y for yes and anything else to quit:" << endl;
        cin  >> enterAgain;
    } while(enterAgain == 'Y' && !(isFull(seatChart)));

    if (isFull(seatChart))
        cout << "Sorry, there are no more empty seats on this plane." << endl;

    return 0;
}

bool isFull(char seatChart[7][5]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 1; j < 4; j++) {
            if (seatChart[i][j] != 'X')
                return false;
        }
    }
    return true;
}

void checkSeat(char seatChart[7][5], int row, char seat) {
    int i = 0;
    // Mapping seat letters to the column index makes indexing easier
    switch (seat) {
        case 'A': i = 1; break;
        case 'B': i = 2; break;
        case 'C': i = 3; break;
        case 'D': i = 4; break;
    }
    // If the seat isn't taken, we mark it with an 'X' and give the user that seat.
    // Otherwise, we tell the user the seat's already taken.
    if (seatChart[row - 1][i] != 'X') {
        seatChart[row - 1][i] = 'X';
        cout << "Congrats! Your seat is " << row << seat << "." << endl;
    } else {
        cout << "Sorry, that seat is already taken." << endl;
    }
}

void printSeats(char seatChart[7][5]) {
    // We print out each value in the matrix seatChart and separate by rows
    cout << "AVAILABLE SEATS:" << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            cout << seatChart[i][j] << " ";
        }
        cout << endl;
    }
}
