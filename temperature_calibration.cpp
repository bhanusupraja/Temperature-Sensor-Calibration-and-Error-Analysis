#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Simulate temperature sensor readings
std::vector<double> simulateSensorReadings(size_t numReadings) {
    std::vector<double> readings;
    for (size_t i = 0; i < numReadings; ++i) {
        // Simulate sensor readings with some random noise
        double simulated = 25.0 + (rand() % 100) / 10.0; // Simulated temperature between 25.0 and 30.0
        readings.push_back(simulated);
    }
    return readings;
}

// Apply linear calibration (offset and scale)
std::vector<double> calibrateReadingsLinear(const std::vector<double>& readings, double offset, double scale) {
    std::vector<double> calibratedReadings;
    for (double reading : readings) {
        double calibrated = (reading + offset) * scale;
        calibratedReadings.push_back(calibrated);
    }
    return calibratedReadings;
}

// Apply polynomial calibration (second degree)
std::vector<double> calibrateReadingsPolynomial(const std::vector<double>& readings, double a, double b, double c) {
    std::vector<double> calibratedReadings;
    for (double reading : readings) {
        double calibrated = a * reading * reading + b * reading + c;
        calibratedReadings.push_back(calibrated);
    }
    return calibratedReadings;
}

// Calculate the mean absolute error
double calculateMeanAbsoluteError(const std::vector<double>& readings, const std::vector<double>& knownValues) {
    double errorSum = 0.0;
    size_t count = readings.size();
    for (size_t i = 0; i < count; ++i) {
        errorSum += std::abs(readings[i] - knownValues[i]);
    }
    return errorSum / count;
}

int main() {
    // Simulated sensor readings
    size_t numReadings = 10;
    std::vector<double> sensorReadings = simulateSensorReadings(numReadings);
    
    // Known standard values (e.g., readings at known temperatures)
    std::vector<double> knownValues = {25.0, 26.0, 27.0, 28.0, 29.0, 25.5, 26.5, 27.5, 28.5, 29.5};
    
    // Calibration parameters (example values)
    double linearOffset = -1.0;
    double linearScale = 1.1;
    double polyA = 0.01;
    double polyB = -0.5;
    double polyC = 25.0;
    
    // Perform linear calibration
    std::vector<double> calibratedReadingsLinear = calibrateReadingsLinear(sensorReadings, linearOffset, linearScale);
    double meanErrorLinear = calculateMeanAbsoluteError(calibratedReadingsLinear, knownValues);
    
    // Perform polynomial calibration
    std::vector<double> calibratedReadingsPolynomial = calibrateReadingsPolynomial(sensorReadings, polyA, polyB, polyC);
    double meanErrorPolynomial = calculateMeanAbsoluteError(calibratedReadingsPolynomial, knownValues);
    
    // Output the results
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << "Original Sensor Readings: ";
    for (double reading : sensorReadings) {
        std::cout << reading << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Linear Calibrated Readings: ";
    for (double reading : calibratedReadingsLinear) {
        std::cout << reading << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Polynomial Calibrated Readings: ";
    for (double reading : calibratedReadingsPolynomial) {
        std::cout << reading << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Mean Absolute Error (Linear): " << meanErrorLinear << std::endl;
    std::cout << "Mean Absolute Error (Polynomial): " << meanErrorPolynomial << std::endl;
    
    return 0;
}


