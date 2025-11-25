# 🏥 MedPlus - Clinic Management System

A comprehensive and user-friendly Clinic Management System built with Qt C++ and SQLite, designed to streamline appointment scheduling, patient management, and clinic operations.

![Qt](https://img.shields.io/badge/Qt-6.0%2B-green.svg)
![C++](https://img.shields.io/badge/C++-17-blue.svg)
![SQLite](https://img.shields.io/badge/SQLite-3.x-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

---

## ✨ Features

### 👥 Multi-User System
- **Patient Portal**: Book, view, and manage appointments  
- **Admin Panel**: Comprehensive clinic management and analytics  
- **Secure Authentication**: Role-based access control  

### 🗓️ Appointment Management
- **Smart Scheduling**: Real-time slot availability (2 patients per slot)  
- **Rescheduling Support**  
- **Cancellations** with status tracking  
- **Time Slot System**: 30-minute intervals in a 12-hour format  

### 👨‍⚕️ Doctor Management
- **Specializations & Profiles**  
- **Availability Toggle**  
- **Performance Analytics**  
- **Custom Consultation Fee** per doctor  

### 📊 Analytics & Reporting
- **Real-time Dashboard**  
- **Doctor Performance Insights**  
- **Clinic-wide Statistics**  
- **CSV Export Support**  

### 🎨 User Experience
- **Modern, Clean UI**  
- **Responsive Layout**  
- **Color-coded Indicators**  
- **Advanced Search & Filters**  

---

## 🚀 Installation

### Prerequisites
- Qt 6.0+  
- C++17 compatible compiler  
- SQLite3  

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/medplus-clinic.git
cd medplus-clinic

# Create build directory
mkdir build && cd build

# Configure with Qt
qmake ..
make

# Run application
./MedPlus
