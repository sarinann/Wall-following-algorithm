/**
 * @file main.cpp
 * @author Sarin Ann Mathew (sarinann@umd.edu)
 * @author Aditi Bhoir (abhoir@umd.edu)
 * @author Aditya Chaugule (aditya97@umd.edu)
 * @brief Main Function
 * @version 1.0
 * @date 2022-11-07 
 * @copyright Copyright (c) 2022
 */

#include <iostream>
#include <string>
#include "simulator/simulator.h"
#include "robot/robot.h"
#include "algorithm/algorithm.h"

/**
 * @brief 
 * 
 * @param argc - Number of arguments
 * @param argv - A pointer representing the value of the argument
 * @return String to the argument "-left" or "-right"
 */
int main(int argc, char *argv[])
{
    rwa2group8::algorithm obj;
    std::unique_ptr<rwa2group8::algorithm> function;
    if(argc ==2){
        if (std::string(argv[1])=="-left")
        {
        std::cerr << "Left Handed Algorithm Initiated"<<std::endl;
        rwa2group8::algorithm obj;
        obj.run_left();
        
        }
        else{
        std::cerr << "Right Handed Algorithm Initiated"<<std::endl;
        rwa2group8::algorithm obj;
        obj.run_right();
       
        }
    }
    else {std::cerr << "Please enter value for algorithm"<<std::endl;}
}
