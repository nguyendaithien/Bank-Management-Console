#include<iostream>
#include<string>
#include"utilities.h"
#include"../admin/admin.h"
#include"../admin/admin.h"
#include"../account/account.h"

// const char* fileUserPath = "./Data/dataFileUsers.txt";
// const char* fileAccountPath = "./Data/dataFileAccounts.txt";


using namespace std;

//Draw line
void drawline(int number, char symbol) {
    for (int i = 0; i < number; i++) {
        cout << symbol;
    }
}

//Enter Number
__int16 choiceNumber(__int16 minRange, __int16 maxRange, string warning) {
    __int16 number;
    do {
        cin >> number;
        if (minRange > number || number > maxRange) {
            cout << "\n" << warning;
        }
        else {
            return number;
        }
    } while (minRange > number || number > maxRange);
}

//Log in Mode Display
void listsModesToSignIn() {
    system("cls");
    drawline(80, '=');
    cout << "\n";
    cout << "**";
    drawline(28, '_');
    cout << "BANKING MANAGEMENT SYSTEM";
    drawline(23, '_');
    cout << "**" << endl;
    cout << "**";
    drawline(33, '_');
    cout << "SIGN IN MODE";
    drawline(31, '_');
    cout << "**" << endl;
    cout << "**\t\t\t\t1. ADMIN MODE\t\t\t\t      **\n";
    cout << "**\t\t\t\t2. USER MODE\t\t\t\t      **\n";
    cout << "**\t\t\t\t3. EXIT\t\t\t\t\t      **\n";
    drawline(80, '=');
    cout << "\n";
}

//Display modes of Admin's Account
void displayModeOfAdmin() {
    system("cls");
    drawline(84, '=');
    cout << "\n";
    cout << "**";
    drawline(30, '_');
    cout << "MODES OF ADMIN ACCOUNT";
    drawline(28, '_');
    cout << "**" << endl;
    cout << "**\t\t\t1. CREATE ACCOUNT\t\t\t\t          **\n";
    cout << "**\t\t\t2. VIEW CUSTOMER ACCOUNT INFORMATION BY ID\t\t  **\n";
    cout << "**\t\t\t3. VIEW ALL CUSTOMER ACCOUNT INFORMATION\t\t  **\n";
    cout << "**\t\t\t4. DEPOSIT MONEY INTO THE CUSTOMER'S ACCOUNT\t\t  **\n";
    cout << "**\t\t\t5. CLOSING AN ACCOUNT\t\t\t\t          **\n";
    cout << "**\t\t\t6. SIGN OUT\t\t\t\t\t          **\n";
    drawline(84, '=');
    cout << "\n";

}

//Display modes of user
void displayModeOfUser() {
    system("cls");
    drawline(84, '=');
    cout << "\n";
    cout << "**";
    drawline(30, '_');
    cout << "MODES OF USER ACCOUNT";
    drawline(28, '_');
    cout << "**" << endl;
    cout << "**\t\t\t1. UPDATING ACCOUNT\t\t\t\t         **\n";
    cout << "**\t\t\t2. CHANGE PASSWORD\t\t\t\t         **\n";
    cout << "**\t\t\t3. TRANFER MONEY\t\t\t\t\t **\n";
    cout << "**\t\t\t4. WITHDRAW MONEY\t\t\t\t\t **\n";
    cout << "**\t\t\t5. VIEW TRANSACTION HISTORY\t\t\t         **\n";
    cout << "**\t\t\t6. SIGN OUT\t\t\t\t\t         **\n";
    drawline(84, '=');
    cout << "\n";

}

void choiceModeOfAdmin() {
    __int16 choice;
    Admin admin;
    admin.getUsersDataFromFile();
    admin.getAcountDataFromFile();
    do {
        displayModeOfAdmin();

        cout << "Enter number(1,6) to select mode: ";
        choice = choiceNumber(1, 6, "Please enter valid mode: ");
        switch (choice) {
        case 1:
            admin.addUser();
            cin.ignore();
            getchar();
            break;
        case 2:
            admin.getInforOfUserByID();
            cin.ignore();
            getchar();
            break;
        case 3:
            admin.getInforOfUsers();
            cin.ignore();
            getchar();
            break;
        case 4:
            admin.depositMoneyIntoAccountOfUser();
            cin.ignore();
            getchar();
            break;

        case 5:
            admin.removeTheAccount();
            cin.ignore();
            getchar();
            break;

        case 6:
            admin.writeAccountDataInFile();
            cin.ignore();
            system("cls");
            cout << "Made by ___Try Hard team___  " << endl;
            cout << "EXITING PROGRAM.... ";
            system("pause");
            break;
        default:
            break;
        }
    } while (choice != 6);
}

//choice Mode of User's Account
void choiceModeOfUser(User& user, Account& accounts, vector<User>& users) {
    __int16 choice;
    do {
        displayModeOfUser();
        user.displayData();
        drawline(84, '=');
        cout << endl << "Enter number(1,6) to select mode: ";
        choice = choiceNumber(1, 6, "Please enter valid mode : ");
        switch (choice) {
        case 1:
            user.updatingAccount();
            cin.ignore();
            getchar();
            break;
        case 2:
            user.changePassword(accounts);
            cin.ignore();
            getchar();
            break;
        case 3:
            user.transferMoney(accounts, users);
            cin.ignore();
            getchar();
            break;
        case 4:
            user.withdrawMoney(accounts);
            cin.ignore();
            getchar();
            break;

        case 5:
            user.viewTransactionHistory();
            cin.ignore();
            getchar();
            break;

        case 6:
            // writeAccountDataInFile(accounts, users);
            cin.ignore();
            system("cls");
            cout << "Made by ___Troai Hat Team___  " << endl;
            cout << "EXITING PROGRAM.... ";
            system("pause");
            break;
        default:
            break;
        }
    } while (choice != 6);
}

//choice mode to sign in
void choiseModeToSignIn() {
    __int16 choice;
    bool isLogIn = false;
    string userName, password;
    vector<Account> accounts;
    vector<User> users;
    char temp[255];

    //open user data file
    FILE* dataFileUser = fopen("./Data/dataFileUsers.txt", "r");
    User readUser;
    //open account data file
    FILE* dataFileAccount = fopen("./Data/dataFileAccounts.txt", "r");
    Account readAcount;

    //Select SIGN IN mode
    do {
        listsModesToSignIn();
        cout << "Enter Number (1-3) to select mode: ";
        choice = choiceNumber(1, 3, "Please enter valid mode : ");
        switch (choice) {
        case 1:
            do {
                system("cls");
                drawline(80, '=');
                cout << endl << "**";
                drawline(33, '_');
                cout << "ADMIN MODE";
                drawline(33, '_');
                cout << "**" << endl;
                cout << "Please enter USERNAME: ";
                cin >> userName;
                cout << "Please enter PASSWORD: ";
                cin >> password;
                if (userName == "ADMIN" && password == "ADMIN") {
                    choiceModeOfAdmin();
                }
                else {
                    system("cls");
                    drawline(80, '=');
                    cout << endl << "**";
                    drawline(33, '_');
                    cout << "ADMIN MODE";
                    drawline(33, '_');
                    cout << "**" << endl;
                    cout << "USERNAME or PASSWORD incorrect !!!" << endl;
                    cout << "......Please enter again......";
                    cin.ignore();
                    cin.get();
                }
            } while (userName != "ADMIN" && password != "ADMIN");
            break;
        case 2:

            //ghi data doc duoc tu file vao users
            while (fgets(temp, 255, dataFileUser) != NULL) {
                string s = temp;
                readUser.readData(s);
                users.push_back(readUser);
            }
            fclose(dataFileUser);

            //ghi data doc duoc tu file vao accounts
            while (fgets(temp, 255, dataFileAccount) != NULL) {
                string s = temp;
                readAcount.readData(s);
                accounts.push_back(readAcount);
            }
            fclose(dataFileAccount);
            do {
                system("cls");
                drawline(80, '=');
                cout << endl << "**";
                drawline(33, '_');
                cout << "USER MODE";
                drawline(33, '_');
                cout << "**" << endl;
                cout << "Please enter USERNAME: ";
                cin >> userName;
                cout << "Please enter PASSWORD: ";
                cin >> password;

                for (__int16 i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getUserName() == userName && accounts[i].getPassWord() == password) {
                        isLogIn = true;
                        choiceModeOfUser(users[i], accounts[i], users);
                        break;
                    }
                }
                if (!isLogIn) {
                    system("cls");
                    drawline(80, '=');
                    cout << endl << "**";
                    drawline(33, '_');
                    cout << "USER MODE";
                    drawline(33, '_');
                    cout << "**" << endl;
                    cout << "USERNAME or PASSWORD incorrect !!!" << endl;
                    cout << "......Please enter again......";
                    cin.ignore();
                    cin.get();
                }

            } while (isLogIn == false);
            writeAccountDataInFileUserMode(accounts, users);
            break;
        case 3:
            // writeAccountDataInFileUserMode(accounts, users);
            system("cls");
            cout << "Made by ___Troai Hat Team___  " << endl;
            cout << "EXITING PROGRAM.... ";
            system("pause");
            break;
        default:
            break;
        }
    } while (choice != 3);
}

void writeAccountDataInFileUserMode(vector<Account>& accounts, vector<User>& users) {
    FILE* dataFile = fopen("./Data/dataFileUsers.txt", "w+");
    for (auto x : users) {
        x.writeData(dataFile);
    }
    fclose(dataFile);
    //
// ghi thông tin Username, Password vào trong file quản lý Account
    FILE* dataFile2 = fopen("./Data/dataFileAccounts.txt", "w+");
    for (auto y : accounts) {
        y.writeData(dataFile2);
    }
    fclose(dataFile2);
}