#include "../simulator/simulator.h"
#include "../robot/robot.h"
#include "algorithm.h"

/**
 * @file algorithm.cpp
 * @author Sarin Ann Mathew (sarinann@umd.edu)
 * @author Aditi Bhoir      (abhoir@umd.edu)
 * @author Aditya Chaugule  (aditya97@umd.edu)
 * @brief Implementation of class algorithm for initializing outer walls, generating goal and executing search algorithm
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 */

#include <vector>
#include <array>
#include <time.h>
#include <cstdlib>


// Method for initializing outer walls
void rwa2group8::algorithm::init_outer_walls(){
    std ::cerr << "Initializing the outer walls" << '\n';
    int i;
    int j;
    for (i = 0; i <= 15; i++)
    {
        Simulator::setWall(i, 0, 's');
        for (j = 0; j <= 15; j++)
        {
            Simulator ::setWall(j, 15, 'n');
        }
    }

    for (i = 0; i <= 15; i++)
        Simulator ::setWall(0, i, 'w');
    for (j = 0; j <= 15; j++)
    {
        Simulator ::setWall(15, j, 'e');
    }
}

//Method to generate a random goal on each run
void rwa2group8::algorithm::generate_goal() { 
    std ::cerr << "Generating the goal " << '\n';
    int x_coordinate, y_coordinate;
    int max = 15;
    srand(time(0));
    x_coordinate = rand() % max;
    std ::cout << "x is : " << x_coordinate << '\n';

    int max2 = 14;
    if (x_coordinate == 0)
    {
        y_coordinate = 1 + rand() % max2;
        std ::cout << "y is: " << y_coordinate << '\n';
    }

    if (x_coordinate == 15)
    {
        y_coordinate = rand() % max;
        std ::cout << "y is: " << y_coordinate;
    }

    if (x_coordinate != 0 && x_coordinate != 15)
    {
        y_coordinate = (rand() > RAND_MAX / 2) ? 0 : 15;
    }
    std ::cerr << "Goal is :" << "( " << x_coordinate << "," << y_coordinate << " )" << "\n";
    Simulator::setColor(x_coordinate, y_coordinate, 'R');
    Simulator::setText(x_coordinate, y_coordinate, "G");    
    goal.first = x_coordinate;
    goal.second = y_coordinate;
}

// Method to set the front wall
void rwa2group8::algorithm::set_front_wall(int x, int y, char dir) {
     if (Simulator::wallFront()){
        if (dir == 'n')
        {
            Simulator::setWall(x, y, 'n');
        }
        else if (dir == 'e')
        {
            Simulator::setWall(x, y, 'e');
        }
        else if (dir == 's')
        {
            Simulator::setWall(x, y, 's');
        }
        else
        {
            Simulator::setWall(x, y, 'w');
        }
    }
}

//Method to set the left wall
void rwa2group8::algorithm::set_left_wall(int x, int y, char dir) {
     if (Simulator::wallLeft())
        if (dir == 'n')
        {
            Simulator::setWall(x, y, 'w');
        }
        else if (dir == 'e')
        {
            Simulator::setWall(x, y, 'n');
        }
        else if (dir == 's')
        {
            Simulator::setWall(x, y, 'e');
        }
        else
        {
            Simulator::setWall(x, y, 's');
        }
    
}

//Method to set the right wall
void rwa2group8::algorithm::set_right_wall(int x, int y, char dir){
     if (Simulator::wallRight()) {
        if (dir == 'n')
        {
            Simulator::setWall(x, y, 'e');
        }
        else if (dir == 'e')
        {
            Simulator::setWall(x, y, 's');
        }
        else if (dir == 's')
        {
            Simulator::setWall(x, y, 'w');
        }
        else
        {
            Simulator::setWall(x, y, 'n');
        }
    }
}

//Algorithm for left handed approach to follow the wall
void rwa2group8::algorithm::follow_wall_left(){
    std::cerr << "Left_Wall Following Algorithm"<<std::endl;
    auto robot = std::make_unique<rwa2group8::Robot>(); 
    Simulator::setColor(x, y, 'C');
    Simulator::setText(x, y, "S");    
    while (x != goal.first || y != goal.second){ 
        set_right_wall(x, y, robot->get_direction());
        set_left_wall(x, y, robot->get_direction());
        set_front_wall(x, y, robot->get_direction());   
          
        {
        if (robot ->get_direction() == 'n')
        {
            if (Simulator::wallLeft())
            {
                if (Simulator::wallFront())
                {
                    if (Simulator::wallRight())
                        {
                        Simulator::turnLeft();
                        std::cerr << "--- turn left ---" << std::endl;
                        Simulator::turnLeft();
                        std::cerr << "--- turn left ---" << std::endl;
                        y -= 1;
                        robot->set_direction('s');
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();                            
                        Simulator::setColor(x, y, 'C');
                        }
                        else
                        {
                            std::cerr << "--- turn right ---" << std::endl;
                            Simulator::turnRight();
                            robot->set_direction('e');
                            std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            x += 1;
                            Simulator::setColor(x, y, 'C');
                        }
                    }
                    else
                    {
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        y += 1;
                        Simulator::setColor(x, y, 'C');
                    }
                }
                else
                {
                    std::cerr << "--- turn left ---" << std::endl;
                    Simulator::turnLeft();
                    x -= 1;
                    robot->set_direction('w');
                    std :: cerr << "--- move forward ---" << std::endl;
                    Simulator::moveForward();
                    Simulator::setColor(x, y, 'C');
                }
            }

            else if (robot ->get_direction() == 'e')
            {
                if (Simulator::wallLeft())
                {
                    if (Simulator::wallFront())
                    {
                        if (Simulator::wallRight())
                        {
                            std::cerr << "--- turn left ---" << std::endl;
                            Simulator::turnLeft();
                            std::cerr << "--- turn left ---" << std::endl;
                            Simulator::turnLeft();
                            x -= 1;
                            robot->set_direction('w');
                            std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            Simulator::setColor(x, y, 'C');
                        }
                        else
                        {
                            std::cerr << "--- turn right ---" << std::endl;
                            Simulator::turnRight();
                            y -= 1;
                            robot->set_direction('s');
                            std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            Simulator::setColor(x, y, 'C');
                        }
                    }
                    else
                    {
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        x += 1;
                        Simulator::setColor(x, y, 'C');
                    }
                }
                else
                {
                    std::cerr << "--- turn left ---" << std::endl;
                    Simulator::turnLeft();
                    y += 1;
                    robot->set_direction('n');
                    std :: cerr << "--- move forward ---" << std::endl;
                    Simulator::moveForward();
                    Simulator::setColor(x, y, 'C');
                }
            }

            else if (robot ->get_direction() == 's')
            {
                if (Simulator::wallLeft())
                {
                    if (Simulator::wallFront())
                    {
                        if (Simulator::wallRight())
                        {
                            std::cerr << "--- turn left ---" << std::endl;
                            Simulator::turnLeft();
                            std::cerr << "--- turn left ---" << std::endl;
                            Simulator::turnLeft();
                            y += 1;
                            robot->set_direction('n');
                            std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            Simulator::setColor(x, y, 'C');
                        }
                        else
                        {
                            std::cerr << "--- turn right ---" << std::endl;
                            Simulator::turnRight();
                            x -= 1;
                            robot->set_direction('w');
                            std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            Simulator::setColor(x, y, 'C');
                        }
                    }
                    else
                    {
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        y -= 1;
                        Simulator::setColor(x, y, 'C');
                    }
                }
                else
                {
                    std::cerr << "--- turn left ---" << std::endl;
                    Simulator::turnLeft();
                    x += 1;
                    robot->set_direction('e');
                    std :: cerr << "--- move forward ---" << std::endl;
                    Simulator::moveForward();
                    Simulator::setColor(x, y, 'C');
                }
            }

            else if (robot ->get_direction() == 'w')
            {
                if (Simulator::wallLeft())
                {
                    if (Simulator::wallFront())
                    {
                        if (Simulator::wallRight())
                        {
                            std::cerr << "--- turn left ---" << std::endl;
                            Simulator::turnLeft();
                            std::cerr << "--- turn left ---" << std::endl;
                            Simulator::turnLeft();
                            x += 1;
                            robot->set_direction('e');
                            std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            Simulator::setColor(x, y, 'C');
                        }
                        else
                        {
                            std::cerr << "--- turn right ---" << std::endl;
                            Simulator::turnRight();
                            y += 1;
                            robot->set_direction('n');
                            std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            Simulator::setColor(x, y, 'C');
                        }
                    }
                    else
                    {
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        x -= 1;
                        Simulator::setColor(x, y, 'C');
                    }
                }
                else
                {
                    std::cerr << "--- turn left ---" << std::endl;
                    Simulator::turnLeft();
                    y -= 1;
                    robot->set_direction('s');
                    std :: cerr << "--- move forward ---" << std::endl;
                    Simulator::moveForward();
                    Simulator::setColor(x, y, 'C');
                }
            }
    robot ->set_position(x, y);
    std::cerr <<"Robot position: " << x << "," << y << std::endl;
    }     
    }
}

//Algorithm for right handed approach to follow the wall
void rwa2group8::algorithm::follow_wall_right(){
    std::cerr << "Right_Wall Following Algorithm"<<std::endl;
    auto robot = std::make_unique<rwa2group8::Robot>(); 
    Simulator::setColor(x, y, 'C');
    Simulator::setText(x, y, "S");   
    while(x != goal.first || y != goal.second){ 
        set_right_wall(x, y, robot->get_direction());
        set_left_wall(x, y, robot->get_direction());
        set_front_wall(x, y, robot->get_direction());    
        {
        if (robot ->get_direction() == 'n'){
            if (Simulator::wallRight()){
                if (Simulator::wallFront()){
                    if (Simulator::wallLeft()){
                        Simulator::turnRight();
                        std::cerr << "--- turn right ---" << std::endl;
                        Simulator::turnRight();
                        std::cerr << "--- turn right---" << std::endl;
                        y -= 1;
                        robot->set_direction('s');
                         std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();                            
                        Simulator::setColor(x, y, 'C');
                        }
                        else
                        {
                            std::cerr << "--- turn left ---" << std::endl;
                            Simulator::turnLeft();
                            robot->set_direction('w');
                             std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            x -= 1;
                            Simulator::setColor(x, y, 'C');
                        }
                }
                    else
                    {
                         std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        y += 1;
                        Simulator::setColor(x, y, 'C');
                    }
            }
            else
            {
                std::cerr << "--- turn right ---" << std::endl;
                Simulator::turnRight();
                x += 1;
                robot->set_direction('e');
                std :: cerr << "--- move forward ---" << std::endl;
                Simulator::moveForward();
                Simulator::setColor(x, y, 'C');
            }
        }

        else if (robot ->get_direction() == 'e'){
            if (Simulator::wallRight()){
                if (Simulator::wallFront()){
                    if (Simulator::wallLeft()){
                            std::cerr << "--- turn right ---" << std::endl;
                            Simulator::turnRight();
                            std::cerr << "--- turn right ---" << std::endl;
                            Simulator::turnRight();
                            x -= 1;
                            robot->set_direction('w');
                             std :: cerr << "--- move forward ---" << std::endl;
                            Simulator::moveForward();
                            Simulator::setColor(x, y, 'C');
                    }
                    else{     
                        std::cerr << "--- turn left ---" << std::endl;
                        Simulator::turnLeft();
                        y += 1;
                        robot->set_direction('n');
                         std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        Simulator::setColor(x, y, 'C');
                    }
                }
                else{
                    std :: cerr << "--- move forward ---" << std::endl;
                    Simulator::moveForward();
                    x += 1;
                    Simulator::setColor(x, y, 'C');
                }
            }
            else{
                std::cerr << "--- turn right ---" << std::endl;
                Simulator::turnRight();
                y -= 1;
                robot->set_direction('s');
                std :: cerr << "--- move forward ---" << std::endl;
                Simulator::moveForward();
                Simulator::setColor(x, y, 'C');
            }
        }

        else if (robot ->get_direction() == 's'){
            if (Simulator::wallRight()){
                if (Simulator::wallFront()){
                    if (Simulator::wallLeft()){
                        std::cerr << "--- turn right ---" << std::endl;
                        Simulator::turnRight();
                        std::cerr << "--- turn right ---" << std::endl;
                        Simulator::turnRight();
                        y += 1;
                        robot->set_direction('n');
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        Simulator::setColor(x, y, 'C');
                    }
                    else{
                        std::cerr << "--- turn left---" << std::endl;
                        Simulator::turnLeft();
                        x += 1;
                        robot->set_direction('e');
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        Simulator::setColor(x, y, 'C');
                    }
                }
                else{
                    std :: cerr << "--- move forward ---" << std::endl;
                    Simulator::moveForward();
                    y -= 1;
                    Simulator::setColor(x, y, 'C');
                }
            }
            else
            {
                std::cerr << "--- turn right ---" << std::endl;
                Simulator::turnRight();
                x -= 1;
                robot->set_direction('w');
                std :: cerr << "--- move forward ---" << std::endl;
                Simulator::moveForward();
                Simulator::setColor(x, y, 'C');
            }
        }

        else if(robot ->get_direction() == 'w'){
            if (Simulator::wallRight()){
                if (Simulator::wallFront()){
                    if (Simulator::wallLeft()){
                        std::cerr << "--- turn right ---" << std::endl;
                        Simulator::turnRight();
                        std::cerr << "--- turn right---" << std::endl;
                        Simulator::turnRight();
                        x += 1;
                        robot->set_direction('e');
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        Simulator::setColor(x, y, 'C');
                    }
                    else{
                        std::cerr << "--- turn left ---" << std::endl;
                        Simulator::turnLeft();
                        y -= 1;
                        robot->set_direction('s');
                        std :: cerr << "--- move forward ---" << std::endl;
                        Simulator::moveForward();
                        Simulator::setColor(x, y, 'C');
                    }
                }
                else{
                    std :: cerr << "--- move forward ---" << std::endl;
                    Simulator::moveForward();
                    x -= 1;
                    Simulator::setColor(x, y, 'C');
                }
            }
            else{
                std::cerr << "--- turn right ---" << std::endl;
                Simulator::turnRight();
                y += 1;
                robot->set_direction('n');
                std :: cerr << "--- move forward ---" << std::endl;
                Simulator::moveForward();
                Simulator::setColor(x, y, 'C');
            }
        }
    }
    robot ->set_position(x,y);
    std::cerr <<"Robot position: " << x << "," << y << std::endl;
    }
}


//Method to set the outer walls, generate the goal and follow left handed approach 
void rwa2group8::algorithm::run_left()
{
    init_outer_walls();
    generate_goal();
    follow_wall_left(); 
    std :: cerr << "Goal reached" << std :: endl;
    Simulator::clearAllColor();
    Simulator::clearText(goal.first, goal.second);
    Simulator::ackReset();
}

//Method to set the outer walls, generate the goal and follow right handed approach 
void rwa2group8::algorithm::run_right()
{
    init_outer_walls();
    generate_goal();
    follow_wall_right();
    std :: cerr << "Goal reached" << std :: endl;
    Simulator::clearAllColor();
    Simulator::clearText(goal.first, goal.second);
    Simulator::ackReset(); 
}

