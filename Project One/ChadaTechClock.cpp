/*
Created by Shirl Lakeway
Date: 11/16/2025
CS-210 Programming Laguages
Chada Tech Clock Project
*/

#include <iostream>
#include "ChadaTechClockFunctions.h" // This file contains the functions for the clock updates
using namespace std;

int main()
{
    int hours, minutes, seconds; // Time variables
    char meridian;               // 'A' for AM, 'P' for PM
    int menuInput = 0;           // Menu selection variable

    initialTimeInput(hours, minutes, seconds, meridian); // Get initial time input from user and stores in variables
    while (menuInput != 5)                               // Main loop for menu selection
    {
        cout << "Please select an option from the menu below:" << endl;
        cout << "1. Display Clocks" << endl;
        cout << "2. Add Hour" << endl;
        cout << "3. Add Minute" << endl;
        cout << "4. Add Second" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ", cin >> menuInput;

        if (menuInput < 1 || menuInput > 5) // Input validation for menu selection
        {
            cout << endl;
            cout << "Invalid choice. Please try again." << endl;
            cout << endl;
            continue;
        }

        if (menuInput == 1) // Display both clocks to the screen
        {
            displayTime12h(hours, minutes, seconds, meridian);
            displayTime24h(hours, minutes, seconds, meridian);
        }
        if (menuInput == 2) // Add one hour to the clock
        {
            hours++;
            if (hours == 24)
            {
                hours = 0; // Reset hours after 24 hours
            }
            if (hours == 12)
            {
                meridian = (meridian == 'A') ? 'P' : 'A'; // Conditional to switch AM/PM when crossing 12 hours
            }
            displayTime12h(hours, minutes, seconds, meridian);
            displayTime24h(hours, minutes, seconds, meridian);
        }
        if (menuInput == 3) // Add one minute to the clock
        {
            minutes++;
            if (minutes == 60)
            {
                minutes = 0; // Reset minutes after 60 minutes
                hours++;
                if (hours == 24)
                {
                    hours = 0; // Reset hours after 24 hours
                }
                if (hours == 12)
                {
                    meridian = (meridian == 'A') ? 'P' : 'A'; // Conditional to switch AM/PM when crossing 12 hours
                }
            }
            displayTime12h(hours, minutes, seconds, meridian);
            displayTime24h(hours, minutes, seconds, meridian);
        }
        if (menuInput == 4) // Add one second to the clock
        {
            seconds++;
            if (seconds == 60)
            {
                seconds = 0; // Reset seconds after 60 seconds
                minutes++;
                if (minutes == 60)
                {
                    minutes = 0; // Reset minutes after 60 minutes
                    hours++;
                    if (hours == 24)
                    {
                        hours = 0; // Reset hours after 24 hours
                    }
                    if (hours == 12)
                    {
                        meridian = (meridian == 'A') ? 'P' : 'A'; // Conditional to switch AM/PM when crossing 12 hours
                    }
                }
            }
            displayTime12h(hours, minutes, seconds, meridian);
            displayTime24h(hours, minutes, seconds, meridian);
        }
        if (menuInput == 5) // Exits the program
        {
            cout << endl;
            cout << "********************************************" << endl;
            cout << "*    Thank you for choosing Chada Tech!    *" << endl;
            cout << "********************************************" << endl;
            cout << endl;
            break;
        }
    }

    return 0;
}
