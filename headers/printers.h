#pragma once
#include <iostream>
//Defined as an interface
class Printers {
public:
    virtual ~Printers() = default;
    virtual void PrintStatus(std::string status_option, std::string status_value) const = 0;
};