#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <cstdio>

using namespace std;
using std::string;
class Cat {
    std::string name;
    std::string breed;
    int age;
    std::string favoriteTreat;
    public:
        //contructor
        Cat(string n, string b, int a, string f): name(n),breed(b),age(a),favoriteTreat(f) {}
        //method
        void displayCatDetails() {
            std::cout << "Cat name: " << name << "\n";
            std::cout << "Cat breed: " << breed << "\n";
            std::cout << "Cat age: " << age << "\n";
            std::cout << "Cat fav treat: " << favoriteTreat << "\n";
        }
        //setter
        void setname(const string& value) {
            name = value;
        }
        void setbreed(const string& value) {
            breed = value;
        }
        void setage(int value) {
            age = value;
        }
        void settreat(const string& value) {
            favoriteTreat = value;
        }
        //getter
        string getname() {
            return name;
        }
        string getbreed() {
            return breed;
        }
        int getage() {
            return age;
        }
        string gettreat() {
            return favoriteTreat;
        }
};
/* class SpecialCat: public Cat {
    string specialSkill;
    public:

}; */
class Treat {
    string treatName;
    int quantity;
    public:
        Treat(string t, int q): treatName(t),quantity(q) {}
        int consumeTreat(int amount) {
            if (quantity-amount<0) {
                std::cout << "Error: Not enough treats, we have " << quantity << " treats";
                return -1;
            }
            else {
                quantity-=amount;
                return quantity;
            }
        }
        void displayTreatDetails() {
            std::cout << "Treat name: " << treatName << "\n";
            std::cout << "Current Quantity: " << quantity << "\n";
        }
        //setter
        void settname(const string& value) {
            treatName = value;
        }
        void setq(int value) {
            quantity = value;
        }
        //getter
        string gettname() {
            return treatName;
        }
        int getq() {
            return quantity;
        }
};

class CustomerVisit {
    string customerName;
    string catInteractedWith;
    string dateOfVisit;
    public:
        CustomerVisit(string cname, string catint, string date): customerName(cname),catInteractedWith(catint),dateOfVisit(date) {}
        void displaycustomerDetails() {
            std::cout << "Customer name: " << customerName << "\n";
            std::cout << "Cat Interacted With: " << catInteractedWith << "\n";
            std::cout << "Date Of Visit: " << dateOfVisit << "\n";
        }
};

void addcat(std::vector<Cat>& catList) {
    string name,breed, favoriteTreat;
    int age;
    std::cout << "Enter name: ";
    cin.ignore();
    getline(cin,name);
    std::cout << "Enter breed: ";
    getline(cin,breed);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter fav treat: ";
    cin.ignore();
    getline(cin,favoriteTreat); 
    Cat newCat(name,breed,age,favoriteTreat);
    catList.push_back(newCat);
    std::cout << "Added successfully!\n";
}
void displaycats(vector<Cat>& catList) {
    if (catList.size()==0) {
        std::cout << "No cats available at the moment :(\n";
    }
    std::cout << "------------\n";
    for (Cat& cat: catList) {
        cat.displayCatDetails();
        std::cout << "------------\n";
    }
}
void addTreat(std::vector <Treat>& treatList) {
    string treatName;
    int quantity;

    std::cout << "Enter Treat name: ";
    cin.ignore();
    getline(cin,treatName);

    std::cout << "Enter quantity: ";
    cin >> quantity;

    Treat newTreat(treatName,quantity);
    treatList.push_back(newTreat);
    std::cout << "Added successfully!\n";
}

void consume(std::vector<Treat>& treatList) {
    string treatToConsume;
    int amountToConsume;

    cout << "Enter the treat name to consume: ";
    cin.ignore();
    getline(cin, treatToConsume);

    bool found = false;
    for (size_t i = 0; i < treatList.size(); ++i) {
        if (treatList[i].gettname() == treatToConsume) {
            found = true;
            cout << "Enter the quantity to consume: ";
            cin >> amountToConsume;

            int remaining = treatList[i].consumeTreat(amountToConsume);
            if (remaining >= 0) {
                cout << "Consumed " << amountToConsume << " " << treatList[i].gettname() << " treats.\n";
                treatList[i].setq(remaining);
                treatList[i].displayTreatDetails();
            }
            break;
        }
    }

    if (!found) {
        cout << "Treat not found in the menu.\n";
    }
}

void logCustomerVisit(std::vector<CustomerVisit>& customerList) {
    string customerName;
    string catInteractedWith;

    std::cout << "Enter Customer Name: ";
    std::cin.ignore();
    getline(cin,customerName);

    std::cout << "Cat Interacted With: ";
    std::cin.ignore();
    getline(cin,catInteractedWith);

    std::string dateInput;
    int day, month, year;
    std::cout << "Enter visit of date in format DD-MM-YYYY: ";
    if (scanf("%d-%d-%d", &day, &month, &year) != 3) {
        std::cout << "Invalid date format. Please enter in dd-mm-yyyy format.\n";
        return;
    }
    std::string dateOfVisit = std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
    CustomerVisit newCustomer(customerName, catInteractedWith, dateOfVisit);
    customerList.push_back(newCustomer);
    std::cout << "Customer Logged successfully!\n";
}

void displayVisit(std::vector<CustomerVisit>& customerList) {
    if (customerList.size()==0) {
        std::cout << "No logged visits at the moment :(\n";
    }
    std::cout << "------------\n";
    for (CustomerVisit& customer: customerList) {
        customer.displaycustomerDetails();
        std::cout << "------------\n";
    }
}
int main() {
    std::cout << "Welcome to our Cat Cafe \nHere's our Menu\n";
    std::vector<Cat> catList;
    std::vector<Treat> treatList;
    std::vector<CustomerVisit> customerList;
    int n;

    do {
        std::cout << "1. Add a new cat\n"; 
        std::cout << "2. Display all cats\n"; 
        std::cout << "3. Add treats\n";     
        std::cout << "4. Consume treats\n";  
        std::cout << "5. Log a customer visit\n";  
        std::cout << "6. Display all visits\n";  
        std::cout << "7. Exit\n";            
        std::cout << "Choose an option: ";
        std::cin >> n;
            switch (n) {
                case 1:
                    addcat(catList);
                    break;
                case 2:
                    displaycats(catList);
                    break;
                case 3:
                    addTreat(treatList);
                    break;
                case 4:
                    consume(treatList);
                    break;
                case 5:
                    logCustomerVisit(customerList);
                    break;
                case 6:
                    displayVisit(customerList);
                    break;
                case 7:
                    cout << "Exiting...\nThank you for visiting";
                    break;
                default:
                    cout << "Invalid choice! Please Enter your choice again\n";
                    /* break; */
            }
    } while (n!=7);
}