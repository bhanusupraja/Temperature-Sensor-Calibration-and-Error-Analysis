import matplotlib.pyplot as plt

# Example data from the C++ output
sensor_readings = [26.1, 27.2, 28.3, 29.0, 30.1, 26.3, 27.4, 28.7, 29.3, 30.2]
calibrated_readings_linear = [25.6, 26.8, 27.9, 28.7, 29.8, 25.8, 27.0, 28.2, 29.0, 30.0]
calibrated_readings_polynomial = [25.5, 26.6, 27.8, 28.6, 29.7, 25.7, 26.9, 28.0, 29.0, 30.1]

# Plot
plt.figure(figsize=(10, 6))
plt.plot(sensor_readings, label='Original Sensor Readings', marker='o')
plt.plot(calibrated_readings_linear, label='Linear Calibration', marker='x')
plt.plot(calibrated_readings_polynomial, label='Polynomial Calibration', marker='s')
plt.xlabel('Sample Index')
plt.ylabel('Temperature (°C)')
plt.title('Temperature Sensor Calibration')
plt.legend()
plt.grid(True)
plt.show()
