// Created By Muhammad Talha on 14/12/2024

#ifndef KITCHEN_APP_REGISTER_H
#define KITCHEN_APP_REGISTER_H
// contains the logic of register for the new custom RoobID
#include <string>
#include <fstream>
#include <filesystem>

namespace KitchenApp::Authenticator
{
  class Register
  {
        std::string FirstName; // FirstName of the User
        std::string LastName; // LastName of the User
        std::string E_Mail; // EMail of the User (Required to Push Notifications... Not Here [In Your Real App]) {Here it is just for keeping the formality}
        std::string Password; // Password of the User.... Needed to Login to RoobID
        std::string UserName; // UserName of the User.... Needed to Login to RoobID
        std::ofstream UserDataFile; // Needed to Store User Credentials {Username & Password}... You will need to implement it via DataBase
        std::string FileName;
        std::filesystem::path FolderName;
        static bool IsEmailValid(const std::string& email); // Essential Part of the Registration Process (Helps Prevention from IrregularEmail Format)
        static bool IsPasswordValid(const std::string& password); // Essential Part of the Registration Process (Helps Users to Create Strong Passwords)
        bool IsNotUniqueUser() const; // Check if the username is taken by some other user or not....
    public:
        Register(const std::string& FirstName, const std::string& LastName, const std::string& E_Mail, const std::string& Password, const std::string& UserName);
        void RegisterUser();
       ~Register();
  };
}

#endif