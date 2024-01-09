#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Welcome.h"

using namespace std;

void Welcome::displayWelcome()
{
    ifstream in("welcome.txt"); // Open the file "welcome.txt" for reading

    if (!in)
    {
        cerr << "Cannot open input file.\n"; // Display an error message if the file cannot be opened
        return;
    }

    char str[1000];

    // Read lines from the file and display them
    while (in)
    {
        in.getline(str, 1000); // Read a line from the file
        if (in)
            cout << str << endl; // Display the line on the output screen
    }

    in.close(); // Close the file

    this_thread::sleep_for(chrono::seconds(3)); // Wait for 5 seconds

    system("CLS"); // Clear the screen after 5 seconds
}
