/*Documentation
Name        :G Gangadhar
Date        :02/07/2025
Description :Address Book project
*/
#include <stdio.h>
#include "file.h"
#include "contact.h"

//  to save all contacts into a file
void saveContactsToFile(AddressBook *addressBook)
{
    // Open the file "contacts.csv" in write mode
    FILE *fptr = fopen("contacts.csv", "w");

    // If file cannot be opened, show error and exit function
    if (fptr == NULL)
    {
        fprintf(stderr, "Cannot open the file for writing\n");
        return;
    }

    // Loop to access each contact in the address book
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // Write contact's name, phone, and email to file in CSV format
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    // Close the file after writing is done
    fclose(fptr);
}

//  to load contacts from a file into address book
void loadContactsFromFile(AddressBook *addressBook)
{
    // Open the file "contacts.csv" in read mode
    FILE *fptr = fopen("contacts.csv", "r");

    // If file cannot be opened, show error and exit function
    if (fptr == NULL)
    {
        fprintf(stderr, "Cannot open the file for reading\n");
        return;
    }

    int i = 0;

    //  reading the  contacts until MAX_CONTACTS is reached
    while (i < MAX_CONTACTS)
    {
        // Read one line from the file (name, phone, email separated by commas)
        int ret = fscanf(fptr, "%99[^,],%19[^,],%99[^\n]\n",
                         addressBook->contacts[i].name,
                         addressBook->contacts[i].phone,
                         addressBook->contacts[i].email);

        // If not all three values are read correctly, stop reading
        if (ret != 3)
        {
            break;
        }

        i++; // Move to the next contact
    }

    // Set the total number of contacts read into contactCount
    addressBook->contactCount = i;

    // Close the file after reading is done
    fclose(fptr);
}
