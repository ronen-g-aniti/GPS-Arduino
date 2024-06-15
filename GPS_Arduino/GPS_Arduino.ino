/*
  GPS_Data_Acquisition.ino

  This sketch demonstrates basic interfacing between an Arduino board
  and a GPS module to acquire and display location data (latitude,
  longitude, and altitude).

  This example code is tailored to align with my professional brand, 
  showcasing my expertise in embedded systems development and 
  autonomous systems, specifically focusing on:

  * Algorithm Development and Integration: Demonstrating proficiency
    in utilizing external libraries (TinyGPS++) for efficient data 
    processing and extraction.
  * Real-time Data Acquisition and Analysis: Highlighting my ability to
    interface with sensors (GPS) to acquire real-time data, relevant to
    my work in autonomous flight technologies.

  This foundational project aligns with my broader goals of developing
  sophisticated navigation and autonomous systems.

  Hardware Requirements:
  * Arduino board (e.g., Arduino Uno)
  * GPS module with UART interface (ensure compatibility)
  * Jumper wires 

  Software Requirements:
  * Arduino IDE
  * TinyGPS++ library (Install through the Arduino Library Manager)

*/

#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Define software serial pins for GPS communication (adjust if needed)
SoftwareSerial ss(4, 3); 

// Create a TinyGPSPlus object to handle GPS data
TinyGPSPlus gps; 

void setup() {
  // Initialize serial communication for outputting data to the serial monitor
  Serial.begin(9600); 

  // Initialize software serial for communication with the GPS module
  ss.begin(9600); 
}

void loop() {
  // Continuously check for available data from the GPS module
  while (ss.available() > 0) {
    // Read a byte of data from the GPS module
    byte gpsData = ss.read();

    // Pass the received byte to the TinyGPS++ library for processing
    gps.encode(gpsData);

    // Check if valid location and altitude data have been parsed by the library
    if (gps.location.isUpdated() || gps.altitude.isUpdated()) {
      // Print the acquired data to the serial monitor
      Serial.print("Latitude: ");
      Serial.print(gps.location.lat(), 6);  // Print latitude with 6 decimal places
      Serial.print(" Longitude: ");
      Serial.print(gps.location.lng(), 6); // Print longitude with 6 decimal places
      Serial.print(" Altitude (meters): ");
      Serial.println(gps.altitude.meters()); 
    }
  }
} 