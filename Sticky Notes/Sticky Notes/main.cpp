/*Sticky Notes Program

This program allow users to write thier notes ,save them and retrieve them whenever they want.

*/
#include<iostream>
using namespace std;
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
	}
	       


	system("pause");
	return 0;

}