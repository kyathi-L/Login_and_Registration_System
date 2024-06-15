#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Users{
    string name;
    string username;
    string password;
    string ans;
};
class Login{
    public:
        // Function to authenticate a user based on provided credentials
        bool authenticate(const string& username, const string& password){
            ifstream file("users.txt"); // Open the file for reading
            Users user;
            while (file >> user.name>>user.username >> user.password >> user.ans){
                // Compare stored credentials with provided credentials
                if (user.username == username && user.password == password){
                    cout << "Login successful." << endl;
                    file.close();
                    return true;
                }
            }
            file.close();
            cout << "Login failed. Invalid credentials." << endl;
            return false;
        }
};
