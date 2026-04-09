#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//#include <argon2.h>

using namespace std;

class PasswordEntry {
private:
    string username;
    string password;
    string apps;

public:
    PasswordEntry(string u, string p, string a) : username(u), password(p), apps(a) {}

    void display() {
        cout << "App: " << apps << " | Username: " << username << " | Password: " << password << endl;
    }
};

int main() {
    string usernames[5] = {};
    string passwords[5] = {};
    string apps[5] = {};
    int options;
    int entryCount = 0;

    do {
        cout << "\n--- Password Management Options ---" << endl;
        cout << "1. Add New Password" << endl;
        cout << "2. List All Passwords" << endl;
        cout << "3. Search For Passwords" << endl;
        cout << "4. Update Passwords" << endl;
        cout << "5. End program" << endl;
        cout << "Selection: ";
        cin >> options;

        switch (options) {
            case 1:
                if (entryCount < 5) {
                    cout << "Enter App: "; cin >> apps[entryCount];
                    cout << "Enter Username: "; cin >> usernames[entryCount];
                    cout << "Enter Password: "; cin >> passwords[entryCount];
                    entryCount++;
                } else {
                    cout << "Storage full!" << endl;
                }
                break;

            case 2:
                for (int i = 0; i < entryCount; i++) {
                    PasswordEntry myEntry(usernames[i], passwords[i], apps[i]);
                    myEntry.display();
                }
                break;
                
            case 3:
                break;

            case 4:
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
                break;
        }
    } while (options != 5);

    return 0;
}
