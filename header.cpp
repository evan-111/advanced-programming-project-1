#include "header.h"

void loadMenu(MENU menu[], int &count){
   ifstream menuFile("Menu.txt");
    if(!menuFile) {
        cerr<<"Error opening file."<<endl;
        return ;
    }
    
    string line;
    count = 0;
    while(getline(menuFile, line)){
        stringstream ss(line);
        string MenuIdSTR;
        string MenuNameSTR;
        string PriceSTR; 
        string QuantitySTR;
           
        getline(ss, MenuIdSTR, ',');
        getline(ss, MenuNameSTR, ';');
        getline(ss, PriceSTR, '&');
        getline(ss, QuantitySTR);

        menu[count].MENUId = stoi(MenuIdSTR);
        menu[count].MenuName = MenuNameSTR;
        menu[count].Price = stod(PriceSTR);
        menu[count].MenuQuantity = stoi(QuantitySTR);
        count++;
    }
    menuFile.close();
}

void displayMenu(MENU menu[], int count){

    cout << "---------------------- UOW FOOD MENU -----------------------"<<endl;
    cout << left<< setw(2) << "Id" << "| "
         << left << setw(25) << "Name"
         << fixed << setprecision(2) << " Price"<<endl;

    for (int i = 0; i < count; i++) {
        if(menu[i].MenuQuantity>0){
            cout << left<< setw(2) << menu[i].MENUId << "| "
                 << left << setw(25) << menu[i].MenuName
                 << " RM " << fixed << setprecision(2) << menu[i].Price
                 <<" (Quantity: " << menu[i].MenuQuantity << ")" << endl;
        }
        else{
            cout << left<< setw(2) << menu[i].MENUId << "| "
                 << left << setw(25) << menu[i].MenuName
                 << " RM " << fixed << setprecision(2) << menu[i].Price
                 << " (Quantity: out of stock)" << endl;
        }    
    }
}
    
bool placeOrders(MENU menu[], int count, ORDER orders[], int &orderCount, int OrderId,int TableNum,double &currentCost) {
    int menuId;
    int quantity;

    cout<<endl;
    cout << "Please enter the Menu ID you want to order (Enter 0 to finish order): ";
    cin >> menuId;

    if (menuId == 0)
        return false;

    cout << "Please enter the quantity: ";
    cin >> quantity;

    for (int i = 0; i < count; i++) {
        if (menuId==menu[i].MENUId) {
            if (quantity <= menu[i].MenuQuantity) {
                menu[i].MenuQuantity -= quantity;
                orders[orderCount].OrderId = OrderId;
                orders[orderCount].menuId = menuId;
                orders[orderCount].TableNum = TableNum;
                orders[orderCount].OrderQuantity = quantity;
                orders[orderCount].TotalCost = menu[i].Price * quantity;
                currentCost += orders[orderCount].TotalCost;
                orderCount++;

                cout << "Your order is added!" << endl;
                cout << "Current total cost: RM " << currentCost << endl;
                cout<<endl;

                return true;
            } else {
                cout << "Apologies, not enough quantity available." << endl;
                return true;
            }
        }
    }
    cout << "Invalid Menu ID, please input only the Menu ID from the menu." << endl;
    return true;
}

void generateReceipt(MENU menu[], int count, ORDER order[], int orderCount, int OrderId, int tableNum){
    time_t timestamp;
    time(&timestamp);
    cout << "Final order for table " << tableNum << " (Order ID #" << OrderId << ")"<<" "<<ctime(&timestamp);
    cout<<"***************** Customer Receipt ********************"<<endl;
    cout << left << setw(10) << "Quantity"
         << setw(18) << "    Name"
         << setw(10) << "Price"
         << right << setw(10) << "Total" << endl;
    cout << "*******************************************************"<<endl;

    double realTotal=0;
    for(int i=0;i<orderCount;i++){
        if (order[i].OrderId == OrderId){
            for(int j=0;j<count;j++){
                if(order[i].menuId == menu[j].MENUId){
                    double itemTotal = order[i].TotalCost;
                    realTotal +=itemTotal;
                    cout << left << setw(10)<<order[i].OrderQuantity
                        << setw(18) << menu[j].MenuName
                        << "RM" <<setw(10) <<left<<menu[j].Price
                        << right << setw(5) <<"RM"<< itemTotal<<endl;
                }
            }
        }
    }
    cout<<endl;
    cout<<"Total Amount Due: RM "<<realTotal<<endl;
}

void paying(ORDER orders[], int orderCount, int orderId, double &pay, double &change){
    double realTotal=0.00;

    for (int i = 0; i < orderCount; i++) {
            if (orders[i].OrderId == orderId){
                realTotal += orders[i].TotalCost;
            }
        }
        do {
            cout << "Enter payment amount (RM): ";
            cin >> pay;

            if (pay < realTotal) {
                cout <<"not enough money. Please enter at least RM " << realTotal << "." << endl;
            } 
            else {
                change = pay - realTotal;
            }
        } while (pay < realTotal);

        cout << "Payment succesful. Change: RM " << change << endl;
}

void recordReceipt(MENU menu[], int count, ORDER order[], int orderCount, int OrderId,double pay,double change){
    double realTotal = 0;
    time_t timestamp;
    time(&timestamp);
    ofstream out("receipt History.txt", ios::app);

    if(out){
        int tableNum = 0;
        for (int i=0;i<orderCount;++i) {
            if (order[i].OrderId == OrderId) {
                tableNum = order[i].TableNum;
                break;
            }
        }

        out<< "Final order for table " << tableNum << " (Order ID #" << OrderId << ")"<<" "<<ctime(&timestamp);
        out<<"***************** Customer Receipt ********************"<<endl;
        out << left << setw(10) << "Quantity"
            << setw(18) << "      Name"
            << setw(10) << "Price"
            << right << setw(10) << "Total" << endl;
        out << "*******************************************************"<<endl;

        for (int i=0;i<orderCount;++i) {
            if (order[i].OrderId == OrderId){
                for(int j=0;j<count;j++){
                    if(order[i].menuId == menu[j].MENUId){
                    double itemTotal = order[i].TotalCost;
                    realTotal +=itemTotal;
                    out << left << setw(10)<<order[i].OrderQuantity
                        << setw(18) << menu[j].MenuName
                        << "RM" <<setw(10) <<left<<menu[j].Price
                        << right << setw(5) <<"RM"<< itemTotal<<endl;

                    }
                }
            }
        }
    }
    
    out<<"Total Amount Due: RM "<<realTotal<<endl;
    out << "Payment Received: RM " << pay << endl;
    out << "Change Given: RM " << change << endl;
    out<<endl;
    out.close();
}