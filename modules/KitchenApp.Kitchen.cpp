// Created by Muhammad Talha on 15/12/2024.


#include "KitchenApp.Kitchen.h"

#include <iostream>
#include <pstl/algorithm_fwd.h>

#include "KitchenApp.Exceptions.h"

namespace KitchenApp::Kitchen {
    /**
     * Returns a vector of integers representing the indices of each '|'
     * character in the given FoodString.
     *
     * The returned vector will have a size of 3, as there are 3 '|' characters
     * in a FoodString in the correct format.
     *
     * @param FoodString A string representing a food item.
     * @return A vector of integers representing the indices of each '|'
     * character in the given FoodString.
     */
    std::vector<int> FoodMenu::GetIndexOfEachPipeSeparator(const std::string &FoodString) {
        std::vector<int> v; // Size will be 3 , because
        for (int i = 0 ; i < FoodString.size(); i++) {
            if (FoodString.at(i)=='|')
                v.emplace_back(i);
        }
        return v;
    }

    /**
     * Constructs a FoodMenu object and initializes the FoodDataFile.
     *
     * When a FoodMenu object is constructed, the FoodDataFile is opened
     * and a check is performed to see if the file was opened successfully.
     * If the file was not opened successfully, an exception of type
     * FoodDataFileReadingError is thrown.
     */
    FoodMenu::FoodMenu() {
        FoodDataFile.open("Data\\FoodData\\FoodList");
        if (!FoodDataFile.is_open())
            throw Exceptions::FoodDataFileReadingError();
        this->FillFoodList();
    }

    /**
     * Fills the FoodList vector by reading from the file located at
     * "Data\\FoodData\\FoodList".
     *
     * This function assumes that the file is in the following format:
     * Name|Price|Restaurant , and each food item is on a new line.
     *
     * If the file is not in the correct format, or if the file does not
     * exist, an exception of type FoodDataFileReadingError is thrown.
     */
    void FoodMenu::FillFoodList() {
        int i=1;
        FoodItem f;
        while (!FoodDataFile.eof()) {
            std::string temp_str;
            std::getline(FoodDataFile,temp_str);
            std::vector<int> v = GetIndexOfEachPipeSeparator(temp_str);
            const std::string FoodName = temp_str.substr(0,v[0]);
            const double FoodPrice = std::stod(temp_str.substr(v[0]+1,v[1]));
            const std::string FoodRestaurant = temp_str.substr(v[1]+1);
            f.index=i;
            i++;
            f.name=FoodName;
            f.price = FoodPrice;
            f.restaurant = FoodRestaurant;
            FoodList.emplace_back(f);
        }
    }

    /**
     * Prints the list of FoodItems in the FoodList.
     *
     * This function iterates over each FoodItem in the FoodList and prints its
     * index, name, price and restaurant to the standard output.
     */
    void FoodMenu::PrintFoodList() const {
        for (const auto& item: FoodList) {
            std::cout << item.index << " | Name: " << item.name << " | Rs. " << item.price << " | Available At: " << item.restaurant << "\n";
        }
    }

    /**
     * Returns a copy of the FoodList.
     *
     * This function returns a copy of the FoodList, which is a vector of
     * FoodItem objects. The returned vector can be used to iterate over the
     * list of food items available in the kitchen.
     *
     * @return A copy of the FoodList.
     */
    std::vector<FoodItem> FoodMenu::GetFoodList() {
        return FoodList;
    }

    FoodItem FoodMenu::GetFoodInstance(const int &index) {
        FoodItem f;
        bool found;
        for (const auto& fInstance : FoodList) {
            if (index == fInstance.index) {
                f = fInstance;
                found=true;
                break;
            }
        }
        if (!found)
            throw Exceptions::OutOfBoundError();
        return f;
    }

    /**
     * Destructor of FoodMenu class.
     *
     * This function is the destructor of the FoodMenu class. It is called
     * when an object of type FoodMenu is destroyed. The destructor is
     * responsible for closing the file opened by the constructor.
     */
    FoodMenu::~FoodMenu() {
        FoodDataFile.close();
    }
}
