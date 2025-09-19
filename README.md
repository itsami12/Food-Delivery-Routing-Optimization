🚚 Food Delivery Routing Optimization
A C++ project for CS2001 that calculates the optimal delivery routes and times for a food delivery service in a grid-based city.

</div>

<p align="center">
<img src="https://img.shields.io/badge/Language-C%2B%2B-blue.svg" alt="Language C++">
<img src="https://img.shields.io/badge/License-MIT-yellow.svg" alt="License MIT">
</p>

📋 Table of Contents
About The Project

✨ Features

🛠️ Data Structures & Algorithms

🚀 Getting Started

📝 Usage & Example

📂 Code Structure

👥 Authors

📍 About The Project
This project is a C++ application designed to solve a routing optimization problem for a food delivery service, "Food Polar Bear," operating in a grid-based city. The primary goal is to calculate the minimum time required to deliver all orders from multiple restaurants to various customer locations, considering individual delivery time limits. The city is represented as an N x N grid, where travel between adjacent nodes takes one unit of time.

✨ Features
🏙️ Grid-Based City Model: Represents the operational area as an N x N grid, with locations identified by a single index converted to (x, y) coordinates.

🔄 Multiple Test Cases: Handles and processes multiple independent scenarios in a single run.

🏪 Restaurant & Order Management: Efficiently structures data for multiple restaurants, each with its own set of unique orders.

⏱️ Optimal Time Calculation: Calculates the total time for each restaurant's deliveries based on travel distance and specified delivery time limits.

🗺️ Path Visualization: Outputs a detailed, step-by-step traversal path from a restaurant to each order destination.

✔️ Input Validation: Includes checks to ensure location indices are within grid boundaries and delivery time limits are positive.

🛠️ Data Structures & Algorithms
Data Structures
struct Location & struct Restaurant: These structures model the core entities. Location stores an order's destination and time constraints, while Restaurant aggregates restaurant information and its associated orders.

Queue (Linked List): A custom FIFO queue is used to manage the flow of test cases, cleanly separating the input phase from the processing phase.

Algorithms
Manhattan Distance: Travel time is calculated using the Manhattan distance formula, which is ideal for a grid-based map where movement is restricted to horizontal and vertical paths.

d((x 
1
​
 ,y 
1
​
 ),(x 
2
​
 ,y 
2
​
 ))=∣x 
2
​
 −x 
1
​
 ∣+∣y 
2
​
 −y 
1
​
 ∣
Delivery Time Calculation: The function aStar (note: not a traditional A* search algorithm) calculates the time required for a restaurant to service its orders. For each order, it computes the total time as:

Total Time 
order
​
 =Travel Time+Delivery Time Limit

The function then determines the maximum of these individual order times. This value represents the minimum time window required to complete the most time-consuming delivery, assuming riders can operate in parallel.

🚀 Getting Started
Follow these steps to get a local copy up and running.

Prerequisites
You need a C++ compiler installed on your system. The g++ compiler is recommended.

Compilation & Execution
Clone the repository (or save the code)
Save the code in a file named main.cpp.

Compile the code
Open your terminal, navigate to the project directory, and run:

Bash

g++ main.cpp -o delivery_optimizer
Run the program
Execute the compiled file from your terminal:

Bash

./delivery_optimizer
The program will then prompt you to enter the details for each test case interactively.

📝 Usage & Example
The program takes input directly from the console. You will be prompted for the number of test cases, grid details, and information for each restaurant and its orders.

<details>
<summary><strong>Click to view Sample Input & Output</strong></summary>

Sample Input
Here is an example of the interactive input process:

Plaintext

Enter the number of test cases: 2
Enter grid size, number of riders, and number of restaurants for test case 1: 5 2 2
Enter restaurant name and index: BurgerPalace 10
Enter number of orders for BurgerPalace: 2
Enter order name and index: Beef 7
Enter delivery time limit for Beef: 5
Enter order name and index: Zinger 15
Enter delivery time limit for Zinger: 8
Enter restaurant name and index: PizzaPlanet 18
Enter number of orders for PizzaPlanet: 1
Enter order name and index: Tikka 21
Enter delivery time limit for Tikka: 5
Enter grid size, number of riders, and number of restaurants for test case 2: 5 2 1
Enter restaurant name and index: CurryHouse 10
Enter number of orders for CurryHouse: 3
Enter order name and index: Chicken 2
Enter delivery time limit for Chicken: 7
Enter order name and index: ButterChicken 18
Enter delivery time limit for ButterChicken: 5
Enter order name and index: Biryani 15
Enter delivery time limit for Biryani: 2
Corresponding Output
Based on the code's logic, the output for the sample input above will be:

Plaintext

Total minimum time required for BurgerPalace: 10 time units
Detailed traversal for BurgerPalace:
Rider 1: (2, 4)->(2, 3)->(2, 2)-> = 2 time units
Rider 2: (2, 4)->(2, 5)->  (3, 5)-> = 2 time units
Total minimum time required for PizzaPlanet: 8 time units
Detailed traversal for PizzaPlanet:
Rider 1: (4, 3)->(4, 2)->(4, 1)->  (5, 1)-> = 3 time units
Total minimum time required for CurryHouse: 9 time units
Detailed traversal for CurryHouse:
Rider 1: (2, 4)->(2, 3)->(2, 2)->  (1, 2)-> = 3 time units
Rider 2: (2, 4)->(2, 3)->  (3, 3)->  (4, 3)-> = 3 time units
Rider 3: (2, 4)->(2, 5)->  (3, 5)-> = 2 time units
</details>

📂 Code Structure
Structs (Location, Restaurant): Define the primary data models for orders and restaurants.

Queue Class: A linked-list based queue to manage the processing of restaurants.

enqueue(): Adds a restaurant to the rear of the queue.

dequeue(): Removes a restaurant from the front.

isEmpty(): Checks if the queue is empty.

calculateDistance(): A helper function to compute the Manhattan distance between two coordinates.

aStar(): The core logic function that calculates the maximum required time for a restaurant's orders.

getUserInput(): Manages all interactive console input, populates data structures, and performs validation.

calculateMinTime(): Dequeues each restaurant, invokes the time calculation logic, and prints the final results.

main(): The entry point of the program that orchestrates the overall flow.

👥 Authors
Hussain Ahmad - Project Member

Sami Naeem - Project Member

Asad Ullah - Project Member
