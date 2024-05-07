/*/ Write a Java/C/C++/Python program that contains a string (char pointer)
with a value \Hello World’. The program should AND or and XOR each character in
this string with 127 and display the result.
*/

#include<iostream>
#include<string>
using namespace std;
void printCharList(const string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        cout << " " << ch;
    }
}
void printAsciiList(const string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int asciiValue = static_cast<int>(ch);
        cout << " " << asciiValue;
    }
}
void printXoredList(const string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int asciiValue = static_cast<int>(ch);
        int xorList = asciiValue ^ 127;
        cout << " " << xorList;
    }
}
void printNewCharList(const string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int asciiValue = static_cast<int>(ch);
        int xorList = asciiValue ^ 127;
        char chnew = static_cast<char>(xorList);
        cout << " " << chnew;
    }
}
void printStringList(const string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int asciiValue = static_cast<int>(ch);
        int xorList = asciiValue ^ 127;
        char chnew = static_cast<char>(xorList);
        string resultString(1, chnew);
        cout << " " << resultString;
        
    }
}
int main()
{
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    cout << "Character List: ";
    printCharList(inputString);

    cout << "\nInteger List: ";
    printAsciiList(inputString);

    cout << "\nXored List: ";
    printXoredList(inputString);
    
    cout << "\nNew Character List: ";
    printNewCharList(inputString);

    cout << "\nString List: ";
    printStringList(inputString);

    return 0;
}