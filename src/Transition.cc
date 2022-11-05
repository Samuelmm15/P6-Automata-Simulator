/**
 * @file Transition.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * @signature Computabilidad y Algoritmia.
 *  @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/Transition.h"

Transition::Transition() {
  transition_ = "";
};

void Transition::setTransitionSymbol(std::string transition_symbol) {
  transition_symbol_ = transition_symbol;
};

std::string Transition::getTransitionSymbol() {
  return transition_symbol_;
};

void Transition::setTransitionState(std::string transition) {
    transition_ = transition;
};

std::string Transition::getTransitionState() {
  return transition_;
};

std::string Transition::at() {
    return transition_;
};