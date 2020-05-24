/***********************************************
 * Name:
 * Josh Mayberry
 *********************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/**********************************************
 * NUMCOMBOS : Determine how many combinations 
 *             of passwords exist in this set
 **********************************************/
long double numCombos(string password)
{
    bool isLower = false;
    bool isUpper = false;
    bool isNum = false;
    bool isSymbol = false;

    char lowerArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upperArray[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char numArray[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char symbolArray[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '`', '~', '[', ']', '{', '}', '|', '/', '<', '>', ',', '.', '?', ';', ':', '\'', '\\', '"'};
    
    long double passwordSize = password.size();                                // This is m in the equation
    long double lowerAlphabetSize = *(&lowerArray + 1) - lowerArray;           // All the remaining sizes are what could add up to n in the equation
    long double upperAlphabetSize = *(&upperArray + 1) - upperArray;           
    long double numAlphabetSize = *(&numArray + 1) - numArray;                 // My source for this code giving me the size of the array without using sizeof(): https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/
    long double symbolAlphabetSize = *(&symbolArray + 1) - symbolArray;
    long double totalAlphabetSize;                                             // This is n in the equation

    for (int i = 0; i < passwordSize; i++)
    {
        if (isalpha(password[i]))
        {
            if (isupper(password[i]) && !isUpper)
            {
                totalAlphabetSize += upperAlphabetSize;
                isUpper = true;
            }
            else if (islower(password[i]) && !isLower)
            {
                totalAlphabetSize += lowerAlphabetSize;
                isLower = true;
            }
        }
        else if (isdigit(password[i]) && !isNum)
        {
            totalAlphabetSize += numAlphabetSize;
            isNum = true;
        }
        else if (ispunct(password[i]) && !isSymbol)
        {
            totalAlphabetSize += symbolAlphabetSize;
            isSymbol = true;
        }
    }
    long double combos = pow(totalAlphabetSize, passwordSize);
    return combos;
}

/**********************************************
 * BITSTRENGTH : Your program will next compute
 *               the bit strength of a password. 
 *               This is accomplished by using
 *               the bit strength equation
 *               presented in the textbook.
 **********************************************/
long double bitStrength(long double combos)
{
    long double bits = floor(log2(combos));
    return bits;
}

/**********************************************
 * MAIN : Старый, добрый Мэйн
 **********************************************/
int main()
{
    // First prompt the user for his password
    string password;
    cout << "Please enter your password: ";
    cin >> password;

    long double combos = numCombos(password);
    cout << "\tThere are " << fixed << setprecision(0) << combos << " combinations." << endl;

    long double strengthOfBits = bitStrength(combos);
    cout << "\tThat is equivalent to a key of " << setprecision(0) << strengthOfBits << " bits." << endl;

    return 0;
}