#include "functions.h"
#include "Bank.h"
extern int main_exit;
int main();

float inter(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}

void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void close(void)
{
     cout<<"\n\n\n\nThis Program is Closed... Thank You";
}

void employee() // ... (login functionality for employees)
{
    char pass[10];
    char c;
    string s, name;
    int i=0;
    cout<<"\n\n\t\tFor Security Purpose:";
    cout<<"\n\n\t\tEnter the Login Emplyoee Id:";
    cin>>name;
    cout<<"\n\n\t\tEnter the password to login:";
    while(1)
	{
    	c=getch();
        cout<<"*";
        s+=c;
    	if(c=='\r')
        {
            break;
        }    	
	}
 	s = s.substr(0, s.size()-1);
    cout<<endl;
    if(s == "1234" && (name == "Admin" || name == "ADMIN"))
        {
			cout<<"\n\nAccess Granted!\nLOADING";
        	for(i=0;i<=6;i++)
        	{
            	fordelay(100000000);
            	cout<<".";
        	}
            	system("cls");
            	menu_employee();
        }
    else
        {   cout<<"\n\nWrong password or Emplyoee Id!!";
            login_try:
            cout<<"\nEnter 1 to try again , 2 for Main Menu and"
					<<" 0 to Exit:";
            cin >> main_exit;
            if (main_exit==1)
            {
                system("cls");
                employee();
            }
            else if (main_exit==0)
            {
                system("cls");
            	close();
			}
			else if (main_exit == 2)
			{
				system("cls");
				main();
			}
            else
            {
				cout<<"\nInvalid!";
                fordelay(1000000000);
                system("cls");
                goto login_try;
			}
        }
}

void menu_employee() // ... (employee menu with options to search records, display all, etc.)
{
    int choice;
    Bank B;
    menu:
    system("cls");
    system("color 2");
	cout<<"\n\n\t\t\tBANK RECORD SYSTEM";
    cout<<"\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME "
		<<"TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<"\n\n\t\t\tEmployee Menu";
	cout<<"\n\t\t1.Check the details of existing account\n";
    cout<<"\t\t2.Display All Account Holder Name\n";
	cout<<"\t\t3.Exit\n\n\n\n\n\t\t Enter your choice:";
    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:	B.search_rec();
        		break;
        case 2: B.display_all();
        		break;
        case 3:	close();
        		break;
        default :cout<<"Invalid Input!\n";
        		cout<<"   Try Again\n";
				goto menu;
    }
    login_try:
    cout<<"\nEnter 1 for Main Menu , 2 for Previous Menu and"
		<<" 0 to Exit:";
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
				employee();
			}
            else
            {
				cout<<"\nInvalid!";
                fordelay(1000000000);
                system("cls");
                goto login_try;
			}
}

void customer() {
    char pass[10];
    char c;
    string s, name, acc_no, password;
    int i = 0, x;
    system("cls");
    
    cout << "\n\n\t\t\tMENU";
    cout << "\n\t\t1. New Customer";
    cout << "\n\t\t2. Existing Customer";
    
    // Loop until valid input is received
    while (true) {
        cout << "\n\t\tEnter Your Choice : ";
        cin >> x;
        
        if (cin.fail() || (x != 1 && x != 2)) {
            // Display error message for invalid input
            cout << "\n\t\tInvalid input! Please enter 1 or 2 only.\n";
            
            // Clear the error flag for cin and discard invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break; // Valid input received, exit the loop
        }
    }

    if (x == 1)
        menu_customer();
    else {
        // Existing customer login
        cout << "\n\n\t\tFor Security Purpose:";
        cout << "\n\n\t\tEnter the Login Customer Id:";
        cin >> name;
        cout << "\n\n\t\tEnter the password to login:";

        while (1) {
            c = getch();
            cout << "*";
            s += c;
            if (c == '\r') {
                break;
            }
        }
        s = s.substr(0, s.size() - 1);
        cout << endl;

        ifstream is("Account_info.csv");
        do {
            getline(is, acc_no, ',');
            getline(is, password, '\n');
            if (acc_no == name) {
                i = 1;
                if (password == s)
                    cout << "\n\nAccess Granted!\nLOADING";
                for (i = 0; i <= 6; i++) {
                    fordelay(100000000);
                    cout << ".";
                }
                system("cls");
                menu_customer();
            }
        } while (is.good());

        if (i == 0) {
            cout << "\n\nWrong password or Customer Id!!";
            login_try:
            cout << "\nEnter 1 to try again, 2 for Main Menu, and 0 to Exit:";
            cin >> main_exit;
            if (main_exit == 1) {
                system("cls");
                customer();
            } else if (main_exit == 0) {
                system("cls");
                close();
            } else if (main_exit == 2) {
                system("cls");
                main();
            } else {
                cout << "\nInvalid!";
                fordelay(1000000000);
                system("cls");
                goto login_try;
            }
        }
    }
}


void menu_customer(void)
{
    int choice;
    Bank B;
    
    login_try:
    system("cls");
    system("color 2");
    cout << "\n\n\t\t\tBANK RECORD SYSTEM";
    cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME"
         << " TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\n\t\t1.Create new account\n";
    cout << "\t\t2.Update information of an existing account\n";
    cout << "\t\t3.For transactions\n";
    cout << "\t\t4.Check the details of an existing account\n";
    cout << "\t\t5.For Transfer\n";
    cout << "\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:";
    cin >> choice;

    system("cls");
    switch (choice)
    {
    case 1:
        B.account_write();
        break;
    case 2:
        B.modify_account();
        break;
    case 3:
        B.deposit_withdraw();
        break;
    case 4:
        B.search_rec();
        break;
    case 5:
        B.transfer();
        break;
    case 6:
        close();
        break;
    default:
        cout << "\aInvalid choice! Please enter a number between 1 and 6.";
        fordelay(1000000000);
        goto login_try;
    }

    cout << "\nEnter 1 for the Main Menu, 2 for the Previous Menu, and 0 to Exit:";
    cin >> main_exit;
    if (main_exit == 1)
    {
        system("cls");
        main();
    }
    else if (main_exit == 0)
    {
        system("cls");
        close();
    }
    else if (main_exit == 2)
    {
        system("cls");
        employee();
    }
    else
    {
        cout << "\nInvalid!";
        fordelay(1000000000);
        system("cls");
        goto login_try;
    }
}
