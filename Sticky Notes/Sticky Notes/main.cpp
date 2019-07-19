/*Sticky Notes Program

This program allow users to write thier notes ,save them and retrieve them whenever they want.

*/
#include<iostream>
#include<fstream>//library for files
#include<string>
using namespace std;

void addNewUser()
{
	string firstName,lastName,fullName;
	cout<<"Welcome aboard new user!\nPlease let me know your first name: ";
	cin>>firstName;
    cout<<"Great "<<firstName<<" now please enter your last name: "; 
	cin>>lastName;
	cout<<"Done!\nNice to meet you "<<firstName<<" "<<lastName<<endl<<endl;

	//open a file for a new user to write on it 
	ofstream outfile;
	fullName=firstName+"_"+lastName+".txt";
	//creat file with user name
	outfile.open(fullName.c_str());
	outfile.close();

}
int main()
{
	int choice;
	while(1)
	{
		/*creat the menu so from it the user would like to be asked to enter his/her user name, then enter a text message. 
          Later on, the user should be able to retrieve all his/her messages.*/
		
		cout<<"Welcome to the brand new 'Sticky Notes'\nHere is the list of operation this program offers:\n";
		cout<<"1- Add new user\n";
		cout<<"2- Add new note\n";
		cout<<"3- View notes for a specific user\n";
		cout<<"4- Exit\n";
		cout<<"Enter your choice : ";
		cin >> choice;

		system("cls");
		switch(choice)
		{
		case 1:
			{
				addNewUser();
			}
		}

	}
	       


	system("pause");
	return 0;

}