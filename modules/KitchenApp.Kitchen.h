// Created by Muhammad Talha on 15/12/2024.

// This file contains the logic to load food from file so that I can use it in the codebase and the user can order some food.
#ifndef KITCHENAPP_MENU_H
#define KITCHENAPP_MENU_H

#include <filesystem>
#include "KitchenApp.Food.h" // contains the struct fooditem
#include <fstream>
#include <vector>

namespace KitchenApp::Kitchen {
    /**
     * class FoodMenu, have the logic to populate menu from file...  In your case from DB.
     */
    class FoodMenu {
        std::vector<FoodItem> FoodList;
        std::ifstream FoodDataFile;
        static std::vector<int> GetIndexOfEachPipeSeparator(const std::string& FoodString);
        void FillFoodList();
    public:
        FoodMenu();
        void PrintFoodList() const;
        std::vector<FoodItem> GetFoodList();
        FoodItem GetFoodInstance(const int& index);
        ~FoodMenu();
    };
}

#endif //KITCHENAPP_MENU_H
