//
// Created by Muhammad Talha on 12/15/2024.
//

#include "KitchenApp.Exceptions.h"

namespace KitchenApp::Exceptions {
    /**
     * Constructor of KitchenError class
     * @param error The error message passed here to initialize 'this->message' field.
     */
    KitchenError::KitchenError(const std::string &error) {
        message = error;
    }

    /**
     * Returns the C-style string associated with the current object.
     * @return a pointer to a null-terminated character array containing the error message.
     */
    /**
     * @brief Returns the C-style string associated with the current object.
     *
     * @details This function is overridden from the base class std::exception.
     *          It returns a pointer to a null-terminated character array
     *          containing the error message.
     *
     * @return a pointer to a null-terminated character array containing the error message.
     */
    const char * KitchenError::what() const noexcept {
        return message.c_str();
    }

    /**
     * Constructor of IntegrityError class
     * @details This constructor is used to throw an exception when the integrity of the application is compromised.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: Integrity Check Failed !".
     */
    IntegrityError::IntegrityError() : KitchenError("\nError: Integrity Check Failed !") {}

    /**
     * @brief Constructor of InvalidEmailError class
     *
     * @details This constructor is used to throw an exception when an invalid email address is provided.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: Invalid E-Mail !".
     */
    InvalidEmailError::InvalidEmailError() : KitchenError("\nError: Invalid E-Mail !") {}

    /**
     * @brief Constructor of InvalidPasswordError class
     *
     * @details This constructor is used to throw an exception when an invalid password is provided.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: Invalid Password !".
     */
    InvalidPasswordError::InvalidPasswordError() : KitchenError("\nError: Invalid Password !") {}

    /**
     * @brief Constructor of NonUniqueUserNameError class
     *
     * @details This constructor is used to throw an exception when a user tries to register with a username that already exists.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: Username Already Taken !".
     */
    NonUniqueUserNameError::NonUniqueUserNameError() : KitchenError("\nError: Username Already Taken !") {}

    /**
     * @brief Constructor of UserDataFileWritingError class
     *
     * @details This constructor is used to throw an exception when there is a failure in writing user data to a file during registration.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: User Registration Failed !".
     */
    UserDataFileWritingError::UserDataFileWritingError() : KitchenError("\nError: User Registration Failed !") {}

    /**
     * @brief Constructor of UserDataFileReadingError class
     *
     * @details This constructor is used to throw an exception when there is a failure in reading user data from a file during authentication.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: User Authentication Failed !".
     */
    UserDataFileReadingError::UserDataFileReadingError() : KitchenError("\nError: User Authentication Failed !") {}

    /**
     * @brief Constructor of CredentialsMismatchError class
     *
     * @details This constructor is used to throw an exception when the provided username or password does not match the stored credentials.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: Username Or Password Are Wrong !".
     */
    CredentialsMismatchError::CredentialsMismatchError() : KitchenError("\nError: Username Or Password Are Wrong !") {}

    /**
     * @brief Constructor of FoodDataFileReadingError class
     *
     * @details This constructor is used to throw an exception when there is a failure in reading food data from a file during the display of the menu.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: Cannot Fetch Food Contents !".
     */
    FoodDataFileReadingError::FoodDataFileReadingError() : KitchenError("\nError: Cannot Fetch Food Contents !") {}

    /**
     * @brief Constructor of FoodDataFileWritingError class
     *
     * @details This constructor is used to throw an exception when there is a failure in writing food data to a file during the process of updating the menu.
     *          It calls the constructor of the base class KitchenError and passes the error message as a parameter.
     *          The error message is "Error: Cannot Update Food Contents !".
     */
    FoodDataFileWritingError::FoodDataFileWritingError() : KitchenError("\nError: Cannot Update Food Contents !") {}

    OutOfBoundError::OutOfBoundError() : KitchenError("\nError: Out of Range Index !"){}
}
