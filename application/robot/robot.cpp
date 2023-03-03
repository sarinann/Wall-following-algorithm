#include "robot.h"
#include<cstdlib>
#include<ctime>
/**
 * @file robot.cpp
 * @author Sarin Ann Mathew (sarinann@umd.edu)
 * @author Aditi Bhoir (abhoir@umd.edu)
 * @author Aditya Chaugule (aditya97@umd.edu)
 * @brief Implementation of the attributes defined in Class 'Robot'
 * @version 1.0
 * @date 2022-11-07
 * @copyright Copyright (c) 2022
 */
    /**
     * @brief Method called to set the direction of the robot
    */
    void rwa2group8::Robot::set_direction(char dir){
        m_direction=dir;}

    /**
     * @brief Method called to set the position of the robot
     * 
     * @param x -coordinate of robot
     * @param y -coordinate of robot
     * @return * position of robot
     */
    void rwa2group8::Robot:: set_position(int x, int y){
        m_position.first= x;
        m_position.second =y;
    }
    