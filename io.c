#include <stdio.h>
#include <string.h>
#include "io.h"

// this reads the input, separate it to tokens and based on the value of each token 
//it updates the headerline and filenames[]
void processInput(char *input, char **array_columns, char *headerLine, char filenames[][64], int *count) {
    char *column = strtok(input, ",");
    while (column != NULL && *count < 16) {
        array_columns[*count] = column;
        if (strcmp(array_columns[*count], "1") == 0) {
            strcat(headerLine, "UserID, ");
            strcpy(filenames[*count], "1"); // Added
        }
        else if (strcmp(array_columns[*count], "2") == 0) {
            strcat(headerLine, "First Name, ");
            strcpy(filenames[*count], "first_names.txt");
        }
        else if (strcmp(array_columns[*count], "3") == 0) {
            strcat(headerLine, "Last Name, ");
            strcpy(filenames[*count], "last_names.txt");
        }
        else if (strcmp(array_columns[*count], "4") == 0) {
            strcat(headerLine, "Country, ");
            strcpy(filenames[*count], "countries.txt");
        }
        else if (strcmp(array_columns[*count], "5") == 0) {
            strcat(headerLine, "Phone, ");
            strcpy(filenames[*count], "5");
        }
        else if (strcmp(array_columns[*count], "6") == 0) {
            strcat(headerLine, "Email, ");
            strcpy(filenames[*count], "email_suffixes.txt");
        }
        else if (strcmp(array_columns[*count], "7") == 0) {
            strcat(headerLine, "SIN, ");
            strcpy(filenames[*count], "7"); // Added
        }
        else if (strcmp(array_columns[*count], "8") == 0) {
            strcat(headerLine, "Password, ");
            strcpy(filenames[*count], "8");
        }
        else {
            printf("Unknown column %s\n", array_columns[*count]);
            // handles  the case  of unrecognzed column 
            strcat(headerLine, "Unknown, ");
            strcpy(filenames[*count], ""); 
        }

        column = strtok(NULL, ",");
        (*count)++;
    }
}


// This function is used to show the content on the screen
void displayFileContents(char outputFileName[64]) {
// Open the file for reading and showing it on the screen
  FILE *fileRead = fopen(outputFileName, "r");
    if (fileRead == NULL) {
        perror("Unable to open file for reading and showing it on the screen.");
        }
    char line[300];  // Adjust the buffer size as needed
    while (fgets(line, sizeof(line), fileRead) != NULL) {
        printf("%s", line);
    }

    fclose(fileRead);


}
