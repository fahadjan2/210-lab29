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
    
    cout << "Initial Data" << endl;
    display(restaurants);

    //25 month run
    for (int i = 0; i < 25; i++) {
        cout << "Month " << i + 1 << endl;

        removeEmployees(restaurants["Italiano"][1]);
        addEmployees(restaurants["Italiano"][1], names);
        changeMenu(restaurants["Italiano"][0], menuItems);

        cout << "\n------Restaurant details------" << endl;
        display(restaurants);
        
        

        int num = rand() % 300 + 201;
        for (int i = 0; i < num; i++) {

        }
    
        //Randomize a percentage of how many employees will leave, 1-100. 
        //40% that one will leave, 30% that 2 will leave, 20% that 3 will leave, 10% that 4 will leave

        //Randomize a percentage of how many employees will be hired, 1-100. If over a certain limit of employees, then add none or the max 
        //50% that one will join, 30% that 2 will join, 20% that 3 will join

        //Randomize a number from 0-3 to represent how many menu items will change.
        //Change accordingly, and pick a menu item from another menu text file

        //Randomize a number from 200-500 to represent how many purchases will be made
        //The cost will then be randomly generated from 10-30 and added to the purchase list
        
        //Display call
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
                cout << "Total purchases: " << sum << endl;
            }
        }
    }
    
    cout << endl;
}


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
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (count == randomNum) {
                employees.erase(it);
                cout << *it << "quit the job." << endl;
                break;
            }
            count++;
        }
    }
}

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
        int randName = rand() % names.size();
        employees.push_back(names[randName]);
        cout << randName << " started the job." << endl;
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

        //Removes the menuItem from the vector and replaces it with the removed
        menuItem[randomItem] = tempItem;
    }
}