# M08 Final Project - Block Letter Display Program

## Project Description
This C++ program reads coordinate data from an input file, creates a 2D array, fills it with block characters at specified positions, and prints the result to reveal block-annotated letters.

## Author
- **Name:** Allen Poston
- **Date:** March 4, 2026
- **Course:** CSCI101

## Files Included
- `src/main.cpp` - Main source code file
- `data/input_data.txt` - Extracted coordinate data from PDF
- `data/M08 Final Project InputData.pdf` - Original input data file
- `docs/FLOWCHART.txt` - Program flowchart description
- `docs/UML.txt` - UML diagram description
- `results.txt` - Program execution results
- `README.md` - This documentation file

## How to Compile
Using g++ (MinGW on Windows):
```bash
g++ -o BlockLetterDisplay.exe src/main.cpp -std=c++17
```

Using Visual Studio Developer Command Prompt:
```bash
cl /EHsc /Fe:BlockLetterDisplay.exe src/main.cpp
```

## How to Run
```bash
./BlockLetterDisplay.exe
```
Or on Windows:
```bash
BlockLetterDisplay.exe
```

**Note:** Run the program from the project root directory so it can find `data/input_data.txt`.

## Program Flow
1. **Read Input Data** - Reads coordinate data from `data/input_data.txt`
2. **Find Maximum Dimensions** - Determines the size of the 2D array needed
3. **Initialize Array** - Creates a 2D array filled with spaces
4. **Fill Array** - Places characters at their specified coordinates
5. **Print Array** - Outputs the array to reveal block letters

## Input Data Format
The input file contains lines with the format:
```
x_coordinate y_coordinate character
```
Where:
- `x_coordinate` - Column position (0-89)
- `y_coordinate` - Row position (0-6)
- `character` - Block character (█ or ░)

## Output
The program displays a 7-row by 90-column grid of block characters (█ and ░) that spell "EICMDKO" when viewed together.

Example output:
```
██████████░ ██████░    ███████░     ██░     ██░     ████████░    ██░    ███░   ████████░
██░           ██░    ███░    ██░   ████░   ████░    ██░     ██░  ██░  ███░   ███░     ███░
██░           ██░   ███░           ██░██░ ██░██░    ██░      ██░ ██░███░     ██░       ██░
████████░     ██░   ██░           ███░ ██░██░ ██░   ██░      ██░ ████░       ██░       ██░
██░           ██░   ███░          ██░  █████░ ███░  ██░      ██░ ██░███░     ██░       ██░
██░           ██░    ███░    ██░ ███░   ███░   ██░  ██░     ██░  ██░  ███░   ███░     ███░
██████████░ ██████░    ███████░  ██░           ███░ ████████░    ██░    ███░   ████████░
```

## Functions
| Function | Description |
|----------|-------------|
| `readInputData()` | Reads and parses the input file |
| `findMaxDimensions()` | Finds maximum x and y coordinates |
| `initializeArray()` | Creates 2D array with spaces |
| `fillArray()` | Populates array with characters |
| `printArray()` | Displays the final result |

## Requirements
- C++17 compatible compiler
- Windows (for UTF-8 console support) or Linux/macOS
