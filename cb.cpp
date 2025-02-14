#include <iostream>
#include <fstream>
using namespace std;

void addContact() {
    string name, number;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Number: ";
    cin >> number;

    ofstream file("contacts.txt", ios::app);
    file << name << " " << number << endl;
    file.close();
    cout << "Contact saved!\n";
}

void viewContacts() {
    ifstream file("contacts.txt");
    string name, number;
    cout << "Contacts:\n";
    while (file >> name >> number) {
        cout << name << ": " << number << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "1. Add Contact\n2. View Contacts\n3. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) addContact();
        else if (choice == 2) viewContacts();
    } while (choice != 3);
    return 0;
}
