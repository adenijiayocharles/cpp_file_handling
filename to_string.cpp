#include <iostream>
#include <iomanip>
#include <sstream>

void convertToString(double number, int precision)
{
    std::stringstream stream;

    stream << std::fixed << std::setprecision(precision) << number;
    std::cout << stream.str();
}

int main()
{
    double value = 5.6;
    convertToString(value, 2);
    return 0;
}