//
// Created by Muhammad Talha on 12/18/2024.
//

#ifndef KITCHENAPP_CART_H
#define KITCHENAPP_CART_H

#include "KitchenApp.Food.h"
#include <vector>


// contains the logic to

namespace KitchenApp::CartManager {
    class Checkout {
        std::vector<FoodItem> Cart;
        void ReOrderCart();
        static void DeleteCart(const std::string& UserName);
        static std::vector<int> GetIndexOfEachPipeSeparator(const std::string& FoodString);
    public:
        void RemoveFromCart(const int& index);
        void AddToCart(const FoodItem& f);
        double GetTotalBill();
        void ResetCart();
        void PrintActiveCart();
        void SaveCart(const std::string& UserName) const;
        void LoadCart(const std::string& UserName);
        [[nodiscard]] bool CartFileExists(const std::string& UserName) const;
        [[nodiscard]] std::vector<FoodItem> GetActiveCart() const;
    };
}

#endif //KITCHENAPP_CART_H
