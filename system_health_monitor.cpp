#include <iostream>
#include <string>
#include <cstdio>

float getCPUUsage() {
    std::string command = "top -bn1 | grep 'Cpu(s)' | awk '{print $2}' | awk -F. '{print $1}'";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return -2.0;
    float cpuUsage;
    fscanf(pipe, "%f", &cpuUsage);
    pclose(pipe);
    return cpuUsage;
}

int main() {
    std::cout << "System Health Monitor" << std::endl;
    float cpuUsage = getCPUUsage();
    std::cout << "CPU Usage: " << cpuUsage << "%" << std::endl;
    return 0;
}