/*
Author: Talan Tabares
StudentID: 3108074
Date: 3/26/2025
Reason: Lab07
Description:
Program that performs temperature conversions in Fahrenheir, Celsius, and Kelvin. This program will also categorize each temperature into a weather advisory category

inputs:
temperature 
start_unit
target_unit

outputs:
all conversion functions return values to terminal
various messages are printed to the terminal

sources:
- Google AI
    Google AI was used to quickly search for the proper conversion formulas between units
- W3Schools
    Used W3Schools to get more information on how pointers worked
*/


#include <stdio.h> // Standard Library
#include <stdlib.h> // Header Library


float celsius_to_fahrenheit(float celsius) { // convert celsius to fahrenheit
    return (celsius * 9.0 / 5.0) + 32; // conversion formula
}


float fahrenheit_to_celsius(float fahrenheit) { // convert fahrenheit to celsius
    return (fahrenheit - 32) * 5.0 / 9.0; // conversion formula
}


float celsius_to_kelvin(float celsius) { // convert celsius to kelvin
    return celsius + 273.15; // conversion formula
}


float kelvin_to_celsius(float kelvin) { // convert kelvin to celsius
    if (kelvin < 0) { // Because kelvin cannot be negative this if statement checks for an error
        printf("Kelvin value cannot be negative.\n"); // Error message if kelvin is negative
        exit(1); // Ends the program
    }
    return kelvin - 273.15; // conversion formula
}


float fahrenheit_to_kelvin(float fahrenheit) { // convert fahrenheit to kelvin
    return (fahrenheit_to_celsius(fahrenheit) + 273.15); // use fahrenheit to celsius conversion then convert to kelvin
}


float kelvin_to_fahrenheit(float kelvin) { // convert kelvin to fahrenheit
    return (kelvin_to_celsius(kelvin) * 9.0 / 5.0) + 32; // use kelvin to celsius conversion then convert to fahrenheit
}


void categorize_temperature(float celsius) { // This function categorizes each temperature and gives a weather advisory
    char *category; // Initialize variable for category
    char *advisory; // Initialize variable for the advisory message

    // Categorize the temperatures usign celcius
    if (celsius < 0) { // check if temp is < 0
        category = "Freezing"; // below 0
        advisory = "Wear a jacket!"; // Advisory for freezing weather
    } else if (celsius >= 0 && celsius <= 10) { // check if temp is 0-10
        category = "Cold"; // Between 0 and 10
        advisory = "Wear a coat!"; // Advisory for cold weather
    } else if (celsius > 10 && celsius <= 25) { // check if temp is 10-25
        category = "Comfortable"; // Between 10 and 25
        advisory = "It's a nice day!"; // Advisory for comfortable weather
    } else if (celsius > 25 && celsius <= 35) { // check if temp is 25-35
        category = "Hot"; // Between 25 and 35
        advisory = "Stay cool!"; // Advisory for hot weather
    } else { // if temp is above 35
        category = "Extreme Heat"; // Above 35
        advisory = "Stay indoors!"; // Advisory for extreme heat
    }

    printf("Category: %s\n", category); // print category
    printf("Advisory: %s\n", advisory); // print advisory
}


int get_valid_input() { // This function handles invalid inputs and re-asks the user for a valid number
    int value; // Initialize variable to store input
    while (scanf("%d", &value) != 1) { // Check if the input is a valid integer
        while (getchar() != '\n'); // Clear the input 
        printf("Invalid input. Enter a valid number: "); // Prompt user to enter a valid input
    }
    return value; // Return the input
}

int main() {
    float temperature; // Initialize variable to store user input
    int start_unit, target_unit; // Initialize variables that indicate starting and target units

  
    printf("Enter the temperature value: "); // Asking for temperature
    if (scanf("%f", &temperature) != 1) { // Check if the temperature input is valid
        printf("Invalid temperature input.\n"); // Print error message if invalid
        return 1; // Exit the program
    }


    printf("Select the starting unit (1. Celsius, 2. Fahrenheit, 3. Kelvin): "); // Ask user for starting unit
    start_unit = get_valid_input(); // Get the starting unit input and checking validity
    if (start_unit < 1 || start_unit > 3) { // check range of input
        printf("Invalid unit choice.\n"); // Print error message if invalid
        return 1; // Exit the program
    }


    printf("Select the conversion unit (1. Celsius, 2. Fahrenheit, 3. Kelvin): "); // Ask user for conversion unit
    target_unit = get_valid_input(); // Get the target unit input and checking validity
    if (target_unit < 1 || target_unit > 3) { // check range of input
        printf("Invalid unit choice.\n"); // Print error message if invalid
        return 1; // Exit the program
    }

    /*
    
    The rest of the following code I had to convert all temperatures back to celsius to be used in the categorization process. I couldn't really think of a better way to be able to categorize
    the temperatures differently in each unit so I standardized it back to celsius for categorization purposes.
    
    */
    if (start_unit == target_unit) { // Checks if starting and ending unit are the same
        printf("Starting unit and target unit are the same.\n"); // Inform user that starting and ending unit are the same
        categorize_temperature(temperature); // Categorize the original temperature
        return 0; // Exit the program
        if (start_unit == 1) {
            categorize_temperature(temperature); // If the temperature is already in celsius it will go straight to categorization
        } else if (start_unit == 2) {
            categorize_temperature(fahrenheit_to_celsius(temperature)); // convert from fahrenheit to celsius to categorize
        } else if (start_unit == 3) {
            categorize_temperature(kelvin_to_celsius(temperature)); // convert from kelvin to celsius to categorize
        }
    }


    float converted_temperature_in_celsius; // Initialize variable to store conversion

   // converting temperatures to celsius
   if (start_unit == 1) {  // Celsius
    converted_temperature_in_celsius = temperature; // No conversion 
} else if (start_unit == 2) {  // Fahrenheit
    converted_temperature_in_celsius = fahrenheit_to_celsius(temperature); // Convert fahrenheit to celsius
} else if (start_unit == 3) {  // Kelvin
    converted_temperature_in_celsius = kelvin_to_celsius(temperature); // Convert kelvin to celsius
}

// Print the converted temperatures
if (start_unit == 1) {  // Celsius
    if (target_unit == 1)
        printf("Converted Temperature: %.2f Celsius\n", temperature); // No conversion 
    else if (target_unit == 2)
        printf("Converted Temperature: %.2f Fahrenheit\n", celsius_to_fahrenheit(temperature)); // Convert to fahrenheit
    else
        printf("Converted Temperature: %.2f Kelvin\n", celsius_to_kelvin(temperature)); // Convert to kelvin
} else if (start_unit == 2) {  // Fahrenheit
    if (target_unit == 1)
        printf("Converted Temperature: %.2f Celsius\n", converted_temperature_in_celsius); // Convert to celsius
    else if (target_unit == 2)
        printf("Converted Temperature: %.2f Fahrenheit\n", temperature); // No conversion 
    else
        printf("Converted Temperature: %.2f Kelvin\n", fahrenheit_to_kelvin(temperature)); // Convert to kelvin
} else if (start_unit == 3) {  // Kelvin
    if (target_unit == 1)
        printf("Converted Temperature: %.2f Celsius\n", converted_temperature_in_celsius); // Convert to celsius
    else if (target_unit == 2)
        printf("Converted Temperature: %.2f Fahrenheit\n", kelvin_to_fahrenheit(temperature)); // Convert to fahrenheit
    else
        printf("Converted Temperature: %.2f Kelvin\n", temperature); // No conversion 
}

// Categorize the converted temperature in unit celsius and give advisory
categorize_temperature(converted_temperature_in_celsius);

    return 0; // Returns '0' to show that the program ran successfully
}
