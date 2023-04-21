#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "I love coding!";
    cout << ".back(): " << str.back() << endl;
    cout << "[]: " << str[13] << endl;
    cout << ".length(): " << str[str.length() - 1] << endl;
    return 0;
}