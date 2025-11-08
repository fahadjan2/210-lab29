#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

void display(map <string, vector<list<string>>>);
void removeEmployees(list<string> &list);
void addEmployees(list<string> &list, vector<string> names);
void changeMenu(list<string> &list, vector<string> &menuItem);
void purchaseGenerator(list<string> &list);

int main() {
    srand(time(0));
    map <string, vector<list<string>>> restaurants;
    restaurants["Italiano"].resize(3);
    
    //FILE OPENING AND POPULATING VALUES
    //File open
	ifstream file;
	file.open("data.txt");
	if (!file.is_open()) {
	    cout << "Failed to open file" << endl;
	    return 1;
	}
    //Populating values
    string value;
    int current = 0;
    while (getline(file, value)) {
        if (value == "///")
            current++;
        else
            restaurants["Italiano"][current].push_back(value);
    };
    file.close();

    //Extra file
    vector<string> names;
    vector<string> menuItems;
    ifstream file2;
	file2.open("extra.txt");
	if (!file2.is_open()) {
	    cout << "Failed to open file" << endl;
	    return 1;
	}
    //Populating name and menu items values
    current = 0;
    while (getline(file2, value)) {
        if (value == "///")
            current++;
        else if (current == 0) {
            names.push_back(value);
        } else {
            menuItems.push_back(value);
        }
    };
    file2.close();
    
    //Initial Display
    cout << "Initial Data" << endl;
    display(restaurants);

    //25 month run
    for (int i = 0; i < 25; i++) {
        cout << "Month " << i + 1 << endl;
        cout << endl;

        removeEmployees(restaurants["Italiano"][1]);
        addEmployees(restaurants["Italiano"][1], names);
        changeMenu(restaurants["Italiano"][0], menuItems);
        purchaseGenerator(restaurants["Italiano"][2]);
        cout << endl;

        cout << "\n------Restaurant details------" << endl;
        display(restaurants);
    }
    

}

//Display Function that will go through the restaurant's current data and display it neatly
void display(map <string, vector<list<string>>> restaurantData) {
    for (auto pair : restaurantData) { //Loops through every restaurant
        cout << "Restaurant name: " << pair.first << endl;
        for (int i = 0; i < pair.second.size(); i++) { //Loops through the data in each restaurant, ie list
            if (i == 0) { //First list, Menu items
                cout << "Menu Items: ";
                for (auto item : pair.second[i]) { //Loops through the list
                    cout << item << ", ";
                }
                cout << endl;
            } else if (i == 1) { //Second list, employees
                cout << "Employees: ";
                for (auto value : pair.second[i]) { //Loops through list
                    cout << value << ", ";
                }
                cout << endl;
            } else if (i == 2) { //Third List, all the purchases
                int sum = 0;
                for (auto value : pair.second[i]) { //Loops through list
                    sum += stoi(value);
                }
                cout << "Total purchases: $" << sum << endl;
            }
        }
    }
    
    cout << endl;
}

//Remove employees function, will take in the list for employees, then remove a certain amount
void removeEmployees(list<string> &employees) {
    //Removing Employees
    int num = rand() % 100 + 1;
    int removalNum = 0;
    if (num <= 10) {
        removalNum = 4;
    } else if (num <= 30) {
        removalNum = 3;
    } else if (num <= 60) {
        removalNum = 2;
    } else {
        removalNum = 1;
    }
    for (int i = 0; i < removalNum; i++) { //Removes removalNum times
        int randomNum = rand() % employees.size();
        int count = 0;
        for (auto it = employees.begin(); it != employees.end(); ++it) { //Iterator through the list, removes a random employee
            if (count == randomNum) {
                cout << *it << " quit the job." << endl;
                employees.erase(it);
                break;
            }
            count++;
        }
    }
}

//Add employee function, will go through the list of employees, and take in a vector of names, and add a certain amount of employees
void addEmployees(list<string> &employees, vector<string> names) {
    //Adding Employees
    int num = rand() % 100 + 1;
    int addNum = 0;
    if (num <= 20) {
        addNum = 3;
    } else if (num <= 50) {
        addNum = 2;
    } else {
        addNum = 1;
    }

    for (int i = 0; i < addNum; i++) { //Adds addNum times
        if (employees.size() != 20) { //If doesn't exceed 20 employees
            int randName = rand() % names.size();
            employees.push_back(names[randName]);
            cout << names[randName] << " started the job." << endl;
        }
    }
}

//Function that changes menu items, taking in the list and a vector filled with new menu Items
void changeMenu(list<string> &menu, vector<string> &menuItem) {
    int num = rand() % 3; //Number of items that will change
    for (int i = 0; i < num; i++) {
        int randomNum = rand() % menu.size(); //Random position to replace
        int randomItem = rand() % menuItem.size(); //Random menu item to take
        string tempItem;

        auto it = menu.begin();
        advance(it, randomNum);
        tempItem = *it;
        it = menu.erase(it);
        menu.insert(it, menuItem[randomItem]);

        cout << tempItem << " removed." << endl;
        cout << menuItem[randomItem] << " added." << endl;

        //Removes the menuItem from the vector and replaces it with the removed
        menuItem[randomItem] = tempItem;
    }
}

void purchaseGenerator(list<string> &purchases) {
    purchases.clear();
    int num = rand() % 300 + 401; //random number from 400-700, amount to add
    for (int i = 0; i < num; i++) {
        int randPurchase = rand() % 20 + 11; //10 - 30, random price
        purchases.push_back(to_string(randPurchase)); 
    }
}