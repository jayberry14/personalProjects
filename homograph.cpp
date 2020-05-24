#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <list>
#define GetCurrentDir getcwd

using namespace std;
string GetCurrentWorkingDir(void);

/*********************
 * CANONICALIZATION
 * *******************/
list<string> canonicalization(string encoding) {
    //Write parsing code here
    list <string> cleanPath;
    string temp = "";

    if (encoding[0] == '~') {
        cleanPath.push_back("home");
        cleanPath.push_back("may15012");
    }
    
    for (int i = 0; i < encoding.size(); i++) {
        if (encoding[i] != '/') {
            temp += encoding[i];
            i++;
            while (encoding[i] != '/' && i < encoding.size()) {
                temp += encoding[i];
                i++;
            }
            cleanPath.push_back(temp);
            temp.clear();
        }
    }
    
    cleanPath.remove(".");
    cleanPath.remove("~");
    return cleanPath;
}

/*******************************
 * IS HOMOGRAPH
 *******************************/
bool isHomograph(string input, string forbiddenPath) {
    list<string> forbiddenL = canonicalization(forbiddenPath);
    list<string> userL = canonicalization(input);
    string curDir = GetCurrentWorkingDir();
    list<string> userDir = canonicalization(curDir);

    list<string> :: iterator firstWord = userL.begin();
    if (*firstWord != "home") {
        userL.splice(userL.begin(), userDir);
    }
            
    list<string> :: iterator userIter = userL.begin();
    
    for(auto i = userL.begin(); i != userL.end();) {
        if(*i == "..") {
            if (userL.size() > 1 && i != userL.begin()) {
                list<string> :: iterator userIter1 = i;
                list<string> :: iterator userIter2 = --i;
                userL.erase(userIter1);
                userL.erase(userIter2);
                i = userL.begin();
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    
    userL.remove("..");
    return (userL == forbiddenL) ? true : false;
}

/***************************************************************************************************/
//CURRENT WORKING DIRECTOR GETTER FUNCTION
//SOURCE : http://www.codebind.com/cpp-tutorial/c-get-current-directory-linuxwindows/

string GetCurrentWorkingDir(void) { //Returns the Absolute Path
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}
/**************
 * MAIN
 * ************/
int main(int argc, char const *argv[]) {
    string input; 
    int option;
    bool done = false;
    string forbiddenPath = "/home/may15012/secret/topSecret/password.txt";

    while (!done) {
        cout << "Options:" << endl 
            << "1. Test case #1" << endl 
            << "2. Test case #2" << endl
            << "3. Test case #3" << endl
            << "4. Test case #4" << endl
            << "5. Test case #5" << endl
            << "6. Test case #6" << endl
            << "7. Test case #7" << endl
            << "8. Test case #8" << endl
            << "9. Test case #9" << endl
            << "10. Test case #10" << endl
            << "11. User input" << endl
            << "12. Exit" << endl
            << "Insert number: ";
        cin >> option;

        switch (option)
        {
        case 1:
            input = "/home/may15012/../may15012/././././././secret/topSecret/password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;
            
        case 2:
            input = "~/secret/../secret/.././././././../may15012/secret/./topSecret/../../secret/topSecret/password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;
            
        case 3:
            input = "~/secret/topSecret/../../../may15012/secret/topSecret/password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;
            
        case 4:
            input = "/home/may15012/secret//topSecret";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;
            
        case 5:
            input = "home/may15012//secret/////topSecret/password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;

        case 6:
            input = "~/../../../../../../home/may15012/secret/topSecret/password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;

        case 7:
            input = "/secret/secret/topSecret/password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;

        case 8:
            input = "/home/may15012/../../../../secret/topSecret/password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;

        case 9:
            input = "home/may15012/secret/topsecret/password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;
            
        case 10:
            input = "~/././././././password.txt";
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;
        
        case 11:
            cout << "Enter file path: ";
            cin >> input;
            cout << "Path is : " << input << endl;
            cout << "Checking to see if file path is a homograph of the forbidden path..." << endl << endl;
            if (isHomograph(input, forbiddenPath)) {
                cout << "They are homographs!" << endl;
            }
            else {
                cout << "They are not homographs!" << endl;
            }
            break;
        
        case 12:
            done = true;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }


    return 0;
}