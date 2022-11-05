/**
 * @file State.cc
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

#include "../include/State.h"
#include "../include/Transition.h"

State::State() {
  state_ = "";
};

State::~State() {
  state_ = "";
  transitions_.clear();
};

void State::setState(std::string state_number) {
  state_ = state_number;
};

void State::setTransitions(Transition transition) {
  transitions_.push_back(transition);
};

void State::setFinalState(bool final_state) {
  final_state_ = final_state;
};

void State::setNumberTransitions(int number_transitions) {
  number_of_transitions_ = number_transitions;
};

Transition State::getTransition(int position) {
  return transitions_[position];
};

void State::PrintState() {
    std::cout << "State: " << state_ << std::endl;
    std::cout << "Number of transitions: " << number_of_transitions_ << std::endl;
    std::cout << "Transitions: " << std::endl;
    for (int i = 0; i < transitions_.size(); i++) {
        std::cout << getTransition(i).at() << std::endl;
    }
};