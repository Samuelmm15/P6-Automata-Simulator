/**
 * @file State.h
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

#include "../include/Transition.h"

#pragma once

class State {
  public:
    State();
    ~State();
    void setState(std::string state_number);
    void setTransitions(Transition transition);
    void setFinalState(bool final_state);
  private:
    std::string state_;
    std::vector<Transition> transitions_;
    bool final_state_; /// Para comprobar si se trata de un estado de aceptación o no.
};