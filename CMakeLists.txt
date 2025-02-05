cmake_minimum_required(VERSION 3.30)
project(Kitchen_App)
set(CMAKE_CXX_STANDARD 20)


add_executable(
        KitchenApp main.cpp
        modules/KitchenApp.Register.h
        modules/KitchenApp.Register.cpp
        modules/KitchenApp.Login.cpp
        modules/KitchenApp.Login.h
        modules/KitchenApp.Kitchen.cpp
        modules/KitchenApp.Kitchen.h
        modules/KitchenApp.Integrity.cpp
        modules/KitchenApp.Integrity.h
        modules/KitchenApp.Exceptions.cpp
        modules/KitchenApp.Exceptions.h
        modules/KitchenApp.Cart.cpp
        modules/KitchenApp.Cart.h
        modules/KitchenApp.Food.h
        modules/ms-dos/conio.cpp
        modules/ms-dos/conio.h
)
