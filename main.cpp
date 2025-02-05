// Created By Muhammad Talha on 14/12/2024

#include <algorithm>

#include "modules/KitchenApp.Register.h" // For Logic To Registering a User.
#include "modules/KitchenApp.Login.h" // For Authenticating with Stored User Data for successful login.
#include "modules/KitchenApp.Exceptions.h" // For Roob's Kitchen App Related Errors.
#include "modules/KitchenApp.Integrity.h" // For Verifying App Integrity at the start of main function.
#include "modules/ms-dos/conio.h" // For Look & Feel of #include<conio.h> from MS-DOS's Turbo C++
#include "modules/KitchenApp.Kitchen.h" // For Loading and Getting Available Food List.
#include "modules/KitchenApp.Cart.h" // For Cart Management.

#include <iostream>
#include <memory> // for std::make_unique, these pointers from modern c++

using namespace KitchenApp::Authenticator;
using namespace KitchenApp::Exceptions;
using namespace KitchenApp::Integrity;
using namespace KitchenApp::Kitchen;
using namespace KitchenApp::CartManager;





/**
 * The main function is the entry point of Roob's Kitchen App.
 * It displays a menu with options to Login, Register, or Exit the app.
 * Depending on the user's choice, it will call the respective function.
 * If the user chooses to login, it will authenticate the user and then
 * display the main menu which has options to select food, place an order,
 * and exit the app.
 * If the user chooses to register, it will register the user and then
 * display the main menu.
 * If the user chooses to exit, it will exit the app.
 * The main function also handles exceptions that may be thrown during
 * the execution of the app.
 * \return 0 if the app executes successfully, EXIT_FAILURE otherwise.
 */
int main() {
    clrscr();
    try {
        IntegrityCheck::CheckForMissingFolders();
    } catch (const IntegrityError& e) {
        std::cerr << "Exception Caught: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    } catch (const FoodDataFileWritingError& e) {
        std::cerr << "Exception Caught: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    while (true) {
        clrscr();
        int choice;
        std::cout << "\t\t**************************\n\t\t   Roob's Kitchen App\n\t\t**************************\n\n";
        std::cout << "\t\t    Authentication Menu  \n\n";
        std::cout << "1. Login ?\n2. New User? Register !\n3. Exit Roob's Kitchen App !\n\nEnter Choice:";
        std::cin >> choice;
        std::string Password,UserName;
        if (choice == 1) {
            try {
                clrscr();
                std::cin.ignore(); // ignore newline buffer
                std::cout << "\t\t**************************\n\t\t   Roob's Kitchen App\n\t\t**************************\n";
                std::cout << "\t\t    Login Form:\n\n";
                std::cout << "Enter UserName: ";
                std::getline(std::cin,UserName);
                std::cout << "Enter Password: ";
                std::getline(std::cin,Password);
                const auto login_class = std::make_unique<Log_In>(UserName,Password);
                login_class->AuthenticateUser();
            } catch (const UserDataFileWritingError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
            catch (const CredentialsMismatchError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
            catch (const UserDataFileReadingError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
            const auto food_stock = std::make_unique<FoodMenu>();
            const auto cart_manager = std::make_unique<Checkout>();
            try {
                main_menu:
                clrscr();
                if (cart_manager->CartFileExists(UserName)) {
                    cart_manager->LoadCart(UserName);
                }
                int MChoice;
                std::cout << "\t\t**************************\n\t\t   Roob's Kitchen App\n\t\t**************************\n";
                std::cout << "Welcome " << UserName << " !\t\t\t\tPayment Method: Cash on delivery\n";
                std::cout << "\t\t     Main Menu:\n\n";
                std::cout << "1.Select Food By Index (Add To Cart)\n";
                std::cout << "2.Deselect Food By Index (Remove From Cart)\n";
                std::cout << "3.Place Order (See Total Bill & Cart)\n";
                std::cout << "4.Exit Roob's Kitchen App\n\nEnter Choice:";
                std::cin >> MChoice;
                /*
                 * IMPORTANT NOTE
                 * You must implement mechanism to save the cart to database if user haven't placed order and exit the app.
                 * so upon the next restart, the cart must be loaded from database.
                 * Here we implement with the help of file....
                 */
                if (MChoice==1) {
                    AddToCartMenu:
                    clrscr();
                    food_stock->PrintFoodList();
                    int index;
                    std::cout << "\n\nEnter Index of Food to Add to Cart (-1 to go back) : ";
                    std::cin >> index;
                    if (index==-1) goto main_menu;
                    cart_manager->AddToCart(food_stock->GetFoodInstance(index));
                    goto AddToCartMenu;
                }
                else if (MChoice==2) {
                    RemoveFromCart:
                    if (cart_manager->GetActiveCart().empty()) {
                        clrscr();
                        std::cout << "Cart is Empty !\nPress Any Key To Go Back !";
                        getch();
                        goto main_menu;
                    }
                    clrscr();
                    cart_manager->PrintActiveCart();
                    int index;
                    std::cout << "\n\nEnter Index of Food to Remove from Cart (-1 to go back) : ";
                    std::cin >> index;
                    if (index==-1) goto main_menu;
                    cart_manager->RemoveFromCart(index);
                    goto RemoveFromCart;
                }
                else if (MChoice==3) {
                    if (cart_manager->GetActiveCart().empty()) {
                        clrscr();
                        std::cout << "Cart is Empty !\nPress Any Key To Go Back !";
                        getch();
                        goto main_menu;
                    }
                    clrscr();
                    std::cout << "You Are About to Purchase The Following Food Items:\n";
                    cart_manager->PrintActiveCart();
                    std::cout << "\nTotal Bill: " << cart_manager->GetTotalBill() << std::endl;
                    std::cout << "\nPress Any Key To Confirm Order !"; // In your real app , you implement yes/no with confirm message box.
                    getch();
                    std::cout << "Order Successfully Placed !\n\n";
                    cart_manager->ResetCart();
                    std::cout << "Press any key to go back !";
                    getch();
                    goto main_menu;
                }
                else if (MChoice==4) {
                    if (!cart_manager->GetActiveCart().empty()) {
                        cart_manager->SaveCart(UserName);
                    }
                    break;
                }
                else
                    goto main_menu;
            }
            catch (const FoodDataFileReadingError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
            catch (const OutOfBoundError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (choice == 2) {
            try {
                clrscr();
                std::cin.ignore(); // ignore newline buffer.
                std::cout << "\t\t**************************\n\t\t   Roob's Kitchen App\n\t\t**************************\n\n";
                std::cout << "Register Form:\n\n";
                std::string FName,LName,EMail;
                std::cout << "Enter First Name: ";
                std::getline(std::cin,FName);
                std::cout << "Enter Last Name: ";
                std::getline(std::cin,LName);
                std::cout << "Enter E-Mail: ";
                std::getline(std::cin,EMail);
                std::cout << "Enter UserName: ";
                std::getline(std::cin,UserName);
                std::cout << "Enter Password: ";
                std::getline(std::cin,Password);
                const auto R = std::make_unique<Register>(FName,LName,EMail,Password,UserName);
                R->RegisterUser();
            } catch (const UserDataFileWritingError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            } catch (const InvalidEmailError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            } catch (const InvalidPasswordError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            } catch (const NonUniqueUserNameError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            } catch (const CredentialsMismatchError& e) {
                std::cerr << "Exception Caught: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (choice==3)
            break;
        else {
            // left empty
            // to restart the loop...
        }
    }
    getch();
    return 0;
}