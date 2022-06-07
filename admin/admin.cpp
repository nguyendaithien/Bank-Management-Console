#include<iostream>
#include<string>
#include"admin.h" 
#include"../utilities/utilities.h"
#include<cstdlib>
#include<ctime>

//thư viện stdlib dùng hàm srand, rand để láy password ngẫu nhiên
//thư viện time để random k trùng nhau theo time

using namespace std;


Admin::Admin() {}
Admin::~Admin() {}

// get users
vector<User> Admin::getUsers() {
    return this->users;
}
// get accounts
vector<Account> Admin::getAccount() {
    return this->accounts;
}

//add user
void Admin::addUser() {
    User newUser;
    Account newAcount;
    __int16 count = 0;
    // FILE* dataFile = fopen(fileAccountPath, "a+");
    srand(time(NULL));
    //
    system("cls");
    drawline(30, '=');
    cout << " CREATING AN ACCOUNT ";
    drawline(29, '=');
    cout << "\n\n";
    //nhap sđt của nguoi dung
    string phoneNumber;
    do {
        cout << "Enter phone number of User: ";
        cin.ignore();
        getline(cin, phoneNumber);
        for (__int16 i = 0; i < users.size(); i++) {
            if (users[i].getPhoneNumber() == phoneNumber) {
                cout << "This phone number is already registered!!";
                count = i;
            }
        }
    } while (phoneNumber == users[count].getPhoneNumber());

    //nhap thong tin khach hang sau khi đã kiểm tra SĐT
    newUser.inData(phoneNumber);
    cout << "\n";

    // đẩy newUser vào đằng sau của mảng quản lý users thông qua hàm push_back
    this->users.push_back(newUser);
    //
    system("cls");
    cout << "Create Account Success!" << "\n";
    // hien thi USERNAME là phoneNumber, PASSWORD ngẫn nhiên 
    // Gán USERNAME, PW vào Mảng quản lý accounts (thuộc tính của Admin)
    newAcount.setUserName(newUser.getPhoneNumber());
    cout << "USERNAME of Customer : " << newAcount.getUserName() << endl;
    newAcount.setPassWord(to_string(rand()));
    cout << "PASSWORD of Customer : 2020" << newAcount.getPassWord();
    this->accounts.push_back(newAcount);

}

//get infor of user
void Admin::getInforOfUserByID() {
    string ID;
    __int16 count = -1;
    system("cls");
    drawline(30, '=');
    cout << " VIEW CUSTOMER ACCOUNT INFORMATION BY ID ";
    drawline(29, '=');
    cout << "\n";

    do {
        cout << endl << "Enter ID of Customer: ";
        cin >> ID;
        // cout << "ID: " << ID << endl;
        for (__int16 i = 0; i < this->users.size(); i++) {
            if (this->users[i].getPhoneNumber() == ID) {
                count = i;
                break;
            }
        }
        if (count == -1) {
            cout << "ID Invalid !!!" << endl << "Please enter again!" << endl;
            cout << "<Exit by Enter 0>" << endl;
            if (ID == "0") {
                break;
            }

        }
        else {
            system("cls");
            drawline(30, '=');
            cout << " INFORMATION OF CUSTOMER " << ID << " ";
            drawline(28, '=');
            cout << endl;
            printf("%-20s%-30s%-20s%-20s$\n", "ID", "FULL NAME", "CITIZEN ID", "BALANCE");
            this->users[count].outData();
        }
    } while (count == -1);
}

//deposit money into account's customer
void Admin::depositMoneyIntoAccountOfUser() {
    __int16 count = -1;
    __int32 money = 0;
    system("cls");
    drawline(30, '=');
    cout << " DEPOSIT MONEY INTO THE CUSTOMER'S ACCOUNT ";
    drawline(29, '=');
    cout << "\n";
    string ID;
    do {
        cout << "Enter ID of Customer: ";
        cin >> ID;
        //find Customer by ID
        for (__int16 i = 0; i < users.size(); i++) {
            if (users[i].getPhoneNumber() == ID) {
                count = i;
            }
        }
        if (count == -1) {
            cout << "ID Invalid !!!" << endl << "Please enter again!" << endl;
            cout << "<Exit by Enter 0>" << endl;
            cin >> ID;
            if (ID == "0") {
                break;
            }
        }
        else {
            cout << "Enter Money into of Customer: ";
            cin >> money;
            users[count].setBalance(users[count].getBalance() + money);
            system("cls");
            cout << "Deposit money Successfully!" << endl;
            cout << "Balance of Customer: " << users[count].getBalance();
        }

    } while (count == -1);
}

//remove the account
void Admin::removeTheAccount() {
    __int16 count = 0;
    system("cls");
    drawline(30, '=');
    cout << " CLOSING AN ACCOUNT ";
    drawline(29, '=');
    cout << "\n\n";
    string ID;
    //find Customer by ID
    do {
        cout << "Enter ID of Customer: ";
        cin >> ID;
        //find Customer by ID
        for (__int16 i = 0; i < users.size(); i++) {
            if (users[i].getPhoneNumber() == ID) {
                count = i;
            }
        }
        if (count == -1) {
            cout << "ID Invalid !!!" << endl << "Please enter again!" << endl;
            cout << "<Exit by Enter 0>" << endl;
            cin >> ID;
            if (ID == "0") {
                break;
            }

        }
        else {
            cout << "Customer : " << users[count].getFullName() << endl;
            // erase(); // hàm xoá phần tử của vector
            __int16 choice = 0;
            cout << "Close Account? Are you sure ?" << endl;
            cout << "0. NO" << endl << "1. YES" << endl;
            cout << "YOUR CONFIRM: ";
            choice = choiceNumber(0, 1, "Confirm invalid ! Enter Again!");
            if (choice == 0) {
                break;
            }
            else {
                users.erase(users.begin() + count);
                accounts.erase(accounts.begin() + count);
                cout << "Close account successfully!!" << endl;
            }
        }
    } while (count == -1);

}

//get information of users
void Admin::getInforOfUsers() {
    system("cls");
    drawline(30, '=');
    cout << " INFORMATION OF ALL CUSTOMER ";
    drawline(28, '=');
    cout << endl;
    printf("%-20s%-30s%-20s%-20s$\n", "ID", "FULL NAME", "CITIZEN ID", "BALANCE");
    for (__int16 i = 0; i < users.size(); i++) {
        this->users[i].outData();
    }
}

//get user data from file
void Admin::getUsersDataFromFile() {
    FILE* dataFile = fopen("./Data/dataFileUsers.txt", "r");
    char temp[255];
    User readUser;
    while (fgets(temp, 255, dataFile) != NULL) {
        string s = temp;
        readUser.readData(s);
        users.push_back(readUser);
    }
    fclose(dataFile);
}

//get account data from file
void Admin::getAcountDataFromFile() {
    FILE* dataFile = fopen("./Data/dataFileAccounts.txt", "r");
    char temp[255];
    Account readAcount;
    while (fgets(temp, 255, dataFile) != NULL) {
        string s = temp;
        readAcount.readData(s);
        accounts.push_back(readAcount);
    }
    fclose(dataFile);
}

//write data in file
void Admin::writeAccountDataInFile() {
    FILE* dataFile = fopen("./Data/dataFileUsers.txt", "w");
    for (auto x : users) {
        x.writeData(dataFile);
    }
    fclose(dataFile);
    //
// ghi thông tin Username, Password vào trong file quản lý Account
    FILE* dataFile2 = fopen("./Data/dataFileAccounts.txt", "w");
    for (auto y : accounts) {
        y.writeData(dataFile2);
    }
    fclose(dataFile2);
}

