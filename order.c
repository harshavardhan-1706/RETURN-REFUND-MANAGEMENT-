#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ORDERS 100

struct Order {
    int orderId;
    char customerName[50];
    char productName[50];
    float amount;
    int isReturned;    // 0 = not returned, 1 = returned
    int isRefunded;    // 0 = not refunded, 1 = refunded
};

void addOrder(struct Order orders[], int *orderCount) {
    if (*orderCount >= MAX_ORDERS) {
        printf("Order list is full. Cannot add more orders.\n");
        return;
    }

    struct Order o;
    printf("\nEnter Order ID: ");
    scanf("%d", &o.orderId);
    getchar(); // clear newline
    printf("Enter Customer Name: ");
    fgets(o.customerName, sizeof(o.customerName), stdin);
    o.customerName[strcspn(o.customerName, "\n")] = '\0';
    printf("Enter Product Name: ");
    fgets(o.productName, sizeof(o.productName), stdin);
    o.productName[strcspn(o.productName, "\n")] = '\0';
    printf("Enter Order Amount: ");
    scanf("%f", &o.amount);

    o.isReturned = 0;
    o.isRefunded = 0;

    orders[*orderCount] = o;
    (*orderCount)++;

    printf("Order added successfully.\n");
}

int findOrderIndexById(struct Order orders[], int orderCount, int orderId) {
    for (int i = 0; i < orderCount; i++) {
        if (orders[i].orderId == orderId) {
            return i;
        }
    }
    return -1;
}

void requestReturn(struct Order orders[], int orderCount) {
    int id;
    printf("\nEnter Order ID for return request: ");
    scanf("%d", &id);

    int idx = findOrderIndexById(orders, orderCount, id);
    if (idx == -1) {
        printf("Order not found.\n");
        return;
    }

    if (orders[idx].isReturned) {
        printf("Return already requested for this order.\n");
    } else {
        orders[idx].isReturned = 1;
        printf("Return requested successfully for Order ID %d.\n", id);
    }
}

void processRefund(struct Order orders[], int orderCount) {
    int id;
    printf("\nEnter Order ID to process refund: ");
    scanf("%d", &id);

    int idx = findOrderIndexById(orders, orderCount, id);
    if (idx == -1) {
        printf("Order not found.\n");
        return;
    }

    if (!orders[idx].isReturned) {
        printf("Refund cannot be processed because return is not requested yet.\n");
        return;
    }

    if (orders[idx].isRefunded) {
        printf("Refund already processed for this order.\n");
    } else {
        orders[idx].isRefunded = 1;
        printf("Refund of Rs. %.2f processed for Order ID %d.\n", orders[idx].amount, id);
    }
}

void viewOrders(struct Order orders[], int orderCount) {
    if (orderCount == 0) {
        printf("\nNo orders available.\n");
        return;
    }

    printf("\n%-8s %-20s %-20s %-10s %-10s %-10s\n",
           "ID", "Customer", "Product", "Amount", "Returned", "Refunded");
    for (int i = 0; i < orderCount; i++) {
        printf("%-8d %-20s %-20s %-10.2f %-10s %-10s\n",
               orders[i].orderId,
               orders[i].customerName,
               orders[i].productName,
               orders[i].amount,
               orders[i].isReturned ? "Yes" : "No",
               orders[i].isRefunded ? "Yes" : "No");
    }
}

void viewPendingRefunds(struct Order orders[], int orderCount) {
    int found = 0;
    printf("\nOrders with return requested but refund not processed:\n");
    printf("%-8s %-20s %-20s %-10s\n", "ID", "Customer", "Product", "Amount");

    for (int i = 0; i < orderCount; i++) {
        if (orders[i].isReturned && !orders[i].isRefunded) {
            printf("%-8d %-20s %-20s %-10.2f\n",
                   orders[i].orderId,
                   orders[i].customerName,
                   orders[i].productName,
                   orders[i].amount);
            found = 1;
        }
    }

    if (!found) {
        printf("No pending refunds.\n");
    }
}

int main() {
    struct Order orders[MAX_ORDERS];
    int orderCount = 0;
    int choice;

    while (1) {
        printf("\n====== Return/Refund Management System ======\n");
        printf("1. Add Order\n");
        printf("2. Request Return\n");
        printf("3. Process Refund\n");
        printf("4. View All Orders\n");
        printf("5. View Pending Refunds\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addOrder(orders, &orderCount);
                break;
            case 2:
                requestReturn(orders, orderCount);
                break;
            case 3:
                processRefund(orders, orderCount);
                break;
            case 4:
                viewOrders(orders, orderCount);
                break;
            case 5:
                viewPendingRefunds(orders, orderCount);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}