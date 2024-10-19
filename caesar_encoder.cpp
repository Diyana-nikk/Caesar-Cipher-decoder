#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
string x; 
cout << "Type your message here: \n"; // Type a message here and press enter
char message[250];
char output[250];
cin.getline(message,250); // Get user input from the keyboard

int shift;

cout << "Enter the shift value: \n" << endl;
cin>> shift;

const int length = strlen(message); 

char item;
for (int i = 0; i < length+1; i++) { 
      item = message[i]; // get ith character of the message

    // if lower case
   if (item >= 'a' && item <= 'z'){
            item = ((item - 'a' + shift) % 26) + 'a'; //Wrap-around for lowercase ASKII characters
            output[i] = item;
        }

    // if upper case
        else if (item >= 'A' && item <= 'Z'){
            item = ((item - 'A' + shift) % 26) + 'A'; //Wrap-around for uppercase
            output[i]g+ = item;
        }
    else{
        output[i]=item;
    }
    }
 cout << "Encrypted message: " << output << endl;
   return 0;
}