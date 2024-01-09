#include "Bank.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <bits/stdc++.h>
#include <string>
int main_exit;
int main();





void Bank::search_rec() //function for searching record
{
     int test=0,rate;
    int choice, date1;
    float t;
    string intrst, x, y;
    int amount, b;
    string acc_no, name_s;
    ifstream is("Bank_Record.csv");
    
    cout<<"Do you want to check by\n1.Account no\n2.Name"
			<<"\nEnter your choice:";
    cin>>choice;
    if (choice==1)
    {   
		cout<<"Enter the account number:";
        cin>>acc_no;
        do
        {
        	getline(is,account_number, ',');
       		getline(is, name, ',');
       		getline(is, dob, ',');
       		getline(is, age, ',');
       		getline(is, address, ',');
      		getline(is, phone, ',');
       		getline(is, depo, ',');
      		getline(is, acc_type, ',');
      		getline(is, date, ',');
      		getline(is, doc,',');
      		getline(is, interest,'\n');
        	amount = atoi(depo.c_str());
    		if(acc_no == account_number)
    		{
    			test = 1; system("cls");   
				cout<<"\nAccount NO.:"<<account_number<<endl;
				cout<<"\nName:" <<name<<endl;
				cout<<"\nDOB:" <<dob<<endl;
				cout<<"\nAge:" <<age<<endl;
				cout<<"\nAddress: "<<address<<endl;
				cout<<"\nPhone number:"<<phone<<endl;
				cout<<"\nType Of Account:"<<acc_type<<endl;
				cout<<"\nDate of Account creation:"<<date<<endl;
				cout<<"\nAmount deposited:"<<depo<<endl;
				
				ifstream file ( "Bank_Record.csv" );
				ofstream ofile ( "temp.txt" );
				
            	if(acc_type == "Saving")
                {
                	time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
                        
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get RM " <<intrst
								<<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)
        						ofile << intrst <<",";
    						else if(x == depo)
        					{
        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        					ofile << y << ",";
							}	
        					else
        						ofile << x <<","; 
						}
					}	
					else
					{
						cout<<"\n\nYou will get RM 0 as interest"
								<<" for today...";
					}
					break;                    
                }
                else if(acc_type == "Current")
                {
                    time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get RM " <<intrst
								<<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)
        						ofile << intrst <<",";
    						else if(x == depo)
        					{
        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        					ofile << y << ",";
							}
							else
        						ofile << x <<","; 
						}
					}	
					else
					{
						cout<<"\n\nYou will get RM 0 as interest"
								<<" for today...";
					}
					break;
				}
            }
        }while (is.good());
    }
    else if (choice==2)
    {   
		cout<<"Enter the Name of Account Holder:";
        cin>>name_s;
        do
        {
        	getline(is,account_number, ',');
       		getline(is, name, ',');
       		getline(is, dob, ',');
       		getline(is, age, ',');
       		getline(is, address, ',');
      		getline(is, phone, ',');
       		getline(is, depo, ',');
      		getline(is, acc_type, ',');
      		getline(is, date, ',');
      		getline(is, doc,',');
      		getline(is, interest, '\n');
        	amount = atoi(depo.c_str());
    		if(name_s == name)
            {   
				test = 1; system("cls");   
				cout<<"\nAccount NO.:"<<account_number<<endl;
				cout<<"\nName:" <<name<<endl;
				cout<<"\nDOB:" <<dob<<endl;
				cout<<"\nAge:" <<age<<endl;
				cout<<"\nAddress: "<<address<<endl;
				cout<<"\nPhone number:"<<phone<<endl;
				cout<<"\nType Of Account:"<<acc_type<<endl;
				cout<<"\nDate of Account creation:"<<date<<endl;
				cout<<"\nAmount deposited:"<<depo<<endl;
				
				ifstream file ( "Bank_Record.csv" );
				ofstream ofile ( "temp.txt" );
				
            	if(acc_type == "Saving")
                {
                	time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get RM " <<intrst
								<<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)
        						ofile << intrst <<",";
    						else if(x == depo)
        					{
        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        					ofile << y << ",";
							}
							else
        						ofile << x <<","; 
						}
					}	
					else
					{
						cout<<"\n\nYou will get RM 0 as interest "
								<<"for today...";
					}
					break;                    
                }
                else if(acc_type == "Current")
                {
                    time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get RM " <<intrst
								<<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)
        						ofile << intrst <<",";
    						else if(x == depo)
        					{
        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        					ofile << y << ",";
							}
							else
        						ofile << x <<","; 
						}
					}	
					else
					{
						cout<<"\n\nYou will get RM 0 as interest for today...";
					}
					break;
				}
            }
        }while (is.good());
    }
    if(test == 0)
    {
    	cout<<"\n\n\t\tAccount doesn't Exist!";
	}
    remove("Bank_Record.csv");
   	rename("temp.txt","Bank_Record.csv");	
	is.close();
    login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Customer Menu\n\t"
			<<"3. For Employee Menu and 0 to Exit:";
    cin >> main_exit;
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		menu_customer();
	}
	else if(main_exit == 3)
	{
		system("cls");
		employee();
	}
    else
    {
		cout<<("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
}




void Bank::transfer() {
    int amount, amt, test = 0;
    string acc_no_from, acc_no_to, y, x;

    ifstream file("Bank_Record.csv");
    ofstream ofile("temp.txt");

    cout << "Enter Your account number:";
    cin >> acc_no_from;

    while (getline(file, x, ',')) {
        getline(file, name, ',');
        getline(file, dob, ',');
        getline(file, age, ',');
        getline(file, address, ',');
        getline(file, phone, ',');
        getline(file, depo, ',');
        getline(file, acc_type, ',');
        getline(file, date, ',');
        getline(file, doc, ',');
        getline(file, interest, '\n');

        if (acc_no_from == x) {
            test = 1;
            cout << "Account No.:" << x << endl;
            cout << "Name:" << name << endl;
            cout << "DOB:" << dob << endl;
            cout << "Age:" << age << endl;
            cout << "Address: " << address << endl;
            cout << "Phone number:" << phone << endl;
            cout << "Type Of Account:" << acc_type << endl;
            cout << "Balance:" << depo << endl;

            cout << "\nEnter the amount you want to transfer: ";
            cin >> amt;

            if (amt > atoi(depo.c_str())) {
                cout << "Not Enough Balance\n";
            } else {
                amount = atoi(depo.c_str()) - amt;
                y = std::to_string(amount);
                cout << "\n\tBalance : " << y;

                // Update the balance for the source account
                ofile << x << "," << name << "," << dob << "," << age << "," << address << ","
                      << phone << "," << y << "," << acc_type << "," << date << "," << doc << "," << interest << '\n';
            }
        } 
    }

    if (test == 0) {
        cout << "\n\n\t\tAccount doesn't Exist!";
        file.close();
        ofile.close();
        remove("temp.txt");
        return;
    }

    // Prompt for the target account
    cout << "\nEnter the account number where to transfer:";
    cin >> acc_no_to;
    test = 0;
    file.clear(); // Clear the end-of-file flag
    file.seekg(0, ios::beg);

    while (getline(file, x, ',')) {
        getline(file, name, ',');
        getline(file, dob, ',');
        getline(file, age, ',');
        getline(file, address, ',');
        getline(file, phone, ',');
        getline(file, depo, ',');
        getline(file, acc_type, ',');
        getline(file, date, ',');
        getline(file, doc, ',');
        getline(file, interest, '\n');

        if (acc_no_to == x) {
            test = 1;
            cout << "Account No.:" << x << endl;
            amt = atoi(depo.c_str()) + amt;
            y = std::to_string(amt);

            // Update the balance for the target account
            ofile << x << "," << name << "," << dob << "," << age << "," << address << ","
                  << phone << "," << y << "," << acc_type << "," << date << "," << doc << "," << interest << '\n';

            cout << "\n\tTransfer Successful!";
        }
    }

    if (test == 0) {
        cout << "\n\n\t\tTarget Account doesn't Exist!";
    }

    file.close();
    ofile.close();
    remove("Bank_Record.csv");
    rename("temp.txt", "Bank_Record.csv");

	login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Previous Menu "
			<<"and 0 to Exit:";
    cin >> main_exit;
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		menu_customer();
	}
    else
    {
		cout<<("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
}
