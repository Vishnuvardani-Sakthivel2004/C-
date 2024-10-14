#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;

void menu();

//creating class
class ManageMenu
{
protected:
    string userName;
public:
    //constructor
    ManageMenu()
    {
        system("color 0A"); //change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu(); //call to main function to load after executing the constructr
    }
    //Destructor
    ~ManageMenu(){}
};

class Customer
{
public:
    string name, gender, address;
    int age, mobileNo, menuBack;
    static int cusID;
    char all[999];
    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app); //open file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> mobileNo;
            cout << "Address: ";
            cin >> address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n" << endl;
    }
    void showDetails() //function to show old customer records
    {
        ifstream in("old-customers.txt");
        {
            if(!in)
            {
                cout << "File Error!" << endl;
            }
            while(!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};
int Customer::cusID;

class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;
    void cabDetails()
    {
        cout << "WE COLLABRATED WITH FASTEST,SAFEST and SMARTEST CAB SERVICE AROUND THE COUNTRY" << endl;
        cout << "\t\t---------------SV CABS----------------\n" << endl;
        cout << "\t\t1. Rent a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "\t\t2. Rent a Luxury Cab   - Rs.25 per 1KM" << endl;

        cout << "\nEnter another key to back or," << endl;

        cout << "\nTo calculate the cost for your journey......" << endl;
        cout << "\nEnter which kind of cab you need: ";
        cin >> cabChoice;
        cout << "\nEnter Kilometers you have to travel: ";
        cin >> kilometers;
        int hireCab;
        if(cabChoice == 1)
{
            cabCost = kilometers * 15;
            cout << "\nYour tour will cost " << cabCost << " rupees for a STANDARD CAB...." << endl;
            cout << "\nPress 1 to hire this cab: or ";
            cout << "\nPress 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
{
                lastCabCost = cabCost;
                cout << "You have successfully hired --Standard Cab--" << endl;
                cout << "\nGoto Menu to take the receipt" << endl;
            }
            else if(hireCab == 2)
{
                cabDetails();
            }
            else
{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else if(cabChoice == 2)
{
            cabCost = kilometers * 25;
            cout << "\nYour tour will cost " << cabCost << " rupees for a LUXURY CAB...." << endl;
            cout << "\nPress 1 to hire this cab: or ";
            cout << "\nPress 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
{
                lastCabCost = cabCost;
                cout << "You have successfully hired --Luxury Cab--" << endl;
                cout << "\nGoto Menu to take the receipt" << endl;
            }
            else if(hireCab == 2)
{
                cabDetails();
            }
            else
{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else
{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if(hireCab == 1)
{
            menu();
        }
        else{
            menu();
        }
    }
};

float Cabs::lastCabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice1;
    int gotoMenu;
    static float hotelCost;

    void hotels()
     {
        string hotelNo[]={"VISU","SUVI","SV"};
        for(int a=0;a<3;a++)
        {
            cout << (a+1) <<". Hotel " << hotelNo[a] << endl;
        }
        cout << "\nCurrently we collaborated with above hotels!" << endl;
        cout << "Press any key to back or\nEnter Number of the hotel you want to book or see details: ";
        cin >> choiceHotel;
        system("CLS");
        if(choiceHotel == 1)
{
            cout << "\t\t\t-------WELCOME TO HOTEL VISU-------\n" << endl;
            cout << "The Garden,food and beverage. Enjoy all you can drink,Stay cool and get chilled in the summer sun." << endl;
            cout << "Packages offered by Visu:" << endl;
            cout << "\n 1. Standard Pack" << endl;
            cout << "\t All basic facilities you need just for: Rs.5000.00" << endl;
            cout << "\n 2. Premium Pack" << endl;
            cout << "\t Enjoy Premium: Rs.10000.00" << endl;
            cout << "\n 3. Luxury Pack" << endl;
            cout << "\t Live a Luxury at Visu: Rs.15000.00" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
{
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Visu" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
{
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Visu" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
{
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Visu" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else
{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
{
                menu();
            }
            else
{
                menu();
            }
        }
        else if(choiceHotel == 2)
{
            cout << "\t\t\t-------WELCOME TO HOTEL SUVI-------\n" << endl;
            cout << "Swimming Pool | Free WiFi | Family Rooms \nFitness Center | Restaurant & Bar" << endl;
            cout << "Packages Offered by Suvi:" << endl;
            cout << "\n 1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "\n 2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "\n 3. Single Pack" << endl;
            cout << "\t Rs.5000.00  for a day" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
{
                hotelCost = 15000.00;
                cout << "You have successfully booked Family Pack at Suvi" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
{
                hotelCost = 10000.00;
                cout << "You have successfully booked Couple Pack at Suvi" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
{
                hotelCost = 5000.00;
                cout << "You have successfully booked Single Pack at Suvi" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
{
                menu();
            }
            else
{
                menu();
            }
        }
        else if(choiceHotel == 3)
{
            cout << "\t\t\t-------WELCOME TO HOTEL SV-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephant" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for a one day!!!" << endl;
            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            if (packChoice1 == 1)
{
                hotelCost = 5000.00;
                cout << "You have successfully booked SV Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
{
                menu();
            }
            else
{
                menu();
            }
        }
        else
{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
    }
};

float Booking::hotelCost;//scope resolution operator
class Chargers : public Booking, Cabs, Customer //Multiple Inheritance
{
public:
    void printBill()
    {
        ofstream outf("receipt.txt"); //receipt for bought items
        {
            outf << "\t\t\t--------SV Travel Agency--------" << endl;
            outf << "\t\t\t-------------Receipt-------------" << endl;
            outf << "\t\t\t_________________________________" << endl;
            outf << "\t\t\tCustomer ID: " << Customer::cusID << endl << endl;
            outf << "\t\t\tDescription\t\t Total" << endl;
            outf << "\t\t\tHotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "\t\t\tTravel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
            outf << "\t\t\t_________________________________" << endl;
            outf << "\t\t\tTotal Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastCabCost << endl;
            outf << "\t\t\t_________________________________" << endl;
            outf << "\t\t\t------------THANK YOU------------" << endl;
        }
        outf.close();
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout << "File Error!" << endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

void menu() //menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t\t\t* SV TRAVELS *\n" << endl;
    cout << "\t------------------------- MAIN MENU --------------------------" << endl;

    cout << "\n\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "\n\t\t|\t\t\t\t\t|" << endl;
    cout << "\n\t\t|\tCustomer Details -> 1     \t|" << endl;
    cout << "\n\t\t|\tCabs Booking     -> 2     \t|" << endl;
    cout << "\n\t\t|\tHotel Booking    -> 3     \t|" << endl;
    cout << "\n\t\t|\tCharges & Bill   -> 4     \t|" << endl;
    cout << "\n\t\t|\tExit             -> 5     \t|" << endl;
    cout << "\n\t\t|\t\t\t\t\t|" << endl;
    cout << "\n\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Your Choice: ";
    cin >> mainChoice;

    system("CLS");
    Customer a2; //creating objects
    Cabs a3;
    Booking a4;
    Chargers a5;

    if(mainChoice == 1){
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1)
{
            a2.getDetails();
        }
        else if(inChoice == 2)
{
            a2.showDetails();
        }
        else
{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1)
{
            menu();
        }
        else
{
            menu();
        }
    }
    else if(mainChoice == 2)
{
        a3.cabDetails();
    }
    else if(mainChoice == 3)
{
        cout << "\t\t--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4)
{
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1)
{
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
{
                menu();
            }
            else
{
                menu();
            }
        }
        else
{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5)
{
        cout << "\n\n\t--GOOD-BYE!--\n--VIST AGAIN!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else
{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu startObj;
    return 0;
}

