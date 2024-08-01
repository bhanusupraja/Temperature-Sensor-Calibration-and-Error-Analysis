#include <iostream>
#include <vector>
#include <cmath>

// Function to calibrate the temperature sensor readings
std::vector<double> calibrateReadings(const std::vector<double>& readings, double offset, double scale) {
    std::vector<double> calibratedReadings;
    for (double reading : readings) {
        double calibrated = (reading + offset) * scale;
        calibratedReadings.push_back(calibrated);
    }
    return calibratedReadings;
}

// Function to calculate the mean absolute error
double calculateMeanAbsoluteError(const std::vector<double>& readings, const std::vector<double>& knownValues) {
    double errorSum = 0.0;
    size_t count = readings.size();
    
    for (size_t i = 0; i < count; ++i) {
        errorSum += std::abs(readings[i] - knownValues[i]);
    }
    
    return errorSum / count;
}

int main() {
    // Example temperature sensor readings (in degrees Celsius)
    std::vector<double> sensorReadings = {22.4, 23.1, 21.9, 22.8, 23.0};
    
    // Known standard values for calibration (in degrees Celsius)
    std::vector<double> knownValues = {22.0, 22.5, 22.0, 22.5, 22.5};
    
    // Calibration parameters (example values)
    double offset = -0.5; // Example offset to correct the readings
    double scale = 1.05;  // Example scale factor to adjust the readings
    
    // Calibrate the sensor readings
    std::vector<double> calibratedReadings = calibrateReadings(sensorReadings, offset, scale);
    
    // Calculate the mean absolute error
    double meanAbsoluteError = calculateMeanAbsoluteError(calibratedReadings, knownValues);
    
    // Output the results
    std::cout << "Calibrated Readings: ";
    for (double reading : calibratedReadings) {
        std::cout << reading << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Mean Absolute Error: " << meanAbsoluteError << std::endl;
    
    return 0;
}
