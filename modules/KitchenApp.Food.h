//
// Created by Muhammad Talha on 12/18/2024.
//

#ifndef KITCHENAPP_FOOD_H
#define KITCHENAPP_FOOD_H
#include <string>

struct FoodItem { // Think of food as structure having properties defined below
    std::string name; // Name of that food.
    std::string restaurant; // Available in that restaurant.
    double price; // having this cost price.
    int index; // found at this index in the menu.
    FoodItem() : price(0) , index(0) {} // Constructor to initialize fields price and index.
};
#endif //KITCHENAPP_FOOD_H
