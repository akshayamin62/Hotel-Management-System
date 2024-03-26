#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#define max 100

// using namespace std;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::vector;

int maxBid()
{
    int maxb = 0, found = 0;
    ifstream summaryFile("summary_data.txt");

    int bookingId, roomNum, food = 0, paymentAdvance;
    string fname, sname, address, phone, fromDate, toDate;
    // double paymentAdvance;

    while (summaryFile >> bookingId >> roomNum >> fname >> sname >> address >> phone >> fromDate >> toDate >> paymentAdvance >> food)
    {
        if (maxb < bookingId)
        {
            maxb = bookingId;
        }
    }
    summaryFile.close(); // Close the customer data file
    return maxb + 1;
}

int checkRoom(int rm)
{
    int i, found = 0;
    ifstream customerFile("customer_data.txt");

    // if (!customerFile)
    // {
    //     cerr << "Error opening customer data file." << endl;
    //     return ;
    // }

    int bookingId, roomNum, food = 0, paymentAdvance;
    string fname, sname, address, phone, fromDate, toDate;
    // double paymentAdvance;

    while (customerFile >> bookingId >> roomNum >> fname >> sname >> address >> phone >> fromDate >> toDate >> paymentAdvance >> food)
    {
        if (roomNum == rm)
        {
            return 1;
        }
    }
    customerFile.close(); // Close the customer data file
    return 0;
}

class Customer
{
public:
    char fname[100];
    char sname[100];
    char address[100];
    char phone[12];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    int booking_id;
    int food;
};

class Room
{
public:
    char type;
    char stype;
    char ac;
    int roomNumber;
    int rent;
    int status;

    Customer cust;
    void searchRoom(int);
};

// global variables
int count = 80;
// Room rooms[max];

void Room::searchRoom(int rno)
{
    int i, found = 0;
    found = checkRoom(rno);
    ifstream customerFile("customer_data.txt");

    int bookingId, roomNum, food = 0, paymentAdvance;
    string fname, sname, address, phone, fromDate, toDate;
    // getch();
    if (found == 1)
    {

        while (customerFile >> bookingId >> roomNum >> fname >> sname >> address >> phone >> fromDate >> toDate >> paymentAdvance >> food)
        {
            if (roomNum == rno)
            {
                cout << "Customer Information:" << endl;
                cout << "Booking ID: " << bookingId << endl;
                cout << "Room No. :  " << roomNum << endl;
                cout << "Customer Name: " << fname << " " << sname << endl;
                cout << "Customer Address: " << address << endl;
                cout << "Customer Phone: " << phone << endl;
                cout << "From Date: " << fromDate << endl;
                cout << "To Date: " << toDate << endl;
                cout << "Payment Advance: " << paymentAdvance << endl;
                cout << "Food: " << food << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Room is Not book Yet" << endl;
    }
    customerFile.close();
    getch();
}

class roomAllocate
{
public:
    vector<int> v1, v2, v3, v4;
    int nextRoom(int n);
};

int roomAllocate ::nextRoom(int n)
{
    ifstream customerFile("customer_data.txt"); // Open the summary data file

    int bookingId, roomNum, food = 0, paymentAdvance;
    string fname, sname, address, phone, fromDate, toDate;

    while (customerFile >> bookingId >> roomNum >> fname >> sname >> address >> phone >> fromDate >> toDate >> paymentAdvance >> food)
    {
        if (roomNum <= 120)
        {
            v1.push_back(roomNum);
        }
        else if (roomNum <= 220)
        {
            v2.push_back(roomNum);
        }
        else if (roomNum <= 320)
        {
            v3.push_back(roomNum);
        }
        else
        {
            v4.push_back(roomNum);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    int a;
    switch (n)
    {
    case 1:
        a = 101;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] == a)
            {
                a++;
            }
            else
            {
                return a;
            }
        }
        // if(a == 121){
        //     cout<<"All room of this Category are Booked\nPlease select different category of Room\n";
        // }
        return a;
        break;
    case 2:
        a = 201;
        for (int i = 0; i < v2.size(); i++)
        {
            if (v2[i] == a)
            {
                a++;
            }
            else
            {
                return a;
            }
        }
        return a;
        break;
    case 3:
        a = 301;
        for (int i = 0; i < v3.size(); i++)
        {
            if (v3[i] == a)
            {
                a++;
            }
            else
            {
                return a;
            }
        }
        return a;
        break;
    case 4:
        a = 401;
        for (int i = 0; i < v4.size(); i++)
        {
            if (v4[i] == a)
            {
                a++;
            }
            else
            {
                return a;
            }
        }
        break;
    default:
        cout << "\nPlease Enter correct option";
        break;
    }
    return a;
    customerFile.close();
    getch();
}

class HotelMgnt : public Room
{
public:
    void checkIn();
    void bookedRoom();
    void searchCustomer(char *);
    void checkOut(int);
    void guestSummaryReport();
    // friend int rentg();
};

void HotelMgnt::guestSummaryReport()
{
    ifstream summaryFile("summary_data.txt");

    int bookingId, roomNum, food = 0, paymentAdvance;
    string fname, sname, address, phone, fromDate, toDate;

    cout << "Customer Information:" << endl
         << endl;
    while (summaryFile >> bookingId >> roomNum >> fname >> sname >> address >> phone >> fromDate >> toDate >> paymentAdvance >> food)
    {
        cout << "Booking ID: " << bookingId << endl;
        cout << "Room No. :  " << roomNum << endl;
        cout << "Customer Name: " << fname << " " << sname << endl;
        cout << "Customer Address: " << address << endl;
        cout << "Customer Phone: " << phone << endl;
        cout << "From Date: " << fromDate << endl;
        cout << "To Date: " << toDate << endl;
        cout << "Payment Advance: " << paymentAdvance << endl;
        cout << "Food Amount: " << food << endl
             << endl;
    }
    summaryFile.close();
    getch();
}

void HotelMgnt::checkIn()
{
    int found, rno;

    // class Room room;
    // cout << "\nEnter Room number : ";
    // cin >> rno;

    // found = checkRoom(rno);

    int n;
    cout << "1. NON -AC\n2. AC\n3. Queen\n4. King\n";
    cout << "Enter Number to book which type of room : ";
    cin >> n;

    roomAllocate ra;
    rno = ra.nextRoom(n);

    int bookingId, roomNum, food = 0, paymentAdvance;
    string fname, sname, address, phone, fromDate, toDate;

    // if (found != 1)
    // {
        // Ask for customer information
        // cout << "\nEnter booking id: ";
        // cin >> bookingId;
        bookingId = maxBid();

        cout << "\nEnter Customer First Name: ";
        cin >> fname;

        cout << "\nEnter Customer Last Name: ";
        cin >> sname;

        cout << "\nEnter Address (only city): ";
        cin >> address;

        cout << "\nEnter Phone: ";
        cin >> phone;

        cout << "\nEnter From Date: ";
        cin >> fromDate;

        cout << "\nEnter to Date: ";
        cin >> toDate;

        cout << "\nEnter Advance Payment: ";
        cin >> paymentAdvance;

        ofstream customerFile("customer_data.txt", ios::app);
        customerFile << bookingId << " " << rno << " " << fname << " " << sname << " " << address << " " << phone << " " << fromDate << " " << toDate << " " << paymentAdvance << " " << food << endl;
        customerFile.close();

        ofstream summaryFile("summary_data.txt", ios::app);
        summaryFile << bookingId << " " << rno << " " << fname << " " << sname << " " << address << " " << phone << " " << fromDate << " " << toDate << " " << paymentAdvance << " " << food << endl;
        summaryFile.close();

        cout << "\nCustomer Checked-in Successfully..";
        getch();
    // }
    // else
    // {
    //     cout << "\nRoom not found or already booked.";
    //     getch();
    // }
}

// hotel management shows available rooms
void HotelMgnt::bookedRoom()
{
    ifstream customerFile("customer_data.txt"); // Open the summary data file

    int bookingId, roomNum, food = 0, paymentAdvance;
    string fname, sname, address, phone, fromDate, toDate;

    cout << "Booked Room :\n"
         << endl;
    vector<int> v1, v2, v3, v4;

    while (customerFile >> bookingId >> roomNum >> fname >> sname >> address >> phone >> fromDate >> toDate >> paymentAdvance >> food)
    {
        // cout << " " << rno;
        if (roomNum <= 120)
        {
            v1.push_back(roomNum);
        }
        else if (roomNum <= 220)
        {
            v2.push_back(roomNum);
        }
        else if (roomNum <= 320)
        {
            v3.push_back(roomNum);
        }
        else
        {
            v4.push_back(roomNum);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    cout << "NON-AC Room" << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << "\n\nAC Room" << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << "\n\nQueen Room" << endl;
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << "\n\nKing Room" << endl;
    for (int i = 0; i < v4.size(); i++)
    {
        cout << v4[i] << " ";
    }

    customerFile.close(); // Close the summary data file
    getch();
}

// hotel management shows all persons that have booked room
void HotelMgnt::searchCustomer(char *pname)
{
    ifstream inFile("customer_data.txt");
    if (!inFile)
    {
        cerr << "Error opening the file for reading." << endl;
        return;
    }

    int i, found = 0;

    while (!inFile.eof())
    {
        int roomNumber;

        Customer customer;
        inFile >> customer.booking_id;
        inFile >> roomNumber;
        inFile >> customer.fname;
        inFile >> customer.sname;
        inFile >> customer.address;
        inFile >> customer.phone;
        inFile >> customer.from_date;
        inFile >> customer.to_date;
        inFile >> customer.payment_advance;
        inFile >> customer.food;

        if (strcmp(customer.fname, pname) == 0)
        {
            cout << "\nCustomer Name: " << customer.fname << " " << customer.sname;
            cout << "\nRoom Number: " << roomNumber;
            cout << "\nAddress (only city): " << customer.address;
            cout << "\nPhone: " << customer.phone;
            cout << "\nFrom Date: " << customer.from_date;
            cout << "\nTo Date: " << customer.to_date;
            cout << "\nAdvance Payment: " << customer.payment_advance;
            cout << "\nFood Amount: " << customer.food;
            cout << "\n\nPress enter :- ";
            found = 1;
            // break;
        }
    }

    inFile.close();

    if (found == 0)
    {
        cout << "\nThere is no room booked by this person name.";
        // getch();
    }
            getch();
}

int rentg(int rno)
{
    if (rno <= 120)
    {
        return 1000;
    }
    else if (rno <= 220)
    {
        return 2000;
    }
    else if (rno <= 320)
    {
        return 3000;
    }
    else
    {
        return 4000;
    }
}

void HotelMgnt::checkOut(int roomNum)
{
    int i, found = 0, days, rno;
    float billAmount = 0;

    found = checkRoom(roomNum);

    if (found == 1)
    {
        cout << "\nEnter Number of Days:\t";
        cin >> days;
        billAmount = days * rentg(roomNum);

        // Remove the customer's data from the customer data file
        ifstream inFile("customer_data.txt");
        // if (!inFile)
        // {
        //     cerr << "Error opening the customer data file for reading." << endl;
        //     getch();
        //     return;
        // }

        ofstream tempFile("temp_customer_data.txt");
        // if (!tempFile)
        // {
        //     cerr << "Error opening the temporary customer data file." << endl;
        //     inFile.close();
        //     getch();
        //     return;
        // }

        int b_id, roomNumber;
        while (inFile >> b_id)
        {
            inFile >> roomNumber;
            // cout<<roomNumber<<endl;
            Customer customer;
            customer.booking_id = b_id;
            inFile >> customer.fname;
            inFile >> customer.sname;
            inFile >> customer.address;
            inFile >> customer.phone;
            inFile >> customer.from_date;
            inFile >> customer.to_date;
            inFile >> customer.payment_advance;
            inFile >> customer.food;

            if (roomNumber != roomNum)
            {
                tempFile << customer.booking_id << " " << roomNumber << " " << customer.fname << " " << customer.sname << " "
                         << customer.address << " " << customer.phone << " " << customer.from_date << " "
                         << customer.to_date << " " << customer.payment_advance << " " << customer.food << "\n";
            }
            else
            {
                cout << "\n\t######## CheckOut Details ########\n";
                cout << "\nCustomer Name : " << customer.fname << " " << customer.sname;
                cout << "\nRoom Number : " << roomNumber;
                cout << "\nAddress : " << customer.address;
                cout << "\nPhone : " << customer.phone;
                cout << "\nTotal Amount Due : " << billAmount << " /";
                cout << "\nAdvance Paid: " << customer.payment_advance << " /";
                cout << "\nFood Amount: " << customer.food << " /";
                cout << "\n*** Total Payable: " << billAmount - customer.payment_advance + customer.food << "/ only";
            }
        }

        inFile.close();
        tempFile.close();

        remove("customer_data.txt");
        rename("temp_customer_data.txt", "customer_data.txt");
    }
    else
    {
        cout << "The Room is already check out" << endl;
    }
    getch();
}

class RoomInfo
{
public:
    RoomInfo()
    {
        cout << "************ Welcome to Our Hotel ************" << endl;
        cout << "Room Categories and Prices:" << endl;

        string roomCategories[] = {"NON-AC", "AC", "Queen", "King"};
        int roomPrices[] = {1000, 2000, 3000, 4000};

        string roomAmenities[] = {
            "Complimentary Breakfast",
            "Free Wi-Fi",
            "Flat-screen TV",
            "Private Bathroom",
            "Room Service",
        };

        string roomDescriptions[] = {
            "Standard room with basic amenities.",
            "Cozy room with air conditioning and a comfortable bed.",
            "Luxurious room with a queen-sized bed and additional space.",
            "Spacious king-sized bed with a beautiful view.",
        };

        for (int i = 0; i < 4; i++)
        {
            cout << "Category: " << roomCategories[i] << endl;
            cout << "Price: $" << roomPrices[i] << " per night" << endl;
            cout << "Amenities: " << roomAmenities[i] << endl;
            cout << "Description: " << roomDescriptions[i] << endl;
            cout << "************" << endl;
        }
    }
};
void InforamtionAboutRoom()
{
    RoomInfo r;
}

void foodList(string *s1)
{
    cout << "Veg Menu:\n";
    cout << "Starters:\n";
    cout << "1. Vegetable Spring Rolls - 150\n";
    cout << "2. Spinach and Cheese Stuffed Mushrooms - 200\n";
    cout << "3. Tomato Bruschetta - 300\n";

    // Main Courses
    cout << "\nMain Courses:\n";
    cout << "4. Vegetable Curry - 250\n";
    cout << "5. Spinach and Ricotta Ravioli - 400\n";
    cout << "6. Veggie Burger - 150\n";

    // Desserts
    cout << "\nDesserts:\n";
    cout << "7. Chocolate milkshake - 120\n";
    cout << "8. Fruit Salad - 100\n";
    cout << "9. Cheesecake - 150\n";
}

void foodList(const string *s2)
{
    cout << "Non-Veg Menu:\n";

    // Starters
    cout << "Starters:\n";
    cout << "1. Chicken Wings - 500\n";
    cout << "2. Shrimp Cocktail - 400\n";
    cout << "3. Bacon-Wrapped Scallops - 700\n";

    // Main Courses
    cout << "\nMain Courses:\n";
    cout << "4. Steak with Mashed Potatoes - 600\n";
    cout << "5. Grilled Salmon - 550\n";
    cout << "6. Lobster Tail - 750\n";

    // Desserts
    cout << "\nDesserts:\n";
    cout << "7. Chocolate Lava Cake - 150\n";
    cout << "8. Tiramisu - 300\n";
    cout << "9. Panna Cotta - 200\n";
}

class food
{
public:
    string *s1;
    const string *s2;
    int q;

    food()
    {
        cout << "1. Veg \n2. Non Veg\nEnter your choice : ";
        cin >> q;
        cout << endl;
        if (q == 1)
        {
            foodList(s1);
        }
        else if (q == 2)
        {
            foodList(s2);
        }
    }
};

class Getorder : public food
{
public:
    int order()
    {
        int i = 0;
        int number_of_items;
        cout << "\nEnter the number of items you want : ";
        cin >> number_of_items;
        vector<int> price;
        int sum = 0;
        if (q == 1)
        {
            while (i < number_of_items)
            {
                cout << "Enter your " << i + 1 << " choice : ";
                int num;
                cin >> num;
                switch (num)
                {
                case 1:
                    price.push_back(150);
                    break;
                case 2:
                    price.push_back(200);
                    break;
                case 3:
                    price.push_back(300);
                    break;
                case 4:
                    price.push_back(250);
                    break;
                case 5:
                    price.push_back(400);
                    break;
                case 6:
                    price.push_back(150);
                    break;
                case 7:
                    price.push_back(120);
                    break;
                case 8:
                    price.push_back(100);
                    break;
                case 9:
                    price.push_back(150);
                    break;
                default:
                    cout << "Enter the correct value" << endl;
                }
                i++;
            }

            for (int i = 0; i < price.size(); i++)
            {
                sum += price[i];
            }

            return sum;
        }
        else if (q == 2)
        {
            while (i < number_of_items)
            {
                cout << "Enter your " << i + 1 << " choice : ";
                int num;
                cin >> num;

                switch (num)
                {
                case 1:
                    price.push_back(500);
                    break;
                case 2:
                    price.push_back(400);
                    break;
                case 3:
                    price.push_back(700);
                    break;
                case 4:
                    price.push_back(600);
                    break;
                case 5:
                    price.push_back(550);
                    break;
                case 6:
                    price.push_back(750);
                    break;
                case 7:
                    price.push_back(150);
                    break;
                case 8:
                    price.push_back(300);
                    break;
                case 9:
                    price.push_back(200);
                    break;
                default:
                    cout << "Enter the correct value" << endl;
                }
                i++;
            }
            for (int i = 0; i < price.size(); i++)
            {
                sum += price[i];
            }

            return sum;
        }
    }
};
int foodcall()
{

    Getorder fd;

    return fd.order();
    // cout<<"helllo";
    // cout << "The total amount= " <<p<< endl;
    // getch();
}

void roomFood()
{
    int rno, found, amount;
    cout << "\nEnter room number: ";
    cin >> rno;

    found = checkRoom(rno);

    if (found == 1)
    {

        ifstream inFile("customer_data.txt");

        ofstream tempFile("temp_customer_data.txt");

        amount = foodcall();

        cout << "Amount " << amount << " added to your bill" << endl;

        int b_id, roomNumber, B;
        while (inFile >> b_id)
        {
            inFile >> roomNumber;

            Customer customer;
            customer.booking_id = b_id;
            inFile >> customer.fname;
            inFile >> customer.sname;
            inFile >> customer.address;
            inFile >> customer.phone;
            inFile >> customer.from_date;
            inFile >> customer.to_date;
            inFile >> customer.payment_advance;
            inFile >> customer.food;

            if (roomNumber == rno)
            {
                B = customer.booking_id;
                tempFile << customer.booking_id << " " << roomNumber << " " << customer.fname << " " << customer.sname << " "
                         << customer.address << " " << customer.phone << " " << customer.from_date << " "
                         << customer.to_date << " " << customer.payment_advance << " " << amount + customer.food << "\n";
            }
            else
            {
                tempFile << customer.booking_id << " " << roomNumber << " " << customer.fname << " " << customer.sname << " "
                         << customer.address << " " << customer.phone << " " << customer.from_date << " "
                         << customer.to_date << " " << customer.payment_advance << " " << customer.food << "\n";
            }
        }

        inFile.close();
        tempFile.close();

        remove("customer_data.txt");
        rename("temp_customer_data.txt", "customer_data.txt");

        ifstream iFile("summary_data.txt");

        ofstream temFile("temp_summary_data.txt");

        while (iFile >> b_id)
        {
            iFile >> roomNumber;

            Customer customer;
            customer.booking_id = b_id;
            iFile >> customer.fname;
            iFile >> customer.sname;
            iFile >> customer.address;
            iFile >> customer.phone;
            iFile >> customer.from_date;
            iFile >> customer.to_date;
            iFile >> customer.payment_advance;
            iFile >> customer.food;

            if (B == customer.booking_id)
            {
                temFile << customer.booking_id << " " << roomNumber << " " << customer.fname << " " << customer.sname << " "
                        << customer.address << " " << customer.phone << " " << customer.from_date << " "
                        << customer.to_date << " " << customer.payment_advance << " " << amount + customer.food << "\n";
            }
            else
            {
                temFile << customer.booking_id << " " << roomNumber << " " << customer.fname << " " << customer.sname << " "
                        << customer.address << " " << customer.phone << " " << customer.from_date << " "
                        << customer.to_date << " " << customer.payment_advance << " " << customer.food << "\n";
            }
        }

        iFile.close();
        temFile.close();

        remove("summary_data.txt");
        rename("temp_summary_data.txt", "summary_data.txt");
    }
    else
    {
        cout << "The Room is Not currently booked" << endl;
    }
    // getch();
}

class manager
{
    int M_id;
    char name[100];
    char username[100];
    char password[100];
public:
    friend int managerCheck(char *s1, char *s2);
    friend void managerLogin();
};

int managerCheck(char *s1, char *s2)
{
    ifstream inFile("manager_data.txt");

    int i, found = 0;

    while (!inFile.eof())
    {
        manager m;
        inFile >> m.M_id;
        inFile >> m.name;
        inFile >> m.username;
        inFile >> m.password;

        if ((strcmp(s1, m.username) == 0) && (strcmp(s2, m.password) == 0))
        {
            return 1;
        }
    }
    inFile.close();
    return 0;

    // if (found == 0)
    // {
    //     cout << "\nThere is no room booked by this person name.";
    //     getch();
    // }
}

void manageraccess()
{
    int opt, amount;
    do
    {
        system("cls");
        cout << "\n### Manager Page ###";
        cout << "\n1. Search Customer";
        cout << "\n2. Guest Summary Report";
        cout << "\n3. Back to Main Menu";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        char pname[100];
        HotelMgnt c;

        switch (opt)
        {
        case 1:
            cout << "Enter Customer Name: ";
            cin >> pname;
            c.searchCustomer(pname);
            break;
        case 2:
            c.guestSummaryReport();
            break;
        case 3:
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 3);
}

void managerLogin()
{
    manager m;
    cout << "Enter Username : ";
    cin >> m.username;
    cout << "Enter Password : ";
    cin >> m.password;

    int found = managerCheck(m.username,m.password);
    if (found == 0)
    {
        cout << "\nIncorrect Username and Password";
        getch();
    }
    else{
        manageraccess();
    }
}

void restaurant()
{
    int opt, amount;
    do
    {
        system("cls");
        cout << "\n### Restaurant ###";
        cout << "\n1. Order food to Room";
        cout << "\n2. Restaurant";
        cout << "\n3. Back to Main Menu";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            roomFood();
            getch();
            break;
        case 2:
            amount = foodcall();
            cout << "Total Amount : " << amount << endl;
            getch();
            break;
        case 3:
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 3);
}

// managing rooms (adding and searching available rooms)
void manageRooms(HotelMgnt hm)
{
    class Room room;
    int opt, rno, i, flag = 0;
    char ch;
    do
    {
        system("cls");
        cout << "\n### Manage Rooms ###";
        cout << "\n1. Room Inforamtion";
        cout << "\n2. Booked Rooms";
        cout << "\n3. Search Room";
        cout << "\n4. Back to Main Menu";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            InforamtionAboutRoom();
            getch();
            break;
        case 2:
            hm.bookedRoom();
            break;
        case 3:
            cout << "\nEnter room number: ";
            cin >> rno;
            room.searchRoom(rno);
            break;
        case 4:
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 4);
}




int main()
{
    HotelMgnt hm;
    int i, j, opt, rno;
    char ch;
    char pname[100];

    system("cls");

    do
    {
        system("cls");
        cout << "######### Hotel Management #########\n";
        cout << "\n1. Manage Rooms";
        cout << "\n2. Check-In Room";
        cout << "\n3. Check-Out Room";
        cout << "\n4. Manager Login";
        cout << "\n5. Food";
        cout << "\n8. Exit";
        cout << "\n\nEnter Option: ";
        // RoomInfo R(1);
        cin >> opt;
        switch (opt)
        {
        case 1:
            manageRooms(hm);
            break;
        case 2:
            hm.checkIn();
            break;
        case 3:
            cout << "Enter Room Number : ";
            cin >> rno;
            hm.checkOut(rno);
            break;
        case 4:
            managerLogin();
            break;
        case 5:
            restaurant();
            break;
        case 8:
            cout << "\nTHANK YOU! Visit Again";
            break;
        default:
            cout << "\nPlease Enter correct option";
            getch();
            break;
        }
    } while (opt != 8);

    getch();
}