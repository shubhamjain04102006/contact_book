# Contact Book Application

A console-based contact management system built in C++ that allows users to add, view, search, update, and delete contacts. Contacts are saved to a file so they are not lost when the program closes.

## Features

- Add new contacts (name, phone, email)
- View all saved contacts
- Search by name or phone number (case-insensitive)
- Update existing contact details
- Delete a contact
- File handling to store contacts persistently across sessions

## How to Compile and Run

Make sure you have G++ installed.

```bash
g++ contact_book.cpp -o contact_book
./contact_book
```

## Sample Output

```
=== Contact Book Application ===

1. Add Contact
2. View All Contacts
3. Search Contact
4. Update Contact
5. Delete Contact
0. Exit
Enter choice: 1

Enter name: Shubham Jain
Enter phone: 9876543210
Enter email: shubham@email.com
Contact added successfully!
```

## Concepts Used

- OOP (Classes and Objects)
- Vectors
- File I/O (ofstream, ifstream)
- String manipulation
- Case-insensitive search

## File Storage

Contacts are saved in a file called `contacts.txt` in the same folder as the program. Every add, update, or delete operation automatically updates this file.

## Author
Shubham jain
Made by Shubham Jain

