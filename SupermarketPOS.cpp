//
//  main.cpp
//  asd
//
//  Created by Akshit Patel on 12/1/19.
//  Copyright © 2019 Akshit Patel. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


//---------------------------------------------------------------------------------------------------------- POINT OF SALE FUNCTIONS
//Parent Point of Sale Class
class POS {
private:
    string productName;
    string category;
    double price;
    int quantity;
    int expiry;
public:
    POS(string productName, string category, double price, int quantity, int expiry);
    POS();
    int getQuantity();
    void setQuantity(int quantity);
    string getProductName();
    void setProductName(string productName);
    string getCategory();
    void setCategory(string category);
    double getPrice();
    void setPrice(double price);
    int getExpiry();
    void setExpiry(int expiry);

    virtual void print();
};
//------------------------------
//Point of Sale  constructor
POS::POS(string theProduct, string theCategory, double thePrice, int theQuantity, int theExpiration) {
    this->productName = theProduct;
    this->category = theCategory;
    this->price = thePrice;
    this->quantity = theQuantity;
    this->expiry = theExpiration;
}
//------------------------------
//Default constructor
POS::POS() {
    productName = "null";
    category = "Category";
    price = 0.0;
    quantity = 0;
    expiry = 0;
}
//------------------------------
//Return Quantity
int POS::getQuantity() {
    return quantity;
}
//------------------------------
//Set Quantity
void POS::setQuantity(int quantity) {
    this->quantity = quantity;
}
//------------------------------
// Return Product Name
string POS::getProductName() {
    return productName;
}
//------------------------------
//Set Product Name
void POS::setProductName(string productName) {
    this->productName = productName;
}
//------------------------------
//Return Category (Fruit or Veggie)
string POS::getCategory() {
    return category;
}
//------------------------------
//Set Category (Fruit or Veggie)
void POS::setCategory(string category) {
    this->category = category;
}


int POS::getExpiry() {
    return expiry;
}

void POS::setExpiry(int expiry) {
    this->expiry = expiry;
}


//------------------------------
//Return Price
double POS::getPrice() {
    return price;
}
//------------------------------
//Set Price
void POS::setPrice(double price) {
    this->price = price;
}
//------------------------------
//Print Product Details
void POS::print() {
    cout << "-----------------------------" << endl;
    cout << "Product: " << productName << endl;
    cout << "Category: " << category << endl;
    cout << "Quantity in Stock: " << quantity << endl;
    cout << "Price: $" << price << endl;
    cout << "Expiration Date: " << expiry << endl;
    cout << "-----------------------------" << endl;
}
//---------------------------------------------------------------------------------------------------------- END POINT OF SALE FUNCTIONS

//---------------------------------------------------------------------------------------------------------- BEGIN CATEGORIES
//--------------------------------------------------------------------------------------------FRUIT CATEGORY
// Fruit Class
class Fruit : public POS {
public:
    Fruit(string productName, double price, int quantity, int expiry);
    Fruit();

};
//------------------------------
//Fruit Constructor
Fruit::Fruit(string productName, double price, int quantity, int expiry) {
    setProductName(productName);
    setCategory("Fruit");
    setPrice(price);
    setQuantity(quantity);
    setExpiry(expiry);

}
//------------------------------
//Default Constructor
Fruit::Fruit() {
    setProductName("null");
    setCategory("Fruit");
    setPrice(0.0);
    setQuantity(0);
    setExpiry(0);
}

//----------------------------------------------------------------------------------------END FRUIT CATEGORY
//----------------------------------------------------------------------------------------VEGETABLE CATEGORY
//Vegetable Class
class Vegetable : public POS {
private:
    int ExpiryDate;
public:
    Vegetable(string productName, double price, int quantity, int expiry);
    Vegetable();
};
//------------------------------
//Vegetable Constructor
Vegetable::Vegetable(string productName, double price, int quantity, int expiry) {
    setProductName(productName);
    setCategory("Veggie");
    setPrice(price);
    setQuantity(quantity);
    setExpiry(expiry);
}

//Default Constructor
Vegetable::Vegetable() {
    setProductName("null");
    setCategory("Veggie");
    setPrice(0.0);
    setQuantity(0);
    setExpiry(0);
}

//------------------------------------------------------------------------------------END VEGETABLE CATEGORY
//--------------------------------------------------------------------------------------------JUICE CATEGORY
//Juice Class
class Juice : public POS {
private:
    int ExpiryDate;
public:
    Juice(string productName, double price, int quantity, int expiry);
    Juice();
};
//------------------------------
//Vegetable Constructor
Juice::Juice(string productName, double price, int quantity, int expiry) {
    setProductName(productName);
    setCategory("Juice");
    setPrice(price);
    setQuantity(quantity);
    setExpiry(expiry);
}
//------------------------------
//Default Constructor
Juice::Juice() {
    setProductName("null");
    setCategory("Juice");
    setPrice(0.0);
    setQuantity(0);
    setExpiry(0);
}

//----------------------------------------------------------------------------------------END JUICE CATEGORY
//---------------------------------------------------------------------------------------------------------- END CATEGORY FUNCTIONS



//---------------------------------------------------------------------------------------------------------- MENU FUNCTION
void printMenu() {
    cout << "----------MENU----------" << endl;
    cout << "1. Search Products" << endl;
    cout << "2. Sell Products" << endl;
    cout << "3. Return Products" << endl;
    cout << "4. Add a Product" << endl;
    cout << "5. Update a Product" << endl;
    cout << "6. Check Expiring Products (EXTRA CREDIT)" << endl;
    cout << "7. Exit" << endl;
}

//---------------------------------------------------------------------------------------------------------- CHECK PRODUCT NAME
bool checkProductName(string productName, vector<POS*>& list) {
    bool check = false;
    for (int i = 0; i < list.size(); i++) {
        if ((*list[i]).getProductName() == productName) {
            (*list[i]).print();
            check = true;
        }
    }

    return check;
}
//---------------------------------------------------------------------------------------------------------- CHECK CATEGORY
bool checkCategory(string category, vector<POS*>& list) {
    bool check = false;
    //for loop that increments through all the values in the vector to check for the matching category
    for (int i = 0; i < list.size(); i++)
        if ((*list[i]).getCategory() == category) {
            check = true;
            (*list[i]).print();
        }
    if (check == false) {
        cout << "Category not found." << endl;
    }
    return check;
}

//---------------------------------------------------------------------------------------------------------- CHECK EXPIRATION

bool checkExpirationDate(int expiry, vector<POS*>& list) { //Using
    bool check = false;
    //for loop that increments through all the values in the vector to check for expiration date matching up
    for (int i = 0; i < list.size(); i++)
        if ((*list[i]).getExpiry() == expiry) {
            check = true;
            (*list[i]).print();
    }
    return check;
}

//---------------------------------------------------------------------------------------------------------- MAIN FUNCTION OF PROGRAM

int main() {
    //Vector of Foods in the list
    vector<POS*> FoodList;
    //Vector of Foods that were sold
    vector<POS*> soldList;
    // Variables to search for the products based on chosen variable inputs.
    int choice, searchChoice, categoryChoice;
    //Variables for adding products & updating.
    string  addProductName;
    int addQuantity, addChoice, addExpiry, addFruitExpiration, addJuiceExpiration, expirationDate;
    double addPrice;
    bool loop = true;
    string productNameSearch, productName;


    // Sample List of 10 items. For testing purposes,
    FoodList.push_back(new Fruit("Apple", 1.00, 1, 1));
    FoodList.push_back(new Fruit("Pear", 2.00, 1, 2));
    FoodList.push_back(new Fruit("Grapes", 5.00, 1, 3));
    FoodList.push_back(new Fruit("Watermelon", 10.00, 1, 4));
    FoodList.push_back(new Fruit("Banana", 10, 1, 5));
    FoodList.push_back(new Vegetable("Carrots", 3.00, 1, 6));
    FoodList.push_back(new Vegetable("Kale", 6.00, 1, 7));
    FoodList.push_back(new Vegetable("Spinach", 8.00, 1, 8));
    FoodList.push_back(new Vegetable("Celery", 2.50, 1, 9));
    FoodList.push_back(new Vegetable("Cucumber", 2.99, 1, 10));
    FoodList.push_back(new Juice("AppleJ", 25.00, 1, 11));
    FoodList.push_back(new Juice("CranberryJ", 26.00, 1, 12));
    FoodList.push_back(new Juice("OrangeJ", 27.00, 1, 13));
    FoodList.push_back(new Juice("PineappleJ", 28.00, 1, 14));
    FoodList.push_back(new Juice("GrapeJ", 29.00, 1, 15));




    cout << "---------- POS Supermarket Application ---------" << endl;
    cout << "---------      Coded by Ak Patel       ---------" << endl;
    cout << endl;


    //Infinite loop to print menu
    do {
        printMenu();
        cout << endl;
        cout << "Select your option:  ";
        cin >> choice;
        switch (choice) {
        case 1:            // 1. Search Products
        {
            cout << "1. Search by Name" << endl;
            cout << "2. Search by Category" << endl;
            cout << "3. List All Products" << endl;
            cout << "Please Enter your Option: ";
            cin >> searchChoice;
            if (searchChoice == 1) {
                cout << "Enter Name: ";
                cin >> productNameSearch;
                cout << endl;
            

                if (checkProductName(productNameSearch, FoodList) != true) {
                    cout << "Product not found." << endl;
                }
                else
                    cout << endl;

                break;
            }

            else if (searchChoice == 2) {
                cout << "You've selected to search by Category. \n1. Veggie \n2. Fruit \n3. Juice" << endl;
                cout << "Your selection: ";
                cin >> categoryChoice;
                cout << endl;                //Input for category, then says if 1, print that checkCategory, then if 2, then if 3.
                if (categoryChoice == 1) {
                    checkCategory("Veggie", FoodList);
                }
                else if (categoryChoice == 2) {
                    checkCategory("Fruit", FoodList);
                }
                else if (categoryChoice == 3) {
                    checkCategory("Juice", FoodList);
                }
                else {
                    cout << "There is no such category." << endl;
                }
                break;
            }
            else if (searchChoice == 3)
            {
                cout << "All Products: \n";
                checkCategory("Fruit", FoodList);
                checkCategory("Veggie", FoodList);
                checkCategory("Juice", FoodList);

            }
            else {
                cout << "Error: You can only search by name or category. Please try again." << endl;
                break;
            }
            break;
        }

        case 2:        //2. Sell Products
        {
            cout << "Enter the product you wish to sell: ";
            cin >> productName;
            bool findSell1 = checkProductName(productName, FoodList);
            //Makes sure that the productName exists
            if (findSell1 == true) {
                //for loop to increment through list, find the product
                for (int i = 0; i < FoodList.size(); i++) {
                    if ((*FoodList[i]).getProductName() == productName) {
                        //Pushes food from Inventory to SoldList
                        soldList.push_back(FoodList[i]);
                        FoodList.erase(FoodList.begin() + i);
                        cout << productName << " has been sold." << endl;
                    }
                }
                break;
            }
            else {
                cout << "This product either does not exist or has not been returned.\nReturning to Main Menu." << endl;
                break;
            }
        }
        case 3:        //3. Return Products
        {
            cout << "Enter The Product you wish to return: ";
            cin >> productName;
            bool findCase3 = checkProductName(productName, soldList);
            if (findCase3 == true) {
                for (int i = 0; i < soldList.size(); i++) {
                    if ((*soldList[i]).getProductName() == productName) {
                        //Puts Food back from soldList to FoodList
                        FoodList.push_back(soldList[i]);
                        soldList.erase(soldList.begin() + i);
                        cout << productName << " has been returned." << endl;
                    }
                }
                break;
            }
            else {
                cout << "This product either does not exist or has not been sold.\nReturning to Main Menu." << endl;
                break;
            }
        }
        case 4:        //4. Add a Product
        {
            cout << "Enter Product Name:";
            cin >> addProductName;
            cout << "Enter price: $";
            cin >> addPrice;
            cout << "Enter Quantity:";
            cin >> addQuantity;
            cout << "Is the product a Veggie, a Fruit, or a Juice?" << endl;
            cout << "1. Veggie" << endl;
            cout << "2. Fruit" << endl;
            cout << "3. Juice" << endl;
            cout << "Your Selected Option: ";
            cin >> addChoice;
            //For Veggies
            if (addChoice == 1) {
                cout << "Enter Number of Days before Expiry: ";
                cin >> addExpiry;
                bool checkVeggie = checkProductName(addProductName, FoodList);
                if (checkVeggie == false) {
                    FoodList.push_back(new Vegetable(addProductName, addPrice, addQuantity, addExpiry));
                    cout << "Vegetable added." << endl;
                }
                else
                    cout << "Vegetable already exists." << endl;
                break;
            }
            //For Fruit
            else if (addChoice == 2) {
                cout << "Enter Number of Days before Expiry: ";
                cin >> addFruitExpiration;
                bool checkFruit = checkProductName(addProductName, FoodList);
                if (checkFruit == false) {
                    FoodList.push_back(new Fruit(addProductName, addPrice, addQuantity, addFruitExpiration));
                    cout << "Fruit added." << endl;
                }
                else
                    cout << "Fruit already exists." << endl;
                break;
            }

            //For Juice
            else if (addChoice == 3) {
                cout << "Enter Number of Days before Expiry: ";
                cin >> addJuiceExpiration;
                bool checkJuice = checkProductName(addProductName, FoodList);
                if (checkJuice == false) {
                    FoodList.push_back(new Juice(addProductName, addPrice, addQuantity, addJuiceExpiration));
                    cout << "Juice added." << endl;
                }
                else
                    cout << "Juice already exists." << endl;
                break;
            }

            else {
                cout << "Invalid input." << endl;
                break;
            }
        }

        case 5:        //5. Update the file
        {
            cout << "Enter the product you wish to update: ";
            cin >> productName;
            bool findSell1 = checkProductName(productName, FoodList);
            //Makes sure that the productName exists
            if (findSell1 == true) {
                cout << "Product Found! " << endl;
                //for loop to increment through list and find selection
                for (int i = 0; i < FoodList.size(); i++) {
                    if ((*FoodList[i]).getProductName() == productName) {
                        //Pushes food from Inventory to SoldList

                        FoodList.erase(FoodList.begin() + i);
                        cout << "Enter Updated Product Name:";
                        cin >> addProductName;
                        cout << "Enter Updated Price: $";
                        cin >> addPrice;
                        cout << "Enter Updated Quantity:";
                        cin >> addQuantity;
                        cout << "Is the product a Veggie, Fruit, or a Vegetable?" << endl;
                        cout << "1. Veggie" << endl;
                        cout << "2. Fruit" << endl;
                        cout << "3. Juice" << endl;
                        cout << "Selected Option: ";
                        cin >> addChoice;
                        //For Veggies
                        if (addChoice == 1) {
                            cout << "Enter Number of Days before Expiry: ";
                            cin >> addExpiry;
                            bool checkVeggie = checkProductName(addProductName, FoodList);
                            if (checkVeggie == false) {
                                FoodList.push_back(new Vegetable(addProductName, addPrice, addQuantity, addExpiry));
                                cout << "Vegetable has been updated." << endl;
                            }
                            else
                                cout << "Error! This Vegetable could not be updated. File may have been deleted." << endl;
                            break;
                        }
                        //For Fruit
                        else if (addChoice == 2) {
                            cout << "Enter Number of Days before Expiry: ";
                            cin >> addFruitExpiration;
                            bool checkFruit = checkProductName(addProductName, FoodList);
                            if (checkFruit == false) {
                                FoodList.push_back(new Fruit(addProductName, addPrice, addQuantity, addFruitExpiration));
                                cout << "Fruit updated." << endl;
                            }
                            else
                                cout << "Error! This Fruit could not be updated. File may have been deleted." << endl;
                            break;
                        }

                        else if (addChoice == 3) {
                            cout << "Enter Number of Days before Expiry: ";
                            cin >> addJuiceExpiration;
                            bool checkJuice = checkProductName(addProductName, FoodList);
                            if (checkJuice == false) {
                                FoodList.push_back(new Fruit(addProductName, addPrice, addQuantity, addJuiceExpiration));
                                cout << "Juice updated." << endl;
                            }
                            else
                                cout << "Error! This Juice could not be updated. File may have been deleted." << endl;
                            break;
                        }
                        else {
                            cout << "Invalid Update Trial." << endl;
                            break;
                        }

                        cout << productName << " has been Updated." << endl;
                    }

                }

            }
            else
                cout << "Uh Oh! Product doesn't exist" << endl;
            break;
        }



        case 6: // Show which products are about to expire
        {
            cout << "Enter the date you wish to search for: ";
            cin >> expirationDate;

        
            for (int i = 0; i <= expirationDate; i++) {

                checkExpirationDate(i, FoodList);
            }

            
            break;
        }


        case 7:        //6. Exit and close file.
        {
            cout << "You've chosen to exit the POS Software." << endl;
            system("Pause");
            return 1;
        }
        default:
        {
            cout << "Invalid input." << endl;
        }
        }

    } while (loop == true);


    return 0;
}

