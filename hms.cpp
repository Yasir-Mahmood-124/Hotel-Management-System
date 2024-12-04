#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

//...Funtions Prototypes...
string who();
void add_user(string username, string password, string role);
char menu2(char op2);
char menu1(char op1);
void exit();
void header();
void clear_screen();
void price_of_rooms();
void discount();
void data_of_customer();
void view_data();
float final_bill(int stays, int cost_per_night);
void exit();
//...Prototypes End...


//.................Data Structure Start
int user_count = 0;
const int TOTAL_USER = 10;
string usernameA[TOTAL_USER];
string passwordA[TOTAL_USER];
string roleA[TOTAL_USER];

const int TOTAL_CUSTOMER = 10;
int customer_data_count = 0;
string nameA[TOTAL_CUSTOMER];
string mobile_numberA[TOTAL_CUSTOMER];
string emailA[TOTAL_CUSTOMER];
string cnicA[TOTAL_CUSTOMER];
int staysA[TOTAL_CUSTOMER];
int customer_bill_count = 0;
string type[TOTAL_CUSTOMER];
int type_count = 0;
float actual_bill[TOTAL_CUSTOMER];
bool customer_bill = false;
bool room_price = false;
bool discount_price = false;
bool customer_data = false;
bool customer_stays = false;
bool billing = false;
int discounted, five_star, four_star, three_star, two_star;
int stays;
float billings[10];
int bill_counter = 0;
//.................Data Structure End


//...Main Starts...
main()
{
    add_user("admin", "123", "ADMIN");
    add_user("customer", "123", "CUSTOMER");

    while (true)
    {
        string find = who();
        clear_screen();
        char admin_option = ' ';
        if (find == "ADMIN")
        {
            while (true)
            {
               
                //...Admin Menmu Starts...
                
                admin_option = menu1(admin_option);
                if (admin_option == '1')
                {
                    price_of_rooms();
                    system("cls");
                }

                else if (admin_option == '2')
                {
                    discount();
                    system("cls");
                }

                else if (admin_option == '3')
                {
                    data_of_customer();
                    system("cls");
                }

                else if (admin_option == '4')
                {
                    if (customer_data == true)
                    {
                        view_data();
                    }

                    else
                    {
                        cout << "Customer data has not entered yet." << endl;
                    }
                }

                else if (admin_option == '5')
                {
                    string asking;
                    cout << "Are you sure want to delete the data of the customer(yes or no):";
                    cin >> asking;
                    if (asking == "yes")
                    {
                        cout << "Successfully deleted." << endl;
                    }

                    else if (asking == "no")
                    {
                        cout << "Data is not deleteed." << endl;
                    }

                    else
                    {
                        cout << "Invalid option!" << endl;
                        cout << "##### Validation #####" << endl;
                        cout << "Write yes or no." << endl;
                    }
                }

                else if (admin_option == '6')
                {
                    if (customer_stays == true && room_price == true)
                    {
                        float actual_bill;
                        string type2;
                        cout << "Enter the type of room(fivestar,fourstar,threestar,twostar):";
                        cin >> type2;
                        if (type2 == "fivestar")
                        {

                            actual_bill = final_bill(stays, five_star);

                            billing = true;
                        }
                        else if (type2 == "fourstar")
                        {

                            actual_bill = final_bill(stays, four_star);

                            billing = true;
                        }
                        else if (type2 == "threestar")
                        {

                            actual_bill = final_bill(stays, three_star);

                            billing = true;
                        }
                        else if (type2 == "twostar")
                        {

                            actual_bill = final_bill(stays, two_star);

                            billing = true;
                        }

                        else
                        {
                            cout << "Invalid room." << endl;
                            cout << "#### Validation ####" << endl;
                            cout << "Please select the right type of room." << endl;
                        }

                        billings[bill_counter] = actual_bill;
                        bill_counter = bill_counter + 1;

                        for (int a = 0; a < bill_counter; a++)
                        {
                            cout << "SO bill of the customer is:" << billings[a] << endl;
                        }
                        cout << endl;
                    }

                    else
                    {
                        cout << "Customer has not entered the number of stays yet.";
                        cout << "#### Validation ####" << endl;
                        cout << "First enter the number of stays." << endl;
                    }
                }

                else if (admin_option == '7')
                {
                    //...Sorting Feature....

                    cout << "Bill in Sorted order:" << endl;

                    for (int i = 0; i < bill_counter - 1; i++)
                    {
                        for (int j = i + 1; j < bill_counter; j++)
                        {
                            if (billings[j] > billings[i])
                            {
                                int temp = billings[j];
                                billings[j] = billings[i];
                                billings[i] = temp;
                            }
                        }
                    }

                    for (int i = 0; i < bill_counter; i++)
                    {
                        cout << "SO the bill is :" << billings[i] << endl;
                    }
                }

                else if (admin_option == '8')
                {
                    exit();
                    break;
                }

                else
                {
                    cout << "Invalid option." << endl;
                    cout << "#### Validation ####" << endl;
                    cout << "Please try again! You have entered wrong option." << endl;
                }
                clear_screen();

                //...Admin Menu End...
            }
        }

        else if (find == "CUSTOMER")
        {
            char customer_option = ' ';
            while (true)
            {
                //...Customer Menu Starts...

                customer_option = menu2(customer_option);
                if (customer_option == '1')
                {
                    if (room_price == false)
                    {
                        cout << "Prices of the rooms are not entered yet." << endl;
                    }

                    else
                    {
                        fstream file2;
                        string test;
                        file2.open("RoomPrice.txt", ios::in);

                        while (getline(file2, test))
                        {                         // read data from file object and put it into string.
                            cout << test << "\n"; // print the data of the string
                        }
                        file2.close();
                    }
                }

                else if (customer_option == '2')
                {
                    if (discount_price == true)
                    {

                        fstream file4;
                        file4.open("Discount.txt", ios::in);
                        file4 >> discounted;
                        cout << "Discount on per night stay is:" << discounted << endl;
                    }

                    else
                    {
                        cout << "Discount has not been entered yet." << endl;
                    }
                }

                else if (customer_option == '3')
                {
                    int persons;
                    cout << "Enter the number of persons:";
                    cin >> persons;
                    system("cls");
                }

                else if (customer_option == '4')
                {
                    if (type_count < 10)
                    {
                        cout << "You can select the type of room:(five star,four star,three star,two star):";
                        cin >> type[type_count];
                        type_count = type_count + 1;
                    }

                    else
                    {
                        cout << "No more rooms." << endl;
                    }
                }

                else if (customer_option == '5')
                {
                    if (customer_bill_count < 10)
                    {
                        cout << "Enter the number of stays:";
                        cin >> stays;
                        customer_stays = true;
                        customer_bill_count = customer_bill_count + 1;
                    }

                    else
                    {
                        cout << "No more space!" << endl;
                    }
                }

                else if (customer_option == '6')
                {
                    if (billing == true)
                    {
                        cout << "Your Total bill is:" << actual_bill;
                    }

                    else
                    {
                        cout << "Bill has not been generated by the admin." << endl;
                    }
                }

                else if (customer_option == '7')
                {
                    exit();
                    break;
                }

                else
                {
                    cout<<"   #### Validation ####"<<endl;
                    cout << "Please try again! You have entered wrong option." << endl;
                }
                clear_screen();
            }
            clear_screen();

            //...Customer Menu Ends...
        }
        else
        {
            cout<<"   ##### VALIDATION #####"<<endl;
            cout << "Wrong username or password."<<endl;
        }

    }
}
//...Main End...



//...Funtions Implementation...

float final_bill(int stays, int cost_per_night)
{
    float bill, discount, bill_after_discount;
    bill = stays * cost_per_night;
    discount = (discounted * bill) / 100;
    bill_after_discount = bill - discount;
    return bill_after_discount;
}

void view_data()
{
    fstream file6;
    string test2;
    file6.open("Customer_Data.txt", ios::in);
    while (getline(file6, test2))
    {
        cout << test2 << endl;
    }
}

void data_of_customer()
{
    fstream file5;
    file5.open("Customer_Data.txt", ios::app);
    if (customer_data_count < 10)
    {
        cout << "Enter the name of the " << customer_data_count + 1 << " customer:";
        cin >> nameA[customer_data_count];
        cout << "Enter the mobile number of the " << customer_data_count + 1 << " customer:";
        cin >> mobile_numberA[customer_data_count];
        cout << "Enter the email of the " << customer_data_count + 1 << " customer:";
        cin >> emailA[customer_data_count];
        cout << "Enter the CNIC of the " << customer_data_count + 1 << " customer:";
        cin >> cnicA[customer_data_count];
        file5 << nameA[customer_data_count] << "\t" << mobile_numberA[customer_data_count] << "\t" << emailA[customer_data_count] << "\t" << cnicA[customer_data_count] << endl;
        customer_data_count = customer_data_count + 1;
        cout << endl;
    }
    customer_data = true;
}

void discount()
{

    fstream file3;
    file3.open("Discount.txt", ios::out);
    cout << "Enter your discount percentage for per night star:";
    cin >> discounted;
    file3 << discounted;
    file3.close();
    room_price = true;
}

void price_of_rooms()
{
    fstream file1;
    file1.open("RoomPrice.txt", ios::out);
    cout << "Enter the price of five star room:";
    cin >> five_star;
    cout << "Enter the price of four star room:";
    cin >> four_star;
    cout << "Enter the price of three star room:";
    cin >> three_star;
    cout << "Enter the price of the two star room:";
    cin >> two_star;
    file1 << "Fivestar"
          << "\t"
          << "Fourstar"
          << "\t"
          << "Threestar"
          << "\t"
          << "Twostar" << endl;
    file1 << five_star << "\t"
          << "\t" << four_star << "\t"
          << "\t" << three_star << "\t"
          << "\t" << two_star;
    file1.close();
    discount_price = true;
}

void header()
{
    
    cout << "   ************************************************************************" << endl;
    cout << "   *                  HOTEL MANAGEMENT SYSTEM                             *" << endl;
    cout << "   ************************************************************************" << endl;
}

void exit()
{
    cout << "******************************************************************" << endl;
    cout << "*****    Thanks for using Hotel Management System            *****" << endl;
    cout << "******************************************************************" << endl;
}

string who()
{
    cout << "                          " << endl;
    cout << "   ****** LOG-IN MENU *****" << endl;
    string password, username;
    cout << "Enter the username (admin or customer):";
    cin >> username;
    cout << "Enter the password (123):";
    cin >> password;

    for (int a = 0; a < TOTAL_USER; a++)
    {
        if (usernameA[a] == username && passwordA[a] == password)
        {
            return roleA[a];
        }
    }
    return "Wrong.";
}

void add_user(string username, string password, string role)
{
    if (user_count < TOTAL_USER)
    {
        usernameA[user_count] = username;
        passwordA[user_count] = password;
        roleA[user_count] = role;
        user_count = user_count + 1;
    }
    else
    {
        cout << "No more space.";
    }
}

char menu1(char op1)
{
    header();
    cout << "WELCOME ADMIN." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "MAIN MENU:" << endl;
    cout << "1) You can add the cost of rooms for per night stay." << endl;
    cout << "2) You can give discount." << endl;
    cout << "3) You can add the data of the customer." << endl;
    cout << "4) You can view the data of the customer." << endl;
    cout << "5) You can delete the data of the customer." << endl;
    cout << "6) You can generate the total bill of the customer." << endl;
    cout << "7) You can generate sorted bill list." << endl;
    cout << "8) Exit." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Enter your option:" << endl;
    cin >> op1;
    return op1;
}

char menu2(char op2)
{
    header();
    cout << "WELCOME CUSTOMER." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "MAIN MENU:" << endl;
    cout << "1) You can see the cost of per night stay." << endl;
    cout << "2) You can see the discount on rooms." << endl;
    cout << "3) You can select the number of persons." << endl;
    cout << "4) You can select the type of Room." << endl;
    cout << "5) You can select the number of stays." << endl;
    cout << "6) You can see the total bill." << endl;
    cout << "7) Exit..." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Enter your option:" << endl;
    cin >> op2;
    return op2;
}

void clear_screen()
{
    cout << "Press any key to continue..." << endl;
    getch();
    system("CLS");
}