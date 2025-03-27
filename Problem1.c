/*
Author: Talan Tabares
StudentID: 3108074
Date: 3/26/2025
Reason: Lab07
Description:
Program that calculates possible combinations of football scores based on the total score. The total score is an input from the user and all combinations are printed to terminal

inputs:
score

outputs:
total

sources:
- ChatGPT
    I knew that the best way to do the computations would be some sort of nested loop, but I was not sure exactly how to implement it. I utilized ChatGPT to get an idea of the algorithm
    That I would need to use.
- W3Schools 
    I used W3Schools to get an idea how to handle invalid inputs in C

*/


#include <stdio.h> // standard library


void combinations(int score) { // Function that will be finding all combinations and printing them to the terminal

    int td, fg, safety, td2pt, td1fg, total; // Inialize the variables that will be used in the combinations


    printf("Combinations with a score of %d:\n", score); // Repeats the score that was inputed
    /*
    
    The nested for loops below are responsible for all of the computations to find combinations of scores. The order of the computations is arbitrary as it does not matter what the order is.
    At the end of each iteration the program will check to see if the current score matches the target score. If so, it will be printed to the terminal. All of the variables start at 0, then 
    1 will begin to be added to each variable as the loop continues. Once one variable reaches the max value it could be it will stop, but the loops will continue on the other variables until 
    they can no longer increase. 

    */
    for (td = 0; td * 6 <= score; td++) { // calculates possible combinations of touchdowns
        for (fg = 0; fg * 3 <= score; fg++) { // calculates possible combinations of field goals
            for (safety = 0; safety * 2 <= score; safety++) { // calculates possible combinations of safeties
                for (td2pt = 0; td2pt * 8 <= score; td2pt++) { // calculates possible combinations of touchdown & 2 point conversions
                    for (td1fg = 0; td1fg * 7 <= score; td1fg++) { // calculates possible combinations of touchdowns & 1 point field goal
                        total = td * 6 + fg * 3 + safety * 2 + td2pt * 8 + td1fg * 7; // calculates total score based on the current iteration
                        
            
                        if (total == score) { // checks to see if current total matches desired score
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1fg, td, fg, safety); // prints combination if there is a match
                        }
                    }
                }
            }
        }
    }
}


int main() { // Main function where program runs
    int score; // Initializes variable that will store the user input

    while (1) { //This loop will continue until the user enters '0' or '1'
        printf("Enter 0 or 1 to STOP\n"); // stop command
        printf("Enter the NFL score: "); // prompt for desired score
        if (scanf("%d", &score) != 1) { // gets input. If input is invalid it will ask again
            printf("Invalid input. Enter a positive integer.\n"); // Error message
            while(getchar() != '\n'); // Removes invalid input 
            continue; // restarts prompt
        }

        if (score < 0) { // if negative integer is given raise another error. Mostly as a double check in case something gets through that shouldn't
            printf("Invalid input. The score cannot be negative. Please enter a positive score.\n"); // Error message
            continue; // restarts prompt
        }

        if (score <= 1) { // If score is '0' or '1' this code ends the program
            printf("Program ended.");  // End message
            break;  // exits loop
        }

        combinations(score); // Calls function to calculate combinations
    }

    return 0;  // return '0' to show that the program was run successfully 
}