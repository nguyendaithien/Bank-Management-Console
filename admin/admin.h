#ifndef _ADMIN_H_
#define _ADMIN_H_
#include<vector>
#include"../user/user.h"
#include"../account/account.h"

// const char* fileUserPath = "./Data/dataFileUsers.txt";
// const char* fileAccountPath = "./Data/dataFileAccounts.txt";

using namespace std;
class Admin {
private:

    vector<User> users;
    vector<Account> accounts;
    // string fullName;
    // string phoneNumber;
    

public:

    Admin();
    ~Admin();
    // Admin(string fullName, string phoneNumber) {}
    // //getter, setter
    // string getFullName() {};
    // void setFullName(string fullName) {};
    // string getPhoneNumber() {};
    // void setPhoneNumber(string phoneNumber) {};
    
    vector<Account> getAccount ();
    vector<User> getUsers();
    //Add user
    void addUser (); 

    //get infor of user by ID
    void getInforOfUserByID();

    //get infor of users
    void getInforOfUsers();

    //deposit money into account's customer
    void depositMoneyIntoAccountOfUser();

    //remove the account
    void removeTheAccount();

    //get user data from file
    void getUsersDataFromFile();

    //get account data from file
    void getAcountDataFromFile();

    //write data in file
    void writeAccountDataInFile();
    
};

#endif