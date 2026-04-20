#include <iostream>
using namespace std;


template <class T>
void display(T arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <class T>
void reverseArray(T arr[], int n)
{
    for(int i = 0; i < n/2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

template <class T>
T findMax(T arr[], int n)
{
    T max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

template <class T>
void findLeaders(T arr[], int n)
{
    T max_right = arr[n-1];
    cout << "Leaders: " << max_right << " ";

    for(int i = n-2; i >= 0; i--)
    {
        if(arr[i] > max_right)
        {
            max_right = arr[i];
            cout << max_right << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of integer array: ";
    cin >> n;
    int arr1[100];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    cout << "\nInteger Array:\n";
    display(arr1, n);
    cout << "Max: " << findMax(arr1, n) << endl;
    reverseArray(arr1, n);
    cout << "Reversed: ";
    display(arr1, n);
    findLeaders(arr1, n);

    cout << "\nEnter size of float array: ";
    cin >> n;
    float arr2[100];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr2[i];

    cout << "\nFloat Array:\n";
    display(arr2, n);
    cout << "Max: " << findMax(arr2, n) << endl;
    reverseArray(arr2, n);
    cout << "Reversed: ";
    display(arr2, n);
    findLeaders(arr2, n);

    cout << "\nEnter size of character array: ";
    cin >> n;
    char arr3[100];

    cout << "Enter characters: ";
    for(int i = 0; i < n; i++)
        cin >> arr3[i];

    cout << "\nCharacter Array:\n";
    display(arr3, n);
    cout << "Max: " << findMax(arr3, n) << endl;
    reverseArray(arr3, n);
    cout << "Reversed: ";
    display(arr3, n);
    findLeaders(arr3, n);

    cout<<"This program is made by Angel Bavarva";
    return 0;
}
