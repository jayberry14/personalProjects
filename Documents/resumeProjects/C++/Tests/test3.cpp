#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "I love coding!";
    cout << "Last char using .back(): " << str.back() << endl;
    cout << "Last char using []: " << str[13] << endl;
    cout << "Last char using .length(): " << str[str.length() - 1] << endl;
    return 0;
}