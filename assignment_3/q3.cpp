#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

//Fixed spelling error
int countOccurrences(int arr[], int size, int n);
void sortArray(int arr[], int size);

int main() {
    int size = 0;

    int arr[50];

    // Read in the values into an array
    cout << "Enter size of array: " << endl;
    cin >> size;
    cout << "Enter array elements: " << endl;

    // Take in numbers for each array element until reaching the size of the array
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sortArray(arr,size);

    cout << left << setw(10) << "Number" << setw(10) << "Count" << endl;

    // Count and print occurrences of each number
    for (int i = 0; i < size; i++) {
        // If it's the first element or an element that isn't the same as the previous one, count number of occurrences
        if (i==0||arr[i] != arr[i-1]){ 
            int count = countOccurrences(arr, size, arr[i]);
            cout << left << setw(10) << arr[i] << setw(10) << count << endl;
        }
    }


    return 0;
}

int countOccurrences(int *arr, int size, int n) {
    //If the integer is equal to the ith element in array increment the count.
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == n){
            count++;
        }
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
