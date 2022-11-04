/**
 * @file Automata.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-11-04
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

class Automata {
  public:
    Automata(std::vector<std::string> automata_file_lines_vector);
  private:
    std::vector<std::string> states_;
    std::vector<std::string> alphabet_;
    std::vector<std::string> transitions_;
    std::string initial_state_;
    std::vector<std::string> final_states_;
};