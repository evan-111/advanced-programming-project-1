#include "header.h"

int main() {        
    MENU menu[20];
    int count = 0;
    int orderId = 1;
    ORDER orders[20];
    int orderCount = 0;
    loadMenu(menu, count);
    time_t timestamp;
    time(&timestamp);
    double pay = 0.00;
    double change = 0.00;
    double realTotal = 0.0;
    int tableNum;

    char moreCustomers = 'y';
    while(moreCustomers == 'y' || moreCustomers == 'Y'){
        double currentCost=0.00;
        cout << "\nEnter Table Number: ";
        cin >> tableNum;
        if(tableNum<=0){
            cout<<"invalid table number(must be more than 0)";
            continue;
        }

        bool ordering = true;
        while (ordering) {
            displayMenu(menu, count);
            ordering = placeOrders(menu, count, orders, orderCount, orderId, tableNum,currentCost);
        }

        cout<<endl;
        
        generateReceipt(menu, count, orders, orderCount, orderId,tableNum);
        paying(orders, orderCount, orderId, pay, change);
        recordReceipt(menu, count, orders, orderCount, orderId,pay,change);
        cout << "next customer? (y/n): ";
        cin >> moreCustomers;
        orderId++;
    }
    
    cout << "system shutting down"<<endl;
    return 0;
}
