#include<iostream>    //input output library
#include<fstream>     //for reding and writing on files
#include<iomanip>     //for spacing
#include<windows.h>
#include <string> 
using namespace std;
int choice;
struct Student
{
	string firstname;
	string roll, dep;
	int calculusMarks, semester;
	int programmingMarks;
	int engMarks;
	int islamicStudiesMarks, physics;
	float total_marks;
	char grade;
	double gpa;
	float per;
};
Student s[1000];		// structure array so that we can add multiple user in one programs
int i = 0;				// globally declared  i so that can be used in whole program
void up_gpa(float percentage, double& gpa);
void add_student()
{

	cout << "*********************************************************************************************************************" << endl;
	cout << "*                                                                                                                   *" << endl;
	cout << "*                                            ADD  STUDENTS                                                          *" << endl;
	cout << "*                                                                                                                   *" << endl;
	cout << "*********************************************************************************************************************" << endl;
	ofstream file("student_recrd.txt", ios::app);   // made file for purpose of appending data into file
	cout << "\n\n\tHow many students you want to enter: ";
	cin >> choice;						           // asking user how many student he want to enter
	if (!file.is_open()) {
		cout << "Error: Unable to open file for writing!" << endl;
		return;
	}
	else {
		ofstream file("student_recrd.txt", ios::app|ios::out);   // made file for purpose of appending data into file
		for (int i = 0; i < choice; i++)
		{
			cout << "\n\tS T U D E N T " << i + 1 << endl;
			cout << "\n\n\tEnter student name :";
			cin >> s[i].firstname;
			cin.ignore();
			cout << "\n\n\tEnter student Roll number :";
			cin >> s[i].roll;
			cin.ignore();
			cout << "\n\n\tEnter student semester :";
			cin >> s[i].semester;
			cin.ignore();
			cout << "\n\n\tEnter student department :";
			cin >> s[i].dep;
			cin.ignore();
			while (true)
			{			// while(true) is useed to ask user marks while marks are correctly written if incorrect hen it ask again
				cout << left << setw(25) << "   Programming " << setw(15);
				cin >> s[i].programmingMarks;
				if (s[i].programmingMarks <= 100)
				{
					break;				//break the loop
				}
				else
				{
					cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
				}
			}
	
			while (true)
			{
				cout << left << setw(25) << "  Calculas " << setw(15);
				cin >> s[i].calculusMarks;
				if (s[i].calculusMarks <= 100)
				{
					break;
				}
				else
				{
					cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
				}
			}
	
			while (true)
			{
				cout << left << setw(25) << "  Physic " << setw(15);
				cin >> s[i].physics;
				if (s[i].physics <= 100)
				{
					break;
				}
				else
				{
					cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
				}
			}
	
			while (true)
			{
				cout << left << setw(25) << "   English" << setw(15);
				cin >> s[i].engMarks;
				if (s[i].calculusMarks <= 100)
				{
					break;
				}
				else
				{
					cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
				}
			}
	
			while (true)
			{
				cout << left << setw(25) << "   Islamic Studies " << setw(15);
				cin >> s[i].islamicStudiesMarks;
				if (s[i].islamicStudiesMarks <= 100)
				{
					break;
				}
				else
				{
					cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
				}
			}
			s[i].total_marks = s[i].programmingMarks + s[i].calculusMarks + s[i].engMarks + s[i].islamicStudiesMarks + s[i].physics;
			s[i].per = (s[i].total_marks/500)*100;
			up_gpa(s[i].per, s[i].gpa);
			file << left << setw(25) << s[i].firstname
                 << setw(20) << s[i].roll
                 << setw(20) << s[i].semester
                 << setw(20) << s[i].dep<< setw(15) << s[i].calculusMarks
                 << setw(15) << s[i].engMarks
                 << setw(15) << s[i].physics
                 << setw(15) << s[i].programmingMarks
                 << setw(15) << s[i].islamicStudiesMarks 
                 << setw(20) << s[i].total_marks
                 << setw(20) << s[i].gpa << endl;
		}
			cout << endl << "			----------RECORD ADDED SUCCESSFULLY----------" << endl;
			
	}
	file.close();			/// to close a file
}
void up_gpa(float percentage, double &gpa)
{
		if (percentage >= 90)
		{
			gpa = 4.00;
			
		}
		else if (percentage >= 80)
		{
			gpa = 3.5;
		}
		else if (percentage >= 70)
		{
			gpa = 3.0;
		}
		else if (percentage >= 60)
		{
			gpa = 2.5;
		}
		else
		{
			gpa = 2.0;
		}
}
void std_rec()
{
	cout << "*********************************************************************************************************************" << endl;
	cout << "*                                                                                                                   *" << endl;
	cout << "*                                            UPDATE STUDENTS RECORD                                                 *" << endl;
	cout << "*                                                                                                                   *" << endl;
	cout << "*********************************************************************************************************************" << endl;
	string rollToUpdate;
    int updateResult = 0;
	ifstream getting_from_File("student_recrd.txt");
	i=0;
	ofstream sending_to_File("temp.txt", ios::out);  
	cout << "\n\tEnter Roll number to Update : ";
    cin >> rollToUpdate;
    while(getting_from_File >> s[i].firstname>>s[i].roll>> s[i].semester>>s[i].dep 
				>>s[i].programmingMarks >> s[i].physics>> s[i].engMarks>> s[i].calculusMarks
				>>s[i].islamicStudiesMarks >>s[i].total_marks >> s[i].gpa)
				{
					if (s[i].roll == rollToUpdate)
					{
						updateResult ++;
					cout << "\n\n\tEnter student name :";
					cin >> s[i].firstname;
					cin.ignore();
					cout << "\n\n\tEnter student Roll number :";
					cin >> s[i].roll;
					cin.ignore();
					cout << "\n\n\tEnter student semester :";
					cin >> s[i].semester;
					cin.ignore();
					cout << "\n\n\tEnter student department :";
					cin >> s[i].dep;
					cin.ignore();
					while (true)
					{			// while(true) is useed to ask user marks while marks are correctly written if incorrect hen it ask again
						cout << left << setw(25) << "   Programming " << setw(15);
						cin >> s[i].programmingMarks;
						if (s[i].programmingMarks <= 100)
						{
							break;				//break the loop
						}
						else
						{
							cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
						}
					}
			
					while (true)
					{
						cout << left << setw(25) << "  Calculas " << setw(15);
						cin >> s[i].calculusMarks;
						if (s[i].calculusMarks <= 100)
						{
							break;
						}
						else
						{
							cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
						}
					}
			
					while (true)
					{
						cout << left << setw(25) << "  Physic " << setw(15);
						cin >> s[i].physics;
						if (s[i].physics <= 100)
						{
							break;
						}
						else
						{
							cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
						}
					}
			
					while (true)
					{
						cout << left << setw(25) << "   English" << setw(15);
						cin >> s[i].engMarks;
						if (s[i].engMarks <= 100)
						{
							break;
						}
						else
						{
							cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
						}
					}
			
					while (true)
					{
						cout << left << setw(25) << "   Islamic Studies " << setw(15);
						cin >> s[i].islamicStudiesMarks;
						if (s[i].islamicStudiesMarks <= 100)
						{
							break;
						}
						else
						{
							cout << left << setw(25) << "   Enter Marks less than or equal to 100!" << endl;
						}
					}
					s[i].total_marks = s[i].programmingMarks + s[i].calculusMarks + s[i].engMarks + s[i].islamicStudiesMarks + s[i].physics;
					s[i].per = (s[i].total_marks/500)*100;
					up_gpa(s[i].per, s[i].gpa);
					cout << endl << "			----------RECORD UPDATED SUCCESSFULLY----------" << endl;
					sending_to_File << left << setw(25) << s[i].firstname
                 << setw(20) << s[i].roll
                 << setw(20) << s[i].semester
                 << setw(20) << s[i].dep<< setw(15) << s[i].calculusMarks
                 << setw(15) << s[i].engMarks
                 << setw(15) << s[i].physics
                 << setw(15) << s[i].programmingMarks
                 << setw(15) << s[i].islamicStudiesMarks 
                 << setw(20) << s[i].total_marks
                 << setw(20) << s[i].gpa << endl;
				}	
				else {
            		sending_to_File << left << setw(25) << s[i].firstname
                 << setw(20) << s[i].roll
                 << setw(20) << s[i].semester
                 << setw(20) << s[i].dep<< setw(15) << s[i].calculusMarks
                 << setw(15) << s[i].engMarks
                 << setw(15) << s[i].physics
                 << setw(15) << s[i].programmingMarks
                 << setw(15) << s[i].islamicStudiesMarks 
                 << setw(20) << s[i].total_marks
                 << setw(20) << s[i].gpa << endl;
        		}	
        		i++;
			}
	getting_from_File.close();
    sending_to_File.close();

    remove("student_recrd.txt");       // remove original file
    rename("temp.txt", "student_recrd.txt");      // rename temprorary file to original file name

    if (updateResult == 0) 
	{
        cout << "\n\n\t\t\t*****************" << endl;
        cout << "\t\t\t*    NOT FOUND!   *" << endl;
        cout << "\t\t\t*****************" << endl;
    }
}
void std_rep()
{
	    cout << "*********************************************************************************************************************" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*                                            A L L  R E C O R D                                                     *" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*********************************************************************************************************************" << endl << endl << endl;

    ifstream file("student_recrd.txt");    // declared to read file and take data from it and display the data

    if (!file) {
        cout << "Error opening the file." << std::endl;
        return;
    }

    int found = 0;   // variable initialization for seeing if data exists then it would increment as 1 and if not found then remain 0 and print error that data not esists
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(16) << "Name"
         << setw(12) << "Roll"
         << setw(10) << "Semester";
    cout << setw(10) << "Calculus"
         << setw(13) << "English"
         << setw(10) << "Physics"
         << setw(14) << "Programming "
         << setw(10) << "Islamic"
         << setw(15) << "Total Marks"
         << setw(15) << "GPA" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    while (file >>s[i].firstname>> s[i].roll>> s[i].semester>>s[i].dep 
				>>s[i].programmingMarks >> s[i].physics>> s[i].engMarks>> s[i].calculusMarks
				>>s[i].islamicStudiesMarks >>s[i].total_marks >> s[i].gpa) 
	{
        found++;		
		cout << left << setw(16) << s[i].firstname
             << setw(12) << s[i].roll
             << setw(10) << s[i].semester
				<<setw(10) << s[i].calculusMarks
                 << setw(13) << s[i].engMarks
                 << setw(12) << s[i].physics
                 << setw(13) << s[i].programmingMarks
                 << setw(10) << s[i].islamicStudiesMarks 
                 << setw(15) << s[i].total_marks
                 << setw(10) << s[i].gpa << endl;		
        i++;           //increment
    }

    file.close();

    if (found == 0) 
	{
        cout << "\n\n\t\t\t*********************" << endl;
        cout << "\t\t\t*    NOT FOUND!     *" << endl;
        cout << "\t\t\t*********************" << endl;
    }
}
void std_sum() {
    cout << "*" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*                                            STUDENTS SUMMARY                                                       *" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*" << endl;
    i = 0;
    ifstream file("student_recrd.txt");    

    if (!file) {
        cout << "Error opening the file." << std::endl;
        return;
    }
    double avg = 0;
    int found = 0; 
	int maxIndex = 0, minIndex = 0; // Variables to store indices of maximum and minimum total marks records
	int maxTotalMarks = 0, minTotalMarks = 500; // Initialize minTotalMarks with maximum possible value

	while (file >> s[i].firstname >> s[i].roll >> s[i].semester >> s[i].dep 
            >> s[i].programmingMarks >> s[i].physics >> s[i].engMarks >> s[i].calculusMarks
            >> s[i].islamicStudiesMarks >> s[i].total_marks >> s[i].gpa) {
    found++;        
	avg = avg + s[i].gpa;
    if (s[i].total_marks < minTotalMarks) {
        minTotalMarks = s[i].total_marks;
        minIndex = i; 
    }
    else if (s[i].total_marks > maxTotalMarks) {
        maxTotalMarks = s[i].total_marks;
        maxIndex = i; 
    }
             
        i++;          
}
	avg = avg / i;
    file.close();

    if (found == 0) {
        cout << "\n\n\t\t\t*********************" << endl;
        cout << "\t\t\t*    NOT FOUND!     *" << endl;
        cout << "\t\t\t*********************" << endl;
    } else {
        cout << "\t\tMaximum GPA: " << s[maxIndex].gpa << " (Student: " << s[maxIndex].firstname << ")" << endl <<endl; 
        cout << "\t\tMinimum GPA: " << s[minIndex].gpa << " (Student: " << s[minIndex].firstname << ")" << endl <<endl;
        cout << "\t\tAverage GPA: " << avg << endl <<endl;
    }
}
void sort() {
    cout << "*" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*                                            GPA SORTING                                                            *" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*" << endl;

    ifstream file("student_recrd.txt", ios::in);
    ofstream infile("temp.txt", ios::out);
    int found = 0;
    Student s[100]; 
    while (file >> s[found].firstname >> s[found].roll >> s[found].semester >> s[found].dep
        >> s[found].programmingMarks >> s[found].physics >> s[found].engMarks >> s[found].calculusMarks
        >> s[found].islamicStudiesMarks >> s[found].total_marks >> s[found].gpa) {
        found++;
    }

    cout << "Total students found: " << found << endl;

    // Sorting
    for (int i = 0; i < found - 1; i++) {
        for (int j = i + 1; j < found; j++) {
            if (s[i].gpa < s[j].gpa) {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    // Writing sorted data
    for (int k = 0; k < found; ++k) {
        infile << s[k].firstname << "    " << s[k].roll << "    " << s[k].semester << "    " << s[k].dep << "    "
               << s[k].programmingMarks << "    " << s[k].physics << "    " << s[k].engMarks << "    " << s[k].calculusMarks
               << "    " << s[k].islamicStudiesMarks << "   " << s[k].total_marks << "   " << s[k].gpa << endl;
    }
	cout<<"\n\n\t\t**********************"<<endl;
    cout<<"\t\t*  Sorted Data.      *" << endl;
    cout<<"\t\t**********************"<<endl;
    file.close();
	infile.close();
    remove("student_recrd.txt");
    rename("temp.txt", "student_recrd.txt");
    ifstream file_display("student_recrd.txt"); 
     cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(16) << "Name"
         << setw(12) << "Roll"
         << setw(10) << "Semester";
    cout << setw(10) << "Calculus"
         << setw(13) << "English"
         << setw(10) << "Physics"
         << setw(14) << "Programming "
         << setw(10) << "Islamic"
         << setw(15) << "Total Marks"
         << setw(15) << "GPA" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	i = 0;
    while (file_display >>s[i].firstname>> s[i].roll>> s[i].semester>>s[i].dep 
				>>s[i].programmingMarks >> s[i].physics>> s[i].engMarks>> s[i].calculusMarks
				>>s[i].islamicStudiesMarks >>s[i].total_marks >> s[i].gpa) 
	{		
		cout << left << setw(16) << s[i].firstname
             << setw(12) << s[i].roll
             << setw(10) << s[i].semester
				<<setw(10) << s[i].calculusMarks
                 << setw(13) << s[i].engMarks
                 << setw(12) << s[i].physics
                 << setw(13) << s[i].programmingMarks
                 << setw(10) << s[i].islamicStudiesMarks 
                 << setw(15) << s[i].total_marks
                 << setw(10) << s[i].gpa << endl;		
        i++;           //increment
    }
    file.close();
}


void exp_report() {
    cout << "*" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*                                            EXPORT REPORT                                                          *" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*" << endl;

    string name, location;
    int found = 0;
    int i = 0;
	string file_name = "ali.txt";
    ofstream sending_to_File("ali.txt"); // Append the ".txt" extension to the filename
    ifstream getting_from_file("student_recrd.txt");
    
    if (!sending_to_File.is_open()) {
        cout << "Error: Unable to open file for writing: " << name << ".txt" << endl;
        return;
    }
    
    if (!getting_from_file.is_open()) {
        cout << "Error: Unable to open file for reading: student_recrd.txt" << endl;
        sending_to_File.close();
        return;
    }
	sending_to_File <<left<<setw(25)<<"Names "<<setw(20)<<"Roll num" << setw(20) << "Semester"
                 << setw(20) << "Department"<< setw(15) << "Calculus"
                 << setw(15) << "English"
                 << setw(15) << "Physics"
                 << setw(15) << "Programming "
                 << setw(15) << "Islamic"
                 << setw(20) << "Total Marks"
                 << setw(20) << "GPA" << endl<<endl;
    while (getting_from_file >> s[found].firstname >> s[found].roll >> s[found].semester >> s[found].dep 
            >> s[found].programmingMarks >> s[found].physics >> s[found].engMarks >> s[found].calculusMarks
            >> s[found].islamicStudiesMarks >> s[found].total_marks >> s[found].gpa)
    {
        sending_to_File << left << setw(25) << s[i].firstname
                 << setw(20) << s[i].roll
                 << setw(20) << s[i].semester
                 << setw(20) << s[i].dep<< setw(15) << s[i].calculusMarks
                 << setw(15) << s[i].engMarks
                 << setw(15) << s[i].physics
                 << setw(15) << s[i].programmingMarks
                 << setw(15) << s[i].islamicStudiesMarks 
                 << setw(20) << s[i].total_marks
                 << setw(20) << s[i].gpa << endl;
        found++; // Increment the index for the next student record
        i++;
    }
  	i = 0;
    ifstream file("student_recrd.txt");    

    if (!file) {
        cout << "Error opening the file." << std::endl;
        return;
    }
    double avg = 0;
    found = 0; 
	int maxIndex = 0, minIndex = 0; // Variables to store indices of maximum and minimum total marks records
	int maxTotalMarks = 0, minTotalMarks = 500; // Initialize minTotalMarks with maximum possible value

	while (file >> s[i].roll >> s[i].firstname >> s[i].semester >> s[i].dep 
            >> s[i].programmingMarks >> s[i].physics >> s[i].engMarks >> s[i].calculusMarks
            >> s[i].islamicStudiesMarks >> s[i].total_marks >> s[i].gpa) {
    found++;        
	avg = avg + s[i].gpa;
    if (s[i].total_marks < minTotalMarks) {
        minTotalMarks = s[i].total_marks;
        minIndex = i; 
    }
    else if (s[i].total_marks > maxTotalMarks) {
        maxTotalMarks = s[i].total_marks;
        maxIndex = i; 
    }
             
        i++;          
}
	avg = avg / i;
    	sending_to_File <<endl<<left<<setw(10)<<"Maximum GPA : "<<setw(5)<<s[maxIndex].gpa <<setw(6)<<" Name: "<<setw(15)<< s[maxIndex].firstname
		 <<setw(15)<<"Roll number : "<<s[maxIndex].roll<< endl <<left<<setw(10)<<"Minimum GPA : "<<setw(5)<<s[minIndex].gpa <<setw(6)<<" Name: "<<setw(15)<<s[minIndex].firstname
		  <<setw(15)<<"Roll number : "<<s[minIndex].roll<<endl<<"Class Average : "<<avg;
    
    sending_to_File.close();
    getting_from_file.close();
    file.close();
    if(found == 0)
    {
		cout<<"\t\t***********************************"<<endl;
		cout<<"\t\t*       DATA not found!           *"<<endl;
		cout<<"\t\t***********************************";
	}
	else
	{
		cout<<"\t\t***********************************"<<endl;
		cout<<"\t\t*       DATA Transferred!         *"<<endl;
		cout<<"\t\t***********************************"<<endl;
	}
}


void search()
{
	
    string roll_number,name;
    int found = 0;			// variable initialization for seeing if data exists then it would increment as 1 and if not found then remain 0 and print error that data not esists
    cout << "*********************************************************************************************************************" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*                                           Search Student Record                                                   *" << endl;
    cout << "*                                                                                                                   *" << endl;
    cout << "*********************************************************************************************************************" << endl;
    cout << "\n\tEnter Roll number: ";
    cin >> roll_number;
    cout << "\n\tEnter Name: ";
    cin >> name;
    ifstream file("student_recrd.txt");			//for reading file

    while (file >>s[i].firstname>> s[i].roll>> s[i].semester>>s[i].dep 
				>>s[i].programmingMarks >> s[i].physics>> s[i].engMarks>> s[i].calculusMarks
				>>s[i].islamicStudiesMarks >>s[i].total_marks >> s[i].gpa) 
	{
        if (s[i].roll == roll_number || s[i].firstname == name) 		// check if user entered rooll number exists in the whole file by checking line by line using i as index of line or student data
		{
            found++;
            cout << "\n\n\t\t\t\t\t*****************" << endl;
            cout << "\t\t\t\t\t*    I N F O    *" << endl;
            cout << "\t\t\t\t\t*****************" << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << left << setw(25) << "Name"
                 << setw(20) << "Roll Number"
                 << setw(20) << "Semester"
                 << setw(20) << "Department"
                 << endl;
            cout << "------------------------------------------------------------------------------------------" << endl << endl;
            cout << left << setw(25) << s[i].firstname
                 << setw(20) << s[i].roll
                 << setw(20) << s[i].semester
                 << setw(20) << s[i].dep;

            cout << "\n\n\t\t\t\t\t*****************" << endl;
            cout << "\t\t\t\t\t*   M A R K S   *" << endl;
            cout << "\t\t\t\t\t*****************" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------" << endl;

            cout << setw(15) << "Calculus"
                 << setw(15) << "English"
                 << setw(15) << "Physics"
                 << setw(15) << "Programming "
                 << setw(15) << "Islamic"
                 << setw(20) << "Total Marks"
                 << setw(20) << "GPA" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------" << endl << endl;

            cout << setw(15) << s[i].calculusMarks
                 << setw(15) << s[i].engMarks
                 << setw(15) << s[i].physics
                 << setw(15) << s[i].programmingMarks
                 << setw(15) << s[i].islamicStudiesMarks 
                 << setw(20) << s[i].total_marks
                 << setw(20) << s[i].gpa << endl;
        }
        i++;				//increment in i
    }

    file.close();

    if (found == 0) // show error if not entered if statemnet of loop
	{
        cout << "\n\n\t\t\t*********************" << endl;
        cout << "\t\t\t*    NOT FOUND!     *" << endl;
        cout << "\t\t\t*********************" << endl;
    }
}
int main() {
	int input;
	cout << "*********************************************************************************************************************" << endl;
		cout << "*                                                                                                                   *" << endl;
		cout << "*                                      A I R   U N I V E R S I T Y                                                  *" << endl;
		cout << "*                                S T U D E N T  M A N A G E M E N T  S Y S T E M                                    *" << endl;
		cout << "*                                                                                                                   *" << endl;
		cout << "*********************************************************************************************************************" << endl;
		cout<<"\n\n\n\n\n\n\t\t\tLoading Please Wait....\t| ";
	
		char bar = 178;
		for(int i = 0 ;i< 35;i++)
		{
			cout<<bar;
			if(i<10)
			{
				Sleep(300);
			}
			if(i>=10 && i < 20)
			{
				Sleep(200);
			}
			if(i>=20 && i < 25)
			{
				Sleep(100);
			}
		}
		system("cls");
	while (true) {	// While(true) is used so that user would able to do multiple task as many times as he wants.
		system("cls");
		
			cout << "*********************************************************************************************************************" << endl;
		cout << "*                                                                                                                   *" << endl;
		cout << "*                                      A I R   U N I V E R S I T Y                                                  *" << endl;
		cout << "*                                S T U D E N T  M A N A G E M E N T  S Y S T E M                                    *" << endl;
		cout << "*                                                                                                                   *" << endl;
		cout << "*********************************************************************************************************************" << endl;
		
		cout << "\n\t\t*****************" << endl;
		cout << "\t\t*    M E N U    *" << endl;
		cout << "\t\t*****************" << endl;
		cout << "\t\n\t1.\tPress 1: \" Add a student. \" " << endl;
		cout << "\t\n\t3.\tPress 2: \" Update Student Record. \"" << endl;
		cout << "\t\n\t4.\tPress 3: \" Student Report Card. \" " << endl;
		cout << "\t\n\t5.\tPress 4: \" Generate Summary. \"" << endl;
		cout << "\t\n\t6.\tPress 5: \" Sort Students By GPA.\"" << endl;
		cout << "\t\n\t7.\tPress 6: \" Export Report. \"" << endl;
		cout << "\t\n\t8.\tPress 7: \" Search Student Information. \"" << endl;
		cout << "\t\n\t9.\tPress 0: \" Exit Program.\"" << endl;
		cout << "\n\t\tEnter your choice : ";
		cin >> input;//take user choice for performing operation from above menu.
		system("cls");
		if (input == 1)
		{
			
			add_student();
			cout << "Press 1 to continue :";
			cin >> choice;
			if (choice == 1 )
			{
				continue;
			}
		}
		else if (input == 2)
		{
			std_rec();
			cout << "Press 1 to continue :";
			cin >> choice;
			if (choice == 1 )
			{
				continue;
			}
		}
		else if (input == 3)
		{
			std_rep();
			cout << "Press 1 to continue :";
			cin >> choice;
			if (choice == 1 )
			{
				continue;
			}
		}
		else if (input == 4)
		{
			std_sum();
			cout << "Press 1 to continue :";
			cin >> choice;
			if (choice == 1 )
			{
				continue;
			}
		}
		else if (input == 5)
		{
			sort();
			cout << "Press 1 to continue :";
			cin >> choice;
			if (choice == 1 )
			{
				continue;
			}
		}
		else if (input == 6)
		{
			exp_report();
			cout << "Press 1 to continue :";
			cin >> choice;
			if (choice == 1 )
			{
				continue;
			}
		}
		else if (input == 7)
		{
			search();
			cout << "Press 1 to continue :";
			cin >> choice;
			if (choice == 1 )
			{
				continue;
			}
		}
		else if (input == 0)
		{
			exit(0);
		}
	}
}
