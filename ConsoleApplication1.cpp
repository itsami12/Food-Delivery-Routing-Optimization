#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Constants
const int MAX_ORDERS = 100;
const int MAX_RESTAURANTS = 100;
const int MAX_LOCATIONS = MAX_ORDERS * MAX_RESTAURANTS;

// Define a structure to represent a location
struct Location {
    string name;
    int index;
    int x, y; // Coordinates
    int deliveryTimeLimit; // Maximum time allowed for delivery
};

// Define a structure to represent a restaurant
struct Restaurant {
    string name;
    int index; // Index of the restaurant in the grid
    int x, y; // Coordinates
    Location orders[MAX_ORDERS]; // Maximum number of orders
    int numOrders; // Number of orders for this restaurant
};

// Define the Queue class using a linked list
class Queue {
private:
    struct Node {
        Restaurant data;
        Node* next;
    };

    Node* front; // Pointer to the front of the queue
    Node* rear; // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Enqueue a restaurant into the queue
    void enqueue(Restaurant data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue a restaurant from the queue
    Restaurant dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            exit(EXIT_FAILURE);
        }
        Node* temp = front;
        Restaurant data = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return data;
    }
};

// Function to calculate the Manhattan distance between two locations
int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

// Function to implement A* algorithm
int aStar(Restaurant restaurant) {
    int maxTime = 0;
    // Calculate the maximum time required for delivery
    for (int o = 0; o < restaurant.numOrders; ++o) {
        int orderTimeLimit = restaurant.orders[o].deliveryTimeLimit;
        int distance = calculateDistance(restaurant.x, restaurant.y, restaurant.orders[o].x, restaurant.orders[o].y);
        // Assuming a constant speed for delivery, time = distance / speed
        int deliveryTime = distance; // Assuming speed of 1 unit per time unit
        maxTime = max(maxTime, orderTimeLimit + deliveryTime);
    }
    return maxTime;
}

// Function to take input from the user
void getUserInput(Queue& testCases) {
    int numTestCases;
    cout << "Enter the number of test cases: ";
    cin >> numTestCases;

    // Input for each test case
    for (int t = 0; t < numTestCases; ++t) {
        int gridSize, numRiders, numRestaurants;
        cout << "Enter grid size, number of riders, and number of restaurants for test case " << (t + 1) << ": ";
        cin >> gridSize >> numRiders >> numRestaurants;

        Restaurant restaurant;
        // Input for each restaurant
        for (int r = 0; r < numRestaurants; ++r) {
            cout << "Enter restaurant name and index: ";
            cin >> restaurant.name >> restaurant.index;

            // Convert index to x-axis and y-axis coordinates
            restaurant.x = (restaurant.index - 1) % gridSize + 1;
            restaurant.y = (restaurant.index - 1) / gridSize + 1;

            // Validate input for restaurant's index
            if (restaurant.index < 1 || restaurant.index > gridSize * gridSize) {
                cout << "Invalid index for restaurant " << restaurant.name << ". Please enter a valid index within the grid size.\n";
                exit(EXIT_FAILURE);
            }

            cout << "Enter number of orders for " << restaurant.name << ": ";
            cin >> restaurant.numOrders;

            // Input for each order of the restaurant
            for (int o = 0; o < restaurant.numOrders; ++o) {
                cout << "Enter order name and index: ";
                cin >> restaurant.orders[o].name >> restaurant.orders[o].index;

                // Convert index to x-axis and y-axis coordinates
                restaurant.orders[o].x = (restaurant.orders[o].index - 1) % gridSize + 1;
                restaurant.orders[o].y = (restaurant.orders[o].index - 1) / gridSize + 1;

                // Validate input for order's index
                if (restaurant.orders[o].index < 1 || restaurant.orders[o].index > gridSize * gridSize) {
                    cout << "Invalid index for order " << restaurant.orders[o].name << ". Please enter a valid index within the grid size.\n";
                    exit(EXIT_FAILURE);
                }

                cout << "Enter delivery time limit for " << restaurant.orders[o].name << ": ";
                cin >> restaurant.orders[o].deliveryTimeLimit;
                // Validate input for delivery time limit
                if (restaurant.orders[o].deliveryTimeLimit <= 0) {
                    cout << "Invalid delivery time limit for order " << restaurant.orders[o].name << ". Please enter a positive integer.\n";
                    exit(EXIT_FAILURE);
                }
            }
            testCases.enqueue(restaurant); // Enqueue the restaurant
        }
    }
}

// Function to calculate the total minimum time required for each test case
// Function to calculate the total minimum time required for each test case
void calculateMinTime(Queue& testCases) {
    int testNum = 1;
    while (!testCases.isEmpty()) {
        // Dequeue a restaurant from the queue
        Restaurant restaurant = testCases.dequeue();
        // Calculate the total minimum time required for delivery
        int totalMinTime = aStar(restaurant);
        cout << "Total minimum time required for " << restaurant.name << ": " << totalMinTime << " time units" << endl;

        // Display detailed traversal for each order
        cout << "Detailed traversal for " << restaurant.name << ":" << endl;
        for (int o = 0; o < restaurant.numOrders; ++o) {
            cout << "Rider " << (o + 1) << ": ";
            int startX = restaurant.x; // Starting X coordinate of the restaurant
            int startY = restaurant.y; // Starting Y coordinate of the restaurant
            int endX = restaurant.orders[o].x; // Destination X coordinate
            int endY = restaurant.orders[o].y; // Destination Y coordinate

            // Check if a path exists between the restaurant and the order
            if (startX == endX && startY == endY) {
                cout << "No path found. Cannot deliver order " << restaurant.orders[o].name << endl;
                continue; // Move to the next order
            }

            cout << "(" << startY << ", " << startX << ")";
            cout << "->";

            // Assuming a grid-based map, traverse horizontally first, then vertically
            int nextX = startX;
            int nextY = startY;
            for (int x = startX; x != endX; x += (endX > startX) ? 1 : -1) {
                nextX = x + ((endX > startX) ? 1 : -1);
                cout << "(" << startY << ", " << nextX << ")";
                cout << "->";
            }
            for (int y = startY; y != endY; y += (endY > startY) ? 1 : -1) {
                nextY = y + ((endY > startY) ? 1 : -1);
                cout << "  (" << nextY << ", " << endX << ")";
                cout << "->";
            }

            int deliveryTime = calculateDistance(startX, startY, endX, endY);
            cout << " = " << deliveryTime << " time units" << endl;
        }
        testNum++;
    }
}


int main() {
    Queue testCases;

    // Get input from the user
    getUserInput(testCases);
    // Calculate and display minimum time for each test case
    calculateMinTime(testCases);
    return 0;
}