//
// Created by Muhammad Talha on 12/15/2024.
//

#ifndef KITCHENAPP_FILESYSTEM_H
#define KITCHENAPP_FILESYSTEM_H



namespace KitchenApp::Integrity {
    /**
     * IntegrityCheck class:
     * Contains logic to verify app integrity
     * here we mean the folder and files we need to maintain the proper functionality of the app.
     */
    class IntegrityCheck {
    public:
        /**
         * Perform checks for the missing folders and files, if they don't exist it creates
         * and then throw KitchenApp::Exceptions::IntegrityError.
         */
        static void CheckForMissingFolders(); // static , to call it directly without creating object...
    };
}
#endif //KITCHENAPP_FILESYSTEM_H
