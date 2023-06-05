#include "User.h"
#include "HashTable.h"
#include "sets.h"
#include <iostream>
using namespace std;

VaccQueue Q;
sets  idsets;
User::User(string name, int ID, int age, string pass, string gender, string governorate, bool Vaccine, int dose)
{
    this->name = name;
    this->ID = ID;
    this->age = age;
    this->gender = gender;
    this->governorate = governorate;
    this->Vaccine = Vaccine;
    this->dose = dose;
    if (!Vaccine)
        waiting_list.enqueue(ID);

}

User::User(User&p)
{
    this->age = p.age;
    this->name = p.name;
    this->ID = p.ID;   
    this->pass = p.pass;
    this->governorate = p.governorate;
    this->gender = p.gender;
    this->Vaccine = p.Vaccine;
    this->dose = p.dose;
}
void User::GetData()
{


    cout << "Please Enter User Data\n" << endl;
    cout << "Enter Name: ";
    cin >> name;
    bool x = true;
    cout << "Enter ID: ";
    int temp;
    cin >> temp;
    while (x) {
        if (idsets.insert(temp))
        {
            ID = temp;
            x = false;
        }
        else
         {
            cout <<endl<< "Enter correct ID: ";
            cin >> temp;
        }
    } //MUST BE 13 char
    
    cout << "Enter Gender: ";
    cin >> gender;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Governorate: ";
    cin >> governorate;
    cout << "Are you " << endl << "1. Applying " << endl << "2. Vaccinated" << endl << "Choose 1 or 2" << endl;
    int y;
    cin >> y;
    Vaccine = y - 1;
    if (!Vaccine) {
        cout << "You will be added to the Waitting List" << endl;
        waiting_list.enqueue(ID);
        wait_num = waiting_list.q_num();
        dose = 0;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "How many doses you have taken?" << endl;
        cin >> dose;
        system("pause");
        system("cls");
    }

}
void User::DisplayData()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Pass: " << pass << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
    cout << "Governorate: " << governorate << endl;
    if (Vaccine)
        cout << "You have taken " << dose << " doses.\n" << endl;
    //return count
}

 User::User(){}
void User::Login(int&inputID, string&inputPass)
{
   
 cout << "** Login **\n\n";
        
        cout << "Please Enter Your Username and Password.\n \n";
        cout << "ID: ";
        cin >> inputID;
        cout << "Password: ";
        cin >> inputPass;
      if (inputID == 9999 && inputPass == "Admin")
       { 
            AdminMenu();
            system("cls");
       }
      
       
    
}

void User::AdminMenu()
{
    int inputID;
    int choice;
    system("cls");
    cout << "Hi Admin.\n\n";
    cout << "Please choose a number from 1 to 5.\n" << endl;
    cout << "1. Display All Users" << endl << "2. Delete a User" << endl;
    cout << "3. Display a User Info" << endl << "4. Display Vaccine Queue" << endl;
    cout << "5. Display All Statistics\n" << endl << "6. Return to Main Menu\n" << endl;
    cout << "Your Choice: ";
    cin >> choice;
    bool x = true;
    while (true)
    {
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "Display all Users Data.\n\n";
            //H.hashdisplayall();
            x = false;
            break;
        case 2:
            system("cls");
            cout << "Enter User ID: ";
            cin >> inputID;
            if (inputID == ID)
            {
                cout << "Preview User.\n\n";
                GetData();
                x = false;
            }
            else
            {
                cout << "\nIncorrect ID Entered\n";
                cout << "\nYou Will Return To Admin Menu Page.\n";
                system("pause");
                system("cls");
                x = true;
            }
            break;
        case 3:
            system("cls");
            cout << "Enter User ID: ";
            cin >> inputID;
            if (inputID == ID)
            {
                cout << "DELETE User.\n\n";
                Delete();
                x = false;
            }
            else
            {
                cout << "\nIncorrect ID Entered\n";
                cout << "\nYou Will Return To Admin Menu Page.\n";
                system("pause");
                system("cls");
                x = true;
            }
            break;
        case 4:
            system("cls");
            MainMenu();
            x = false;
            break;
        case 5:
            DisplayStatistics();

        case 6:
            system("cls");
            Q.vacdisplayall();
            x = false;\
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nIncorrect Number\n";
            cout << "Please type 1, 2, 3, 4, 5, 6 ONLY.\n\n";
            x = true;
        }
    }
}

int User::UserMenu()
{
    int choice;
    cout << "User Data\n" << endl;
    DisplayData();
    cout << "Please choose a number from 1 to 3.\n" << endl;
    cout << "1. Edit Data\n" << "2. Delete this User\n" << "3. Log Out\n" << endl;
    cout << "Choice: ";
    cin >> choice;
    bool x = true;
    while (x = true)
    {
        switch (choice)
        {
        case 1:
            system("cls");
            return 1;
           // Edit();
            x = false;
            break;
        case 2:
            system("cls");
            return 2;

            Delete();
            x = false;
            break;
        case 3:
            cout << "\nYou have logged out from your account.\n";
            system("pause");
            system("cls");
            MainMenu();
            x = false;
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nIncorrect Number.\n";
            cout << "Please type 1, 2, 3 ONLY.\n";
            x = true;
        }
    }
}

int User::MainMenu()
{
    int close = 1;
    int choice;
    while (close < 4)
    {
        cout << "**** Vaccine Tracking System ****\n" << endl;
        if (close > 1)
            cout << "Attempt " << close << ".\n\n";
        if (close == 3)
        {
            cout << "If You Entered This Attemp Wrong the Program Will Close.\n \n";
        }
        cout << "Please choose 1 or 2." << endl;
        cout << "1. Login" << endl;
        cout << "2. New User" << endl;
        cout << "Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            return 1;
            break;
        case 2:
            system("cls");
            return 2;
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nInvalid Input!\n";
            if (close < 3)
            {
                cout << "Please type 1 or 2 ONLY.\n";
                system("pause");
                system("cls");
            }
            close++;
            break;
        }
    }
    system("pause");
    system("cls");
    cout << "Thank You For Using Our Program.\n";
}

 void User::Edit()
{

}

void User::Delete()
{

}

void User::DisplayStatistics()
{

}

User::~User()
{

}