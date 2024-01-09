#include "Bank.h"
#include "functions.h"
#include "Welcome.h"




int main()
{
Welcome welcomeObj;

	int ch;
	cout << "\n\n\n\n\n\t\t\t\tWelcome to our bank System";
    int i;
	for(i=0;i<6;i++)
    {
        fordelay(100000000);
        cout<< ".";
	
    }
	system ("CLS");
	 welcomeObj.displayWelcome(); // Call the displayWelcome function
	menu:
	system("cls");
	system("color 4");
	cout<<"\t\t\t ---------------------"<<endl;
	cout<<"\t\t\t|   Malayan Banking |"<<endl;
	cout<<"\t\t\t ---------------------"<<endl;
	system("color 3");
	cout<<"\n\n\t\t\t\t MENU\n";
	cout<<"\n\t\t1. Employee ";
	cout<<"\n\t\t2. Customer ";
	cout<<"\n\t\t3. Exit ";
	cout<<"\n\t\tEnter Your Choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1: employee();
				break;
		case 2: customer();
				break;
		case 3: close();
				break;
		default :	cout<<"Invalid Input! Try Again...\n";
					fordelay(1000000000);
					goto menu;
	}
}
