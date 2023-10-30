#include <iostream>
#include <limits>
#include "ink_quantity.h"

//This is a program to calculate the ink 
//quantity for a N number of printing sheets.

void ignoreLine();
class NumberOfPrints;
class InkOccupation;
class AddDrying;
void printResult();

std::ostream& operator<<(std::ostream& out, const NumberOfPrints p)
{
    out << static_cast<long>(p.m_prints);
    return out;
}

std::istream& operator>>(std::istream& in, NumberOfPrints p)
{
    in >> p.m_prints;
    return in;
}

bool operator<(const NumberOfPrints& n, int i)
{
    return n.m_prints < i;
}

int main()
{
    printResult();
    return 0;
}
