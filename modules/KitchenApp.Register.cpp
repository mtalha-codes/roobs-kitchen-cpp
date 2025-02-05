// Created By Muhammad Talha on 14/12/2024

// Implementation of KitchenApp.Register.h

#include "KitchenApp.Register.h"
#include <iostream>

#include "KitchenApp.Exceptions.h"

namespace KitchenApp::Authenticator
{

    bool Register::IsEmailValid(const std::string &email)
    {
        return email.find('@')!=std::string::npos; // if the email contains @ , then it returns true and vice versa
    }

    bool Register::IsPasswordValid(const std::string &password)
    {
        return password.length()>=8; // check password length, if it is greater than or equal to 8 then return true and vice versa
    }


    bool Register::IsNotUniqueUser() const {
        /*
         * Here I use to check where the userdata file for the same username exists or not
         * You must use SQL queries to check whether the table contains a row with same username or not !
         */
        std::filesystem::path p = "Data\\UserData\\"+UserName;
        return std::filesystem::exists(p); // if it exists then return false that selected username is not unique.
    }


    Register::Register(const std::string& FirstName, const std::string& LastName, const std::string& E_Mail, const std::string& Password, const std::string& UserName)
    {
        // Constructor to Initialize Fields
        // 'this' pointer points to the current object

        this->FirstName = FirstName;
        this->LastName = LastName;
        this->E_Mail = E_Mail;
        this->Password = Password;
        this->UserName = UserName;
        if(!IsEmailValid(this->E_Mail))
        {
            throw Exceptions::InvalidEmailError();
        }
        if (IsNotUniqueUser()) {
            throw Exceptions::NonUniqueUserNameError();
        }
        if(!IsPasswordValid(this->Password))
        {
            throw Exceptions::InvalidPasswordError();
        }
        FolderName = "Data\\UserData\\"+UserName+"\\";
        std::filesystem::create_directory(FolderName);
        FileName = FolderName.string()+UserName;
        UserDataFile.open(FileName);// creates the file, tries to establish connection with DB via ConnectionString...
        if(!UserDataFile.is_open()) // checks whether the file is open or not !, similar to testing connection
        {
            throw Exceptions::UserDataFileWritingError();
        }

    }

    void Register::RegisterUser()
    {
        // Function Contains the logic to register the User
        // Basically it will write the User Credentials to a file
        // You will need to write sql queries to store the credentials in the [db.Table]
        // For extended functionality you might need to add feature to do modifications in their RoobID like change of username or password...
        UserDataFile << UserName << "|" << Password << std::endl;
        // If this was done by DB and SQL , then no restart is needed !...
        std::cout << "User has been successfully registered !" << std::endl; // this will go into your messagebox instance
    }
    Register::~Register() {
        UserDataFile.close();// Closes the file... Same as dropping the connection to the DB which stores UserData, to avoid tampering
    }
}
