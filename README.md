# TableGen - Simple Data Generation Application

This project focuses on creating a straightforward application that generates data for a single output file. Such applications are commonly used to create realistic test sets for databases or other data management systems. While commercial data generators can be sophisticated, this application aims to provide a simple yet effective solution.

## Features

1. **Main Menu**
   - Upon starting the program, a simple main menu will be displayed with two options: build a table and exit.
   - Selecting Option 2 will exit the program with a farewell message.

2. **Build a Table**
   - Choosing Option 1 leads to a new menu, the Column Options menu.
   - Before displaying any menu, the screen will be cleared for a clean display.
   - The Column Options menu allows the user to select columns for the table and define the sort column.
   - Users can input columns as a comma-separated list with no spaces (e.g., 3,2,5 or 1,3,6,8,7).
   - After column selection, the user is prompted to enter the row count (an integer from 1 to 1 million).
   - A final prompt asks for the output file name to store the generated data.

3. **Output Generation**
   - The application generates the output based on user input and confirms that the table has been written.
   - A "continue" prompt allows users to go back to the main menu, providing the option to either exit the program or generate a new table.

## Usage

1. **Main Menu**
   - Select Option 1 to build a table or Option 2 to exit the program.

2. **Column Options Menu**
   - Enter a column-separated list of column numbers with no spaces.
   - Define the sort column by choosing the first column in the list.
   - Input the row count (1 to 1 million) and the output file name.

3. **Generated Output**
   - View the confirmation that the table has been written.
   - Press 'c' to continue and return to the main menu.

## Example

Suppose the user creates a table with 3 columns (Last Name, First Name, Phone), 100 rows, and stores it in a file named `foo.csv`.

### Text Version of `foo.csv`

```
Last Name,First Name,Phone
Doe,John,123-4567
Smith,Jane,987-6543
...
```

### Excel Version (Nicely Formatted as a Table)

| Last Name | First Name | Phone    |
|-----------|------------|----------|
| Doe       | John       | 123-4567 |
| Smith     | Jane       | 987-6543 |
| ...       | ...        | ...      |

Points to Note:
1. The CSV file contains a header row providing column names.
2. Columns are ordered as defined by the user.
3. The table is sorted alphabetically by the last name.
4. Phone numbers are formatted (xxx-xxxx).

## Notes
- The screen is cleared before displaying any menu.
- Utilizes the system function from stdlib.h to clear the screen.
- CSV files can be easily imported into spreadsheet applications for convenient viewing.
