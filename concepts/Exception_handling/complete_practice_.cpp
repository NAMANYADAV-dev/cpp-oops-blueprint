#include <iostream>
using namespace std;

int main()
{
    int choice;

    cout << "1 -> int error\n";
    cout << "2 -> char error\n";
    cout << "3 -> double error\n";

    cin >> choice;

    try
    {
        if(choice == 1)
            throw 10;

        else if(choice == 2)
            throw 'A';

        else if(choice == 3)
            throw 3.14;

        else
            throw "Unknown";
    }

    catch(int)
    {
        cout << "Integer Exception"
             << endl;
    }

    catch(char)
    {
        cout << "Character Exception"
             << endl;
    }

    catch(double)
    {
        cout << "Double Exception"
             << endl;
    }

    catch(...)
    {
        cout << "Catch-All Exception"
             << endl;
    }

    return 0;
}