#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct User{
    string name;
    string username;
    string password;
    string ans;
};
class Registration{
    public:
        // Function to add a user and store their data in the file
        void addUser(const string& name,const string& username, const string& password,const string& ans){
            User user;
            user.name = name;
            user.username = username;
            user.password = password;
            user.ans = ans;
            saveUser(user); // Save the user's data to the file
            cout << "User registered successfully." << endl;
        }

        // Function to save a user's data to the file
        void saveUser(const User& user){
            ofstream file("users.txt", ios::app); // Open the file in append mode
            if (file.is_open()){
                file << user.name<<' '<< user.username << ' ' << user.password<< ' ' << user.ans<< '\n'; // Write user data to the file
                file.close();
            }
        }
};
