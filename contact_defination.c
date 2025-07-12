/*Documentation
Name        :G Gangadhar
Date        :02/07/2025
Description :Address Book project
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

// function to check number is valid or not (only 10 digits allowed)
int validation_num(char *num, AddressBook *addressBook)
{
    int i = 0;
    while (num[i])
    {
        if (num[i] >= '0' && num[i] <= '9') // checking for only digits
            i++;
        else
            break; // if not digit, break the loop
    }
    if (i == 10) // if exactly 10 digits
        return 1;
    else
        return 0; // not valid number
}

// function to check email format is valid or not
int validation_email(char *mail, AddressBook *addressBook)
{
    int i = 0, len = strlen(mail), count = 0;
    char *ch;

    // check for '@' and ".com"
    if ((strchr(mail, '@')) && (strstr(mail, ".com")))
    {
        i = 0;
        while (mail[i])
        {
            if (mail[i] == '@')
            {
                count++;
                if (count > 1)
                    return 0;
                // checking characters before and after '@' are valid
                if ((!isalnum(mail[i - 1])) || (!isalnum(mail[i + 1])))
                {
                    return 0;
                }
            }

            if (mail[i] == '.')
            {
                // checking characters before and after '.' are alphabets
                if ((!isalpha(mail[i - 1])) || (!isalpha(mail[i + 1])))
                {
                    return 0;
                }
            }
            i++;
        }

        // check it ends with ".com"
        ch = strstr(mail, ".com");
        if (strcmp(ch, ".com"))
        {
            return 0;
        }

        // check for no space and no capital letters
        for (i = 0; i < len; i++)
        {
            if ((mail[i] == ' ') || (isupper(mail[i])))
                return 0;
        }
    }
    else
        return 0; // email is invalid

    return 1; // email is valid
}
// checking number already exists or not
int duplicate_num(char *num, AddressBook *addressBook)
{
    int j;
    for (j = 0; j < addressBook->contactCount; j++)
    {
        if (strcmp(num, addressBook->contacts[j].phone) == 0)
        {
            return 0; // if number matched, duplicate found
        }
    }
    return 1; // no duplicate
}

// checking email is already present or not
int duplicate_email(char *email, AddressBook *addressBook)
{
    int j;
    for (j = 0; j < addressBook->contactCount; j++)
    {
        if (strcmp(email, addressBook->contacts[j].email) == 0)
        {
            return 0; // email already present
        }
    }
    return 1; // email is unique
}

// searching by name and do edit or delete
void search_by_name(AddressBook *addressBook, int option)
{
    char name[20];
    int i = 0, count = 0, index_array[MAX_CONTACTS];

    while (1)
    {
        printf("Enter the name:");
        scanf(" %[^\n]", name);
        // Search through the contact list
        for (i = 0; i < addressBook->contactCount; i++)
        {
            // Compare input name with each contact's name
            if (strcmp(name, addressBook->contacts[i].name) == 0)
            {
                // Store the index value into the array of the matched contact
                index_array[count++] = i;
                printf("\n%d.Contacts\n", count);
                printf("Name    :%s\n", addressBook->contacts[i].name);
                printf("Phone   :%s\n", addressBook->contacts[i].phone);
                printf("Email ID:%s\n", addressBook->contacts[i].email);
            }
        }

        if (!count)
        {
            printf("\nInvalid contact. Please try again\n");
            continue;
        }

        // if user selected edit
        if (option == EDIT)
        {
            edit_contact(addressBook, index_array, count);
        }
        // if user selected delete
        else if (option == DELETE)
        {
            delete_contact(addressBook, index_array, count);
        }
        break;
    }
}
// search by number and do edit/delete
void search_by_number(AddressBook *addressBook, int option)
{
    int i = 0, count = 0, num_index = 0;
    char number[20];

    while (1)
    {
        printf("Enter the number:");
        scanf(" %[^\n]", number);

        if (validation_num(number, addressBook)) // check number is valid
        {
            // Search through the contact list
            for (i = 0; i < addressBook->contactCount; i++)
            {
                // Compare input name with each contact's number
                if (strcmp(number, addressBook->contacts[i].phone) == 0)
                {
                    num_index = i; // Store the index of the matched contact
                    count++;
                    printf("\n%d.Contacts\n", count);
                    printf("Name    :%s\n", addressBook->contacts[i].name);
                    printf("Phone   :%s\n", addressBook->contacts[i].phone);
                    printf("Email ID:%s\n", addressBook->contacts[i].email);
                }
            }
        }
        if (!count)
        {
            printf("\nInvalid contact. Please try again.\n");
            continue; // contact not found skips the iteration
        }

        if (option == EDIT)
        {
            edit_contact(addressBook, &num_index, count);
        }
        if (option == DELETE)
        {
            delete_contact(addressBook, &num_index, count);
        }
        break;
    }
}

// search by email and edit/delete
void search_by_email(AddressBook *addressBook, int option)
{
    int i, count = 0, mail_index = 0;
    char mail[50];

    while (1)
    {
        printf("Enter the Email ID:");
        scanf(" %[^\n]", mail);

        if (validation_email(mail, addressBook)) // check email valid
        {
            // Search through the contact list
            for (i = 0; i < addressBook->contactCount; i++)
            {
                // Compare input name with each contact's email
                if (strcmp(mail, addressBook->contacts[i].email) == 0)
                {
                    mail_index = i; // Store the index of the matched contact
                    count++;
                    printf("\n%d.Contacts\n", count);
                    printf("Name    :%s\n", addressBook->contacts[i].name);
                    printf("Phone   :%s\n", addressBook->contacts[i].phone);
                    printf("Email ID: %s\n", addressBook->contacts[i].email);
                }
            }
        }

        if (!count)
        {
            printf("\nInvalid contact. Please try again.\n");
            continue; // contact not found skips the iteration
        }

        if (option == EDIT)
        {
            edit_contact(addressBook, &mail_index, count);
        }
        if (option == DELETE)
        {
            delete_contact(addressBook, &mail_index, count);
        }
        break;
    }
}

// edit contact function
void edit_contact(AddressBook *addressBook, int *index_array, int count)
{
    char new_name[50], new_number[20], new_email[50];
    int ret = 0, choice, option = 1;

    // if more than one contact matched, ask user to choose one
    while (1)
    {
        if (count > 1) // for selection if multiple contacts are found
        {
            printf("Select the one contact to edit:");
            scanf("%d", &option);
            if (option >= 1 && option <= count)
                break;
            else
                printf("\nInvalid selection. Please try again.\n");
        }
        break;
    }

    // choose what to edit
    printf("Select one to edit \n");
    printf("1. Name \n");
    printf("2. Number\n");
    printf("3. Email ID\n");
    printf("4. Back to main menu\n");
    while (1) // iteration take place until a valid choice is entered
    {
        printf("Enter the choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ; // clear input buffer
            printf("\nInvalid input.Select 1 to 4\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            // for name edit
            printf("Enter the new name:");
            scanf(" %[^\n]", new_name);
            strcpy(addressBook->contacts[index_array[option - 1]].name, new_name);
            break;

        case 2:
            while (1)
            {
                // for number edit
                printf("Enter the new number:");
                scanf(" %[^\n]", new_number);
                if (validation_num(new_number, addressBook))
                {
                    ret = duplicate_num(new_number, addressBook);
                }
                if (!ret)
                {
                    printf("\nInvalid number\n");
                    continue;
                }
                break;
            }
            strcpy(addressBook->contacts[index_array[option - 1]].phone, new_number);
            break;

        case 3:
            while (1)
            {
                // for email edit
                printf("Enter the new email:");
                scanf(" %[^\n]", new_email);
                if (validation_email(new_email, addressBook))
                {
                    ret = duplicate_email(new_email, addressBook);
                }
                if (!ret)
                {
                    printf("\nInvalid email\n");
                    continue;
                }
                break;
            }
            strcpy(addressBook->contacts[index_array[option - 1]].email, new_email);
            break;
        case 4:
            printf("Returning...\n");
            break;

        default:
            printf("\nInvalid choice\n");
            continue;
        }
        break;
    }

    // after editing
    printf("\nSucessfully edited\n");
    printf("Name     : %s\n", addressBook->contacts[index_array[option - 1]].name);
    printf("Contact  : %s\n", addressBook->contacts[index_array[option - 1]].phone);
    printf("Email-ID : %s\n", addressBook->contacts[index_array[option - 1]].email);
}

// delete contact function
void delete_contact(AddressBook *addressBook, int *index, int count)
{
    int option = 1, select_index, i;

    while (1)
    {
        if (count > 1) // for selection if multiple contacts are found
        {
            printf("Select one contact to delete: ");
            scanf("%d", &option);
            if (option >= 1 && option <= count)
                break;
            else
                printf("\nInvalid selection. Please try again.\n");
        }
        break;
    }

    select_index = index[option - 1]; // actual index

    // storing in place slected contact after value shiting to slected contact until contactcount;
    for (i = select_index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    (addressBook->contactCount)--; // reduce contact count
    printf("\nSuccessfully deleted the contact\n");
}
