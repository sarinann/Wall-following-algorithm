#ifndef __ROBOT__H
#define __ROBOT__H
/**
 * @file robot.h
 * @author Sarin Ann Mathew (sarinann@umd.edu)
 * @author Aditi Bhoir (abhoir@umd.edu)
 * @author Aditya Chaugule (aditya97@umd.edu)
 * @brief The class 'Robot' includes all the functions required to 
 *        get the direction and position of the robot on the maze.
 * @version 1.0
 * @date 2022-11-07
 * @copyright Copyright (c) 2022
 */
#include <iostream>
#include<array>
#include<memory>

namespace rwa2group8 {
    /**
     * @brief This class represents all the attributes to define the 
     *        robot position and direction.
     */
    class Robot{
    /**
     * @brief Defining all the public attributes of the class 'Robot'
     * 
     */
    public:

    /**
     * @brief Get the direction of the robot - N, S , E or W
     * 
     * @return direction of robot
     */
    char get_direction(){return m_direction;}

    /**
     * @brief Get the position of the robot
     * 
     * @return x and y coordinates of the robot
     */
    std::pair<int, int> get_position(){return m_position;}

    /**
     * @brief Update and Set the direction of the robot to N, S, E or W
     * 
     * @param direction of robot
     */

    void set_direction(char d);

    /**
     * @brief Set the position of the robot
     * 
     * @param x- coordinate of the robot (0 to 15)
     * @param y- coorfinate of the robot (0 to 15)
     */
    void set_position(int x, int y);
    
    /**
     * @brief Defining all the private attributes of the class Robot
     * 
     */
    private:

    /**
     * @brief X and Y position of robot
     * 
     */
    std :: pair<int , int> m_position;

    /**
     * @brief direction of robot
     * 
     */
    char m_direction {'n'};
    }; //class robot
}//namespace rwa2group8


#endif