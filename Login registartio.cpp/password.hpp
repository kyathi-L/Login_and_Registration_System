#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Userss {
    string name;
    string username;
    string password;
    string ans;
};

class RecoverPassword {
public:
    // Function to recover a user's password based on security question and answer
    bool recover(const string& username) {
        ifstream file("users.txt"); // Open the file for reading
        Userss user;
        string answer;

        cout << "Enter your answer: ";
        cin >> answer;

        while (file >> user.name>>user.username >> user.password >> user.ans) {
            // Compare stored credentials with provided credentials
            if (user.username == username && user.ans == answer) {
                cout << "Password recovered successfully." << endl;
                cout << "Your Password: " << user.password << endl;
                file.close();
                return true;
            }
        }

        file.close();
        cout << "Password recovery failed. Invalid credentials." << endl;
        return false;
    }
};
