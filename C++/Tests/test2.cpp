#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countTinyPairs(std::vector<int> a, std::vector<int> b, int k) {
    std::vector<int>::iterator iterA = a.begin();
    std::vector<int>::iterator iterB = b.begin();
    string tinyPairs;
    int numPairs = 0;
    for (int i = 0; iterA != a.end(); ++iterA, ++iterB, ++i) {
        tinyPairs = to_string(*iterA) + to_string(*iterB);
        cout << "This is tiny pair " << i << ": " << tinyPairs << endl;

        if (k > stoi(tinyPairs))
        {
            numPairs++;
        }   
    }
    return numPairs;
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 3};
    int k = 32;
    cout << "The number of tiny pairs is: " << countTinyPairs(a, b, k) << endl;
    return 0;
}