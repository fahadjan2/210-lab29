#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

void display(map <string, vector<list<string>>>);

int main() {
    srand(time(0));
    map <string, vector<list<string>>> restaurants;

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
    while (file >> value) {
        if (value == "")
            current++;
        restaurants["Italiano"][current].push_back(value);
    };

    file.close();

    for (int i = 0; i < 25; i++) {
        cout << "Month " << i << endl;
        int num = rand() % 100 + 1;
        if (num <= 10) {
            //4
        } else if (num <= 30) {
            //3
        } else if (num <= 60) {
            //2
        } else {
            //1
        }
        
        num = rand() % 100 + 1;
        if (num <= 20) {
            //3
        } else if (num <= 50) {
            //2
        } else {
            //1
        }

        num = rand() % 3;
        for (int i = 0; i < num; i++) {

        }

        num = rand() % 300 + 201;
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
    int count = 0;
    for (auto pair : restaurantData) {
        cout << "Restaurant name: " << pair.first << endl;
        
        if (count == 0) {
            cout << "Menu Items: ";
            for (auto value : pair.second) {
                cout << value << endl;
            }
            count++;
        } else if (count == 1) {
            cout << "Employees: ";
            for (auto value : pair.second) {
                cout << value << endl;
            }
            count++;
        } else if (count == 2) {
            int sum = 0;
            for (auto value : pair.second) {
                sum += stoi(value);
            }
            cout << "Total purchases: " << sum << endl;
        }
            
    }
    
    cout << endl;
}