# UOW Food Menu System

A C++ console-based restaurant ordering system for managing food menus, taking orders, generating receipts, and processing payments. Built as part of an advanced programming course.

## Features

- **Menu Management** — Load and display food items from a text file with real-time quantity tracking
- **Order Placement** — Customers can order multiple items with quantity validation against available stock
- **Receipt Generation** — Generates formatted receipts with order ID, table number, timestamp, and itemized costs
- **Payment Processing** — Handles payments and calculates change with insufficient-fund validation
- **Receipt History** — Appends every completed receipt to `receipt History.txt` for record-keeping

## Project Structure

| File | Description |
|------|-------------|
| `header.h` | Struct definitions (`MENU`, `ORDER`) and function declarations |
| `header.cpp` | Implementation of all system functions |
| `driver.cpp` | Main program loop — entry point |
| `Menu.txt` | Menu data source (CSV-like format, **must be provided by user**) |
| `receipt History.txt` | Auto-generated receipt history log |

## How It Works

1. The program loads menu items from `Menu.txt`
2. For each customer, the system asks for a table number
3. The menu is displayed with current stock levels
4. Customers select items by ID and specify quantities (stock is deducted in real time)
5. After ordering, a receipt is displayed and payment is collected
6. The receipt is appended to `receipt History.txt`
7. The system loops for the next customer until the user quits

## Menu.txt Format

Create a `Menu.txt` file in the same directory with the following format:

```
1,Chicken Burger;7.50&10
2,Pizza;8.99&5
```

Each line: `ID,Name;Price&Quantity` — the delimiters (`,`, `;`, `&`) are parsed by the system.

## Compilation & Usage

```bash
g++ driver.cpp header.cpp -o driver
./driver
```

## Requirements

- C++11 or later
- `Menu.txt` in the working directory (see format above)
