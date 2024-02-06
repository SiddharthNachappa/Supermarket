#include<iostream>
#include<iomanip>
using namespace std;

struct Date {
    int mm, dd, yy;
};

class Item {
    int itemNo;
    char name[25];
    Date manufacturingDate;

public:
    void addItem();
    void showItemDetails();
};

class Amount : public Item {
    float price, quantity, tax, discount, netAmount;

public:
    void calculate();
    void displayBill();
};

void Item::addItem() {
    cout << "\n\nEnter Item No: ";
    cin >> itemNo;
    cout << "Enter Name of the item: ";
    cin.ignore(); // Clear buffer before reading string
    cin.getline(name, 25);
    cout << "Enter Manufacturing Date (dd-mm-yy): ";
    cin >> manufacturingDate.mm >> manufacturingDate.dd >> manufacturingDate.yy;
}

void Item::showItemDetails() {
    cout << "\nItem No: " << itemNo;
    cout << "\nName of the item: " << name;
    cout << "\nManufacturing Date: " << manufacturingDate.mm << "-" << manufacturingDate.dd << "-" << manufacturingDate.yy;
}

void Amount::calculate() {
    cout << "\nEnter Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter Tax percent: ";
    cin >> tax;
    cout << "Enter Discount percent: ";
    cin >> discount;

    // Calculate net amount
    float gross = price + (price * (tax / 100));
    netAmount = quantity * (gross - (gross * (discount / 100)));
}

void Amount::displayBill() {
    showItemDetails();
    cout << "\nNet amount: " << netAmount;
}

int main() {
    Amount amt;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout << setprecision(2);

    // Menu loop
    while (true) {
        cout << "\n\n1. Add Item Details";
        cout << "\n2. Display Bill";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                amt.addItem();
                amt.calculate();
                cout << "\nItem Added Successfully!";
                break;

            case 2:
                amt.displayBill();
                break;

            case 3:
                cout << "\nExiting program. Thanks!";
                return 0;

            default:
                cout << "\nInvalid choice. Please try again.";
        }
    }

    return 0;
}
