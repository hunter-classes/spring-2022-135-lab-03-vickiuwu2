#include "reverseorder.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

void reverse_order(std::string date1, std::string date2)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
        if (fin.fail()) 
        {
            std::cerr << "File cannot be opened for reading." << std::endl;
            exit(1); 
        }

    std::string junk;       
    std::getline(fin, junk); 

    std::string date;
    std::string eastSt, eastEl, westSt, westEl;
    std::string s = "";
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl && date <= date2) 
    {
        fin.ignore(INT_MAX, '\n');
        if (date1 <= date)
        {
            s = westEl + "\n" + s;
        }
    }
    std::cout << s;
    fin.close();
}