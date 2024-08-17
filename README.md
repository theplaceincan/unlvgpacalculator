# UNLV GPA Calculator
This was made 'cause, unlike the UNLV website, you can save your courses, calculate GPAs offline, and easily edit your courses in a simple text file.

You're free to download this and start calculating your GPA! This is a simple program that reads from a list of classes & grades in a "grades.csv" file and outputs your GPA, total grade points, and total units/credits taken. 

## To use this program, do the following:
### 1. Setup
1. **Download the Program**: Clone or download the repository (green button).
2. **Prepare Your Grades File**:
   - Edit the `grades.csv` file.
   - **File Format**:
     - Lines for labeling semesters must follow this format:
      ```
        -(FA/SM/SP),(2-digit YEAR, ie. 24 for 2024)
      ```
     - The following lines should list your courses, credits, and grades in this format:
      ```
        (CLASS 100),(CREDITS),(GRADE)
      ```
   - **Example**:
     ```
     -FA,24   
     CS 128,3,A
     ENG 232,3,A
     ```

### 2. Running the Program
1. **Get a C++ Compiler**: If you don't have one installed, download it (e.g., g++).
2. **Choose a Code Editor**: If you don’t already have one, Visual Studio Code (VSCode) is beginner-friendly.
3. **Compile the Program**:
   - Open your code editor and navigate to the folder containing the program.
   - Ensure your `grades.csv` file is in the same directory (folder).
   - Compile the program using the following command:
     ```bash
     g++ unlvgpacalculator.cpp -o main
     ```
4. **Run the Program**:
   - Run the compiled program with:
     ```bash
     ./main
     ```


## Extras

Formula: GPA = totalGradePoints / totalUnitsTaken

_(FYI Units and Credits mean the same thing)_

   
