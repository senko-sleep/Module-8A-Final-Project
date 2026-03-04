/**
 * M08 Final Project - Block Letter Display Program
 *
 * reads coordinate data from an input file, creates a 2D array,
 * fills it with characters at specified positions, and prints the result
 * to reveal block-annotated letters.
 *
 * Author: Allen Poston
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

// holds a single data point with x, y coordinates and character
struct DataPoint {
    int x;
    int y;
    string character;
};

// reads input data from a file and returns a vector of DataPoint structures
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

// finds the maximum x and y coordinates from the data points
void findMaxDimensions(const vector<DataPoint>& dataPoints, int& maxX, int& maxY) {
    maxX = 0;
    maxY = 0;
    
    for (const DataPoint& point : dataPoints) {
        if (point.x > maxX) maxX = point.x;
        if (point.y > maxY) maxY = point.y;
    }
    
    cout << "Maximum dimensions: X = " << maxX << ", Y = " << maxY << endl;
}

// initializes a 2D array with spaces
vector<vector<string>> initializeArray(int rows, int cols) {
    vector<vector<string>> array(rows, vector<string>(cols, " "));
    cout << "Initialized " << rows << " x " << cols << " array with spaces." << endl;
    return array;
}

// fills the 2D array with characters from the data points
void fillArray(vector<vector<string>>& array, const vector<DataPoint>& dataPoints) {
    for (const DataPoint& point : dataPoints) {
        if (point.y >= 0 && point.y < static_cast<int>(array.size()) &&
            point.x >= 0 && point.x < static_cast<int>(array[point.y].size())) {
            array[point.y][point.x] = point.character;
        }
    }
    cout << "Filled array with " << dataPoints.size() << " characters." << endl;
}

// prints the 2D array to the console to reveal the block letters
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

int main() {
    // set console output mode for UTF-8 on Windows
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    
    cout << "M08 Final Project - Block Letter Display Program" << endl;
    cout << "================================================\n" << endl;
    
    string filename = "data/input_data.txt";
    vector<DataPoint> dataPoints = readInputData(filename);
    
    if (dataPoints.empty()) {
        cerr << "Error: No data points were read. Exiting." << endl;
        return 1;
    }
    
    int maxX, maxY;
    findMaxDimensions(dataPoints, maxX, maxY);
    
    // array size is maxY+1 rows by maxX+1 cols (0-indexed)
    int rows = maxY + 1;
    int cols = maxX + 1;
    vector<vector<string>> displayArray = initializeArray(rows, cols);
    
    fillArray(displayArray, dataPoints);
    printArray(displayArray);
    
    cout << "Program completed successfully!" << endl;
    
    return 0;
}
