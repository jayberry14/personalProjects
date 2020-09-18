std::string sumOfStrings(std::string a, std::string b) {
    std::string c;
    std::string::iterator iterA = a.begin();
    std::string::iterator iterB = b.begin();
    for (int i = 0; iterA != a.end(); ++iterA, ++iterB, ++i) {
        cout << "A at [" << i << "] is: " << a[i] << endl;
        cout << "B at [" << i << "] is: " << b[i] << endl;
        c = to_string(*iterA) + to_string(*iterB);
        cout << "This is c: " << c[i] << endl;
    }
    return c;
}




'Add every ith digit of the first string to the ith digit of the second string,
both counted from the end. If the ith digit of one of the strings is absent, 
the sum will be the ith digit of the other string. Return a string of those sums concatenated with each other.

For a = "99" and b = "99", the output should be sumOfStrings(a, b) = "1818".

The sums of both, the first and the second numbers are 18, so the answer is 1818.

For a = "11" and b = "9", the output should be sumOfStrings(a, b) = "110".

The sum of the first numbers from the end is 10, and the sum of the second numbers from the end is 1, so the answer is 110.'