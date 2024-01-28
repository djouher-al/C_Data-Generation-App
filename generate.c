#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "generate.h"

// this function generates the table based on what was added to filenames
void generateTable(FILE* File_write, int row_count, int count, FILE* files[16], char filenames[16][64]) {

    // declaring all my local variables I am using within this function 
     int id=1;
    int index[] = {398, 270, 925, 867, 209, 429, 908, 997, 444, 219};
    int num_index = sizeof(index) / sizeof(index[0]);
    srand(time(NULL));
    int random_num ;
    const char chars[] = "0123456789"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz"
                                   "!\"#$%&'()*+-.:;<=>?@[\\]^_`{|}~";

    int num_chars = sizeof(chars) - 1; 
    int password_length = rand() % 11 + 6;
    char password[17];  // Maximum length is 16 characters plus null terminator
    char Lastnames[100];
    char firstnames[100];
    char email_suffix[200];
    char Array_Reading[64];
    int row = 0;
    while (row < row_count) {
    for (int i = 0; i < count; i++) {
        if (strlen(filenames[i]) > 0) {
            if (files[i] != NULL) {
                if (fgets(Array_Reading, sizeof(Array_Reading), files[i]) == NULL) {
                    fseek(files[i], 0, SEEK_SET); // Resets the file position to the beginning when one of the file is read up to its capacity
                }
                char *duplicate = strndup(Array_Reading, strlen(Array_Reading) - 1);

                //  I need  this so I can use what's read via email_suffixes.txt 
                strcpy(email_suffix, duplicate);

                // This is in charge of wiring the last  names by reading last_names.txt
                if (strcmp(filenames[i], "last_names.txt") == 0) {
                    strcpy(Lastnames, duplicate);
                    fprintf(File_write, " %s", duplicate);
                }
                // This is in charge of wiring the  countries by reading  countries.txt
                if (strcmp(filenames[i], "countries.txt") == 0) {
                    fprintf(File_write, " %s", duplicate);
                }
                // This is in charge of wiring the first names by reading first_names.txt
                if (strcmp(filenames[i], "first_names.txt") == 0) {
                    strcpy(firstnames, duplicate);
                    fprintf(File_write, " %s", duplicate);
                }
                free(duplicate);
            }
            // This is in charge of printing the ID 
            if (strcmp(filenames[i], "1") == 0) {
                fprintf(File_write, " %d", id);
                id++;
            }
            // This is in charge of printing the emails 
            if (strcmp(filenames[i], "email_suffixes.txt") == 0) {
                fprintf(File_write, " %s%s@%s", (strndup(firstnames, 1)), Lastnames, email_suffix);
            }
            // This is in charge of printing the SIN  
            if (strcmp(filenames[i], "7") == 0) {
                for (int i = 0; i < 9; i++) {
                    int random_number = (rand() % 9) + 1;
                    fprintf(File_write, "%d", random_number);
                }
            }
            // This is in charge of printing the phone # 
            if (strcmp(filenames[i], "5") == 0) {
                int random_index = index[rand() % num_index];
                int random_4 = rand() % 10000;
                fprintf(File_write, " %03d-%04d", random_index, random_4);
            }
            // This is in charge of wiring the the password 
            if (strcmp(filenames[i], "8") == 0) {
                for (int i = 0; i < password_length; i++) {
                    int random_index = rand() % num_chars;
                    password[i] = chars[random_index];
                }
                password[password_length] = '\0';
                fprintf(File_write, " %s", password);
            }
        }
        // adds a comma
        if (i < count - 1) {
            fprintf(File_write, ",");
        }
    }
     //  next line when one line is read     
    fprintf(File_write, "\n");
    row++;
}

}