# DynamicsSimulator

### Building Instructions
Requirement: having installed cmake 3.8.0 or above
1. Download / clone the repository
2. In the root folder of the project, create a `build` directory
3. Open the terminal inside of this directory and run `cmake ../CMakeLists.txt`
4. Then run `cmake --build . --config Release`
5. You will find the executable in the directory `build\DynamicsSimulator\Release`

### Usage
The simulator will generate a CSV file with the evolution of the coordinates of an object with a given mass, initial height, initial speed and initial movement angle.

The program can be run in a command line, it takes one optional argument setting the path for the generated CSV file.
If the argument is ommitted, the path will default to `.\output.csv`
