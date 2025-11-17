#include <iostream>
using namespace std;

void displayTime12h(int &hours, int &minutes, int &seconds, char &meridian) // Function to display time in 12-hour format
{
    if (hours == 0) // Converts the time to a 12-hour format for display
    {
        hours = 12;
    }
    else if (hours > 12)
    {
        hours -= 12;
    }
    // Display the formatted time
    cout << endl;
    cout << "*******************************" << endl;
    cout << "*        12-Hour Clock        *" << endl;
    cout << "*  " << "Current Time: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << meridian << "M" << "  *" << endl;
    cout << "*******************************" << endl;
}

void displayTime24h(int hours, int minutes, int seconds, char meridian) // Function to display time in 24-hour format
{
    if (meridian == 'A' && hours == 12) // Converts the time to a 24-hour format for display
    {
        hours = 0;
    }
    else if (meridian == 'P' && hours != 12)
    {
        hours += 12;
    }

    // Display the formatted time
    cout << endl;
    cout << "*******************************" << endl;
    cout << "*        24-Hour Clock        *" << endl;
    cout << "*   " << "Current Time: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << "    *" << endl;
    cout << "*******************************" << endl;
    cout << endl;
}

void initialTimeInput(int &hours, int &minutes, int &seconds, char &meridian) // Function to get initial time input from user
{
    cout << "********************************************" << endl;
    cout << "*              Chada Tech Clock            *" << endl;
    cout << "********************************************" << endl;
    cout << endl;

    // Prompt user for initial time input with validation
    cout << "Please enter the initial time for the clock." << endl;
    cout << "Enter hours (1-12): ", cin >> hours;
    while (hours < 1 || hours > 12)
    {
        cout << "Invalid hours input. Please enter a value between 1 and 12." << endl;
        cout << "Enter hours (1-12): ", cin >> hours;
    }
    cout << "Enter minutes (0-59): ", cin >> minutes;
    while (minutes < 0 || minutes > 59)
    {
        cout << "Invalid minutes input. Please enter a value between 0 and 59." << endl;
        cout << "Enter minutes (0-59): ", cin >> minutes;
    }
    cout << "Enter seconds (0-59): ", cin >> seconds;
    while (seconds < 0 || seconds > 59)
    {
        cout << "Invalid seconds input. Please enter a value between 0 and 59." << endl;
        cout << "Enter seconds (0-59): ", cin >> seconds;
    }
    cout << "Is it AM or PM? (Enter A for AM, P for PM): ", cin >> meridian;
    while (meridian != 'A' && meridian != 'P')
    {
        cout << "Invalid input. Please enter A for AM or P for PM." << endl;
        cout << "Is it AM or PM? (Enter A for AM, P for PM): ", cin >> meridian;
    }
    cout << endl;
}
