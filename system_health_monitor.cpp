#include <iostream>
#include <string>
#include <cstdio>
#include <sys/statvfs.h>
#include <unistd.h>

float getCPUUsage() {
    std::string command = "top -bn1 | grep 'Cpu(s)' | awk '{print $2}' | awk -F. '{print $1}'";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return -2.0;
    float cpuUsage;
    fscanf(pipe, "%f", &cpuUsage);
    pclose(pipe);
    return cpuUsage;
}

float getMemoryUsage() {
    std::string command = "free -m | awk 'NR==2{printf \"%s\", $3*100/$2 }'";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return -1.0;
    float memoryUsage;
    fscanf(pipe, "%f", &memoryUsage);
    pclose(pipe);
    return memoryUsage;
}

float getDiskSpaceUsage() {
    struct statvfs buf;
    statvfs("/", &buf);
    float diskSpaceUsage = (buf.f_blocks - buf.f_bfree) * 100.0 / buf.f_blocks;
    return diskSpaceUsage;
}

int main() {
    std::cout << "System Health Monitor" << std::endl;
    float cpuUsage = getCPUUsage();
    std::cout << "CPU Usage: " << cpuUsage << "%" << std::endl;
    float memoryUsage = getMemoryUsage();
    std::cout << "Memory Usage: " << memoryUsage << "%" << std::endl;
    float diskSpaceUsage = getDiskSpaceUsage();
    std::cout << "Disk Space Usage: " << diskSpaceUsage << "%" << std::endl;
    return 0;
}