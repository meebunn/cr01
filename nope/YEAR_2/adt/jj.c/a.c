#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_item 100
struct item
{
    char itemname[50];
    int quantity;
    float price;
};

int main()
{
    // Variable Declaration
    struct item stock[max_item];
    int choice, itemcount = 0, i, j, requantity, emoji1 = 1;
    float calprice[100], allprice = 0, reprice;
    // Menu Page
    while (1)
    {
        printf("* * * * *Stock Management System* * * * *\n");

        printf("*\t1. Add Item into Stock          *\n");
        printf("*\t2. Check your Stock             *\n");
        printf("*\t3. Calculate the price summary  *\n");
        printf("*\t4. Exit the Program             *\n");
        printf("* * * * * * * * * * * * * * * * * * * * * \n");
        printf(" \tChoose the option 1 - 4          \n");
        printf("Caution : You need to choose option 2 before option 3\n");
        printf("\tYour choice : ");
        scanf("%d", &choice);
        // All case
        switch (choice)
        {
        case 1:
            if (itemcount < max_item)
            {
                char newItemName[50];
                int found = 0;

                printf("\nEnter The Product Detail\n");
                printf("Name : ");
                scanf("%s", newItemName);

                // Check if the item has already in stock
                for (i = 0; i < itemcount; i++)
                {
                    if (strcmp(newItemName, stock[i].itemname) == 0)
                    {
                        found = 1;
                        printf("\n!!!Item already exists!!! Pls Enter additional quantity and price\n");
                        printf("Additional Quantity : ");
                        scanf("%d", &requantity);
                        printf("Additional Price : ");
                        scanf("%f", &reprice);

                        // Update quantity and price
                        stock[i].quantity += requantity;
                        stock[i].price += reprice;
                        printf("\nItem is Updated to your Stock\n\n");
                        break;
                    }
                }
                if (!found)
                {
                    // Add a new item
                    strcpy(stock[itemcount].itemname, newItemName);
                    printf("Quantity : ");
                    scanf("%d", &stock[itemcount].quantity);
                    printf("Price : ");
                    scanf("%f", &stock[itemcount].price);
                    itemcount++;
                    printf("\nItem Added into your Stock\n\n");
                }
            }
            else
            {
                // If reach to Maximum Item
                printf("Your Stock is full. Cannot add more items!!!\n");
            }
            break;
        // If User choose Wrong choice
        default:
            printf("Invalid choice. Please enter a valid option.\n\n");
            break;
            // Display Item in Stock and Calculate Price
        case 2:
            // Have Items in Stock
            if (itemcount > 0)
            {
                printf("\n* * * * * * * * * * *In Stock* * * * * * * * * * * *\n");
                for (i = 0; i < itemcount; i++)
                {
                    printf("| Item %d\n", i + 1);
                    printf("|\tName : %s \n", stock[i].itemname);
                    printf("|\tQuantity : %d \n", stock[i].quantity);
                    printf("|\tPrice : %.2f \n", stock[i].price);
                    calprice[i] = stock[i].quantity * stock[i].price;
                    allprice = allprice + calprice[i];
                    printf("|\tSummary Price for this Product : %.2f\n", calprice[i]);
                    printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
                }
            }
            // Nothing in Stock
            else
            {
                printf("There is no Item in your Stock???\n\n");
            }
            break;
            // Display summary
        case 3:
            printf("----------------------------------\n\n");
            printf("Total Products Price : %.2f %c\n\n", allprice, emoji1);
            printf("----------------------------------\n\n");
            break;
            // Exit from the Program
        case 4:
            printf(".......Closing The Program.......");
            return 0;
        }
    }
}
