#include <iostream>
using namespace std;

int main() {
    int n, m,i;

    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter size of second array: ";
    cin >> m;

    int* arr1 = new int[n];
    int* arr2 = new int[m];


    cout << "Enter elements of first sorted array:\n";
    for (i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter elements of second sorted array:\n";
    for (i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }


    int* merged = new int[n + m];


    for (i = 0; i < n; i++)
    {
        merged[i] = arr1[i];
    }

    for (i = 0; i < m; i++)
    {
        merged[n + i] = arr2[i];
    }


    for (int i = 0; i < n + m - 1; i++)
    {
        for (int j = 0; j < n + m - i - 1; j++)
        {
            if (merged[j] > merged[j + 1])
            {

                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }


    cout << "Merged sorted array:\n";
    for (i = 0; i < n + m; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;


    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}
