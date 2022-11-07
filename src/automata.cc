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

#include "../include/automata.h"
#include "../include/alphabet.h"
#include "../include/state.h"
#include "../include/transition.h"

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

bool Automata::ChainsValidation(std::string chain) {
  std::string current_state = initial_state_;
  std::string next_state;
  bool chain_accepted = false;
  for (int i = 0; i < chain.size(); i++) {
    std::string auxiliary_string;
    auxiliary_string.push_back(chain[i]);
    for (int j = 0; j < states_.size(); j++) {
      if (states_[j].getState() == current_state) {
        for (int k = 0; k < states_[j].getTransition().size(); k++) {
          if (states_[j].getTransition()[k].getTransitionSymbol() == auxiliary_string) {
            next_state = states_[j].getTransition()[k].getTransitionState();
          }
        }
      }
    }
    current_state = next_state;
  }
  for (int i = 0; i < states_.size(); i++) {
    if (states_[i].getState() == current_state) {
      if (states_[i].getFinalState() == true) {
        chain_accepted = true;
      }
    }
  }
  return chain_accepted;
};

// bool Automata::analizarEntrada(std::string entrada){
//     return iChainValidate(entrada, 0, initial_state_);
// };

// //Funcion que se encarga de comprobar si la cadena es valida
// bool Automata::iAnalizarEntrada(std::string chain, int index, std::string state){
//     if(index == chain.size()){
//         for(int i = 0; i < states_.size(); i++){
//             if(states_[i].getState() == state){
//                 if(states_[i].getFinalState() == true){
//                     return true;
//                 }
//             }
//         }
//     } else {
//         for(int i = 0; i < states_.size(); i++){
//             if(states_[i].getState() == state){
//                 for(int j = 0; j < states_[i].getTransition().size(); j++){
//                     std::string aux;
//                     aux.push_back(chain[index]);
//                     if(states_[i].getTransition()[j].getTransitionSymbol() == aux){
//                         if(iAnalizarEntrada(chain, index + 1, states_[i].getTransition()[j].getTransitionState())){
//                             return true;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }

bool Automata::DFAChainValidation(std::string chain) {
  std::string current_state = initial_state_;
  std::string next_state;
  bool chain_accepted = false;
  for (int i = 0; i < chain.size(); i++) {
    std::string auxiliary_string;
    auxiliary_string.push_back(chain[i]);
    for (int j = 0; j < states_.size(); j++) {
      if (states_[j].getState() == current_state) {
        for (int k = 0; k < states_[j].getTransition().size(); k++) {
          if (states_[j].getTransition()[k].getTransitionSymbol() == auxiliary_string) {
            next_state = states_[j].getTransition()[k].getTransitionState();
          }
        }
      }
    }
    current_state = next_state;
  }
  for (int i = 0; i < states_.size(); i++) {
    if (states_[i].getState() == current_state) {
      if (states_[i].getFinalState() == true) {
        chain_accepted = true;
      }
    }
  }
  return chain_accepted;
}