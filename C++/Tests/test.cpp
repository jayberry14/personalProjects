#include <iostream>
#include <vector>

using namespace std;

vector<int> mutateArray(int size, vector<int> a)
{
    vector<int> b (size);
    // int* p = a.data();

    for (int i = 0; i < size; i++)
    {
        if (a.front())
        {
            a[i - 1] = 0;
        }

        if (i == (size - 1))
        {
            a[i + 1] = 0;
        }
        // ++p;
        b[i] = a[i - 1] + a[i] + a[i + 1];
        // cout << "This is a[" << i << "]: " << a[i] << endl;
        cout << "This is b[" << i << "]: " << b[i] << endl;

    }
    return b;
}

int main ()
{
    int size = 11;
    int ints[] = {-1, 2, -3, 4, -5, 6, -7, 8, -9, 10, -11};
    vector<int> a (ints, ints + sizeof(ints) / sizeof(int));
    // int input;
    // cout << "Please give an array of numbers no bigger than the size" << endl;
    // while (cin >> input && input != 9999)
    //     a.push_back(input);
    mutateArray(size, a);
    return 0;
}