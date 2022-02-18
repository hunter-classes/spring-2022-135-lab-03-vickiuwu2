#include "reservoir.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

double get_east_storage(std::string date)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
        if (fin.fail()) 
        {
            std::cerr << "File cannot be opened for reading." << std::endl;
            exit(1); 
        }
    double ans = 0;
    std::string junk;       
    std::getline(fin, junk); 
    std::string date2;
    double eastSt, eastEl, westSt, westEl;
    while(fin >> date2 >> eastSt >> eastEl >> westSt >> westEl) 
    {
        fin.ignore(INT_MAX, '\n');
        if (date == date2)
        {
           ans = eastSt;
        }
    }
    return ans;

    fin.close();
}

double get_min_east()
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
    double eastSt, eastEl, westSt, westEl;
    double min = 999999999;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
    {
        fin.ignore(INT_MAX, '\n');
        if (min > eastSt)
        {
            min = eastSt;
        }
    }

    return min;

    fin.close();
}

double get_max_east()
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
    double eastSt, eastEl, westSt, westEl;
    double max = 0;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
    {
        fin.ignore(INT_MAX, '\n');
        if (max < eastSt)
        {
            max = eastSt;
        }
    }

    return max;

    fin.close();
}

std::string compare_basins(std::string date)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
        if (fin.fail()) 
        {
            std::cerr << "File cannot be opened for reading." << std::endl;
            exit(1); 
        }

    std::string junk;       
    std::getline(fin, junk); 

    std::string date2;
    std::string ans = " ";
    double eastSt, eastEl, westSt, westEl;
    while(fin >> date2 >> eastSt >> eastEl >> westSt >> westEl) 
    {
        fin.ignore(INT_MAX, '\n');
        if (date == date2)
        {   
            if (eastEl > westEl)
            {
                ans = "East"; 
            }
            else if (westEl > eastEl)
            {
                ans = "West";
            }
            else if (westEl == eastEl)
            {
                ans = "Equal";
            }
        }
    }
    return ans;

    fin.close();
}