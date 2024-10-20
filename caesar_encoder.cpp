#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <limits>

using namespace std;

int main()
{
char choice;
bool running = true;
while (running ){
// declare variables:
char message[250];
char output[250];

int shift;

cout << "Type your message here: \n" << endl; // Type a message here and press enter

cin.ignore(); // Ignore leftover newline from previous input
cin.getline(message,250); // Get user input from the keyboard

cout << "Enter the shift value: \n" << endl;
cin>> shift;
// discards the input buffer
cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            output[i]= item;
        }
    else{
        output[i]=item;
    }
    }
 cout << "Encrypted message: " << output << endl;

  // Ask the user if they want to run again
 cout << "Do you want to encode another message? (y/n): " << endl;
 cin >> choice;
 if (choice != 'y'){
    running = false;
 }
 
}

    cout << "See you later!" << endl;

   return 0;

}