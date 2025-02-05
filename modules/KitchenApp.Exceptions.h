//
// Created by Muhammad Talha on 12/15/2024.
//

#ifndef KITCHENAPP_EXCEPTIONS_H
#define KITCHENAPP_EXCEPTIONS_H

#include <exception>
#include <string>


namespace KitchenApp::Exceptions {
    /**
     * KitchenError class is the base class from which all the exceptions associated to KitchenApp are derived.
     */
    class KitchenError : public std::exception {
        std::string message;
    public:
        explicit KitchenError(const std::string& error); // explicit means single argument, think of explicit argument as explicit algebraic functions
        [[nodiscard]] const char *what() const noexcept override; //[[nodiscard]] forces the compiler like "isko halka mat lo"...
    };

    /**
     * @class IntegrityError
     * @brief This exception is thrown when the app detects any change in the files/folders it uses.
     *        This is done to ensure the integrity of the app.
     */

    class IntegrityError : public KitchenError {
    public:
        IntegrityError();
    };

    /**
     * @class InvalidEmailError
     * @brief This exception is thrown when the app receives an invalid email address during user authentication.
     */
    class InvalidEmailError : public KitchenError {
    public:
        InvalidEmailError();
    };
    /**
     * @class InvalidPasswordError
     * @brief This exception is thrown when the app receives an invalid password during user authentication.
     */
    class InvalidPasswordError : public KitchenError {
    public:
        InvalidPasswordError();
    };

    /**
     * @class NonUniqueUserNameError
     * @brief This exception is thrown when the app attempts to register a user with a username that already exists in the database.
     */
    class NonUniqueUserNameError : public KitchenError {
    public:
        NonUniqueUserNameError();
    };

    /**
     * @class UserDataFileWritingError
     * @brief This exception is thrown when there is a failure in writing user data to a file during the process of user registration.
     */
    class UserDataFileWritingError : public KitchenError {
    public:

        UserDataFileWritingError();
    };
    /**
     * @class UserDataFileReadingError
     * @brief This exception is thrown when there is a failure in reading user data from a file during the process of user authentication.
     */
    class UserDataFileReadingError : public KitchenError {
    public:
        UserDataFileReadingError();
    };
    /**
     * @class CredentialsMismatchError
     * @brief This exception is thrown when the app compares the provided username and password with the stored credentials, and they do not match.
     */
    class CredentialsMismatchError : public KitchenError
    {
    public:

        CredentialsMismatchError();
    };
    /**
     * @class FoodDataFileWritingError
     * @brief This exception is thrown when there is a failure in writing food data to a file during the process of updating the menu.
     */
    class FoodDataFileReadingError : public KitchenError {
    public:

        FoodDataFileReadingError();
    };
    /**
     * @class FoodDataFileReadingError
     * @brief This exception is thrown when there is a failure in reading food data from a file during the display of the menu.
     */
    class FoodDataFileWritingError : public KitchenError {
    public:
        FoodDataFileWritingError();
    };
    class OutOfBoundError : public KitchenError {
    public:
        OutOfBoundError();
    };
}

#endif //KITCHENAPP_EXCEPTIONS_H
