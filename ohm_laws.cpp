// Copyright (2025) Aaron Rivelino All rights reserved.
// Date: May 21, 2025
// This is an Ohm's law calculator that gets the resistance,
// voltage, and current, depending on what the user wants
// It uses different functions for each option
// It gets all the user input in the main

#include <iostream>
#include <string>

// Function to calculate current: I = V / R
float calculate_current(float voltage, float resistance) {
    return voltage / resistance;
}

// Function to calculate resistance: R = V / I
float calculate_resistance(float voltage, float current) {
    return voltage / current;
}

// Function to calculate voltage: V = I * R
float calculate_voltage(float current, float resistance) {
    return current * resistance;
}

int main() {
    // Welcome message and options for operation to do
    std::cout << "Welcome to the Ohm’s Law Calculator!\n";
    std::cout << "1: Calculate Current (I = V / R)\n";
    std::cout << "2: Calculate Resistance (R = V / I)\n";
    std::cout << "3: Calculate Voltage (V = I x R)\n";

    // Loop to allow retrying on input errors
    while (true) {
        // Store the user choice as a string
        std::string choiceStr;
        std::cout << "Choose an option (1, 2, or 3): ";
        std::cin >> choiceStr;
        // Set choice as an integer
        int choice;

        try {
            // Try converting input string to integer
            choice = std::stoi(choiceStr);
        } catch (...) {
            std::cout << "Invalid input! Please enter 1, 2, or 3.\n\n";
            // Go back to the start of the loop
            continue;
        }

        // If statement for option 1
        if (choice == 1) {
            // Store this values as strings
            std::string voltageStr, resistanceStr;
            // Input voltage
            std::cout << "Enter the voltage (V): ";
            std::cin >> voltageStr;
            // Input resistance
            std::cout << "Enter the resistance (R): ";
            std::cin >> resistanceStr;

            // Set voltage and resistance to floats
            float voltage, resistance;
            try {
                // Convert voltage string to float
                voltage = std::stof(voltageStr);
                // Convert resistance string to float
                resistance = std::stof(resistanceStr);
            } catch (...) {
                std::cout << "Invalid input! Please enter numeric values.\n\n";
                // Go back to the start of the loop
                continue;
            }

            // Check for invalid values, negative numbers or zero
            if (resistance <= 0 || voltage < 0) {
                if (resistance == 0) {
                    std::cout << "Error: Resistance cannot be zero.\n";
                } else {
                    std::cout
                    << "Resistance and Voltage must be positive numbers.\n";
                }
                // Go back to the start of the loop
                continue;
            }

            // Ser current to a float
            // Call the function current to calculate current and display it
            float current = calculate_current(voltage, resistance);
            std::cout << "The current (I) is: " << current << " Amps\n";
            // Exit the loop
            break;

        // Elif statement for option 2
        } else if (choice == 2) {
            // Get voltage and current as strings
            std::string voltageStr, currentStr;
            std::cout << "Enter the voltage (V): ";
            // Input for voltage
            std::cin >> voltageStr;
            // Input for current
            std::cout << "Enter the current (I): ";
            std::cin >> currentStr;

            // Set voltage a current as float
            float voltage, current;
            try {
                // Convert voltage and current string to float
                voltage = std::stof(voltageStr);
                current = std::stof(currentStr);
            } catch (...) {
                std::cout << "Invalid input! Please enter numeric values.\n\n";
                // Go back to the start of the loop
                continue;
            }

            // Check for invalid values negative numbers or zero
            if (current <= 0 || voltage < 0) {
                if (current == 0) {
                    std::cout << "Error: Current cannot be zero.\n";
                } else {
                    std::cout
                    << "Current and Voltage must be positive numbers.\n";
                }
                // Go back to the start of the loop
                continue;
            }

            // Set resistance as a float
            // and call the function, to calculate the resistance
            // Then display it
            float resistance = calculate_resistance(voltage, current);
            std::cout << "The resistance (R) is: " << resistance << " Ohms\n";
            // Exit the loop
            break;

            // else if statement for option 3
        } else if (choice == 3) {
            // Set this current and resistance as strings
            std::string currentStr, resistanceStr;
            // Input for current
            std::cout << "Enter the current (I): ";
            std::cin >> currentStr;
            // Input for resistance
            std::cout << "Enter the resistance (R): ";
            std::cin >> resistanceStr;

            // Set current and resistance as float
            float current, resistance;
            try {
                // Convert current and resistance string to float
                current = std::stof(currentStr);
                resistance = std::stof(resistanceStr);
            } catch (...) {
                std::cout << "Invalid input! Please enter numeric values.\n\n";
                // Go back to the start of the loop
                continue;
            }

            // Check for invalid values (negative or zero)
            if (current <= 0 || resistance <= 0) {
                std::cout
                << "Current and Resistance must be positive and non-zero.\n";
                continue;  // Retry
            }

            // Set voltage as a float,
            // Then call the function to calculate voltage
            // Then display it
            float voltage = calculate_voltage(current, resistance);
            std::cout << "The voltage (V) is: " << voltage << " Volts\n";
            // Exit the loop
            break;

            // If the user enters something other than 1, 2, or 3
        } else {
            std::cout << "Please choose a valid option: 1, 2, or 3.\n\n";
            // Go back to the start of the loop
            continue;
        }
    }

    return 0;
}
