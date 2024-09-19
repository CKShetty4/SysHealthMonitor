# System Health Monitoring Script

## Project Description

This project provides a system health monitoring solution that keeps track of essential system metrics such as CPU usage, memory usage, disk space, and active processes. The project includes two implementations: one in **C++** and another in **Shell scripting**. Both scripts can:

- Monitor system health.
- Log the data for future reference.
- Display the system metrics in a simple dashboard format.
- Send email alerts when predefined thresholds are exceeded.

### Features Implemented:
- **CPU, Memory, Disk Space, and Active Processes Monitoring:** Regularly track these metrics.
- **Logging:** Store the monitoring data into a log file (in the shell script version).
- **Notifications:** Alerts via email when a specific threshold is breached for any system resource.
- **Cross-platform code:** Tested on **Arch Linux** environment, leveraging common Unix utilities like `top`, `df`, `ps`, `awk`, and `grep`.

---

## Folder Structure

```
.
├── Cpp/
│   └── system_health_monitor.cpp   # C++ implementation of the system health monitor
│   └── system_health_monitor
├── shell/
│   └── system_health_monitor.sh    # Shell script implementation of the system health monitor
│   └── system_health.log
├── Screenshots/                #Project documentation asset
└── README.md                # Project documentation
└── LICENSE                # Project License
```

---

## Skills Demonstrated

- **C++ Programming** for resource monitoring and executing Unix commands.
- **Shell Scripting** for quick monitoring and logging.
- Utilization of tools like `top`, `df`, `ps`, `awk`, and `grep` to extract system health data.
- **Email Alerts:** Integrating email notifications using `mailx` based on system thresholds.
- **Arch Linux** environment for development and testing.

---

## Requirements

### C++ Version

To compile and run the C++ script, ensure you have the following:

- **C++11 or higher** compiler (e.g., `g++`)
- Unix-based system utilities (`top`, `df`, `ps`, `awk`, `grep`)
- `mailx` utility installed and configured for sending emails.

### Shell Script Version

To run the shell script, you need:

- Unix-based system (preferably **Arch Linux**)
- `mailx` utility for email notifications
- Standard Unix commands (`top`, `df`, `ps`, `awk`, `grep`)

---

## Usage

### C++ Implementation

1. **Compile the C++ code**:

    ```bash
    g++ -o system_health_monitor cpp/system_health_monitor.cpp
    ```

2. **Run the compiled program**:

    ```bash
    ./system_health_monitor
    ```

3. **Email Notifications** will be sent if any system metric exceeds the predefined thresholds.

### Shell Script Implementation

1. **Give execute permission** to the shell script:

    ```bash
    chmod +x shell/system_health_monitor.sh
    ```

2. **Run the shell script**:

    ```bash
    ./shell/system_health_monitor.sh
    ```

3. The script will:
   - Log the system health data to a file called `system_health.log`.
   - Display the system health metrics in the terminal.
   - Send email alerts if any thresholds are exceeded.

---

## Thresholds

Both the C++ and shell script versions monitor the following system resources with the below thresholds:

- **CPU Usage**: > 80%
- **Memory Usage**: > 80%
- **Disk Space Usage**: > 80%
- **Active Processes**: > 100 processes

If these thresholds are exceeded, an email alert will be triggered.

---

## Email Alerts

The **mailx** tool is used to send email notifications when system resources exceed the defined thresholds. You can configure the recipient email in both the C++ and Shell implementations. The email will contain a brief message stating which threshold was exceeded and the current value.

Sample alert email:
```
Subject: CPU Usage Alert
Body: CPU usage exceeded 80%
```

---

## Example Output

### C++ Version

```
System Health Dashboard:
------------------------
CPU Usage: 41%
Memory Usage: 44.2117%
Disk Space Usage: 71.9721%
Active Processes: 124
------------------------
Email alert sent successfully!
```

### Shell Script Version

```
System Health Dashboard:
------------------------
CPU Usage: 30%
Memory Usage: 60%
Disk Space Usage: 55%
Active Processes: 95
------------------------
```

Check the `system_health.log` for a detailed log of the shell script execution.

---

## Screenshots

### Terminal Output

Here’s an example of the system health dashboard output from the terminal:

![Terminal](/Screenshots/Terminal.png "Terminal")

### Email Alert

Sample email alert notification when a threshold is breached:

![Email](/Screenshots/Email.png "Email")

---

## Operating Environment

- Developed and tested on **Arch Linux**, but should work on any Unix-based system with the necessary utilities installed.
  
- **Note**: Email functionality relies on `mailx` or similar tools, which should be configured with your email server (e.g., using `ssmtp` or `sendmail` for outgoing emails).

---

## Bonus Features

- The project includes features to **send email alerts** whenever the system exceeds resource thresholds. This was done using the `mailx` utility in both the C++ and Shell implementations.
  
- The shell script additionally logs the data to a file for future reference.

---

## Future Improvements

- Add support for sending **SMS notifications** for critical system health issues.
- Extend the monitoring to network usage or temperature sensors.
- Create a **real-time web dashboard** for remote monitoring of system health.



