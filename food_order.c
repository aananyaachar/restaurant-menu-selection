#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotels {
    char hotel[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    char fourth_food[25];
    int first, second, third, fourth;
};

struct hotels m[5];
int total = 0;

void cart();
void search_by_hotels();
void search_by_food();
void food_order(int food);
void hotel_initialize();
void hotels(int hotel_choice);
void paymentoption();


int choice, hotel_choice, food_choice, n, ch, confirm, food, hotel_id;

int main() {
    hotel_initialize(); 

    while (1) {
        printf("\n\n**************** Welcome to Food Ordering System ****************");
        printf("\n\n1) SEARCH BY FOOD\n");
        printf("2) SEARCH BY HOTEL\n");
        printf("3) EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                search_by_food();
                break;
            case 2:
                search_by_hotels();
                break;
            case 3:
                printf("\n**************** Thank you! Visit again *******************\n");
                exit(0);
            default:
                printf("\nPlease enter a valid choice.\n");
        }
    }
}

void hotel_initialize() {
    strcpy(m[1].hotel, "Ocean Pearl");
    strcpy(m[1].first_food, "Sandwich");
    strcpy(m[1].second_food, "Pizza");
    strcpy(m[1].third_food, "Fried Rice");
    m[1].first = 70;
    m[1].second = 100;
    m[1].third = 95;

    strcpy(m[2].hotel, "Panchami");
    strcpy(m[2].first_food, "Parotta");
    strcpy(m[2].second_food, "Noodles");
    strcpy(m[2].third_food, "Chicken Rice");
    m[2].first = 15;
    m[2].second = 75;
    m[2].third = 80;

    strcpy(m[3].hotel, "Meheraan");
    strcpy(m[3].first_food, "Three Naan");
    strcpy(m[3].second_food, "Prawn");
    strcpy(m[3].third_food, "Falooda");
    m[3].first = 90;
    m[3].second = 120;
    m[3].third = 35;
}

void search_by_hotels() {
    while (1) {
        printf("\n\nPlease choose a hotel:\n");
        printf("1. %s\n", m[1].hotel);
        printf("2. %s\n", m[2].hotel);
        printf("3. %s\n", m[3].hotel);
        printf("4. Cart\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &hotel_choice);

        if (hotel_choice == 4) {
            cart();
            return;
        } else if (hotel_choice == 5) {
            return;
        } else if (hotel_choice >= 1 && hotel_choice <= 3) {
            hotels(hotel_choice);
        } else {
            printf("Invalid choice. Please select a valid hotel.\n");
        }
    }
}

void hotels(int hotel_choice) {
    while (1) {
        printf("\nList of foods available in %s:\n", m[hotel_choice].hotel);
        printf("1. %s\t\t%d\n", m[hotel_choice].first_food, m[hotel_choice].first);
        printf("2. %s\t\t%d\n", m[hotel_choice].second_food, m[hotel_choice].second);
        printf("3. %s\t\t%d\n", m[hotel_choice].third_food, m[hotel_choice].third);
        printf("4. Cart\n");
        printf("5. Back to Hotels\n");
        printf("\nEnter your choice: ");
        scanf("%d", &food_choice);

        if (food_choice == 4) {
            cart();
            return;
        } else if (food_choice == 5) {
            return;
        } else if (food_choice >= 1 && food_choice <= 3) {
            printf("Enter the count of %s: ", 
                   food_choice == 1 ? m[hotel_choice].first_food : 
                   food_choice == 2 ? m[hotel_choice].second_food : 
                   m[hotel_choice].third_food);
            scanf("%d", &n);

            total += n * (food_choice == 1 ? m[hotel_choice].first : 
                          food_choice == 2 ? m[hotel_choice].second : 
                          m[hotel_choice].third);
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }
}
//function to search for food 
void search_by_food() {
    while (1) {
        printf("\n\nAvailable foods:\n");
        printf("1. %s\t\t%d\n", m[1].first_food, m[1].first);
        printf("2. %s\t\t%d\n", m[1].second_food, m[1].second);
        printf("3. %s\t\t%d\n", m[1].third_food, m[1].third);
        printf("4. %s\t\t%d\n", m[2].first_food, m[2].first);
        printf("5. %s\t\t%d\n", m[2].second_food, m[2].second);
        printf("6. %s\t\t%d\n", m[2].third_food, m[2].third);
        printf("7. %s\t\t%d\n", m[3].first_food, m[3].first);
        printf("8. %s\t\t%d\n", m[3].second_food, m[3].second);
        printf("9. %s\t\t%d\n", m[3].third_food, m[3].third);
        printf("10. Cart\n");
        printf("11. Back to Main Menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &food);

        if (food == 10) {
            cart();
            return;
        } else if (food == 11) {
            return; 
        } else if (food >= 1 && food <= 9) {
            food_order(food);
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }
}

//function to order food
void food_order(int food) {
    int hotel_id = (food - 1) / 3 + 1; 
    int food_id = (food - 1) % 3 + 1;

    printf("Enter the count of %s: ", 
           food_id == 1 ? m[hotel_id].first_food : 
           food_id == 2 ? m[hotel_id].second_food : 
           m[hotel_id].third_food);
    scanf("%d", &n);

    total += n * (food_id == 1 ? m[hotel_id].first : 
                  food_id == 2 ? m[hotel_id].second : 
                  m[hotel_id].third);
}

//cart function
void cart() {
    printf("\n\n************* Cart ***************\n");
    printf("Your total order amount is: %d\n", total);
    printf("Do you wish to place the order? Press 1 for Yes, 0 for No: ");
    scanf("%d", &ch);

    if (ch == 1) {
        paymentoption();
        printf("\n\nThank you for your order! Your food is on the way.\n\n");
        exit(0);
    } else if (ch == 0) {
        printf("Order cancelled. Returning to main menu...\n");
    } else {
        printf("Invalid choice. Returning to cart.\n");
        cart();
    }
}

void paymentoption() {
    char cardDetails[50];
    long int upiNumber;
    int paymentchoice;

    printf("\nSelect payment option\n 1. UPI \n 2. Cash on Delivery \n 3. Card \n");
    scanf("%d", &paymentchoice);

    switch (paymentchoice) {
        case 1:
            printf("Enter UPI Number: ");
            scanf("%ld", &upiNumber);
            break;
        case 2:
            printf("Cash On Delivery Selected\n");
            break;
        case 3:
            printf("Enter Card Details: ");
            scanf("%s", cardDetails);
            break;
        default:
            printf("Invalid payment choice.\n");
    }
}
