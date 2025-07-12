
# 📒 Address Book Management System (C)

### Developed by: **G Gangadhar**  
📅 Date: **02/07/2025**  

## 📌 Project Overview

This project is a **menu-driven Address Book Management System** developed in the C programming language. It allows users to **create, view, search, edit, delete, and save contacts** using a command-line interface. All contacts are stored and loaded from a CSV file (`contacts.csv`) for data persistence.

---

## 🔧 Features

- ✅ Add new contacts with validation (name, 10-digit phone number, and email)
- 🔍 Search contacts by name, phone number, or email ID
- ✏️ Edit existing contact details
- 🗑️ Delete contacts with confirmation
- 📄 List all stored contacts
- 💾 Save all data to a file (`contacts.csv`)
- 🔁 Automatically loads existing contacts on startup

---

## 🗂️ File Structure

| File Name            | Description |
|----------------------|-------------|
| `main.c`             | Entry point of the program, contains the main menu loop |
| `contact.c`          | Implements core contact operations like add, edit, search, delete |
| `contact_defination.c` | Defines helper functions for validation, duplicate checking, and logic for editing/deleting |
| `file.c`             | Handles reading from and writing to the `contacts.csv` file |
| `populate.c`         | (Optional) Preloads dummy contacts into memory (for testing/demo) |
| `contact.h`          | Header file for contact data structures and declarations |
| `file.h`             | Header file for file-related functions |
| `populate.h`         | Header file for dummy data population function |
| `contacts.csv`       | CSV file that stores contact data (Name, Phone, Email) |

---

## 🛠️ Compilation Instructions

Use `gcc` to compile:

```bash
gcc main.c contact.c contact_defination.c file.c populate.c -o address_book
```

Run the program:

```bash
./address_book
```

---

## 🧪 Sample Output

Below are example outputs for common operations:

### Create a Contact
### 🔍 Searching a Contact 
### 📝 Editing a Contact
### 🗑️ Deleting a Contact
###    List contact
###    Save contact
## 📁 contacts.csv Format
###    Exit

<img width="1919" height="486" alt="Screenshot 2025-07-06 213915" src="https://github.com/user-attachments/assets/54678ba0-a840-4d7c-a0d1-0235380034db" />


<img width="1919" height="989" alt="Screenshot 2025-07-07 080352" src="https://github.com/user-attachments/assets/88dedbb3-a863-4160-9385-e701d9354e82" />


<img width="1919" height="522" alt="Screenshot 2025-07-12 130727" src="https://github.com/user-attachments/assets/2679d904-3f8a-4ed1-8c84-f91577d7e572" />

###  Project demo video
https://drive.google.com/file/d/1xi62q9mg4XZreRtAcMYFtV8RhPnj7lzj/view?usp=sharing

## ✅ Validations Implemented
- Phone number must be exactly 10 digits and numeric
- Email must contain `@` and end with `.com` (no uppercase letters or spaces)
- Duplicate phone numbers and emails are not allowed

---

## 🧹 Future Enhancements

- Add birthday field and sort by date
- Import/export to JSON or Excel
- GUI integration using GTK or ncurses
- Contact groups and tagging

---

## 📌 Conclusion

This Address Book project demonstrates file I/O handling, user input validation, structured data management using `struct`, and basic error checking in C. It is a suitable project for beginners learning **C programming, modular design, and file management**.
