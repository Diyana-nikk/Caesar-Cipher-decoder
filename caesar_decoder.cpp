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

cout << "Enter the shift value: \n";
cin>> shift;

const int length = strlen(message); 

char item;
for (int i = 0; i < length+1; i++) { 
      item = message[i]; // get ith character of the message

    // if lower case
    if (item >='a' && item <= 'z'){
        item= item + shift;
        if(item>'z'){
            item=item-'z'+'a'-1; // loop over
        }
        output[i]=item;
    }

    //if lowercase:
    else if (item >='A' && item <='Z'){
        item = item + shift;
         if(item>'Z'){
            item=item-'Z'+'A'-1; // loop over
        }
        output[i]=item;
    }
    else{
        output[i]=item;
    }
    }
 cout << "Encrypted message: " << output;
}