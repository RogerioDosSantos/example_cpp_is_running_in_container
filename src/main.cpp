
#include <fstream>
#include <iostream>
#include <string>

bool is_running_in_docker()
{
    std::ifstream file;
    file.open("/proc/self/cgroup");
    // file.open("main.cpp");
    if (!file.is_open())
        return false;
    std::string line;
    unsigned int curLine = 0;
    std::string search("docker");
    while (std::getline(file, line))
    {
        if (line.find(search, 0) != std::string::npos)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

int main()
{
    std::cout << "- Checking if file is running inside docker:" << std::endl;
    if (is_running_in_docker())
        std::cout << "-- Is running inside Docker" << std::endl;
    else
        std::cout << "-- Is NOT running inside Docker" << std::endl;
    return 0;
}
