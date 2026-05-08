header.h 
in the header.h file I included all the library i need for the program which is:

1. iostream for input output(of course la).
2. fstream for facilitation of files for Menu.txt and receipt history.txt
3. string for conveninet way to handle sequnce of characters
4. sstream for me to break the format of the Menu.txt file into the format i want, you can find it at loadMenu function in header.cpp which is ss.
5. iomanip for me to format the menu and receipt into better looking design
6. ctime for me to include a time and date at the receipt, i heard it from miss bridget that a receipt should have it , which i cant argue

the header.h also includes my declaration struct for MENU and ORDER for data organizations, it also includes the function from implemntation so that my main file can retrive it.

header.cpp
the header.cpp file contains all the function implemntation which consist of:
1. loadMenu to load and retrive the data from Menu.txt 
2. displayMenu to display they menu in the form that i want for easy reading by users(i tried mixing both load and read together and end up keep having a bug where the menu keeps being the original so i have to seperate it, i also got to find out that you can use getline for integer just have to do a different way)
3. place orders for users to add food into there order or receipt and also keep track of there current cost .
4. generateReceipt for generating a receipt for the users to confirm there order (i got the idea of the receipt from my local mamak store)
5. paying for customer to pay the orders that they made.(initially i dont have this function but i heard from miss bridget how the hell did you get the receipt if you dont pay which also the same paying concept from the mamak store)
6. recrodReceipt for keeping a record of generated recript adn save it in 'record History.txt'(the format and code is very similar to the generateReceipt function just a bit of tweak. I also forgot that in ofstream you have to replcae cout for out or else it will not record it.)

driver.cpp
the driver.cpp is where my main function is and some the variable needed for the system to work is here like the threashold of the menu item and order which is 20.

this code starts by using moreCustomers and it is set to 'y' and it will keep looping until users prompt 'n' to quit the system.

it also contains all the fucntions needed to make the system work

to compile the file just have all the three file which is header.h , header.cpp, and driver.cpp in the same folder with the Menu.txt and compile it with g++ driver.cpp header.cpp -o driver.exe , once that is done , a driver.exe file is create and execute the file with ./ like this ./driver.exe

receipt History.txt
this file stores all the record of the generated receipt , but if the system is shutdown and open up again the menu will load the original one and the recording will continue.

sample program:

PS C:\Users\evang\OneDrive\Documents\Advanced programming class> g++ driver.cpp header.cpp -o driver.exe
PS C:\Users\evang\OneDrive\Documents\Advanced programming class> ./driver.exe

Enter Table Number: 1
---------------------- UOW FOOD MENU -----------------------
Id| Name                      Price
1 | Chicken Burger            RM 7.50 (Quantity: 10)
2 | Pizza                     RM 8.99 (Quantity: 5)
3 | Fried Rice                RM 6.00 (Quantity: 12)
4 | Coke                      RM 2.00 (Quantity: 20)
5 | Ice Cream                 RM 3.50 (Quantity: out of stock)
6 | Beef Burger               RM 8.20 (Quantity: 8)
7 | Spaghetti Bolognese       RM 9.50 (Quantity: 6)
8 | Grilled Chicken           RM 12.00 (Quantity: 4)
9 | Cheese Sandwich           RM 4.00 (Quantity: 15)
10| French Fries              RM 3.00 (Quantity: 25)
11| Orange Juice              RM 2.80 (Quantity: 18)
12| Hot Dog                   RM 5.50 (Quantity: 7)
13| Chocolate Cake            RM 4.75 (Quantity: 3)
14| Green Tea                 RM 2.20 (Quantity: 10)
15| Salad Bowl                RM 5.00 (Quantity: 9)
16| Fish and Chips            RM 11.50 (Quantity: 5)
17| BBQ Wings                 RM 9.00 (Quantity: 6)
18| Milkshake                 RM 4.20 (Quantity: 12)
19| Spring Rolls              RM 6.50 (Quantity: 10)
20| Water Bottle              RM 1.50 (Quantity: 30)

Please enter the Menu ID you want to order (Enter 0 to finish order): 1
Please enter the quantity: 5
Your order is added!
Current total cost: RM 37.50

---------------------- UOW FOOD MENU -----------------------
Id| Name                      Price
1 | Chicken Burger            RM 7.50 (Quantity: 5)
2 | Pizza                     RM 8.99 (Quantity: 5)
3 | Fried Rice                RM 6.00 (Quantity: 12)
4 | Coke                      RM 2.00 (Quantity: 20)
5 | Ice Cream                 RM 3.50 (Quantity: out of stock)
6 | Beef Burger               RM 8.20 (Quantity: 8)
7 | Spaghetti Bolognese       RM 9.50 (Quantity: 6)
8 | Grilled Chicken           RM 12.00 (Quantity: 4)
9 | Cheese Sandwich           RM 4.00 (Quantity: 15)
10| French Fries              RM 3.00 (Quantity: 25)
11| Orange Juice              RM 2.80 (Quantity: 18)
12| Hot Dog                   RM 5.50 (Quantity: 7)
13| Chocolate Cake            RM 4.75 (Quantity: 3)
14| Green Tea                 RM 2.20 (Quantity: 10)
15| Salad Bowl                RM 5.00 (Quantity: 9)
16| Fish and Chips            RM 11.50 (Quantity: 5)
17| BBQ Wings                 RM 9.00 (Quantity: 6)
18| Milkshake                 RM 4.20 (Quantity: 12)
19| Spring Rolls              RM 6.50 (Quantity: 10)
20| Water Bottle              RM 1.50 (Quantity: 30)

Please enter the Menu ID you want to order (Enter 0 to finish order): 2
Please enter the quantity: 3
Your order is added!
Current total cost: RM 64.47

---------------------- UOW FOOD MENU -----------------------
Id| Name                      Price
1 | Chicken Burger            RM 7.50 (Quantity: 5)
2 | Pizza                     RM 8.99 (Quantity: 2)
3 | Fried Rice                RM 6.00 (Quantity: 12)
4 | Coke                      RM 2.00 (Quantity: 20)
5 | Ice Cream                 RM 3.50 (Quantity: out of stock)
6 | Beef Burger               RM 8.20 (Quantity: 8)
7 | Spaghetti Bolognese       RM 9.50 (Quantity: 6)
8 | Grilled Chicken           RM 12.00 (Quantity: 4)
9 | Cheese Sandwich           RM 4.00 (Quantity: 15)
10| French Fries              RM 3.00 (Quantity: 25)
11| Orange Juice              RM 2.80 (Quantity: 18)
12| Hot Dog                   RM 5.50 (Quantity: 7)
13| Chocolate Cake            RM 4.75 (Quantity: 3)
14| Green Tea                 RM 2.20 (Quantity: 10)
15| Salad Bowl                RM 5.00 (Quantity: 9)
16| Fish and Chips            RM 11.50 (Quantity: 5)
17| BBQ Wings                 RM 9.00 (Quantity: 6)
18| Milkshake                 RM 4.20 (Quantity: 12)
19| Spring Rolls              RM 6.50 (Quantity: 10)
20| Water Bottle              RM 1.50 (Quantity: 30)

Please enter the Menu ID you want to order (Enter 0 to finish order): 0

Final order for table 1 (Order ID #1) Fri Oct 10 15:59:02 2025
***************** Customer Receipt ********************
Quantity      Name          Price          Total
*******************************************************
5         Chicken Burger    RM7.50         RM37.50
3         Pizza             RM8.99         RM26.97

Total Amount Due: RM 64.47
Enter payment amount (RM): 50
not enough money. Please enter at least RM 64.47.
Enter payment amount (RM): 65
Payment succesful. Change: RM 0.53
next customer? (y/n): y

Enter Table Number: 1
---------------------- UOW FOOD MENU -----------------------
Id| Name                      Price
1 | Chicken Burger            RM 7.50 (Quantity: 5)
2 | Pizza                     RM 8.99 (Quantity: 2)
3 | Fried Rice                RM 6.00 (Quantity: 12)
4 | Coke                      RM 2.00 (Quantity: 20)
5 | Ice Cream                 RM 3.50 (Quantity: out of stock)
6 | Beef Burger               RM 8.20 (Quantity: 8)
7 | Spaghetti Bolognese       RM 9.50 (Quantity: 6)
8 | Grilled Chicken           RM 12.00 (Quantity: 4)
9 | Cheese Sandwich           RM 4.00 (Quantity: 15)
10| French Fries              RM 3.00 (Quantity: 25)
11| Orange Juice              RM 2.80 (Quantity: 18)
12| Hot Dog                   RM 5.50 (Quantity: 7)
13| Chocolate Cake            RM 4.75 (Quantity: 3)
14| Green Tea                 RM 2.20 (Quantity: 10)
15| Salad Bowl                RM 5.00 (Quantity: 9)
16| Fish and Chips            RM 11.50 (Quantity: 5)
17| BBQ Wings                 RM 9.00 (Quantity: 6)
18| Milkshake                 RM 4.20 (Quantity: 12)
19| Spring Rolls              RM 6.50 (Quantity: 10)
20| Water Bottle              RM 1.50 (Quantity: 30)

Please enter the Menu ID you want to order (Enter 0 to finish order): 1
Please enter the quantity: 1
Your order is added!
Current total cost: RM 7.50

---------------------- UOW FOOD MENU -----------------------
Id| Name                      Price
1 | Chicken Burger            RM 7.50 (Quantity: 4)
2 | Pizza                     RM 8.99 (Quantity: 2)
3 | Fried Rice                RM 6.00 (Quantity: 12)
4 | Coke                      RM 2.00 (Quantity: 20)
5 | Ice Cream                 RM 3.50 (Quantity: out of stock)
6 | Beef Burger               RM 8.20 (Quantity: 8)
7 | Spaghetti Bolognese       RM 9.50 (Quantity: 6)
8 | Grilled Chicken           RM 12.00 (Quantity: 4)
9 | Cheese Sandwich           RM 4.00 (Quantity: 15)
10| French Fries              RM 3.00 (Quantity: 25)
11| Orange Juice              RM 2.80 (Quantity: 18)
12| Hot Dog                   RM 5.50 (Quantity: 7)
13| Chocolate Cake            RM 4.75 (Quantity: 3)
14| Green Tea                 RM 2.20 (Quantity: 10)
15| Salad Bowl                RM 5.00 (Quantity: 9)
16| Fish and Chips            RM 11.50 (Quantity: 5)
17| BBQ Wings                 RM 9.00 (Quantity: 6)
18| Milkshake                 RM 4.20 (Quantity: 12)
19| Spring Rolls              RM 6.50 (Quantity: 10)
20| Water Bottle              RM 1.50 (Quantity: 30)

Please enter the Menu ID you want to order (Enter 0 to finish order): 0

Final order for table 1 (Order ID #2) Fri Oct 10 15:59:20 2025
***************** Customer Receipt ********************
Quantity      Name          Price          Total
*******************************************************
1         Chicken Burger    RM7.50         RM7.50

Total Amount Due: RM 7.50
Enter payment amount (RM): 10
Payment succesful. Change: RM 2.50
next customer? (y/n): y

Enter Table Number: 100
---------------------- UOW FOOD MENU -----------------------
Id| Name                      Price
1 | Chicken Burger            RM 7.50 (Quantity: 4)
2 | Pizza                     RM 8.99 (Quantity: 2)
3 | Fried Rice                RM 6.00 (Quantity: 12)
4 | Coke                      RM 2.00 (Quantity: 20)
5 | Ice Cream                 RM 3.50 (Quantity: out of stock)
6 | Beef Burger               RM 8.20 (Quantity: 8)
7 | Spaghetti Bolognese       RM 9.50 (Quantity: 6)
8 | Grilled Chicken           RM 12.00 (Quantity: 4)
9 | Cheese Sandwich           RM 4.00 (Quantity: 15)
10| French Fries              RM 3.00 (Quantity: 25)
11| Orange Juice              RM 2.80 (Quantity: 18)
12| Hot Dog                   RM 5.50 (Quantity: 7)
13| Chocolate Cake            RM 4.75 (Quantity: 3)
14| Green Tea                 RM 2.20 (Quantity: 10)
15| Salad Bowl                RM 5.00 (Quantity: 9)
16| Fish and Chips            RM 11.50 (Quantity: 5)
17| BBQ Wings                 RM 9.00 (Quantity: 6)
18| Milkshake                 RM 4.20 (Quantity: 12)
19| Spring Rolls              RM 6.50 (Quantity: 10)
20| Water Bottle              RM 1.50 (Quantity: 30)

Please enter the Menu ID you want to order (Enter 0 to finish order): 1
Please enter the quantity: 6
Apologies, not enough quantity available.
---------------------- UOW FOOD MENU -----------------------
Id| Name                      Price
1 | Chicken Burger            RM 7.50 (Quantity: 4)
2 | Pizza                     RM 8.99 (Quantity: 2)
3 | Fried Rice                RM 6.00 (Quantity: 12)
4 | Coke                      RM 2.00 (Quantity: 20)
5 | Ice Cream                 RM 3.50 (Quantity: out of stock)
6 | Beef Burger               RM 8.20 (Quantity: 8)
7 | Spaghetti Bolognese       RM 9.50 (Quantity: 6)
8 | Grilled Chicken           RM 12.00 (Quantity: 4)
9 | Cheese Sandwich           RM 4.00 (Quantity: 15)
10| French Fries              RM 3.00 (Quantity: 25)
11| Orange Juice              RM 2.80 (Quantity: 18)
12| Hot Dog                   RM 5.50 (Quantity: 7)
13| Chocolate Cake            RM 4.75 (Quantity: 3)
14| Green Tea                 RM 2.20 (Quantity: 10)
15| Salad Bowl                RM 5.00 (Quantity: 9)
16| Fish and Chips            RM 11.50 (Quantity: 5)
17| BBQ Wings                 RM 9.00 (Quantity: 6)
18| Milkshake                 RM 4.20 (Quantity: 12)
19| Spring Rolls              RM 6.50 (Quantity: 10)
20| Water Bottle              RM 1.50 (Quantity: 30)

Please enter the Menu ID you want to order (Enter 0 to finish order): 2
Please enter the quantity: 1
Your order is added!
Current total cost: RM 8.99

---------------------- UOW FOOD MENU -----------------------
Id| Name                      Price
1 | Chicken Burger            RM 7.50 (Quantity: 4)
2 | Pizza                     RM 8.99 (Quantity: 1)
3 | Fried Rice                RM 6.00 (Quantity: 12)
4 | Coke                      RM 2.00 (Quantity: 20)
5 | Ice Cream                 RM 3.50 (Quantity: out of stock)
6 | Beef Burger               RM 8.20 (Quantity: 8)
7 | Spaghetti Bolognese       RM 9.50 (Quantity: 6)
8 | Grilled Chicken           RM 12.00 (Quantity: 4)
9 | Cheese Sandwich           RM 4.00 (Quantity: 15)
10| French Fries              RM 3.00 (Quantity: 25)
11| Orange Juice              RM 2.80 (Quantity: 18)
12| Hot Dog                   RM 5.50 (Quantity: 7)
13| Chocolate Cake            RM 4.75 (Quantity: 3)
14| Green Tea                 RM 2.20 (Quantity: 10)
15| Salad Bowl                RM 5.00 (Quantity: 9)
16| Fish and Chips            RM 11.50 (Quantity: 5)
17| BBQ Wings                 RM 9.00 (Quantity: 6)
18| Milkshake                 RM 4.20 (Quantity: 12)
19| Spring Rolls              RM 6.50 (Quantity: 10)
20| Water Bottle              RM 1.50 (Quantity: 30)

Please enter the Menu ID you want to order (Enter 0 to finish order): 0

Final order for table 100 (Order ID #3) Fri Oct 10 15:59:42 2025
***************** Customer Receipt ********************
Quantity      Name          Price          Total
*******************************************************
1         Pizza             RM8.99         RM8.99

Total Amount Due: RM 8.99
Enter payment amount (RM): 10  
Payment succesful. Change: RM 1.01
next customer? (y/n): n
system shutting down