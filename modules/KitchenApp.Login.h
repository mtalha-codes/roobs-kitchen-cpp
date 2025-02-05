// Created By Muhammad Talha on 14/12/2024
#ifndef KITCHENAPP_LOGIN_H
#define KITCHENAPP_LOGIN_H

#include <fstream>
// contains the logic to Log In to RoobID
namespace KitchenApp::Authenticator {
    class Log_In {
        std::ifstream UserDataFile;
        std::string UserName;
        std::string Password;
        std::string FileName;
    public:
        Log_In(const std::string& UserName,const std::string& Password);
        void AuthenticateUser();
        ~Log_In();
    };

}
#endif
