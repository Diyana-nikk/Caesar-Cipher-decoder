#include <iostream>
#include <string>  // Use string for dynamic input size
#include <limits>

using namespace std;

int main() {
    char choice;
    bool running = true;

    while (running) {
        // Declare variables
        string message;
        string output;
        int shift;

        // Get user input for the message
        cout << "Type your message here: \n" << endl;
        getline(cin, message); 

        // Try getting the shift value
        cout << "Enter a positive integer shift value: \n" << endl;
        cin >> shift;

        // While the input is invalid, make the user re-enter the shift value
        while (cin.fail() || shift < 0) {
            cin.clear();  // Clear the error flag on `cin`
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore remaining characters in the input buffer
            cout << "Nice try, please enter a valid positive integer: \n" << endl;
            cin >> shift;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline after the shift input

        // Reduce the shift value modulo 26 to ensure it wraps around the alphabet
        shift = shift % 26;

        // Encrypt the message
        for (char item : message) {
            // If lowercase
            if (item >= 'a' && item <= 'z') {
                item = ((item - 'a' + shift) % 26) + 'a';  // Wrap-around for lowercase ASCII characters
                output += item;
            }
            // If uppercase
            else if (item >= 'A' && item <= 'Z') {
                item = ((item - 'A' + shift) % 26) + 'A';  // Wrap-around for uppercase
                output += item;
            }
            else {
                output += item;  // Non-alphabetic characters remain unchanged
            }
        }

        cout << "Encrypted message: " << output << endl;

        // Ask the user if they want to run again
        cout << "Do you want to encode another message? (y/n): " << endl;
        cin >> choice;

        if (choice != 'y') {
            running = false;
        }

        // Clear input buffer for next iteration
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "See you later!" << endl;

    return 0;
}
