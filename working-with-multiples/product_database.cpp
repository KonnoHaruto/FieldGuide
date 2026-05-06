#include "splashkit.h"
#include "splashkit-arrays.h"
#include "utilities.h"

const int NO_CHOICE = -1;

enum menu_option
{
    ADD_PRODUCT = 1,
    DELETE_PRODUCT = 2,
    UPDATE_PRODUCT = 3,
    SELL_PRODUCT = 4,
    PRINT_STATUS = 5,
    LIST_PRODUCTS = 6,
    QUIT = 7
};

enum update_product_option
{
    UPDATE_NAME = 1,
    UPDATE_COST_PRICE = 2,
    UPDATE_SALE_PRICE = 3,
    UPDATE_STOCK = 4,
    UPDATE_QUIT = 5
};

struct product_data
{
    string name;
    double cost_price;
    double sale_price;
    int stock;
};

struct store_data
{
    dynamic_array<product_data> products;
    double total_sales;
    double total_profits;
};

void print_main_menu()
{
    write_line("Main Menu");
    write_line("1. Add a new product");
    write_line("2. Delete a product");
    write_line("3. Update a product");
    write_line("4. Sell a product");
    write_line("5. Print status");
    write_line("6. List products");
    write_line("7. Quit");
}

void print_update_menu()
{
    write_line("Update Menu");
    write_line("1. Update name");
    write_line("2. Update cost price");
    write_line("3. Update sale price");
    write_line("4. Update number in stock");
    write_line("5. Quit update");
}

void print_product(const product_data &product)
{
    write_line("name: " + product.name);
    write_line("cost price: " + to_string(product.cost_price));
    write_line("sale price: " + to_string(product.sale_price));
    write_line("stock: " + to_string(product.stock));
}

product_data read_product()
{
    product_data product;

    write_line("Please fill in the product details\n");
    do{
        product.name = read_string("Enter product name: ");
    } while (length_of(product.name) == 0);

    product.cost_price = read_double("Enter cost price: ");
    product.sale_price = read_double("Enter sale_price: ");
    product.stock = read_integer("Enter stock of product: ");

    return product;
}

void add_product(store_data &store)
{
    product_data product;
    product = read_product(); 

    add(store.products, product);

    write_line("Product '" + product.name + "' added to store.");
}

void list_products(const store_data &store)
{
    dynamic_array<product_data> products = store.products;

    for (int i = 0; i < length(products); i++)
    {
        write(to_string(i + 1) + ". ");
        print_product(products[i]);
    }
}

int find_product(const store_data &store)
{
    if (length(store.products) == 0)
    {
        write_line("No products added yet.");
        return NO_CHOICE;
    }

    string searching_text = read_string("Enter text to search for: ");
    bool found_product = false;

    for (int i = 0; i < length(store.products); i++)
    {
        if (contains(store.products[i].name, searching_text))
        {
            write_line(to_string(i + 1) + ". " + store.products[i].name);
            found_product = true;
        }
    }

    if(!found_product)
    {
        write_line("No matching products.");
        return NO_CHOICE;
    }

    int index = read_integer("Select a products: ", 1, length(store.products)) - 1;

    if(!contains(store.products[index].name, searching_text))
    {
        write_line("Invalid selection.");
        return NO_CHOICE;
    }
    return index;
}

void sell_product(store_data &store)
{
    dynamic_array<product_data> products = store.products;

    if (length(products) == 0)
    {
        write_line();
    }
    list_products(store);

    // index is read by find_product procedure. 
    // int index = read_integer("Please select the products you want to buy: ");
    int index = find_product(store);
    if(index == NO_CHOICE) return;

    if(products[index].stock == 0)
    {
        write_line("No stock available for this product.");
        return;
    }

    int units = read_integer("Enter number of units sold: ", 0, products[index].stock);

    double sale_total = products[index].sale_price * units;
    double cost_total = products[index].cost_price * units;
    double profit_total = sale_total - cost_total;

    store.products[index].stock -= units;
    store.total_sales += sale_total;
    store.total_profits += profit_total;

    write_line("Sold " + to_string(units) + " units");
    write_line("Revenue: " + to_string(sale_total, 2) + ", Profit: $" + to_string(profit_total, 2));
}

void delete_product(store_data &store)
{
    // list_products(store);
    // write_line("");

    // in this case, use find_product procedure. tbh, find_product is much complicated for user cause
    // everytime they need to imagine what item is included in the lists.

    // int index = read_integer("Enter the item you want to delete: ");
    // string deleted_item = store.products[index - 1].name;
    // remove(store.products, index - 1);

    // write_line(deleted_item + " was deleted from the store");
    // list_products(store);

    int index = find_product(store);
    if(index == NO_CHOICE) return;

    string name = store.products[index].name;
    remove(store.products, index);

    write_line("Deleted '" + name + "'");
}

void print_status(const store_data &store)
{
    double stock_value = 0;
    int low_stock = 0;

    for (int i = 0; i < length(store.products); i++)
    {
        stock_value += store.products[i].cost_price * store.products[i].stock;

        if (store.products[i].stock < 10)
            low_stock++;
    }

    write_line("== Store Report ==");
    write_line("Total sales:     $" + to_string(store.total_sales, 2));
    write_line("Total profit:    $" + to_string(store.total_profits, 2));
    write_line("Products:        "  + to_string(length(store.products)));
    write_line("Stock value:     $" + to_string(stock_value, 2));
    write_line("Low stock (<10): "  + to_string(low_stock));
}

void update_product(store_data &store)
{
    int index = find_product(store);
    if (index == NO_CHOICE)
        return;

    update_product_option option;
    do
    {
        write_line("Current details:");
        print_product(store.products[index]);
        write_line("");
        print_update_menu();

        option = update_product_option(read_integer("Enter an option: ", 1, 5));

        switch (option)
        {
        case UPDATE_NAME:
            store.products[index].name = read_string("Enter new name: ");
            write_line("Updated name.");
            break;
        case UPDATE_COST_PRICE:
            store.products[index].cost_price = read_double("Enter new cost price: ");
            write_line("Updated cost price.");
            break;
        case UPDATE_SALE_PRICE:
            store.products[index].sale_price = read_double("Enter new sale price: ");
            write_line("Updated sale price.");
            break;
        case UPDATE_STOCK:
            store.products[index].stock = read_integer("Enter new amount in stock: ");
            write_line("Updated amount of stock.");
            break;
        case UPDATE_QUIT:
            break;
        }
    } while (option != UPDATE_QUIT);
}

int main()
{
    store_data store = {};
    write_line("Welcome to Product Database!");

    menu_option option;
    do {
        print_main_menu();
        option = menu_option(read_integer("Please choose an option: ", 1, 7));

        switch (option)
        {
            case ADD_PRODUCT:
                add_product(store);
                break;
            case DELETE_PRODUCT:
                delete_product(store);
                break;
            case UPDATE_PRODUCT:
                // To implement
                break;
            case SELL_PRODUCT:
                sell_product(store);
                break;
            case PRINT_STATUS:
                print_status(store);
                break;
            case LIST_PRODUCTS:
                list_products(store);
                break;
            case QUIT:
                break;
        }
    } while (option != QUIT);

    write_line("Thank you for using!");
}