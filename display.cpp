
#include "Bank.h"
#include "functions.h"

int main();


void Bank::display_all() {
    int amount;
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================="
         << "========================================================="
         << "=========================\n";
    cout << "  Account No.\t\tName\t\tType\t\tBalance\t\tAddress"
         << "\t\tPhone No.\t\tCreation Date\n";
    cout << "====================================================="
         << "========================================================="
         << "=========================\n";

    ifstream is("Bank_Record.csv");
    if (!is.is_open()) {
        cout << "Error opening Bank_Record.csv\n";
        return;
    }

    int i = 1, sz = 0, sz1 = 0;
    char c;
    is.seekg(0, ios::end);
    sz = is.tellg();
    is.seekg(0, ios::beg);

    // Open the file for writing
    ofstream outputFile("Bank_Record_Formatted.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening Bank_Record_Formatted.txt\n";
        return;
    }

    while (!is.eof()) {
    
        outputFile << "\n====================================================="
                   << "========================================================="
                   << "=========================\n";
        outputFile << "  Account No.\t\tName\t\tType\t\tBalance\t\tAddress"
                   << "\t\tPhone No.\t\tCreation Date\n";
        outputFile << "====================================================="
                   << "========================================================="
                   << "=========================\n";

        cout << i << ". ";
        i++;
        getline(is, account_number, ',');
        getline(is, name, ',');
        getline(is, dob, ',');
        getline(is, age, ',');
        getline(is, address, ',');
        getline(is, phone, ',');
        getline(is, depo, ',');
        getline(is, acc_type, ',');
        getline(is, date, ',');
        getline(is, doc, ',');
        getline(is, interest, '\n');
        amount = atoi(depo.c_str());
        sz1 = is.tellg();

        cout << account_number << "\t\t" << name << "\t\t" << acc_type
             << "\t\t" << amount << "\t\t" << address << "\t\t" << phone
             << "\t\t" << date << endl;

        outputFile << account_number << "\t\t" << name << "\t\t" << acc_type
                   << "\t\t" << amount << "\t\t" << address << "\t\t" << phone
                   << "\t\t" << date << endl;

        if (sz == (sz1))
            break;
    }

    // Close the files
    is.close();
    outputFile.close();

    cout << "\nBank_Record_Formatted.txt has been generated successfully.\n";

    login_try:
    cout << "\nEnter 1. For Main Menu\n\t2. For Previous Menu "
         << "and 0 to Exit:";
    cin >> main_exit;

    if (main_exit == 1) {
        system("cls");
        main();
    } else if (main_exit == 0) {
        system("cls");
        close();
    } else if (main_exit == 2) {
        system("cls");
        menu_employee();
    } else {
        cout << "\nInvalid!";
        fordelay(1000000000);
        system("cls");
        goto login_try;
    }
}
