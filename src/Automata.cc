/**
 * @file Automata.cc
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

#include "../include/Automata.h"
#include "../include/Alphabet.h"

Automata::Automata(std::vector<std::string> automata_file_lines_vector) {
  std::string auxiliary_line;
  for (int i = 0; i < automata_file_lines_vector.size(); i++) {
    if (i == 0) {
        auxiliary_line = automata_file_lines_vector[i];
        std::vector<std::string> auxiliary_input;
        for (int j = 0; j < auxiliary_line.size(); j++) {
          if (auxiliary_line[j] != ' ') {
            std::string auxiliary_string;
            auxiliary_string = auxiliary_line[j];
            auxiliary_input.push_back(auxiliary_string);
          }
        }
        Alphabet auxiliary_alphabet;
        auxiliary_input.push_back(auxiliary_line);
        auxiliary_alphabet.setSymbolsToAlphabet(auxiliary_input);
        auxiliary_line.clear();
        std::cout << "Alfabeto del autómata introducido: ";
        auxiliary_alphabet.PrintAlphabet();
        std::cout << std::endl;
        alphabet_ = auxiliary_alphabet; /// Establecimiento del alfabeto del autómata.
    } else if (i == 1) {
      number_of_states_ = std::stoi(automata_file_lines_vector[i]); /// Necesario para convertir a entero
    } else if (i == 2) {
      initial_state_ = automata_file_lines_vector[i];
    } else { /// En este punto se produce el establecimiento de los distintos nodos y transiciones
      /// Creación del vector de estados que tiene asociadas transiciones
    }
  }
};