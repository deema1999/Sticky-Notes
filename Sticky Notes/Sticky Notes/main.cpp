/*Sticky Notes Program

This program allow users to write thier notes ,save them and retrieve them whenever they want.

*/
#include<iostream>
#include<fstream>//library for files
#include<string>
#include<time.h>//header to use tm struct that is defined in it.
using namespace std;
string firstName,lastName,fullName;
void addNewUser()
{
	
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
void addNote()
{
	string note;
	cout<<"Lets add a new note ...\nPlease enter your full name first: ";
	cin>>firstName;
	cin>>lastName;
	fullName = firstName+"_"+lastName+".txt";
	//if the file was found
	if(ifstream(fullName))
	{
		cout<<"Your record is found, Im now opening your file ….\nReady!\nPlease enter your note:\n"; 
		cin.get();
		getline(cin,note);
		//current date/time based on current system.
		time_t now = time(0);
		//a pointer of type tm which is a timer struct is created to point to current date/time.
		tm *ltm = localtime(&now);
		int year = 1900 + ltm->tm_year; //(Itm->tm_year) return years since 1900.
		int month = 1 + ltm->tm_mon; //(Itm->tm_mon) return monthes since Januray.
		int day = ltm->tm_mday; //(ltm->tm_mday) return day of the month.
		int hour = ltm->tm_hour; //(ltm->tm_hour) return hours since midnight.
		int min =  ltm->tm_min; //(ltm->tm_min) return minutes after the hour.
		ofstream outfile;
		outfile.open(fullName.c_str(),ios::app);//open the file with intend to append notes to it.
		outfile << month<<"/"<<day<<"/"<<year<<" "<<hour<<":"<<min<<endl;
		outfile << note <<"\n\n";
		cout<<"\nYour note has been well received, 1 second while saving it ...\nDone!\n\n";

	}
	//if the file was not found
	else
	{
		cout<<"\nOh! Sorry the user name was not found, please check the name again and if this is your\nfirst time here, please go ahead and create a new user from the main menu ...\n\n";
	}


}
void viewNotes()
{
	cout<<"Retrieve your notes? Absolutely!\nPlease let know your full name first: ";
	cin>>firstName>>lastName;
	ifstream infile;
	string fullName=firstName+"_"+lastName+".txt";
    infile.open(fullName.c_str());  
	//this condition check if the user's file not exist then ask the user to check his/her name and if this is first time ask him/her to create a new user and then enter own notes 
    if(!infile) 
	{
		cout<<"Oh! Sorry the user name was not found, please check the name again and if this is your first time here, please go ahead and create a new user from the main menu and add notes"<<endl;
	    return ;
	}
	//this condition check if the file is empty or not st if empty the start(peek) of the file equal to the end of the file
	if ( infile.peek() == EOF )
      {
		  cout<<"Umm, can’t find any saved notes for you."<<endl;
      }
    else 
      {
		  cout<<"Found it!\nHere are your stored notes:\n-------------"<<endl;
		  if(infile.is_open())
		  {
		  string str;
		   
		  while(getline(infile,str))//using to read the file line by line
		  {
			   
			   printf("%s",str.c_str());//using for printing as cout
			   cout<<endl;
			   
		  }

		  
		  cout<<"-------------\nHappy to serve you :)"<<endl<<endl;
		  
      }
	}
	 infile.close(); // close your file
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
				break;
			}
		 case 2:
			{
				addNote();
				break;
			}
		 case 3:
			{
				viewNotes();
				break;
			}
		 case 4:
			{ 

				break;
			}
		 

		}

	}
	       


	system("pause");
	return 0;

}