/*Documentation
Name        :G Gangadhar
Date        :02/07/2025
Description :Address Book project
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook)
{
    int i;
    /* Define the logic for print the contacts */
    printf("\n%d contacts :\n", addressBook->contactCount);
    for (i = 0; i < addressBook->contactCount; i++) // loop will run till last contactcount
    {
        printf("\nContact %d:\n", i + 1);
        // each iteration prints contact
        printf("Name     : %s\n", addressBook->contacts[i].name);
        printf("Contact  : %s\n", addressBook->contacts[i].phone);
        printf("Email-ID : %s\n", addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void save_contact(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
}

void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */

    // Read the name from the user
    printf("Enter the contact name: ");
    // directly storing the name  doesn't have any validation
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);

    char num[11];
    int ret = 0;

    while (1)
    {
        //  Read the contact
        printf("Enter the contact number: ");
        scanf(" %[^\n]", num);
        // - Check whether the count is 10 or not
        // - Check all 10 characters are digits or not.
        if (validation_num(num, addressBook))
        {
            ret = duplicate_num(num, addressBook);
        }
        if (!ret)
        {
            printf("\nInvalid number. Try Again\n");
            continue;
        }
        break;
    }
    // after the validations number copying that number into addressbook
    strcpy(addressBook->contacts[addressBook->contactCount].phone, num);

    char mail[30];

    ret = 0;
    while (1)
    {
        // Read the email ID
        printf("Enter the contact Email ID: ");
        scanf(" %[^\n]", mail);
        /* - Check whether the character array contains lowercase,
         digits and special characters or not*/
        // - Check whether char - @ and .com is present or not

        if (validation_email(mail, addressBook))
        {
            ret = duplicate_email(mail, addressBook);
        }
        if (!ret)
        {
            printf("\nInvalid Email Try Again\n");
            continue;
        }
        break;
    }

    // after the validations of email copying into the addressbook
    strcpy(addressBook->contacts[addressBook->contactCount].email, mail);
    printf("\nContact created successfully\n");
    // Increment the contact count.
    (addressBook->contactCount)++;
}

void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    int choice;
    char option[50];

    printf("\nSelect one to search:\n");
    printf("1. Name\n");
    printf("2. Number\n");
    printf("3. Email ID\n");
    printf("4. Back to main menu\n");
    while (1) // iteration take place until a valid choice is entered
    {
        printf("Enter the choice: ");
        // Check for valid number input
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ; // clear the input buffer
            printf("\nInvalid input.Select 1 to 4 only.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            search_by_name(addressBook, SEARCH);
            break;
        case 2:
            search_by_number(addressBook, SEARCH);
            break;
        case 3:
            search_by_email(addressBook, SEARCH);
            break;
        case 4:
            printf("Returning...\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            continue;
        }
        break;
    }
}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    int choice;
    printf("Select one to search to edit\n");
    printf("1. Name\n");
    printf("2. Number\n");
    printf("3. Email ID\n");
    printf("4. Back to main menu\n");
    while (1) // iteration take place until a valid choice is entered
    {
        printf("Enter the choice: ");
        // Check for valid number input
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ; // clear input buffer
            printf("\nInvalid input.Select 1 to 4 only.\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            search_by_name(addressBook, EDIT);
            break;
        case 2:
            search_by_number(addressBook, EDIT);
            break;
        case 3:
            search_by_email(addressBook, EDIT);
            break;
        case 4:
            printf("Returning...\n");
            break;
        default:
            printf("\nInvalid option\n");
            continue;
        }
        break;
    }
}

void deleteContact(AddressBook *addressBook)
{
    int choice;
    /* Define the logic for deletecontact */
    printf("Select one to search to delete\n");
    printf("1. Name\n");
    printf("2. Number\n");
    printf("3. Email ID\n");
    printf("4. Back to main menu\n");
    while (1) // iteration take place until a valid choice is entered
    {
        printf("Enter the choice: ");
        // Check for valid number input
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ; // clear input buffer
            printf("\nInvalid input.Select 1 to 4 only.\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            search_by_name(addressBook, DELETE);
            break;
        case 2:
            search_by_number(addressBook, DELETE);
            break;
        case 3:
            search_by_email(addressBook, DELETE);
            break;
        case 4:
            printf("Returning...\n");
            break;
        default:
            printf("\nInvalid option\n");
            continue;
        }
        break;
    }
}
