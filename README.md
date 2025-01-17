# Hotel Management System

## Project Overview
The Hotel Management System is a C++ project designed to handle various aspects of hotel management, such as managing rooms, handling customer check-ins and check-outs, managing food services, and providing a manager's interface for administrative tasks. The system simulates real-world hotel operations and ensures a smooth and user-friendly experience for both staff and customers.

---

## Features
### 1. **Room Management**
- View available rooms and their details.
- Check-in and check-out operations for customers.
- Track booked rooms and their statuses.

### 2. **Food Services**
- Order food directly to a room.
- Option to dine in the restaurant.
- Dynamic menu for vegetarian and non-vegetarian food with pre-defined pricing.
- Bill generation and addition to the customer's room bill.

### 3. **Manager Login**
- Secure login for the manager using a username and password.
- Options for:
  - Searching customers by name.
  - Viewing room details by room number.
  - Generating a guest summary report.

### 4. **Customer Data Management**
- Customer information, including personal details and food expenses, are stored in files (`customer_data.txt` and `summary_data.txt`).
- Dynamic updates to customer data during operations like food ordering and check-outs.

---

## File Structure
- **`customer_data.txt`**: Stores customer details, including food expenses.
- **`summary_data.txt`**: Maintains a summary of customer details for reports.
- **`manager_data.txt`**: Stores manager credentials for login verification.
- **`temp_customer_data.txt` & `temp_summary_data.txt`**: Temporary files used for updating customer data.

---
