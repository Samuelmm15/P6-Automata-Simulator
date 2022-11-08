/**
 * @file automata.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the automata class.
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
#include <stdlib.h>

#include "../include/alphabet.h"
#include "../include/chain.h"
#include "../include/state.h"

#pragma once

class Automata : public Chain {
  public:
    Automata(std::vector<std::string> automata_file_lines_vector);
    Alphabet getAlphabet();
    bool ChainsValidation(std::string chain);

  private:
    int number_of_states_;
    std::vector<State> states_;
    Alphabet alphabet_;
    std::string initial_state_;
};