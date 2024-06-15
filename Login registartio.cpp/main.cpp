
#include <iostream>
#include <fstream>
#include <string>
#include "registration.hpp"
#include "login.hpp"
#include "password.hpp"

using namespace std;

int main() {
    Registration registration;
    Login login;
    RecoverPassword pass;

    int choice;
    string username, password, name, ans;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Forgot password\n";
        cout << "4. Exit\n";

        try {
            cout << "\nEnter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice > 4 || choice < 1) {
                throw 0;
            } else {
                switch (choice) {
                case 1:
                    cout << "Enter your First Name: ";
                    cin >> name;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    cout << "What is your favorite movie? (This is the secret question)"<<endl;
                    cout << "Your answer in a single word: ";
                    cin >> ans;
                    registration.addUser(name, username, password, ans);
                    break;

                case 2:
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    login.authenticate(username, password);
                    break;

                case 3:
                    cout << "Enter username: ";
                    cin >> username;
                    cout<<"What is your favorite movie?";
                    pass.recover(username);
                    break;

                case 4:
                    cout << "Goodbye!" << endl;
                    exit(0);
                    //break;

                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
                }
            }
        } catch (int n) {
            cerr << "Error: " << "Enter valid choice" << endl;
        }
        catch(...){
            cout<<"Unexpected Error occured";
        }
    }

    return 0;
}

