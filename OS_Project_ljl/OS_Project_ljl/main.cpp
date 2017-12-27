//
//  main.cpp
//  OS_Project_ljl
//
//  Created by mac on 5/18/17.
//  Copyright (c) 2017 LeeJiangLee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include "process_resource_management.hpp"
#include <list>

int main() {
    std::string command, line;
    
   // std::string defaultpath = "/Volumes/NO\ NAME/";
    std::string path = "/Users/mac/learngit/OS_Project_ljl/OS_Project_ljl/";
    //  path = defaultpath;
    std::ifstream infile(path + "input.txt");
    if (!infile.is_open()) {
        std::cout << "wrong file" << std::endl;
    }
    
    std::ofstream outfile;
    outfile.open(path + "91132408.txt", std::ios::out);
    
    std::string name;
    int priority, unit;
    PRM prm;
    std::cout << "init" << " ";
    outfile << "init" << " ";
    while (std::getline(infile, line)) {
        std::istringstream linestream(line);
        
        if (!line.empty() && line.length() >= 2) {
            
            linestream >> command;
            
            //			std::cout << "line: " << line << std::endl;
            //			std::cout << "command: " << command << std::endl;
            
            if (command == "init") {
                prm.restore();
                std::cout << prm.pcb[prm.current_running].pid << " ";
                outfile << prm.pcb[prm.current_running].pid << " ";
            }
            else if (command == "quit") {
                break;
            }
            else if (command == "cr") {
                linestream >> name >> priority;
                if (prm.contain(name) != -1) {
                    std::cout << "error (duplicate name)" << " ";
                    outfile << "error (duplicate name)" << " ";
                }
                else if (priority > 2 or priority <= 0) {
                    std::cout << "error" << " ";
                }
                else {
                    prm.create(name, priority);
                    std::cout << prm.pcb[prm.current_running].pid << " ";
                    outfile << prm.pcb[prm.current_running].pid << " ";
                }
            }
            else if (command == "de") {
                linestream >> name;
                int t = prm.contain(name);
                if (t == -1) {
                    std::cout << "error (process not existed)" << " ";
                    outfile << "error (process not existed)" << " ";
                }
                else {
                    prm.destroy(t);
                    std::cout << prm.pcb[prm.current_running].pid << " ";
                    outfile << prm.pcb[prm.current_running].pid << " ";
                }
            }
            else if (command == "req") {
                linestream >> name >> unit;
                if (name == "R1" && unit == 1) {
                    prm.request(0, unit);
                    std::cout << prm.pcb[prm.current_running].pid << " ";
                    outfile << prm.pcb[prm.current_running].pid << " ";
                } else if (name == "R2" && (0 < unit && unit <= 2)) {
                    prm.request(1, unit);
                    std::cout << prm.pcb[prm.current_running].pid << " ";
                    outfile << prm.pcb[prm.current_running].pid << " ";
                } else if (name == "R3" && (0 < unit && unit <= 3)) {
                    prm.request(2, unit);
                    std::cout << prm.pcb[prm.current_running].pid << " ";
                    outfile << prm.pcb[prm.current_running].pid << " ";
                } else if (name == "R4" && (0 < unit && unit <= 4)) {
                    prm.request(3, unit);
                    std::cout << prm.pcb[prm.current_running].pid << " ";
                    outfile << prm.pcb[prm.current_running].pid << " ";
                } else {
                    std::cout << "error (invalid request)" << " ";
                    outfile << "error (invalid request)" << " ";
                }
            }
            else if (command == "rel") {
                linestream >> name >> unit;
                if (name == "R1" && unit == 1) {
                    if (prm.pcb[prm.current_running].other_resource[0].used >= unit) {
                        prm.release(0, unit);
                        std::cout << prm.pcb[prm.current_running].pid << " ";
                        outfile << prm.pcb[prm.current_running].pid << " ";
                    } else { std::cout << "error (release exceed actual R1 units)" << " ";
                        outfile << "error (release exceed actual R1 units)" << " ";}
                } else if (name == "R2" && (0 < unit && unit <= 2)) {
                    if (prm.pcb[prm.current_running].other_resource[1].used >= unit) {
                        prm.release(1, unit);
                        std::cout << prm.pcb[prm.current_running].pid << " ";
                        outfile << prm.pcb[prm.current_running].pid << " ";
                    } else { std::cout << "error (release exceed actual R2 units)" << " ";
                        outfile << "error (release exceed actual R2 units)" << " ";}
                } else if (name == "R3" && (0 < unit && unit <= 3)) {
                    if (prm.pcb[prm.current_running].other_resource[2].used >= unit) {
                        prm.release(2, unit);
                        std::cout << prm.pcb[prm.current_running].pid << " ";
                        outfile << prm.pcb[prm.current_running].pid << " ";
                    } else { std::cout << "error (release exceed actual R3 units)" << " ";
                        outfile << "error (release exceed actual R3 units)" << " ";}
                } else if (name == "R4" && (0 < unit && unit <= 4)) {
                    if (prm.pcb[prm.current_running].other_resource[3].used >= unit) {
                        prm.release(3, unit);
                        std::cout << prm.pcb[prm.current_running].pid << " ";
                        outfile << prm.pcb[prm.current_running].pid << " ";
                    } else { std::cout << "error (release exceed actual R4 units)" << " ";
                        outfile << "error (release exceed actual R4 units)" << " ";}
                }
                else {
                    std::cout << "error (invalid release)" << " ";
                    outfile << "error (invalid release)" << " ";
                }
                
            }
            else if (command == "to") {
                prm.timeout();
                std::cout << prm.pcb[prm.current_running].pid << " ";
                outfile << prm.pcb[prm.current_running].pid << " ";
            }
            else {
                std::cout << "error (else error)" << " ";
                outfile << "error (else error)" << " ";
            }
        } else {
            std::cout << std::endl;
            outfile << std::endl;
        }
    }
    
    std::cout << "\nend" << std::endl;
    
    infile.close();
    outfile.close();
    return 0;
}
