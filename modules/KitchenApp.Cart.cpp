//
// Created by Muhammad Talha on 12/18/2024.
//

#include "KitchenApp.Cart.h"
#include "KitchenApp.Exceptions.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace KitchenApp::CartManager {

    /**
     * Reorders the items in the cart by updating their indices.
     *
     * This function iterates through the Cart and assigns a new index to each
     * FoodItem based on its position in the vector, starting from 1.
     */
    void Checkout::ReOrderCart() {
        for (int i = 0 ;i < Cart.size(); i++) {
            Cart[i].index = i+1;
        }
    }

    bool Checkout::CartFileExists(const std::string &UserName) const {
        const std::filesystem::path p = "Data\\UserData\\"+UserName+"\\CART";
        return exists(p);
    }

    void Checkout::DeleteCart(const std::string &UserName) {
        const std::filesystem::path p = "Data\\UserData\\"+UserName+"\\CART";
        std::filesystem::remove(p);
    }

    std::vector<int> Checkout::GetIndexOfEachPipeSeparator(const std::string &FoodString) {
        std::vector<int> v; // Size will be 3 , because we have three pipe separators
        for (int i = 0 ; i < FoodString.size(); i++) {
            if (FoodString.at(i)=='|')
                v.emplace_back(i);
        }
        return v;
    }

    /**
     * Removes a FoodItem from the cart by its index.
     *
     * @param index The index of the FoodItem to remove from the cart.
     *
     * @note The index is 0-based and refers to the position of the FoodItem in
     *       the cart. If the index is out of range, an
     *       Exceptions::OutOfBoundError exception is thrown.
     */
    void Checkout::RemoveFromCart(const int &index) {
        if (index > Cart.size())
            throw Exceptions::OutOfBoundError();
        Cart.erase(Cart.begin()+ index-1);
        ReOrderCart();
    }

    void Checkout::AddToCart(const FoodItem &f) {
        Cart.emplace_back(f);
        ReOrderCart();
    }

    /**
     * Calculates the total bill for all the food items in the Cart.
     *
     * This function iterates over each FoodItem in the Cart and sums up
     * their prices to compute the total bill amount.
     *
     * @return The total price of all food items in the Cart.
     */
    double Checkout::GetTotalBill() {
        double totalPrice=0;
        for (const auto& foodItem: Cart) {
            totalPrice += foodItem.price;
        }
        return totalPrice;
    }

    /**
     * Resets the cart by clearing all items from it.
     *
     * Calling this function will erase all the FoodItems currently in the
     * cart.
     */
    void Checkout::ResetCart() {
        this->Cart.clear();
    }

    /**
     * Prints the list of active FoodItems in the cart.
     *
     * This function iterates over each FoodItem in the cart and prints its
     * index, name, price and restaurant to the standard output.
     */
    void Checkout::PrintActiveCart() {
        for (const auto& item: Cart) {
            std::cout << item.index << " | Name: " << item.name << " | Rs. " << item.price << " | Available At: " << item.restaurant << "\n";
        }
    }

    void Checkout::SaveCart(const std::string &UserName) const {
        const std::filesystem::path p = "Data\\UserData\\"+UserName+"\\CART";
        std::ofstream file(p);
        std::vector<std::string> lines;
        for (const auto & item: Cart) {
            lines.emplace_back(item.name+"|"+std::to_string(item.price)+"|"+item.restaurant+"\n");
        }
        lines[lines.size()-1].pop_back(); // remove the \n from last line...
        for (const auto &line:lines)
            file<<line;
        file.close();
    }

    void Checkout::LoadCart(const std::string &UserName) {
        const std::filesystem::path p = "Data\\UserData\\"+UserName+"\\CART";
        std::ifstream file(p);
        int i = 1;
        while (!file.eof()) {
            FoodItem f;
            std::string line;
            std::getline(file,line);
            const auto v = GetIndexOfEachPipeSeparator(line);
            const std::string FoodName = line.substr(0,v[0]);
            const double FoodPrice = std::stod(line.substr(v[0]+1,v[1]));
            const std::string FoodRestaurant = line.substr(v[1]+1);
            f.index=i;
            i++;
            f.name=FoodName;
            f.price = FoodPrice;
            f.restaurant = FoodRestaurant;
            Cart.emplace_back(f);
        }
        file.close();
        DeleteCart(UserName);
    }


    /**
     * Retrieves the list of active FoodItems in the cart.
     *
     * @return A vector of FoodItem objects representing the current items
     *         in the cart.
     *
     * @note The returned vector contains the FoodItems that have been added
     *       to the cart and not yet removed or reset.
     */
    std::vector<FoodItem> Checkout::GetActiveCart() const {
        return this->Cart;
    }
}
