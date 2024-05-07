/*
Department maintains a student information.
The file contains roll number, name, division and address.
Allow user to add, delete information of student.
Display information of particular employee. 
If record of student does not exist an appropriate message is displayed. 
If it is, then the system displays the student details. 
Use sequential file to main the data
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student
{
	int roll;
	string name;
	char division;
	string address;
		
	public:
		void AddStudent();
		void DisplayStudent();
		void SearchStudent();
		void DeleteStudent();
};

void Student::AddStudent()
{
	ofstream fout("Sample.txt",ios::app);
	char check;
	do{
		cout<<"\nEnter Student Roll No. : ";
		cin>>roll;
		cout<<"Enter Student Name : ";
		cin>>name;
		cout<<"Enter Student Division : ";
		cin>>division;
		cout<<"Enter Student Address : ";
		cin>>address;
		
		fout << roll <<"\t" << name <<"\t\t" << division <<"\t" << address <<endl;
		
		cout<<"\nDo you want to add more record (if yes then type Y/y) : ";
		cin>>check;
	}while(check=='y'||check=='Y');	
	fout.close();
	return;
}
void Student::DisplayStudent()
{
	ifstream fin("Sample.txt");
	cout<<"\nRoll\tName\t\tDivision\tAddress"<<endl;
	while(fin>>roll>>name>>division>>address)
	{
		cout<<roll<<"\t"<<name<<"\t\t"<<division<<"\t\t"<<address<<endl;
	}
	fin.close();
}
void Student::SearchStudent()
{
	int rollNo;
     cout << "\nEnter the Roll No. to search: ";
     cin >> rollNo;

     ifstream fin("Sample.txt");
     bool found = false;

     cout << "\nRoll\tName\t\tDivision\tAddress"<<endl;
     while(fin >> roll >> name >> division >> address)
     {
        if (roll == rollNo)
        {
            cout << roll << "\t" << name << "\t\t" << division << "\t\t" << address << endl;
            found = true;
            break; // Once found, no need to continue searching
        }
     }
    fin.close();
}
void Student::DeleteStudent()
{
    int rollNo;
    cout << "\nEnter the Roll No. to delete: ";
    cin >> rollNo;

    ifstream fin("Sample.txt");
    ofstream fout("temp.txt");

    bool found = false;

    while(fin >> roll >> name >> division >> address)
    {
        if (roll == rollNo)
        {
            found = true;
            cout << "\nRecord with Roll No. " << rollNo << " deleted!" << endl;
            continue;
        }
        fout << roll << "\t" << name << "\t\t" << division << "\t" << address << endl;
    }

    fin.close();
    fout.close();

    remove("Sample.txt");
    rename("temp.txt", "Sample.txt");

    if (!found)
    {
        cout << "Record with Roll No. " << rollNo << " not found!" << endl;
    }
}
int main()
{
	Student obj;
	char ans;
	int ch;
	do{
		cout<<"\nEnter your Choice : ";
		cout<<"\n1.Add Student data \n2.Display Student data \n3.Search Student Data \n4.Delete Student data \n5.Exit \n--->";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				obj.AddStudent();
				break;
			case 2:
				obj.DisplayStudent();
				break;
			case 3:
				obj.SearchStudent();
				break;
			case 4:
				obj.DeleteStudent();
				break;
			case 5:
				exit(0);
			
			cout<<"\nDo you want to continue(if yes then enter Y/y) : ";
			cin>>ans;	
		}
	}while(ans=='Y' || ans=='y');
	return 0;
}