/**
 * M08 Final Project - Block Letter Display Program
 * 
 * This program reads coordinate data from an input file, creates a 2D array,
 * fills it with characters at specified positions, and prints the result
 * to reveal block-annotated letters.
 * 
 * Author: [Your Name Here]
 * Date: March 4, 2026
 * Course: CSCI101
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

/**
 * Structure to hold a single data point with x, y coordinates and character string
 */
struct DataPoint {
    int x;
    int y;
    string character;
};

/**
 * Reads input data from a file and returns a vector of DataPoint structures
 * 
 * @param filename The path to the input file
 * @return Vector containing all data points read from the file
 */
vector<DataPoint> readInputData(const string& filename) {
    vector<DataPoint> dataPoints;
    ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return dataPoints;
    }
    
    int x, y;
    string charStr;
    
    while (inputFile >> x >> y >> charStr) {
        DataPoint point;
        point.x = x;
        point.y = y;
        point.character = charStr;
        dataPoints.push_back(point);
    }
    
    inputFile.close();
    cout << "Read " << dataPoints.size() << " data points from file." << endl;
    return dataPoints;
}

/**
 * Finds the maximum x and y coordinates from the data points
 * 
 * @param dataPoints Vector of data points to analyze
 * @param maxX Reference to store the maximum x coordinate
 * @param maxY Reference to store the maximum y coordinate
 */
void findMaxDimensions(const vector<DataPoint>& dataPoints, int& maxX, int& maxY) {
    maxX = 0;
    maxY = 0;
    
    for (const DataPoint& point : dataPoints) {
        if (point.x > maxX) {
            maxX = point.x;
        }
        if (point.y > maxY) {
            maxY = point.y;
        }
    }
    
    cout << "Maximum dimensions: X = " << maxX << ", Y = " << maxY << endl;
}

/**
 * Initializes a 2D array with spaces
 * 
 * @param rows Number of rows in the array
 * @param cols Number of columns in the array
 * @return 2D vector initialized with space strings
 */
vector<vector<string>> initializeArray(int rows, int cols) {
    vector<vector<string>> array(rows, vector<string>(cols, " "));
    cout << "Initialized " << rows << " x " << cols << " array with spaces." << endl;
    return array;
}

/**
 * Fills the 2D array with characters from the data points
 * 
 * @param array Reference to the 2D array to fill
 * @param dataPoints Vector of data points containing coordinates and characters
 */
void fillArray(vector<vector<string>>& array, const vector<DataPoint>& dataPoints) {
    for (const DataPoint& point : dataPoints) {
        if (point.y >= 0 && point.y < static_cast<int>(array.size()) &&
            point.x >= 0 && point.x < static_cast<int>(array[point.y].size())) {
            array[point.y][point.x] = point.character;
        }
    }
    cout << "Filled array with " << dataPoints.size() << " characters." << endl;
}

/**
 * Prints the 2D array to the console to reveal the block letters
 * 
 * @param array The 2D array to print
 */
void printArray(const vector<vector<string>>& array) {
    cout << "\n========== BLOCK LETTER OUTPUT ==========\n" << endl;
    
    for (const vector<string>& row : array) {
        for (const string& c : row) {
            cout << c;
        }
        cout << endl;
    }
    
    cout << "\n==========================================\n" << endl;
}

/**
 * Main function - orchestrates the program flow
 */
int main() {
    // Set console output mode for UTF-8 on Windows
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    
    cout << "M08 Final Project - Block Letter Display Program" << endl;
    cout << "================================================\n" << endl;
    
    // Step 1: Read input data from file
    string filename = "data/input_data.txt";
    vector<DataPoint> dataPoints = readInputData(filename);
    
    if (dataPoints.empty()) {
        cerr << "Error: No data points were read. Exiting." << endl;
        return 1;
    }
    
    // Step 2: Determine maximum x and y coordinates
    int maxX, maxY;
    findMaxDimensions(dataPoints, maxX, maxY);
    
    // Step 3: Create and initialize 2D array with spaces
    // Array size is maxY+1 rows by maxX+1 columns (0-indexed)
    int rows = maxY + 1;
    int cols = maxX + 1;
    vector<vector<string>> displayArray = initializeArray(rows, cols);
    
    // Step 4: Fill the array with characters from input data
    fillArray(displayArray, dataPoints);
    
    // Step 5: Print the array to reveal the block letters
    printArray(displayArray);
    
    cout << "Program completed successfully!" << endl;
    
    return 0;
}
