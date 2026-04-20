#include<iostream>
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
    int arr1[] = {16, 17, 4, 3, 5, 2};
    float arr2[] = {2.5, 3.1, 1.2, 4.8, 0.9};
    char arr3[] = {'a', 'x', 'c', 'b'};

    int n1 = 6, n2 = 5, n3 = 4;

    cout << "Integer Array:\n";
    display(arr1, n1);
    cout << "Max: " << findMax(arr1, n1) << endl;
    reverseArray(arr1, n1);
    cout << "Reversed: ";
    display(arr1, n1);
    findLeaders(arr1, n1);

    cout << "\nFloat Array:\n";
    display(arr2, n2);
    cout << "Max: " << findMax(arr2, n2) << endl;
    reverseArray(arr2, n2);
    cout << "Reversed: ";
    display(arr2, n2);
    findLeaders(arr2, n2);

    cout << "\nCharacter Array:\n";
    display(arr3, n3);
    cout << "Max: " << findMax(arr3, n3) << endl;
    reverseArray(arr3, n3);
    cout << "Reversed: ";
    display(arr3, n3);
    findLeaders(arr3, n3);

    return 0;
}
