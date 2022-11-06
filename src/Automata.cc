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

/// TENER EN CUENTA QUE SE DEBE DE TENER EN CUENTA TANTO LOS NFAs COMO LOS DFAs
/// TENER EN CUENTA TODAS LAS POSIBLES COMPROBACIONES DE ERRORES CUANDO SE FINALICE CON LA IMPLEMENTACIÓN

#include "../include/Automata.h"
#include "../include/Alphabet.h"
#include "../include/State.h"
#include "../include/Transition.h"

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
      auxiliary_line = automata_file_lines_vector[i];
      auxiliary_line.erase(std::remove(auxiliary_line.begin(), auxiliary_line.end(), ' '), auxiliary_line.end()); 
      // std::cout << "Linea: " << auxiliary_line << std::endl; /// SIRVE PARA LA COMPROBACIÓN
      State auxiliary_state;
      Transition auxiliary_transition;
      bool introduction_of_state = false;
      for (int j = 0; j < auxiliary_line.size(); j++) {
        if (j == 0) {
          std::string auxiliary_string;
          auxiliary_string = auxiliary_line[j];
          auxiliary_state.setState(auxiliary_string);
        } else if (j == 1) {
          if (auxiliary_line[j] == '0') {
            auxiliary_state.setFinalState(false);
          } else {
            auxiliary_state.setFinalState(true);
          }
        } else if (j == 2) {
          std::string auxiliary_string;
          auxiliary_string.push_back(auxiliary_line[j]);
          int auxiliary_number_of_transitions = std::stoi(auxiliary_string);
          auxiliary_state.setNumberTransitions(auxiliary_number_of_transitions);
        } else {
          if (introduction_of_state == false) {
            std::string auxiliary_string;
            auxiliary_string.push_back(auxiliary_line[j]);
            auxiliary_transition.setTransitionSymbol(auxiliary_string);
            introduction_of_state = true;
          } else {
            std::string auxiliary_string;
            auxiliary_string.push_back(auxiliary_line[j]);
            auxiliary_transition.setTransitionState(auxiliary_string);
            auxiliary_state.setTransitions(auxiliary_transition);
            introduction_of_state = false;
            Transition auxiliary_transition_; /// De esta manera se reinicia el objeto
          }
        }
      }
      auxiliary_line.clear();
      states_.push_back(auxiliary_state);
    }
  } /// En este punto el autómata está creado de manera correcta
  // states_[0].PrintState();
  // std::cout << std::endl;
  // states_[1].PrintState();
  // std::cout << std::endl;
  // states_[2].PrintState();
  // std::cout << std::endl;
  // states_[3].PrintState();
};

Alphabet Automata::getAlphabet() {
  return alphabet_;
};

void Automata::ChainValidation(std::vector<Chain> chains_to_validate) {
  std::cout << std::endl;
  for (int i = 0; i < chains_to_validate.size(); i++) {
    std::string chain_to_validate = chains_to_validate[i].getChain();
    std::string current_state = initial_state_;
    bool chain_accepted = true;
    for (int j = 0; j < chain_to_validate.size(); j++) {
      std::string chain_symbol;
      chain_symbol.push_back(chain_to_validate[j]);
      bool symbol_accepted = false;
      for (int k = 0; k < states_.size(); k++) {
        if (states_[k].getState() == current_state) {
          for (int l = 0; l < states_[k].getTransition().size(); l++) {
            if (states_[k].getTransition()[l].getTransitionSymbol() == chain_symbol) {
              current_state = states_[k].getTransition()[l].getTransitionState();
              std::cout << "Estado actual: " << current_state << std::endl;
              symbol_accepted = true;
            }
          }
        }
      }
      if (symbol_accepted == false) {
        std::cout << "Cadena no aceptada" << std::endl;
        chain_accepted = false;
      }
    }
    if (chain_accepted == true) {
      for (int j = 0; j < states_.size(); j++) {
        if (states_[j].getState() == current_state) {
          std::cout << states_[j].getState() << std::endl;
          std::cout << states_[j].getFinalState() << std::endl;
          if (states_[j].getFinalState() == true) {
            std::cout << "Cadena aceptada: " << chain_to_validate << std::endl;
          } else {
            std::cout << "Cadena rechazada: " << chain_to_validate << std::endl;
          }
        }
      }
    } else {
      std::cout << "Cadena rechazada: " << chain_to_validate << std::endl;
    }
  }

  // std::cout << std::endl;
  // std::cout << "Comprobación de cadenas: " << std::endl;
  // for (int i = 0; i < chains_to_validate.size(); i++) {
  //   std::cout << "Cadena " << i + 1 << ": " << chains_to_validate[i].getChain() << std::endl;
  //   std::cout << "Resultado: ";
  //   std::string chain_to_validate = chains_to_validate[i].getChain();
  //   std::string current_state = initial_state_;
  //   std::string next_state;
  //   bool chain_accepted = false;
  //   for (int j = 0; j < chain_to_validate.size(); j++) {
  //     std::string chain_symbol;
  //     chain_symbol.push_back(chain_to_validate[j]);
  //     for (int k = 0; k < states_.size(); k++) {
  //       if (states_[k].getState() == current_state) {
  //         for (int l = 0; l < states_[k].getTransition().size(); l++) {
  //           if (states_[k].getTransition()[l].getTransitionSymbol() == chain_symbol) {
  //             next_state = states_[k].getTransition()[l].getTransitionState();
  //             current_state = next_state;
  //           }
  //         }
  //       }
  //     }
  //   }
  //   for (int j = 0; j < states_.size(); j++) {
  //     if (states_[j].getState() == current_state) {
  //       if (states_[j].getFinalState() == true) {
  //         chain_accepted = true;
  //         break;
  //       }
  //     }
  //   }
  //   if (chain_accepted == true) {
  //     std::cout << "Cadena aceptada" << std::endl;
  //   } else {
  //     std::cout << "Cadena rechazada" << std::endl;
  //   }
  // }

  // std::cout << std::endl;
  // for (int i = 0; i < chains_to_validate.size(); i++) {
  //   std::string auxiliary_chain = chains_to_validate[i].getChain();
  //   if (auxiliary_chain == "&") { /// En el caso de que una de las cadenas sea vacía
  //     for (int j = 0; j < states_.size(); j++) {
  //       if (states_[j].getState() == initial_state_) {
  //         if (states_[j].getFinalState() == true) {
  //           std::cout << auxiliary_chain << " --- Accepted" << std::endl;
  //         } else {
  //           std::cout << auxiliary_chain << " --- Rejected" << std::endl;
  //         }
  //       }
  //     }
  //   } else {
  //     std::string auxiliary_state = initial_state_;
  //     bool chain_accepted = false;
  //     std::cout << auxiliary_chain.size() << std::endl;
  //     for (int j = 0; j < auxiliary_chain.size(); j++) {
  //       std::string auxiliary_string;
  //       auxiliary_string.push_back(auxiliary_chain[j]);
  //       for (int k = 0; k < states_.size(); k++) {
  //         if (states_[k].getState() == auxiliary_state) {
  //           std::cout << "Estado actual: " << states_[k].getState() << std::endl;
  //           std::cout << "Símbolo actual: " << auxiliary_string << std::endl;
  //           // if (j == auxiliary_chain.size() - 1) {
  //           //   if (states_[k].getFinalState() == true) {
  //           //     chain_accepted = true;
  //           //   }
  //           // }
  //           // bool transition_found = false;
  //           for (int l = 0; l < states_[k].getTransition().size(); l++) {
  //             std::cout << "Transición: " << states_[k].getTransition()[l].getTransitionSymbol() << " -> " << states_[k].getTransition()[l].getTransitionState() << std::endl;
  //             if (states_[k].getTransition()[l].getTransitionSymbol() == auxiliary_string) {
  //               auxiliary_state = states_[k].getTransition()[l].getTransitionState();
  //               // transition_found = true;
  //               std::cout << "Estado siguiente: " << auxiliary_state << std::endl;
  //               if (j == auxiliary_chain.size() - 1) {
  //                 for (int m = 0; m < states_.size(); m++) {
  //                   if (states_[m].getState() == auxiliary_state) {
  //                     if (states_[m].getFinalState() == true) {
  //                       chain_accepted = true;
  //                     }
  //                   }
  //                 }
  //               }
  //             } else {
  //               if (j == auxiliary_chain.size() - 1) {
  //                 for (int m = 0; m < states_.size(); m++) {
  //                   if (states_[m].getState() == auxiliary_state) {
  //                     if (states_[m].getFinalState() == true) {
  //                       chain_accepted = true;
  //                     }
  //                   }
  //                 }
  //               }
  //             }
  //           }
  //         }
  //       }
  //       // if (j == auxiliary_chain.size() - 1) {
  //       //   for (int m = 0; m < states_.size(); m++) {
  //       //     if (states_[m].getState() == auxiliary_state) {
  //       //       if (states_[m].getFinalState() == true) {
  //       //         chain_accepted = true;
  //       //       }
  //       //     }
  //       //   }
  //       // }
  //       auxiliary_string.clear();
  //     }
  //     if (chain_accepted == true) {
  //       std::cout << auxiliary_chain << " --- Accepted" << std::endl;
  //     } else {
  //       std::cout << auxiliary_chain << " --- Rejected" << std::endl;
  //     }
  //   }
  // }
};