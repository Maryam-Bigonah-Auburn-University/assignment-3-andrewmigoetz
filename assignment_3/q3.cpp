#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

int countOccurances(int arr[], int size, int n);
void sortArray(int arr[], int size);

int main() {
    int size = 0;

    int arr[50];

    // Read in the values into an array
    cout << "Enter size of array: " << endl;
    cin >> size;
    cout << "Enter array elements: " << endl;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sortArray(arr,size);

    cout << left << setw(10) << "Number" << setw(10) << "Count" << endl;
    for (int i = 0; i < size; i++) {

    }

    return 0;
}

int countOccurences(int *arr, int size, int n) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == n){
            count++;
        }
        i++;
    }
    return count;
}

// I used bubble sort since that is covered in the text for this chapter
void sortArray(int *arr, int size) {
    // Bubble sort program from section 5.9 in the textbook
    for (int i = size-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
