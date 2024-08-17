# UNLV GPA Calculator
This was made 'cause, unlike the UNLV website, you can save your courses, calculate GPAs offline, and easily edit your courses in a simple text file.

You're free to download this and start calculating your GPA!

## To use this program, do the following:
1. Make a "grades.csv" file within the same directory as this program.
2. Fill in the grades.csv file like this format example:

   a. This is the format:
   ```
     -(FA/SM/SP),(2-digit YEAR, ie. 24 for 2024)
     (CLASS 100),(CREDITS),(GRADE)
   ```
   b. Format example (inside the grades.csv file that you create in the same directory as this program):
   ```
     -FA,24   
     CS 128,3,A
     ENG 232,3,A
   ```
4. To run the program: <br/>
   a. download a C++ compiler (ignore this if you have one) <br/>
   b. download a code editor (VSCode is beginner-friendly) (ignore this if you have one) <br/>
   c. open the code editor, and go to the folder where this program file is at <br/>
   d. make a grades.csv file and fill it out with your classes <br/>
   e. compile this program with: g++ unlvgpacalculator.cpp -o main <br/>
   f. run this program with: ./main <br/>

## Extras

Formula: GPA = totalGradePoints / totalUnitsTaken

_(FYI Units and Credits mean the same)_

   
