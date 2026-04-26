#include <iostream>
#include <string>

using namespace std;

class PasswordEntry {
	private:
		string app;
		string username;
		string password;
	public:
		string getApp() {
			return app;
		}
		void setApp(string inputApp) {
			app = inputApp;
			return;
		}
		string getUsername() {
			return username;
		}
		void setUsername(string inputUsername) {
			username = inputUsername;
			return;
		}
		string getPassword() {
			return password;
		}
		void setPassword(string inputPassword) {
			password = inputPassword;
			return;
		}
		PasswordEntry(string inputApp, string inputUsername, string inputPassword) : app(inputApp), username(inputUsername), password(inputPassword) {}
		PasswordEntry() {}
};

PasswordEntry PasswordEntries[5];
unsigned long long PasswordEntriesSize = 0;
const unsigned long long PasswordEntriesMaxSize = 5;

void MenuAddEntry();
void MenuListEntries();
void MenuSearchEntries();
void MenuUpdateEntryApp();
void MenuUpdateEntryUsername();
void MenuUpdateEntryPassword();
void MenuRemoveEntry();

int main() {
	bool menuState = true;
	int userInput;
	
	do {
		cout << "\n-------------------------";
		cout << "\nSimple Password Manager Main Menu";
		cout << "\nEnter an option (1-7):";
		cout << "\n  1. Add Entry";
		cout << "\n  2. List Entries";
		cout << "\n  3. Search For Entry";
		cout << "\n  4. Update Entry App";
		cout << "\n  5. Update Entry Username";
		cout << "\n  6. Update Entry Password";
		cout << "\n  7. Remove Entry";
		cout << "\n  8. Exit";
		cout << "\n\n> ";
		cin >> userInput;
		cout << "\n";
		
		switch (userInput) {
			case 1:
				MenuAddEntry();
				break;
			case 2:
				MenuListEntries();
				break;
			case 3:
				MenuSearchEntries();
				break;
			case 4:
				MenuUpdateEntryApp();
				break;
			case 5:
				MenuUpdateEntryUsername();
				break;
			case 6:
				MenuUpdateEntryPassword();
				break;
			case 7:
				MenuRemoveEntry();
				break;
			case 8:
				menuState = false;
				break;
			default:
				cout << "\nInvalid input! Must be an integer from 1 - 7.";
				break;
		}
	} while (menuState);
	
	return 0;
}

bool AppExists(string inputApp) {
	for (unsigned long long i = 0; i < PasswordEntriesSize; ++i) {
		if (PasswordEntries[i].getApp() == inputApp) {
			return true;
		}
	}
	return false;
}
bool EntryExists(string inputApp, string inputUsername) {
	for (unsigned long long i = 0; i < PasswordEntriesSize; ++i) {
		if (PasswordEntries[i].getApp() == inputApp && PasswordEntries[i].getUsername() == inputUsername) {
			return true;
		}
	}
	return false;
}
unsigned long long GetEntryIndex(string inputApp, string inputUsername) {
	for (unsigned long long i = 0; i < PasswordEntriesSize; ++i) {
		if (PasswordEntries[i].getApp() == inputApp && PasswordEntries[i].getUsername() == inputUsername) {
			return i;
		}
	}
	return PasswordEntriesSize;
}
void AddEntry(PasswordEntry inputEntry) {
	PasswordEntries[PasswordEntriesSize] = inputEntry;
	++PasswordEntriesSize;
	return;
}
void UpdateApp(string targetApp, string targetUsername, string newApp) {
	PasswordEntries[GetEntryIndex(targetApp, targetUsername)].setApp(newApp);
	return;
}
void UpdateUsername(string targetApp, string targetUsername, string newUsername) {
	PasswordEntries[GetEntryIndex(targetApp, targetUsername)].setUsername(newUsername);
	return;
}
void UpdatePassword(string targetApp, string targetUsername, string newPassword) {
	PasswordEntries[GetEntryIndex(targetApp, targetUsername)].setPassword(newPassword);
	return;
}
void RemoveEntry(string inputApp, string inputUsername) {
	if (PasswordEntriesSize > 0) {
		for (unsigned long long i = GetEntryIndex(inputApp, inputUsername); i < PasswordEntriesSize - 1; ++i) {
			PasswordEntries[i] = PasswordEntries[i + 1];
		}
		--PasswordEntriesSize;
	}
	return;
}
void MenuAddEntry() {
	if (PasswordEntriesSize >= PasswordEntriesMaxSize) {
		cout << "The entry array is full!\n\n";
		return;
	}
	string newApp;
	cout << "Enter app: ";
	cin >> newApp;
	string newUsername;
	cout << "Enter username: ";
	cin >> newUsername;
	if (EntryExists(newApp, newUsername)) {
		cout << "That username already exists for that app!\n\n";
		return;
	}
	string newPassword;
	cout << "Enter password: ";
	cin >> newPassword;
	AddEntry(PasswordEntry(newApp, newUsername, newPassword));
	cout << "Entry created.\n\n";
	return;
}
void MenuListEntries() {
	if (PasswordEntriesSize == 0) {
		cout << "No entries to list.\n\n";
		return;
	}
	cout << "Entries (" << PasswordEntriesSize << "/" << PasswordEntriesMaxSize << "):\n\n";
	for (unsigned long long i = 0; i < PasswordEntriesSize; ++i) {
		cout << "  App: " << PasswordEntries[i].getApp() << "\n";
		cout << "  Username: " << PasswordEntries[i].getUsername() << "\n";
		cout << "  Password: " << PasswordEntries[i].getPassword() << "\n\n";
	}
	return;
}
void MenuSearchEntries() {
	string inputApp;
	cout << "Enter the app to search: ";
	cin >> inputApp;
	cout << "Searching...";
	bool appFound = false;
	
	for (unsigned long long i = 0; i < PasswordEntriesSize; ++i) {
		if (inputApp.size() <= PasswordEntries[i].getApp().size() && inputApp == PasswordEntries[i].getApp().substr(0, inputApp.size())) {
			if (!appFound) {
				cout << "\nEntry found!\n";
			}
			appFound = true;
			cout << "\n  App: " << PasswordEntries[i].getApp() << "\n  Username: " << PasswordEntries[i].getUsername() << "\n  Password: " << PasswordEntries[i].getPassword() << "\n";
		}
	}
	if (!appFound) {
		cout << "\nCould not find an entry using the app search criteria.\n";
	}
	cout << "\n";
	return;
}
void MenuUpdateEntryApp() {
	string oldApp;
	cout << "Enter the app that contains the username: ";
	cin >> oldApp;
	if (!AppExists(oldApp)) {
		cout << "That app doesn't exist!\n\n";
		return;
	}
	string inputUsername;
	cout << "Enter the username to update: ";
	cin >> inputUsername;
	if (!EntryExists(oldApp, inputUsername)) {
		cout << "That username doesn't exist!\n\n";
		return;
	}
	string newApp;
	cout << "Enter the new app: ";
	cin >> newApp;
	if (EntryExists(newApp, inputUsername)) {
		cout << "That app and username entry already exists!\n\n";
		return;
	}
	UpdateApp(oldApp, inputUsername, newApp);
	cout << "App changed.\n\n";
	return;
}
void MenuUpdateEntryUsername() {
	string inputApp;
	cout << "Enter the app that contains the username: ";
	cin >> inputApp;
	if (!AppExists(inputApp)) {
		cout << "That app doesn't exist!\n\n";
		return;
	}
	string oldUsername;
	cout << "Enter the username to update: ";
	cin >> oldUsername;
	if (!EntryExists(inputApp, oldUsername)) {
		cout << "That username doesn't exist!\n\n";
		return;
	}
	string newUsername;
	cout << "Enter the new username: ";
	cin >> newUsername;
	if (EntryExists(inputApp, newUsername)) {
		cout << "That app and username entry already exists!\n\n";
		return;
	}
	UpdateUsername(inputApp, oldUsername, newUsername);
	cout << "Username changed.\n\n";
	return;
}
void MenuUpdateEntryPassword() {
	string inputApp;
	cout << "Enter the app that contains the username: ";
	cin >> inputApp;
	if (!AppExists(inputApp)) {
		cout << "That app doesn't exist!\n\n";
		return;
	}
	string inputUsername;
	cout << "Enter the username to update: ";
	cin >> inputUsername;
	if (!EntryExists(inputApp, inputUsername)) {
		cout << "That username doesn't exist!\n\n";
		return;
	}
	string newPassword;
	cout << "Enter the new password: ";
	cin >> newPassword;
	UpdatePassword(inputApp, inputUsername, newPassword);
	cout << "Password changed.\n\n";
	return;
}
void MenuRemoveEntry() {
	string inputApp;
	cout << "Enter the app that contains the username: ";
	cin >> inputApp;
	if (!AppExists(inputApp)) {
		cout << "That app doesn't exist!\n\n";
		return;
	}
	string inputUsername;
	cout << "Enter the username to remove: ";
	cin >> inputUsername;
	if (!EntryExists(inputApp, inputUsername)) {
		cout << "That username doesn't exist!\n\n";
		return;
	}
	RemoveEntry(inputApp, inputUsername);
	cout << "Username removed.\n\n";
	return;
}
