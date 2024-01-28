#ifndef IO_H
#define IO_H

//  prototype for the functions defined in generate2.c
void processInput(char *input, char **array_columns, char *headerLine, char filenames[][64], int *count);
void displayFileContents(char outputFileName[64]);
#endif
