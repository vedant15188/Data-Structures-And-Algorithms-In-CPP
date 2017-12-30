//
// Created by VEDANT KASHYAP on 12/30/2017.
//
#include <iostream>
#include "lib/Arrays.h"

using namespace std;

void RotateFW(int array[], int k, int n) {      // Rotate Forward
    for (int i = 0; i < k; ++i) {
        int temp = array[n - 1];
        for (int j = n - 2; j >= 0; --j)
            array[j + 1] = array[j];
        array[0] = temp;
    }
}

void RotateBW(int *array, int k, int n) {      // Rotate Backward
    for (int i = 0; i < k; ++i) {
        int temp = array[0];
        for (int j = 0; j < n - 1; ++j) {
            array[j] = array[j + 1];
        }
        array[n - 1] = temp;
    }
}

void Arrays() {
    int choice = -1;  // Decides which operation to conduct (i.e. Which function to run)
    int k;          // Amount to be rotated
    int n;          // Array Size
    cout << "Enter the array size: ";
    cin >> n;
    int var_array[n];          // Variable Length Array
    int temp[n];
    for (int i = 0; i < n; ++i) {           // For loop for taking input
        cin >> var_array[i];
        temp[i] = var_array[i];
    }
    while (choice != 0) {
        cout << "Enter your choice\n0 - QUIT\n1 - Forward Shift\n2 - Backward Shift" << endl;
        cin >> choice;
        if (choice == 0)            // Quit the program
            break;
        else if (choice == 1) {      // Forward Shift
            cout << "Enter the no. of times to rotate forward: ";
            cin >> k;
            RotateFW(var_array, k, n);
            cout << "Result for forward shift-  ";
            for (int i = 0; i < n; ++i)
                cout << var_array[i] << " ";
            cout << endl;
        } else if (choice == 2) {      // Backward Shift
            cout << "Enter the no. of times to rotate backward: ";
            cin >> k;
            RotateBW(temp, k, n);
            cout << "Result for backward shift- ";
            for (int i = 0; i < n; ++i)
                cout << temp[i] << " ";
            cout << endl;
        } else         // Invalid Input !!
            cout << "Enter a valid choice!!" << endl;

    }
}