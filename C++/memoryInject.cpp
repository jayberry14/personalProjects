/***********************************************
 * Names:
 * Rio Moura
 * CJ Waisath
 * Robby Breidenbaugh
 * Josh Mayberry
 * Jason Jenkins
 * Michael Flindt
 *********************************************/
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

/**********************************************
 * SUBTERFUGE VULNERABILITY
 * 1. There must be a pointer used in the code.
 * 2. Through some vulnerability, there must be
 *    a way for user input to overwrite the pointer.
 *    This typically happens through a stack buffer
 *    vulnerability.
 * 3. After the pointer is overwritten, the pointer
 *    must be dereferenced.
 **********************************************/
void subterfugeVulnerability(long * array, int size)
{
    long buffer[2];
    const char * message = "Safe";

    for (int i = 0; i < size; i++)
        buffer[i] = array[i];

    cout << "\tMessage is: \"" << message << "\".\n";
}

/**********************************************
 * SUBTERFUGE WORKING
 * Call subterfugeVulnerability() in a way that does
 * not yield unexpected behavior
 **********************************************/
void subterfugeWorking()
{
    // non-malicious array
    long array[2] = {1, 1};

    // execute the code
    subterfugeVulnerability(array, 2);
}

/**********************************************
 * SUBTERFUGE EXPLOIT
 * 1. The attacker must exploit a vulnerability
 *    allowing unintended access to the pointer.
 * 2. The attacker must be able to provide a new
 *    pointer referring to data altering the normal
 *    flow of the program.
 **********************************************/
void subterfugeExploit()
{
    // an attacker's array
    long array[3] = {1, 1, (long)"Dangerous"};

    // exploit it
    subterfugeVulnerability(array, 3);
}

/*************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ****************************************/
void arrayVulnerability(long &input) //TODO insert parameters
{
    // insert code here
    long array[4];
    bool authenticated = false;             // the asset

    array[input] = -1;

    cout << "\tAuthenticated is: \"" << boolalpha << authenticated << "\"\n"; 
}

/**************************************
 * ARRAY WORKING
 * Call arrayVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void arrayWorking()
{
    // non-malicious input
    long input = 2;

    // execute the code
    arrayVulnerability(input); // TODO pass parameters here
}

/**************************************
 * ARRAY EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void arrayExploit()
{
    // an attacker's input
    long input = 5;

    // exploit it
    arrayVulnerability(input); // TODO pass parameters here
}

/**********************************************
 * ARC Injection
 * 1. There must be a function pointer used in the code.
 * 2. Through some vulnerability, there must be a way for user input to
 *    overwrite the function pointer. This typically happens through a stack
 *    buffer vulnerability.
 * 3. After the memory is overwritten, the function pointer must be
 *    dereferenced
 **********************************************/
void safe() { cout << "\tYou are safe :)\n"; }
void dangerous() { cout << "\tYou are in danger :(\n"; }
void arcVulnerability(long * array, long sizeOfArray) //TODO insert parameters
{
    long buffer[1];
    void (* pointerFunction)() = safe;
    
    for (int i = 0; i < sizeOfArray; i++)
    {
        buffer[i] = array[i]; // input references pointerFunction
    }
    pointerFunction();
}

/***********************************************
* ARC WORKING
* Call arcVulnerability() in a way that does
* not yield unexpected behavior
************************************************/
void arcWorking()
{
    //non-malicous input
   long array[1] = {2};
   
    // execute the code
    arcVulnerability(array, 1); // TODO pass parameters here
}

/**************************************
 * ARC EXPLOIT
 * 1. The attacker must exploit a vulnerability allowing
 *    unintended access to the function pointer.
 * 2. The attacker must have the address to another function
 *    which is to be used to replace the existing function pointer.
 *************************************/
void arcExploit()
{
    // an attacker's array
    long array[2] = {3, (long)(void *)dangerous};
    
    // exploit it
    arcVulnerability(array, 2); // TODO pass parameters here
}

/**********************************************
 * VTABLE SPRAYING
 *  1. The vulnerable class must be polymorphic.
 *  2. The class must have a buffer as a member variable.
 *  3. Through some vulnerability, there must be a way for user input to
 *     overwrite parts of the V-Table.
 *  4. After a virtual function pointer is overwritten, the virtual function must
 *     be called.
 **********************************************/
class vulnerable   //Vulnerable Class
{
public:
    virtual void safe(int i) = 0; // polymorphic function
private:
    long buffer[2]; // an array in the class that has a vulnerability

};

class vulnerableDerived : public vulnerable 
{
    public:
        void safe(int i) // polymorphic function
        {
            if (i < sizeof(buffer) / sizeof(buffer[0]))
            {
                buffer[i] = 1;
                cout << "\tWE ARE GOOD BOYZ!!!!" << endl;
            }
            else if (i >= sizeof(buffer) / sizeof(buffer[0]))
            {
                cout << "\tTHIS WOULD HAVE SMASHED A CORE DUMP :O" << endl;
            }
        }
    private:
        long buffer[2]; // an array in the class that has
};


 // a buffer overrun vulnerability

void vtableVulnerability(int i) //TODO insert parameters
{
    vulnerableDerived information;
    information.safe(i);
}

/***********************************************
* VTABLE WORKING
* Call vtableVulnerability() in a way that does
* not yield unexpected behavior
************************************************/
void vtableWorking()
{
    // insert code here

    // execute the code
    vtableVulnerability(1); // TODO pass parameters here
}

/***********************************************
 * VTABLE EXPLOIT 
 * 1. Through some vulnerability, the V-Table pointer or a function pointer
 *    within the V-Table must be overwritten.
 * 2. The attacker must have the address to another V-Table pointer or a
 *    function pointer.
 ***********************************************/
void vtableExploit()
{
    // insert code here

    // exploit it
    vtableVulnerability(3); // TODO pass parameters here
}

/**********************************************
 * STACK SMASHING
 * 1. There must be a buffer (such as an array) on the stack.
 * 2. The buffer must be reachable from an external input.
 * 3. The mechanism to fill the buffer from the external input must not
 *    correctly check for the buffer size.
 * 4. The buffer must be overrun (extend beyond the intended limits of the
 *    array).
 **********************************************/
void stackVulnerability(char input) //TODO insert parameters // Contains stack smashing vulnerability
{
	char text[input];
    // insert code here
    char buffer[8];
    if (sizeof(text) / sizeof(text[0]) > sizeof(buffer) / sizeof(buffer[0]))
        cout << "\tWe are in danger!" << endl;
    else
        cout << "\tWe are safe!" << endl;
}

/***********************************************
* STACK WORKING
* Call stackVulnerability() in a way that does
* not yield unexpected behavior
************************************************/
void stackWorking() // Calls stackVulnerability() with non-malicious attack
{
    // insert code here
    char input = 8;

    // execute the code
    stackVulnerability(input); // TODO pass parameters here
}

/***********************************************
 * STACK EXPLOIT 
 * 1. Through some vulnerability, the V-Table pointer or a function pointer
 *    within the V-Table must be overwritten.
 * 2. The attacker must have the address to another V-Table pointer or a
 *    function pointer.
 ***********************************************/
void stackExploit() // Calls stackVulnerability() and exploits it
{
    // insert code here
    char input = 12;

    // exploit it
    stackVulnerability(input); // TODO pass parameters here // Call to exploit vulnerability
}

/**********************************************
 * HEAP SPRAYING
 * 1. There must be two adjacent heap buffers.
 * 2. The first buffer must be reachable through external input.
 * 3. The mechanism to fill the buffer from the external input must not
 *    correctly check for the buffer size.
 * 4. The second buffer must be released before the first.
 * 5. The first buffer must be overrun (extend beyond the intended limits of
 *    the array).
 **********************************************/
void heapVulnerability(char input[]) //TODO insert parameters // Contains a heap smashing vulnerability
{
    char * buffer1 = new char[4]; // requires two buffers on the heap
	char * buffer2 = new char[4];
	
	assert(buffer1 < buffer2); // buffer 1 must be before buffer 2!

	if (sizeof(input) / sizeof(input[0]) > 4)
    {
        cout << input << endl;
	}
    
	else
    {
        strcpy(buffer1, input);
    }

	delete [] buffer2; // need to delete second buffer first
	delete [] buffer1;

}

/***********************************************
* HEAP WORKING
* Call heapVulnerability() in a way that does
* not yield unexpected behavior
************************************************/
void heapWorking() // Calls heapVulnerability() with non-malicious attac
{
    // insert code here
	char input[] = {"\tSafe"};

    // execute the code
    heapVulnerability(input); // When function is called it displays heap spraying
}

/***********************************************
 * HEAP EXPLOIT 
 * 1. The attacker must provide more data into the outwardly facing heap
 *    buffer than the buffer is designed to hold.
 * 2. The attacker must know the layout of the Memory Control Block (MCB)
 *    (essentially a linked list) residing just after the buffer.
 * 3. The attacker must provide a new MCB containing both the location of
 *    the memory overwrite and the new data to be overwritten.
 ***********************************************/
void heapExploit() //Calls heapVulnerability() and demostrates heap spraying
{
    // insert code here
    char input[] = {"\tWe have sprayed the heap"};

    // exploit it
    heapVulnerability(input); // TODO pass parameters here
}

/**********************************************
 * INT VULNERABILITY
 * 1. There must be a security check represented by an expression.
 * 2. The expression must have the potential for overflow.
 * 3. At least one of the numbers used to compute the sentinel
 *    must be reachable through external input. This sentinel is
 *    a variable used to make the security decision from the first requirement.
 **********************************************/
void intVulnerability(char offset) //TODO insert parameters
{
    // insert code here
    char buffer[128];
    char * sentinel = buffer + 127;   // the end of the buffer, 0 + 127
    char authenticated = 'T';
    for (int i = 0; i < 128; ++i)
    {
    	buffer[i] = authenticated;
    }
    
    if (offset + buffer < sentinel)  // SENTINEL NEEDS TO BE 255
    {
        cout << "\tDisplaying letter T from buffer[]: " << buffer[offset] << endl; //this represents the input a user enters
    }

    cout << "\tIf letter is not T, overflow has occurred!" << endl;
}

/***********************************************
* INTEGER OVERFLOW WORKING
* Call intVulnerability() in a way that does
* not yield unexpected behavior
************************************************/
void integerWorking() // calls int vulnerability without non-malicious attack
{
    // insert code here
    char offset = 64;

    // execute the code
    intVulnerability(offset); // TODO pass parameters here
}

/***********************************************
* INTEGER OVERFLOW WORKING
* 1. Provide input, either a buffer size or a single value, that is directly or
*    indirectly used in the vulnerable expression.
* 2. The input must exceed the valid bounds of the data-type, resulting in an
*    overflow or underflow condition
************************************************/
void integerExploit() // Manipulates vulnerable function
{
    // insert code here
    char offset = 240;

    // exploit it
    intVulnerability(offset); // TODO pass parameters here
}

/**********************************************
 * ANSI-Unicode Conversion
 * 1. There must be a buffer where the basetype is greater than one.
 * 2. Validation of the buffer must check the size of the buffer rather than the
 *    number of elements in the buffer.
 **********************************************/
void ansiVulnerability(long index) //TODO insert parameters // Vulnerable to ANSI-unicode attack
{
    long unicodeText[256];

    if (index < sizeof(unicodeText))
    {
        if (index < (sizeof(unicodeText)/sizeof(unicodeText[0])))
        {
            cout << "\tWe are safe!\n";
        }    
        else
        {
            cout << "\tWe are in danger!\n";
        }
    }
}

/***********************************************
* ANSI WORKING
* Call ansiVulnerability() in a way that does
* not yield unexpected behavior
************************************************/
void ansiWorking() // Calls ansiVulnerability() with non-malicious input
{
    // insert code here
    long input = 16;
    cout << "\tANSI Working:\n";

    // execute the code
    ansiVulnerability(input); // TODO pass parameters here
}

/***********************************************
 * ANSI EXPLOIT
 * 1. The attacker must provide more than half as much data into the
 *      outwardly facing buffer as it is designed to hold.
 * 2. From here, a variety of injection attacks are possible. The most likely
 *      candidates are stack smashing or heap smashing. In the above example,
 *      the third parameter of the copyUnicodeText() function is the number
 *      of elements in the string (256 elements), not the size of the string (512
 *      bytes). The end result is a buffer overrun of 256 bytes.
************************************************/
void ansiExploit() // Manipulates vulnerable function that was not intended by author
{
    // insert code here
    long input = 300;
    cout << "\tANSI Exploit:\n";

    // exploit it
    ansiVulnerability(input); // TODO pass parameters here
}

/**********************************************
 * MAIN : Старый, добрый Мэйн
 **********************************************/
int main()
{
    cout << "***************************************" << endl;
    cout << "Point Subterfuge:" << endl;
    cout << "\tSubterfuge Working:" << endl;
    subterfugeWorking();
    cout << "\tSubterfuge Exploit:" << endl;
    subterfugeExploit();
    cout << endl;

    cout << "***************************************" << endl;
    cout << "Array Index:" << endl;
    cout << "\tArray Working:" << endl;
    arrayWorking();
    cout << "\tArray Exploit:" << endl;
    arrayExploit();
    cout << endl;

    cout << "***************************************" << endl;
    cout << "ARC Injection:" << endl;
    arcWorking();
    arcExploit();
    cout << endl;

    cout << "***************************************" << endl;
    cout << "VTable Spraying:" << endl;
    vtableWorking();
    vtableExploit();
    cout << endl;

    cout << "***************************************" << endl;
    cout << "Stack Smashing:" << endl;
    stackWorking();
    stackExploit();
    cout << endl;

    cout << "***************************************" << endl;
    cout << "Heap Spraying:" << endl;
    heapWorking();
    heapExploit();
    cout << endl;

    cout << "***************************************" << endl;
    cout << "Integer Overflow:" << endl;
    integerWorking();
    integerExploit();
    cout << endl;

    cout << "***************************************" << endl;
    cout << "ANSI-Unicode Conversion:" << endl;
    ansiWorking();
    ansiExploit();
    cout << endl;

    return 0;
}