// Created By Muhammad Talha on 14/12/2024

#include "KitchenApp.Login.h"

#include <filesystem>

#include "KitchenApp.Exceptions.h"
#include <iostream>

// Implementation of KitchenApp.Login.h

/*For Detailed Comments..... See KitchenApp.Register.h && KitchenApp.Register.cpp*/

namespace KitchenApp::Authenticator {
    /**
     * Constructor of Log_In class
     * Opens the file containing user credentials and performs the first level of authentication
     * If the file does not exist or the connection to the file fails, it throws a UserDataFileReadingError
     * @param UserName the username of the user
     * @param Password the password of the user
     */
    Log_In::Log_In(const std::string &UserName, const std::string &Password) {
        this->UserName = UserName;
        this->Password = Password;
        FileName = "Data\\UserData\\"+UserName+"\\"+UserName;
        UserDataFile.open(FileName);
        if (!UserDataFile.is_open()) {
            throw Exceptions::UserDataFileReadingError();
        }
    }

    /**
     * Authenticates the user by reading the cred from file and verifying the same with input
     * If the verification fails, it throws a CredentialsMismatchError
     */
    void Log_In::AuthenticateUser() {
        // Since UserDataFile has only one line so we don't need any loop.
        std::string temp;
        std::getline(UserDataFile,temp); // Read the first line from UserDataFile...
        /*
         * Since, In UserDataFile the cred are stored as UserName|Password
         * We try to separate it...
         */
        const size_t pipe_pos = temp.find('|');
        const std::string UName = temp.substr(0,pipe_pos); // Extracts UserName from temp
        const std::string UPass = temp.substr(pipe_pos+1); // Extracts the Password from temp
        if (UName != UserName || UPass != Password) {
            throw Exceptions::CredentialsMismatchError();
        }
        std::cout << "User Successfully Authenticated... !";
    }


    /**
     * Destructor of Log_In class
     * Closes the UserDataFile after user authentication is done
     */
    Log_In::~Log_In() {
        UserDataFile.close();
    }
}
