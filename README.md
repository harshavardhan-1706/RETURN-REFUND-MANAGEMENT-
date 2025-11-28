Abstact:



This C program implements a simple Return and Refund Management System for tracking customer orders and handling post-purchase operations. Using a structured approach based on arrays and the struct data type
, the system stores essential order details, including customer information, product name, order amount, and return/refund status. The program provides a menu-driven interface that allows users to add new orders,
request returns, process refunds, view all orders, and identify pending refunds.It ensures proper validation, such as preventing duplicate processing of returns or refunds and requiring a return request before
initiating a refund. This system demonstrates fundamental concepts of C programming, including structures, arrays, input handling, iterative menus, and conditional logic, while offering practical functionality for 
basic order management.





Features of the Return/Refund Management System

1. Add New Orders
	•	Allows the user to enter a new order with:
	•	Order ID
	•	Customer name
	•	Product name
	•	Order amount
	•	Automatically initializes return and refund status as “Not Requested” and “Not Refunded.”

⸻

2. Request a Return
	•	Takes an Order ID and marks that order as returned.
	•	Prevents duplicate return requests.

⸻

3. Process a Refund
	•	Processes a refund only if:
	•	The return has been requested.
	•	The refund has not yet been processed.
	•	Displays the refund amount upon successful processing.

⸻

4. View All Orders
	•	Displays a table of all orders with:
	•	Order ID
	•	Customer Name
	•	Product Name
	•	Amount
	•	Returned status (Yes/No)
	•	Refunded status (Yes/No)

⸻

5. View Pending Refunds
	•	Shows only those orders that:
	•	Have a return request
	•	Have not yet been refunded
	•	Helps track orders awaiting refund processing.

⸻

6. Menu-Driven Interface
	•	Simple text-based menu for navigating:
	•	Add Order
	•	Request Return
	•	Process Refund
	•	View All Orders
	•	View Pending Refunds
	•	Exit

⸻

7. Order Search by ID
	•	Uses a dedicated function to locate orders by their Order ID.
	•	Helps prevent errors and ensures operations are done on valid orders.

⸻

8. Basic Validation
	•	Prevents:
	•	Adding more than the maximum allowed number of orders
	•	Processing refunds without return requests
	•	Duplicate return or refund actions





___________




Functional Requirements of the Return/Refund Management System

1. Add a New Order
	•	The system shall allow the user to enter a new order.
	•	The system shall store Order ID, customer name, product name, and amount.
	•	The system shall initialize the order with:
	•	isReturned = 0
	•	isRefunded = 0
	•	The system shall prevent adding more than 100 orders.

⸻

2. Search for an Order
	•	The system shall allow searching for an order by its Order ID.
	•	The system shall return the index of the order or indicate if the order does not exist.

⸻

3. Request a Return
	•	The system shall allow a user to request a return by entering the Order ID.
	•	The system shall verify that the order exists.
	•	The system shall prevent multiple return requests for the same order.
	•	The system shall update the return status to “Returned” upon a valid request.

⸻

4. Process a Refund
	•	The system shall allow the user to process a refund by entering an Order ID.
	•	The system shall verify that the order exists.
	•	The system shall check that a return request has been made.
	•	The system shall prevent processing a refund more than once.
	•	The system shall update the refund status to “Refunded.”
	•	The system shall display the refund amount.

⸻

5. View All Orders
	•	The system shall display a list of all stored orders.
	•	The system shall show:
	•	Order ID
	•	Customer name
	•	Product name
	•	Amount
	•	Return status
	•	Refund status

⸻

6. View Pending Refunds
	•	The system shall display only those orders that have:
	•	isReturned = 1
	•	isRefunded = 0
	•	If no such orders exist, the system shall display a message indicating “No pending refunds.”

⸻

7. Menu Navigation
	•	The system shall provide a menu with the following options:
	1.	Add Order
	2.	Request Return
	3.	Process Refund
	4.	View All Orders
	5.	View Pending Refunds
	6.	Exit
	•	The system shall execute the corresponding function based on the user’s choice.

⸻

8. Exit Program
	•	The system shall allow the user to exit the program cleanly.



__________



Technical Requirements of the Program

1. Programming Language Requirements
	•	The system must be written in the C programming language.
	•	It must use the following standard C libraries:
	•	stdio.h for input/output
	•	string.h for string operations
	•	stdlib.h for memory and exit functions

⸻

2. Compiler Requirements
	•	A standard C compiler is required, such as:
	•	GCC (GNU Compiler Collection)
	•	Clang
	•	MinGW (for Windows)
	•	Turbo C / Turbo C++ (for legacy environments)
	•	The compiler must support basic ANSI C (C89/C90), as no advanced features (like dynamic memory, structs with pointers, etc.) are used.

⸻

3. Hardware Requirements
	•	Any machine capable of running a C compiler and console application.
	•	Minimal memory requirements:
	•	At least a few MB of RAM (program uses an array of 100 structs; memory usage is extremely small).
	•	CPU:
	•	Any modern or legacy CPU; processing requirements are minimal.

⸻

4. Operating System Requirements
	•	Compatible with any OS that supports a C compiler:
	•	Windows
	•	Linux
	•	macOS
	•	Unix-based systems

⸻

5. Data Storage Requirements
	•	Uses in-memory storage only (array of struct Order).
	•	No file handling or database requirements.
	•	Maximum of 100 orders (MAX_ORDERS limit).
	•	Data is lost when the program exits.

⸻

6. Input/Output Requirements
	•	Requires a console/terminal for interactive input and output.
	•	Uses:
	•	scanf() for numeric input
	•	fgets() for string input
	•	Formatted output using printf()

⸻

7. System Constraints
	•	Maximum of 100 orders can be stored at any given time.
	•	Order IDs must be manually entered and managed by the user.
	•	The program runs in a sequential and menu-driven loop.
	•	No concurrency, threading, or multitasking.
	•	No GUI (Graphical User Interface) support.

⸻

8. Memory Management Requirements
	•	Uses static allocation:
	•	A fixed-size array of struct Order is allocated at compile time.
	•	No dynamic memory allocation (malloc/free) is used.

⸻

9. Error Handling Requirements
	•	Handles cases such as:
	•	Invalid Order ID
	•	Exceeding maximum orders
	•	Duplicate return or refund attempts
	•	Requires valid numeric input for menu and order fields.

_________



How to Run the Program

Below are steps for Windows, Linux, and macOS using the GCC compiler.

⸻

🖥 1. Run on Windows (using GCC / MinGW)

Step 1: Install GCC

If you don’t have a C compiler:
	•	Install MinGW or TDM-GCC.

Step 2: Save the Code
	•	Copy your entire C program into a file.
	•	Save it as:
refund_system.c

Step 3: Open Command Prompt

Press Win + R → type cmd → press Enter.

Step 4: Navigate to the Folder

Ex: cd C:\Users\YourName\Desktop

Step 5: Compile the Program

Ex: gcc refund_system.c -o refund_system

Step 6: Run the Program
Ex: refund_system

Screenshots:

