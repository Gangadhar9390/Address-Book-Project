#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>

#define MAX_CONTACTS 100
#define SEARCH 1
#define EDIT 2
#define DELETE 3

typedef struct Contact
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int validation_num(char *num, AddressBook *addressBook);
int duplicate_num(char *num, AddressBook *addressBook);
int duplicate_email(char *email, AddressBook *addressBook);
int validation_email(char *mail, AddressBook *addressBook);
void search_by_name(AddressBook *addressBook, int option);
void search_by_number(AddressBook *addressBook, int option);
void search_by_email(AddressBook *addressBook, int option);
void edit_contact(AddressBook *addressBook, int *index, int count);
void delete_contact(AddressBook *addressBook, int *index, int count);

#endif
