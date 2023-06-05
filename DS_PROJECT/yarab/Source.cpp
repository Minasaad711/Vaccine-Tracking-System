#include "VaccQueue.h"
#include "User.h"
#include  "HashTable.h"
#include <iostream>
#include <string.h>

using namespace std;
VaccQueue User::waiting_list;
HashTable table;
int inputID;
string inputPass;
int main()
{
    User U;
    int x;
    bool attemp = true;
    while (attemp)
    {
        x = U.MainMenu();
        if (x == 1)
            U.Login(inputID, inputPass);
        else if (x == 2)
        {
            U.GetData();
            table.insert(U.ID, U);
            U.Login(inputID, inputPass);
        }
        User* pop = table.search(inputID);
        int res = inputPass.compare(pop->pass);
        if (res == 0)
        {
            attemp = false;
            x = pop->UserMenu();
            if (x == 1)
            {
                table.remove(pop->ID, pop->ID);
                U.GetData();
                table.insert(U.ID, U);
            }
            else if (x == 2)
            {
                table.remove(pop->ID, pop->ID);
                pop->Delete();
            }
        }
        else
        {
            cout << "\n\nIncorrect Username or Password.";
            cout << "\nPlease, Retry the Login.\n";
            system("pause");
            system("cls");
            U.MainMenu();
        }
    }

    

}