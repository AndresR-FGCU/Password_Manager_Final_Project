#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <argon2.h>

using namespace std;

class PasswordEntry {
private:
    string username;
    string password;

public:
    PasswordEntry(string u, string p) : username(u), password(p) {
    }

    void display() {
        cout << "Username: " << username << " | Password: " << password << endl;
    }
};

int main() {

    string usernames[5] = {};
    string passwords[5] = {};

    int i = 0;


    cout << "Enter your Username: " << endl;
    cin >> usernames[i];
    cout << "Enter your Password: " << endl;
    cin >> passwords[i];

    PasswordEntry myEntry(usernames[i],passwords[i]);
        myEntry.display();


    return 0;
}
