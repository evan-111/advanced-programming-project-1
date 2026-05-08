#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <limits>
using namespace std;
//all explanation is in README.md
struct MENU{
    int MENUId;
    string MenuName;
    double Price;
    int MenuQuantity;
};

struct ORDER{
    int OrderId;
    int TableNum;
    int menuId;
    int OrderQuantity;
    double TotalCost;

};

void loadMenu(MENU menu[], int &count);
void displayMenu(MENU menu[], int count);
bool placeOrders(MENU menu[], int count, ORDER orders[], int &orderCount, int OrderId, int TableNum,double &currentCost);
void generateReceipt(MENU menu[],int count,ORDER orders[], int orderCount, int OrderId,int tableNum);
void paying(ORDER orders[], int orderCount, int orderId, double &pay, double &change);
void recordReceipt(MENU menu[], int count, ORDER order[], int orderCount, int OrderId,double pay,double change);
#endif



