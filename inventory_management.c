#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Structure to represent a product
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Array to store products
struct Product inventory[MAX_PRODUCTS];
int numProducts = 0;

// Function to add a new product to inventory
void addProduct() {
    struct Product newProduct;
    
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[numProducts++] = newProduct;
    printf("Product added to inventory successfully.\n");
}

// Function to update quantity of a product in inventory
void updateQuantity() {
    int productId, quantity;
    int found = 0;
    
    printf("Enter product ID: ");
    scanf("%d", &productId);
    printf("Enter quantity to add: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == productId) {
            inventory[i].quantity += quantity;
            printf("Quantity updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

// Function to view available products in inventory
void viewProducts() {
    if (numProducts == 0) {
        printf("No products available in inventory.\n");
    } else {
        printf("Inventory:\n");
        printf("ID\tName\tPrice\tQuantity\n");
        for (int i = 0; i < numProducts; i++) {
            printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
}

// Function to remove a product from inventory
void removeProduct() {
    int productId;
    int found = 0;
    
    printf("Enter product ID to remove: ");
    scanf("%d", &productId);
    
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == productId) {
            for (int j = i; j < numProducts - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            numProducts--;
            printf("Product removed from inventory successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    int choice;
    
    while(1) {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Update Product Quantity\n");
        printf("3. View Products\n");
        printf("4. Remove Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateQuantity();
                break;
            case 3:
                viewProducts();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
