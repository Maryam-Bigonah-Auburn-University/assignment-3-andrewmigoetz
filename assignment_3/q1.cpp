#include <iostream>
using namespace std;

int main() {
    string first, second;

    int added[20] = {0};

    int carry = 0;
    // Get the values
    cout << "Enter the first number: " << endl;
    cin  >> first;

    //Ensure positive integers of length 20 or less
    while (first[0]-'0'<1) {
        cout << "Enter a positive integer for the first number: " << endl;
        cin >> first;
    }
    while (first.length()>20) {
        cout << "Too many digits! Enter a number with 20 digits or less: " << endl;
        cin >> first;
    }

    cout << "Enter the second number: " << endl;
    cin  >> second;

    while (second[0]-'0'<1) {
        cout << "Enter a positive integer for the second number: " << endl;
        cin >> second;
    }
    while (second.length()>20) {
        cout << "Too many digits! Enter a number with 20 digits or less: " << endl;
        cin >> second;
    }

    // Convert digits to ints

    int maxl = max(first.length(), second.length());

    // Initialize three zero arrays of length maxl+1 (addition plus possible carry digit)
    int x[maxl+1] = {0}, y[maxl+1] = {0}, z[maxl+1] = {0};

    // Fill x array with the digits of the first number
    for (int i = first.length() - 1; i >= 0; i--) {
        x[first.length() - 1 - i] = first[i] - '0';
    }

    // Fill y array with digits of the second number
    for (int j = second.length() - 1; j >= 0; j--) {
        y[second.length() - 1 - j] = second[j] - '0';
    }

    // Add the arrays

    //Add x and y in the ones place. If there is a carry left over, it will be added to the tens place
    //If the sum is greater than 10 the %10 operation ensures only what's in the ones place is stored
    for (int k = 0; k < maxl; k++) {
        z[k] = x[k] + y[k] + carry;
        carry = z[k] / 10;
        z[k] %= 10;
    }

    // If there is a carry left over, put that in the last indexed spot we left over and print from there
    // Else, leave the carry spot a zero and start from one spot to the left
    int start = 0;

    if (carry > 0){
        z[maxl] = carry;
        start = maxl;
    } else {
        start = maxl - 1;
    }

    // Print result backwards, starting from either the carry spot or the spot to the left of it
    cout << "Result: " << endl;
    for (int k = start; k >= 0; k--) {
        cout << z[k];
    }

    return 0;
}
