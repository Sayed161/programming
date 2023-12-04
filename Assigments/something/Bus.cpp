#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void Admin_login();
void Passenger_login();
void starting_theme();
void options();
void registration();
void forget();
void All_bus();
void delete_bus();
const string adminUsername = "Admin";
const string adminPassword = "Admin123";
class info
{
public:
    string name;
    string pass;

    // Parameterise constructor
    info(string name, string pass)
    {
        this->name = name;
        this->pass = pass;
    }
    // This is default constructor
    info(){};
};

class Bus
{
public:
    int Bus_NO;
    string Bus_name;
    string Destination;
    int seats;
    int charges;
    string starting_time;
    string ending_time;

    Bus(int Bus_NO, string Bus_name, string Destination, int seats, int charges, string starting_time, string ending_time)
    {
        this->Bus_NO = Bus_NO;
        this->Bus_name = Bus_name;
        this->Destination = Destination;
        this->seats = seats;
        this->charges = charges;
        this->starting_time = starting_time;
        this->ending_time = ending_time;
    }
};
vector<Bus> buses;
void home_page()
{
    cout << "Access Form\n\n\n";
    cout << "1. Admin Pannel\n";
    cout << "2. User Pannel\n";
    int n;
    cout << "Chose Number : ";
    cin >> n;
    if (n == 1)
    {
        string username, userpass;
        cout << "Enter Username : ";
        cin >> username;
        cout << "Enter Password : ";
        cin >> userpass;
        if (username == adminUsername && userpass == adminPassword)
        {
            cout << "\n\n\n\t\t\t\t Thank you for log in  !! YOUR LOGIN IS SUCCESSFUL";
            cout << "\n\n\n\t\t\t\t Press Any Key to continue...";
            getch();
            system("cls");
            Admin_login();
        }
        else
        {
            cout << "\n\n\n\t\t\t\t SORRY !!!!  LOGIN IS UNSUCESSFUL";
            home_page();
        }
    }
    else if (n == 2)
    {
        cout << "Press 1 to Registration\n";
        cout << "Press 2 to Login\n";
        cout << "Press 3 to If forget password\n";
        cout << "Enter your option : ";
        int x;
        cin >> x;
        if (x == 1)
        {
            registration();
        }
        else if (x == 2)
        {
            Passenger_login();
        }
        else if (x == 3)
        {
            forget();
        }
    }
}

void delete_bus()
{
}

void forget()
{
    string userName, id;
    system("cls");
    cout << "\t\t\t\t\t\t  PASSWORD RECOVER  \n";
    cout << "\t\t\t\t\t\t  ------------------ \n\n";
    cout << "\t\t\t\t\t\t Enter your username: ";
    cin >> userName;
    cout << "\t\t\t\t\t\t Enter your Nickname : ";
    cin >> id;

    ifstream myFile("information.txt");

    string f_username, f_id, f_pass;
    int flag = 1;
    while (myFile >> f_username >> f_pass >> f_id)
    {

        if (f_username == userName && f_id == id)
        {
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t Your name is :  " << f_username << " & ";
            cout << "Your password is :  " << f_pass << endl
                 << endl;
            break;
        }
        else
        {
            flag = 0;
        }
    }

    if (flag == 0)
        cout << endl
             << endl
             << "\t ~YOUR GIVEN INFORMATION IS WRONG\n\n";

    char ch;
    cout << "\t\t\t\t\t\t ENTER 'Y' TO GO HOME PAGE: ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        home_page();
    }
}
void registration()
{
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t\t\t ******** REGISTRATION FORM ******** \n\n";

    string user_name, user_pass, user_id;
    cout << "\t\t\t\t\t\t | Enter your username: ";
    cin >> user_name;
    cout << "\t\t\t\t\t\t | Enter your password: ";
    cin >> user_pass;
    cout << "\t\t\t\t\t\t | Enter your Nickname: ";
    cin >> user_id;

    // set value of an user using object
    info person(user_name, user_pass);

    // File create or open and write user information:
    ofstream myFile("information.txt", ios::app);
    // Write name and pass in file using class & object.
    myFile << person.name << " " << person.pass << " " << user_id << endl;
    myFile.close();
    // File Close

    cout << endl
         << endl;
    string success_messege = "\t\t\t\t\t\t REGISTRATION SUCCESSFULL !";
    for (char ch : success_messege)
    {
        cout << ch;
        Sleep(50);
    }
    cout << endl
         << endl;

    char y_n;
    cout << "\t\t\t\t\t\t DO YOU WANT TO LOGIN NOW (Y/N): ";
    cin >> y_n;
    if (y_n == 'y' || y_n == 'Y')
    {
        Passenger_login();
    }
    else
    {
        home_page();
    }
}

void displayBus(const Bus &bus)
{
    cout << "Bus No\t";
    cout << "Bus Name\t";
    cout << "Destination\t";
    cout << "Number of Seats\t";
    cout << "Charges\t";
    cout << "Time\t";
    cout << bus.Bus_NO << "\t" << bus.Bus_name << "\t";
    cout << bus.Destination << "\t" << bus.seats << "\t";
    cout << bus.charges << "\t" << bus.starting_time << "\t";
    cout << bus.ending_time << endl;
}
void All_bus()
{
    ifstream file("Bus.txt");
    if (!file)
    {
        cout << "Error opening "
             << "Bus.txt"
             << " file\n";
        exit(1);
    }

    string destination, stime, Bus_name, etime;
    int tk, bus_id, seats;
    while (file >> bus_id >> Bus_name >> destination >> seats >> tk >> stime >> etime)
    {
        cout << "helo";
        Bus bus(bus_id, Bus_name, destination, seats, tk, stime, etime);
        buses.push_back(bus);
    }

    file.close();

    if (buses.empty())
    {
        cout << "No buses found in the file." << endl;
    }
    else
    {
        for (size_t i = 0; i < buses.size(); i++)
        {
            cout << "Bus " << (i + 1) << " Details:" << endl;
            displayBus(buses[i]);
            cout << endl;
        }
    }
}

void Admin_login()
{
    cout << endl;
    cout << "Press 1 to Add Bus\n";
    cout << "Press 2 to Delete Bus\n";
    cout << "Press 3 to View All Bus\n";
    int x;
    cout << "Enter your option : ";
    cin >> x;
    if (x == 1)
    {
        system("cls");
        cout << "\n\n\n\n\n\t\t\t\t\t\t ******** Bus Add ******** \n\n";
        string destination, stime, etime, Bus_name;
        int tk, bus_id, seats;
        cout << "\t\t\t\t\t\t Enter Bus No : ";
        cin >> bus_id;
        cin.ignore();
        cout << "\t\t\t\t\t\t Enter Bus Name : ";
        getline(cin, Bus_name);
        cout << "\t\t\t\t\t\t Enter Destination : ";
        getline(cin, destination);
        cout << "\t\t\t\t\t\t Enter Number of Seats : ";
        cin >> seats;
        cin.ignore();
        cout << "\t\t\t\t\t\t Enter Charges : ";
        cin >> tk;
        cin.ignore();
        cout << "\t\t\t\t\t\t Enter Starting Time : ";
        cin >> stime;
        cout << "\t\t\t\t\t\t Enter Ending Time : ";
        cin >> etime;

        cin.ignore();

        // set value of an user using object
        Bus bus1(bus_id, Bus_name, destination, seats, tk, stime, etime);

        // File create or open and write user information:
        ofstream myFile("Bus.txt", ios::app);
        // Write name and pass in file using class & object.
        myFile << bus1.Bus_NO << "\t" << bus1.Bus_name << "\t" << bus1.Destination << "\t   " << bus1.seats << "\t" << bus1.charges << "\t" << bus1.starting_time << "\t" << bus1.ending_time << endl;
        myFile.close();
        // File Close

        cout << endl
             << endl;
        string success_messege = "\t\t\t\t\t\t Bus Added Successfully !";
        for (char ch : success_messege)
        {
            cout << ch;
            Sleep(50);
        }
        cout << endl
             << endl;

        char y_n;
        cout << "\t\t\t\t\t\t DO YOU WANT TO SEE ALL BUSSES (Y/N): ";
        cin >> y_n;
        if (y_n == 'y' || y_n == 'Y')
        {
            All_bus();
        }
        else
        {
            home_page();
        }
    }
    else if (x == 2)
    {
        delete_bus();
    }
    else if (x == 3)
    {
        All_bus();
    }
    else
    {
        home_page();
    }
}

void options()
{
    int menu_choice;
    cout << "\n\t\t\t=================================\n";
    cout << " \t\t\t   BUS TICKET RESERVATION SYSTEM";
    cout << "\n\t\t\t=================================\n";
    cout << "\n                                 \n";
    cout << "\n1 Reserve Ticket/s\n";
    cout << "\n2 View All Available Bus\n";
    cout << "\n3 View Reserved Tickets\n";
    cout << "\n4 Cancel Ticket\n";
    cout << "\n5 Exit";
    cout << "\n\n Enter your Choice:";
    cin >> menu_choice;
    if (menu_choice == 1)
    {
        string name, phone;
        cout << "Enter your Name : ";
        cin >> name;
        cout << "Enter your phone no : ";
        cin >> phone;
        All_bus();
        ifstream file("Bus.txt");
        if (!file)
        {
            cout << "Error opening Bus.txt file" << endl;
            return;
        }

        int bus_id;
        string Bus_name, Destination, stime, etime;
        int seats, charges;

        bool found = false;
        vector<Bus> selectedBusDetails;

        int BUs_id;
        cout << "Input Bus ID: ";
        cin >> BUs_id;

        while (file >> bus_id >> Bus_name >> Destination >> seats >> charges >> stime >> etime)
        {
            if (BUs_id == bus_id)
            {
                found = true;
                // Store the details in a vector
                selectedBusDetails.emplace_back(bus_id, Bus_name, Destination, seats, charges, stime, etime);
            }
        }

        file.close();

        if (found)
        {
            // Reservation part
            int seatsToReserve;
            cout << "Enter the number of seats to reserve: ";
            cin >> seatsToReserve;

            int totalCharges = 0; // Variable to store the total charges for reserved seats

            for (auto &bus : buses)
            {
                if (bus.Bus_NO == BUs_id)
                {
                    if (seatsToReserve <= bus.seats)
                    {
                        bus.seats -= seatsToReserve;

                        // Calculate the total charges for the reserved seats
                        totalCharges = seatsToReserve * bus.charges;

                        cout << seatsToReserve << " seat(s) reserved on bus number " << BUs_id << ". Remaining seats: " << bus.seats << endl;
                        cout << "Total charges for reserved seats: " << totalCharges << endl;
                        break; // No need to keep searching
                    }
                    else
                    {
                        cout << "Not enough seats available on the selected bus." << endl;
                    }
                }
            }

            // Saving selected bus details to a file
            ofstream outFile("Selected_Bus_Details.txt");
            if (!outFile)
            {
                cout << "Error creating Selected_Bus_Details.txt file" << endl;
                return;
            }

            outFile << "Selected Bus Details:" << endl;
            for (const auto &bus : selectedBusDetails)
            {
                outFile << "Bus No: " << bus.Bus_NO << "\n";
                outFile << "Bus Name: " << bus.Bus_name << "\n";
                outFile << "Destination: " << bus.Destination << "\n";
                outFile << "Number of Seats: " << bus.seats << "\n";
                outFile << "Charges: " << bus.charges << "\n";
                outFile << "Staring Time: " << bus.starting_time << "\n";
                outFile << "Ending Time: " << bus.ending_time << "\n";
                outFile << endl;
            }

            outFile.close();
            cout << "Selected bus details saved in Selected_Bus_Details.txt file." << endl;
        }
        else
        {
            cout << "Bus ID not found." << endl;
        }
    }
    else if (menu_choice == 2)
    {
        All_bus();
    }
    else if (menu_choice == 3)
    {
        ifstream inFile("Selected_Bus_Details.txt");

        if (!inFile)
        {
            cout << "Error opening Selected_Bus_Details.txt file" << endl;
            return;
        }

        string line;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }

        inFile.close();
    }
    else if (menu_choice == 4)
    {
        int ticketID;
        cout << "Enter the ID of the ticket to cancel: ";
        cin >> ticketID;
        ifstream inputFile("Bus.txt");
        ifstream inputFile2("Selected_Bus_Details.txt");
        ofstream tempFile("temp.txt");
        vector<Bus> buses;
        int bus_id;
        bool found = false;

        while (inputFile2 >> bus_id && inputFile >> bus_id)
        {
            string line;
            string line2;
            getline(inputFile, line);
            getline(inputFile2, line2);
            if (bus_id == ticketID)
            {
                found = true;
            }
            else
            {
                tempFile << bus_id << line << '\n';
            }
        }

        inputFile.close();
        inputFile2.close();
        tempFile.close();

        if (found)
        {
            cout << "Ticket ID " << ticketID << " has been canceled." << endl;
            remove("Selected_Bus_Details.txt");
            remove("Bus.txt");
            rename("temp.txt", "Selected_Bus_Details.txt");
            rename("temp.txt", "Bus.txt");
        }
        else
        {
            cout << "Ticket ID " << ticketID << " not found." << endl;
            remove("temp.txt");
        }
    }
    else
    {

        home_page();
    }
}
void Passenger_login()
{
    system("cls");
    string f_name, f_pass, f_id, u_name, u_pass;
    string copy_name;
    int flag = 0;

    cout << "\n\n\n\n\n\t\t\t\t\t\t ********** LOGIN PAGE ********** \n\n";
    cout << "\t\t\t\t\t\t | Enter your username: ";
    cin >> u_name;
    cout << "\t\t\t\t\t\t | Enter your password: ";
    cin >> u_pass;

    // read value from file
    ifstream myFile("information.txt");

    while (myFile >> f_name >> f_pass >> f_id)
    {
        if (u_name == f_name && u_pass == f_pass)
        {
            copy_name = u_name;
            flag = 1;
            break;
        }
    }

    // Login success or denite
    cout << endl
         << endl;
    if (flag)
    {
        string suc = "\t\t\t\t\t\t >_< LOGIN SUCCESSFULL !!!";

        for (char ch : suc)
        {
            cout << ch;
            Sleep(100);
        }
        options();
    }
    else
    {
        string unc = "\t\t\t\t\t\t INVALID USERNAME AND PASSWORD";
        for (char ch : unc)
        {
            cout << ch;
            Sleep(100);
        }
    }
    cout << endl
         << endl;

    char ch;
    cout << "\t\t\t\t\t\t ENTER 'Y' TO GO HOME PAGE: ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        home_page();
    }
}

int main()
{
    system("COLOR 6");
    starting_theme();
    return 0;
}
void starting_theme()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "B";
    Sleep(150);
    cout << "U";
    Sleep(150);
    cout << "S";
    Sleep(150);
    cout << " ";
    cout << "T";
    Sleep(150);
    cout << "I";
    Sleep(150);
    cout << "C";
    Sleep(150);
    cout << "K";
    Sleep(150);
    cout << "E";
    Sleep(150);
    cout << "T";
    Sleep(150);
    cout << " ";
    cout << "R";
    Sleep(150);
    cout << "E";
    Sleep(150);
    cout << "S";
    cout << "E";
    Sleep(150);
    cout << "R";
    Sleep(150);
    cout << "V";
    Sleep(150);
    cout << "A";
    Sleep(150);
    cout << "T";
    Sleep(150);
    cout << "I";
    Sleep(150);
    cout << "O";
    Sleep(150);
    cout << "N";
    Sleep(150);
    cout << " ";
    Sleep(150);
    cout << "S";
    Sleep(150);
    cout << "Y";
    cout << "S";
    Sleep(150);
    cout << "T";
    Sleep(150);
    cout << "E";
    Sleep(150);
    cout << "M";
    Sleep(150);
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "============================= \n";
    cout << "\n";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "         Developed By Team Alpha_001";
    cout << "\n\n";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "\t";
    cout << "============================= \n";
    cout << "\n";
    cout << "\n";
    cout << " \n Press Enter to Enter the System.....";
    getch();
    system("cls");
    home_page();
}
