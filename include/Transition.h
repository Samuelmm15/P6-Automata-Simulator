/**
 * @file Transition.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#pragma once

class Transition {
  public:
    Transition();
    void setTransitionSymbol(std::string transition_symbol);
    std::string getTransitionSymbol();
    void setTransitionState(std::string transition);
    std::string getTransitionState();
    std::string at();
  private:
    std::string transition_symbol_;
    std::string transition_;
};