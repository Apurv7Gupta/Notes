// A container class is a class designed to hold and organize multiple objects of a specific type, essentially acting like a collection or a container


                                                // Container class thorugh COMPOSITION
#include <iostream>
using std::cout, std::cin, std::string, std::endl;

class Item
{
public:
    string name;
    double price;

    Item(string n, double p) : name(n), price(p) {} // or { name=n; price=p;} //This is just a constructor
};

class Container
{
private:
    Item item; // Declaration of a member of type "Item" and name "item", which is private ---> when a class has a
               //  object from another class, its called COMPOSITION

public:
    Container(string name, double price) : item(name, price) {} ////This is just a constructor

    void showItem()
    {
        cout << "Item: " << item.name << " , Price: $" << item.price << endl; // The private member can be accessed inside the class and used in a function
    }
};

int main()
{
    Container box("Laptop", 999.99);
    box.showItem(); // You can access the private member of a class through calling a function using that member
    return 0;
}

///////////////////////////////////////////////////////// With dynamic arrays /////////////////////////////////////////////////////////////////////

#include <iostream>
using std::cout, std::cin, std::string, std::endl;

class Item
{
public:
    string name;
    double price;
    Item(string n = "", double p = 0.0) : name(n), price(p) {}
};

class Container
{
private:
    Item *items;                                            /* Member declaration, where its name is "items", and it is a pointer to an array of
                                                            "Item"s */

    int size;                                               /* DYNAMIC COMPOSITION: instead of a single item, the container can hold multiple
                                                                items of size: "size" */

public:
    Container(int s) : size(s)                              // Constructor that defines size and an array named items that takes size: "size"
    {
        items = new Item[size];
    }
    void addItem(int index, string name, double price)     // Function to add an item at a specific index, the index must be >=0 and <size
    {
        if (index >= 0 && index < size)
        {
            items[index] = Item(name, price);
        }
    }
    void showItems()                                      // Function to show all the items using for loop
    {
        for (int i = 0; i < size; i++)
        {
            cout << " Item " << i + 1 << ": " << items[i].name << ", Price: $" << items[i].price << endl;
        }
    }
    ~Container()                                         /* Deletion of the Container constructor using "delete" keyword, as the Item array was
                                                            created using "new" keyword */
    {
        delete[] items;
    }
};

int main()
{
    Container box(2);
    box.addItem(0, "Phone", 799.9);
    box.addItem(1, "Tablet", 599.9);
    box.showItems();
    return 0;
}

//////////////////////////////////////////////////////// With Vector //////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

class Item
{
public:
    string name;
    double price;

    Item(string n, double p) : name(n), price(p) {}
};

class Container
{
private:
    vector<Item> items;

public:
    void addItem(string name, double price)
    {
        items.push_back(Item(name, price));
    }
    void showItems()
    {
        for (const auto &item : items)
        {
            cout << "Item: " << item.name << ", Price: $" << item.price << item.name << "endl";
        }
    }
};

int main()
{
    Container box;
    box.addItem("Mentor", 199.99);
    box.addItem("Keyboard", 49.99);
    box.showItems();
    return 0;
}