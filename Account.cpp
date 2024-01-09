#include "Bank.h"
#include "functions.h"
#include <iomanip>
int main();



void Bank::read_data()
{
    int x,i=0;
	string acc_no;
	Retry:
	cout<<"\nEnter Account Number: ";
    cin>>account_number;
    ifstream is("Account_info.csv");
    do
    {
       	getline(is,acc_no, ',');
       	getline(is,password, '\n');
    	if(acc_no == account_number)
    	{
    		cout<<"\nAccount No. Matches with Existing Account!";
    		cout<<"\n1. Try Again!\n2. Login To Account";
    		cin>>x;
    		if(x == 1)
    			goto Retry;
    		else
    			customer();
    	}
    	break;
	}while(is.good());
    fflush(stdin);
    cout<<"\nEnter Name: ";
    getline(cin,name);
    cout<<"\nEnter the  of birth(mm/dd/yyyy):";
    fflush(stdin);
	cin>>dob;
    cout<<"\nEnter the age:";
    cin>>age;
    cout<<"\nEnter the address:";
    fflush(stdin);
	getline(cin,address);
    cout<<"\nEnter the phone number: ";
    fflush(stdin);
    cin>>phone;
    cout<<"\nYou want to deposit amount:\n\t1.Yes\n\t2.No\n:";
    cin>>x;
    if(x == 1)
    {
    	cout<<"\nEnter the amount to deposit: RM ";
		cin>>depo;    	
	}
	else
	{
		depo = to_string(0);
	}
    cout<<"\nType of account:\n\t#Saving\n\t#Current\n\n\tEnter your choice:";
    fflush(stdin);
	cin>>acc_type;    
    cout<<endl;
    time_t now = time(0);
    string dt = ctime(&now);
    cout<<"\nDate and Time of Account Creation:" << dt << endl;
    date = dt;
	struct tm *ltm = localtime(&now);
    doc = to_string(ltm->tm_mday);
    doc = doc.substr(0, doc.size()-1);
    interest = to_string(i++);
    cout<<"\nEnter Password For Your Account:";
    cin>>password;
    cout<<"\nAccount created successfully!";
    login_try:
    cout<<"\n\nEnter 1. For Main Menu\n\t2. For Previous Menu and 0 to Exit:";
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
		cout<<"\nInvalid!";
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
}

void Bank::account_write()
{
    
    ofstream MyFile1, MyFile2;
    read_data();

    // Open Bank_Record.csv
    MyFile1.open("Bank_Record.csv", ios::out | ios::app);
    if (!MyFile1.is_open()) {
        cout << "Error opening Bank_Record.csv\n";
        return;
    }

    // Write data to Bank_Record.csv
    MyFile1 << account_number << "," << name << "," << dob << "," << age << "," << address << "," << phone << "," << depo
            << "," << acc_type << "," << date << "," << doc << "," << interest << "\n";
    MyFile1.flush();
    MyFile1.close();

    // Open Account_info.csv
    MyFile2.open("Account_info.csv", ios::out | ios::app);
    if (!MyFile2.is_open()) {
        cout << "Error opening Account_info.csv\n";
        return;
    }

    // Write data to Account_info.csv
    MyFile2 << account_number << "," << password << "," << "\n";
    MyFile2.flush();
    MyFile2.close();
}


void Bank::modify_account()
{
    Bank ac;
	int test = 0;
	string acc_no;
	cout<<"For Verification:\n";
	cout<<"Enter the Account Number again:";
	cin>>acc_no;
	ifstream is("Bank_Record.csv");
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
        if(acc_no == account_number)
    	{   
    		test = 1;
			cout<<"\nAccount NO.:"<<account_number<<endl;
			cout<<"\nName:" <<name<<endl;
			cout<<"\nDOB:" <<dob<<endl;
			cout<<"\nAge:" <<age<<endl;
			cout<<"\nAddress: "<<address<<endl;
			cout<<"\nPhone number:"<<phone<<endl;
			cout<<"\nType Of Account:"<<acc_type<<endl;
			cout<<"\nDate of Account creation:"<<date<<endl;
			cout<<"\nAmount deposited:"<<depo<<endl;
			break;
        }
	}while (is.good());
	is.close();
	string x, y, z;
	int choice;
	int opt;
	if(test == 1)
	{
		ifstream file ("Bank_Record.csv");
		ofstream ofile ("temp.txt");
		do{
		cout<<"\n\n\n\t\t1.Update Name\n";
    	cout<<"\t\t2.Update dob Of Birth\n";
    	cout<<"\t\t3.Update Age\n";
    	cout<<"\t\t4.Update Address\n";
    	cout<<"\t\t5.Update Phone No.\n";
    	cin>>choice;
    	switch(choice)
    	{
        case 1:	system("color 3");
        		cout<<"\t\tUpdate Name\n\n";
				cout<<"Enter Old Name: ";
        		cin>>y;
        		cout<<"Enter New Name: ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x << ",";
				}
        		break;
        case 2:system("color 4");
        		cout<<"\t\tUpdate dob Of Birth\n\n";
				cout<<"Enter Old dob Of Birth(mm/dd/yyyy): ";
        		cin>>y;
        		cout<<"Enter New dob Of Birth(mm/dd/yyyy): ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x << ",";
				}
        		break;
    	case 3:system("color 5");
    			cout<<"\t\tUpdate Age\n\n";
				cout<<"Enter Old Age: ";
        		cin>>y;
        		cout<<"Enter New Age: ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x << ",";
				}
        		break;
        case 4:system("color 6");
				cout<<"\t\tUpdate Address\n\n";
				cout<<"Enter Old Address: ";
        		cin>>y;
        		cout<<"Enter New Address: ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x << ",";
				}
        		break;
        case 5:system("color 2");
				cout<<"\t\tUpdate Phone No.\n\n";
				cout<<"Enter Old Phone No. : ";
        		cin>>y;
        		cout<<"Enter New Phone No. : ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x <<",";
				}
        		break;
        default: cout<<"Invalid Input";
		}
		
		remove("Bank_Record.csv");
   		rename("temp.txt","Bank_Record.csv");	
		file.seekg(0, ios::beg);
		ofile.seekp(0, ios::beg);
		cout<<"\n\n\t\tDo You Want Update Any Other Field :"
				<<"\n\t\t1: YES\n\t\t2: NO\n";
		cin>>opt;
	}while(opt!=2);
	file.close();
	ofile.close();
	}
	else
	{
		cout<<"\nAccount Doesn't Exist";
	}
	login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Previous Menu and" 
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



void Bank::deposit_withdraw()
{
   int choice,test=0,amt,amount;
	string acc_no, y, x;
    ifstream file ("Bank_Record.csv" );
	ofstream ofile ("temp.txt" );
	Bank ac;
	cout<<"Enter the account number:";
	cin>>acc_no;
    while (getline(file, account_number, ',')) {
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
        
        amount = atoi(depo.c_str());

    	if(acc_no == account_number)
    	{   
			test = 1;
			cout<<"\nAccount No.:"<<account_number<<endl;
			cout<<"\nName:" <<name<<endl;
			cout<<"\nDOB:" <<dob<<endl;
			cout<<"\nAge:" <<age<<endl;
			cout<<"\nAddress: "<<address<<endl;
			cout<<"\nPhone number:"<<phone<<endl;
			cout<<"\nDate of Creation: "<<date<<endl;
			cout<<"\nType Of Account:"<<acc_type<<endl;
			cout<<"\nBalance:"<<depo<<endl;
			test=1;
            cout<<"\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\n"
			<<"Enter your choice(1 for deposit and 2 for withdraw):";
            cin>>choice;
              if (choice == 1) {
                cout << "Enter the amount you want to deposit: ";
                cin >> amt;
                amount += amt;
            } else {
                cout << "Enter the amount you want to Withdraw: ";
                cin >> amt;
                if (amt > amount)
                    cout << "Not Enough Balance\n";
                else
                    amount -= amt;
            }
            // Update the balance in the current line
            ofile << account_number << "," << name << "," << dob << "," << age << "," << address << ","
                  << phone << "," << amount << "," << acc_type << "," << date << "," << doc << "," << interest << "\n";
        } else {
            // Copy the existing data to the new file
            ofile << account_number << "," << name << "," << dob << "," << age << "," << address << ","
                  << phone << "," << depo << "," << acc_type << "," << date << "," << doc << "," << interest << "\n";
        }
    }

    file.close();
    ofile.close();

    remove("Bank_Record.csv");
    rename("temp.txt", "Bank_Record.csv");

   if(test==0)
   {
    	cout<<"\n\nRecord not found!!";
    	login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Previous Menu and"
			<<" 0 to try again:";
    cin >> main_exit;
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        ac.deposit_withdraw();
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
   else
   {
    login_try1:
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
		cout<<"\nInvalid!";
        fordelay(1000000000);
        system("cls");
        goto login_try1;
	}
   }

}