#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <limits>


using namespace std;

class Bank
{
public:
    string account_number;
	string name;
    string dob;
    string age;
    string date;
    string address;
    string phone;
    string doc;
    string depo;
    string acc_type;
    string password;
    string interest;
    
public:
    void read_data();
    void account_write();
	void modify_account();
	void search_rec();
	void deposit_withdraw();
	void display_all();
	void transfer();
    
    
};

#endif
