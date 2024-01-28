#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> 

// This is in order to include my 2 other c files 
#include "io.h" 
#include "generate.h"
int main() {
    char input[100];
    int count = 0;
    char *array_columns[16];
    char headerLine[100] = "";
    FILE *files[16] = {0}; // Initialize all elements to NULL
    char filenames[16][64]; // Array to store file names
    //char Array_Reading[64];
 
    
// Prompt for output file name
    char outputFileName[64];
    int row_count;
    int choice; 
   

    printf("TableGen Menu\n");
    printf("-------------\n");
    printf("1. Generate new table\n");
    printf("2. Exit \n");
    printf("Selection: ");
    scanf("%d", &choice);
        if (choice == 2) {
        system("clear"); // clear so that only the bellow message shows 
        printf("Goodbye and thanks for using TableGen\n");
        exit(0); // terminate the program in this case
    }

    else  {
        printf("Column Options\n"); 
        printf("-------------\n");
        printf("1. User ID                 5. Phone Number\n");
        printf("2. First Name              6. Email address\n");
        printf("3. Last Name               7. SIN\n");
        printf("4. Country                 8. Password\n");
        printf("\n");
        printf("Enter column list( comma-separated, no spaces): ");
        scanf("%s",input);


    char input_copy[sizeof(input)];
    char input_display[sizeof(input)];
    strcpy(input_copy, input);
    strcpy(input_display, input);

    system("clear"); // Clear the screen as requested
    printf("Enter row count (1 < n < 1M): ");
    scanf("%d", &row_count);
    printf("Enter output file name(no suffix): ");
    scanf("%s", outputFileName);

   
    system("clear"); // Clear the screen as requested
    printf("Summary of propreties\n"); 
    printf("Columns:%s\n", input_display); 
    printf("Row count: %d\n", row_count); 
    printf("File name: %s\n", outputFileName);

    // This is necessary because I needed my input to finish with a ","
    // because otherwise there is a mistake using strtok() in processInput
    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] != ',') {
        input[input_length] = ',';  
        input[input_length + 1] = '\0'; 
    }

    // Calling the function to process the input in io.c
    processInput(input, array_columns, headerLine, filenames, &count);


    // Creating a file to write on, and add the extension csv 
    FILE *File_write = fopen(strcat(outputFileName, ".csv"), "wt");
    if (File_write == NULL) {
        perror("Sorry, couldn't open the file to write in.");
        exit(1);
    }
    // Removing the last comma in the headerline and then priting it on file
    int length = strlen(headerLine);
    // Check if the last character is a comma
      while (length > 0 && (headerLine[length - 1] == ',' || headerLine[length - 1] == ' ' || headerLine[length - 1] == '\t' || headerLine[length - 1] == '\n')) {
        headerLine[length - 1] = '\0';
        length--;
    }
    fprintf(File_write, "%s\n", headerLine);
    
   
   // opening all the files bases on processInput()
     for (int i = 0; i < count; i++) {
        if (strlen(filenames[i]) > 0 ) {
            files[i] = fopen(filenames[i], "r");
            if (files[i] == NULL) {
                continue;
            }
        }
    }
    

    // this function is called within generate2.c 
    generateTable(File_write,  row_count,count,files,  filenames);

    // this is in order to close all the files opened  after generating the table
    for (int i = 0; i < count; i++) {
        if (strlen(filenames[i]) > 0 && files[i] != NULL) {
            fclose(files[i]);
        }
    }
    fclose(File_write);
    }
    system("clear"); // Clear the screen as requested
    printf("\n");
    printf("Table written successful to %s ",outputFileName);
    printf("\n");
 
   char proceed;
   printf("\nPress 'c' or 'C' to continue ");
   do{
        scanf("%c", &proceed);
   } while ( (proceed != 'c') && (proceed != 'C'));

    // A function in io.c that displays the content on the screen.
    displayFileContents(outputFileName);

    return 0;
}


