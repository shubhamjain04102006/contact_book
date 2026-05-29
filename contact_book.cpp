#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Convert string to lowercase for case-insensitive search
string toLowerCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}

// Contact class
class Contact {
public:
    string name;
    string phone;
    string email;

    Contact() {}

    Contact(string n, string p, string e) {
        name = n;
        phone = p;
        email = e;
    }

    void display() {
        cout << "Name  : " << name << endl;
        cout << "Phone : " << phone << endl;
        cout << "Email : " << email << endl;
        cout << "-------------------------\n";
    }
};

// ContactBook class
class ContactBook {
private:
    vector<Contact> contacts;
    string filename = "contacts.txt";

    void saveToFile() {
        ofstream file(filename);
        for (int i = 0; i < contacts.size(); i++) {
            file << contacts[i].name << "\n";
            file << contacts[i].phone << "\n";
            file << contacts[i].email << "\n";
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) return;

        string name, phone, email;
        while (getline(file, name) && getline(file, phone) && getline(file, email)) {
            contacts.push_back(Contact(name, phone, email));
        }
        file.close();
    }

public:
    ContactBook() {
        loadFromFile();
    }

    void addContact() {
        string name, phone, email;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter phone: ";
        getline(cin, phone);
        cout << "Enter email: ";
        getline(cin, email);

        contacts.push_back(Contact(name, phone, email));
        saveToFile();
        cout << "Contact added successfully!\n";
    }

    void displayAll() {
        if (contacts.empty()) {
            cout << "No contacts found.\n";
            return;
        }
        cout << "\n--- All Contacts ---\n";
        for (int i = 0; i < contacts.size(); i++) {
            cout << i + 1 << ". ";
            contacts[i].display();
        }
    }

    void searchContact() {
        cin.ignore();
        string keyword;
        cout << "Enter name or phone to search: ";
        getline(cin, keyword);
        string keyLower = toLowerCase(keyword);

        bool found = false;
        for (int i = 0; i < contacts.size(); i++) {
            if (toLowerCase(contacts[i].name).find(keyLower) != string::npos ||
                contacts[i].phone.find(keyword) != string::npos) {
                contacts[i].display();
                found = true;
            }
        }

        if (!found)
            cout << "No contact found with that name or phone.\n";
    }

    void updateContact() {
        cin.ignore();
        string keyword;
        cout << "Enter name of contact to update: ";
        getline(cin, keyword);
        string keyLower = toLowerCase(keyword);

        for (int i = 0; i < contacts.size(); i++) {
            if (toLowerCase(contacts[i].name) == keyLower) {
                cout << "Contact found. Enter new details:\n";
                cout << "New name: ";
                getline(cin, contacts[i].name);
                cout << "New phone: ";
                getline(cin, contacts[i].phone);
                cout << "New email: ";
                getline(cin, contacts[i].email);
                saveToFile();
                cout << "Contact updated successfully!\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void deleteContact() {
        cin.ignore();
        string keyword;
        cout << "Enter name of contact to delete: ";
        getline(cin, keyword);
        string keyLower = toLowerCase(keyword);

        for (int i = 0; i < contacts.size(); i++) {
            if (toLowerCase(contacts[i].name) == keyLower) {
                contacts.erase(contacts.begin() + i);
                saveToFile();
                cout << "Contact deleted successfully!\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }
};

int main() {
    ContactBook book;
    int choice;

    cout << "=== Contact Book Application ===\n";

    do {
        cout << "\n1. Add Contact\n";
        cout << "2. View All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: book.addContact(); break;
            case 2: book.displayAll(); break;
            case 3: book.searchContact(); break;
            case 4: book.updateContact(); break;
            case 5: book.deleteContact(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
