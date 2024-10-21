# Personal Health Calculator

This repository contains a C++ program that calculates the Body Mass Index (BMI) and other health-related metrics based on user input. The program collects personal information such as name, gender, age, weight, and height, and processes the data to provide insights like BMI and Total Daily Energy Expenditure (TDEE). The program supports both metric and imperial unit systems.

## Features

- **User Information Input**: Collects personal data such as name, age, gender, weight, and height.
- **Gender Detection**: Automatically determines gender based on the user's input name.
- **Unit Systems**: Supports both metric and imperial systems for weight and height input.
- **BMI Calculation**: Computes the Body Mass Index based on the user’s input weight and height.
- **Data Storage**: Saves the user data into two output files:
  - `InformacjeZwrotne.txt`: Stores the data in a readable format.
  - `InformacjeZwrotneCSV.csv`: Stores the data in CSV format for further processing.

## How It Works

### 1. Program Start

The program begins by displaying information about the project, including the author’s name and the date the program was created. It also records the current date and time of usage.

### 2. Name Input and Gender Detection

- The program asks the user to input their name.
- Based on the provided name, the program determines the user's gender (if the name ends in 'a', the user is identified as female, except for specific names like "Kuba").

### 3. Collecting Personal Data

The program collects additional information from the user:
- Age
- Gender
- Preferred unit system (metric or imperial)

### 4. Unit System Selection

The user can choose between two unit systems:
- **Metric**: Weight in kilograms and height in centimeters.
- **Imperial**: Weight in pounds and height in feet. The program automatically converts these values into the metric system for calculations.

### 5. BMI Calculation

The BMI is calculated based on the user’s weight and height.


### 6. Output Files

- **InformacjeZwrotne.txt**: This file stores the user's personal data and calculated BMI in a human-readable format.
- **InformacjeZwrotneCSV.csv**: This file stores the user's data in CSV format, suitable for further analysis or use in spreadsheet applications.

## How to Use

1. **Compile the program**: Use your preferred C++ compiler.
2. **Run the executable**: Once compiled, run the program. It will prompt you to input your personal details step by step.
3. **View the results**: The BMI and other data will be displayed on the screen, and the information will be saved to the output files for later reference.

## Files

- **InformacjeZwrotne.txt**: Contains the textual output of the collected data.
- **InformacjeZwrotneCSV.csv**: Contains the CSV format of the collected data.

## License

This project is licensed under the MIT License.

---

Feel free to fork, contribute, or suggest improvements!




