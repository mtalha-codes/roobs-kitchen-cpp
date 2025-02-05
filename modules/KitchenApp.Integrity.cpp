//
// Created by Muhammad Talha on 12/15/2024.
//

#include "KitchenApp.Integrity.h"
#include <filesystem>
#include <fstream>
#include "KitchenApp.Exceptions.h"

namespace KitchenApp::Integrity {
    /**
     * This function checks if all the necessary folders for the app are created
     * if not it creates them and then throws an IntegrityError
     * @throws IntegrityError if the folders don't exist
     * @throws FoodDataFileWritingError if the food data file cannot be written
     */
    void IntegrityCheck::CheckForMissingFolders() {
        const std::filesystem::path RootDir = std::filesystem::current_path().string()+"\\Data\\";
        const std::filesystem::path UserDataDir = RootDir.string()+"UserData\\";
        const std::filesystem::path FoodDataDir = RootDir.string()+"FoodData\\";
        if (exists(RootDir) && exists(UserDataDir) && exists(FoodDataDir)) {
            // If everything is okay
            // Don't Create Any Folders
            // Overwriting Folders May Lead To Performance Degrade
            return; // return early and skips the following guide...
        }
        std::filesystem::create_directory(RootDir);
        std::filesystem::create_directory(UserDataDir);
        std::filesystem::create_directory(FoodDataDir);
        std::string FoodDataFileName = FoodDataDir.string()+"\\FoodList";
        std::ofstream FoodDataFile(FoodDataFileName);
        if (!FoodDataFile.is_open()) {
            throw Exceptions::FoodDataFileWritingError();
        }
        FoodDataFile << "Burger|150|Tikkala\n";
        FoodDataFile << "Shwarma|300|Tikkala\n";
        FoodDataFile << "Regular Fries|250|McDonald\'s\n";
        FoodDataFile << "Zinger Burger|400|KFC\n";
        FoodDataFile << "Paratha Roll|650|KPK Pizza Hut";
        FoodDataFile.close();
        throw Exceptions::IntegrityError();
    }

}
