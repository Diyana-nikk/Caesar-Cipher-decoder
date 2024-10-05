#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
string x; 
cout << "Type your message here: "; // Type a message here and press enter
cin >> x; // Get user input from the keyboard
  
const int length = x.length(); 
char* char_array = new char[length + 1]; 

for (int i = 0; i < x.length(); i++) { 
        char_array[i] = x[i]; 
    }

}