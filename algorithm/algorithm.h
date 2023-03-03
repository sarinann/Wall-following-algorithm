#ifndef __ALGORITHM__H
#define __ALGORITHM__H

/**
 * @file algorithm.h
 * @author Sarin Ann Mathew (sarinann@umd.edu)
 * @author Aditi Bhoir      (abhoir@umd.edu)
 * @author Aditya Chaugule  (aditya97@umd.edu)
 * @brief Definition of class algorithm 
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include<array>
#include<memory>


namespace rwa2group8 {
    /**
     * @brief The class algorithm includes the attributes and methods for setting the outer walls, generating the goal and executing the search algorithm
     */
    class algorithm{
    public:
    /**
     * @brief Method to reach to the goal with all the deliverables using the left handed wall following algorithm
     * 
     */
    void run_left();
    /**
     * @brief Method to reach to the goal with all the deliverables using the right handed wall following algorithm
     * 
     */
    void run_right();
    /**
     * @brief Method to set or initialize the outer walls of the maze
     * 
     */
    void init_outer_walls();
    /**
     * @brief Method to implement the left handed wall following algorithm
     * 
     */
    void follow_wall_left();
    /**
     * @brief Method to implement the right handed wall following algorithm
     * 
     */
    void follow_wall_right();
    /**
     * @brief Method to generate a random goal adjcent to the outer walls
     * 
     */
    void generate_goal();
    /**
     * @brief Set the right wall object
     * 
     * @param x X coodinate of the cell 
     * @param y Y cordinate of the cell
     * @param dir Direction of the front wall ('n', 's', 'e', 'w')
     */
    void set_right_wall(int x, int y, char dir);
    /**
     * @brief Set the front wall object
     * 
     * @param x X coodinate of the cell 
     * @param y Y cordinate of the cell
     * @param dir Direction of the right wall ('n', 's', 'e', 'w')
     */
    void set_front_wall(int x, int y, char dir);
    /**
     * @brief Set the left wall object
     * 
     * @param x X coodinate of the cell 
     * @param y Y coodinate of the cell 
     * @param dir Direction of the left wall ('n', 's', 'e', 'w')
     */
    void set_left_wall(int x, int y, char dir);
    /**
     * @brief X coordinate of the goal
     * 
     */
    int x_coordinate{0};
    /**
     * @brief Y coordinate of the goal
     * 
     */
    int y_coordinate{0};
    /**
     * @brief X and Y coordinates of the cell
     * 
     */
    int x{0}, y{0};


    private:
    /**
     * @brief Pointer to represent the robot on the maze
     * 
     */
    std :: unique_ptr<Robot> robot;
    /**
     * @brief Pair of coordinates of the random goal
     * 
     */
    std :: pair<int, int> goal;

    }; //class algorithm

}//namespace rwa2group8

#endif