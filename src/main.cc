/**
 * @file main.cc
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
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

/// Sobrecarga del operador de entrada para la lectura de los ficheros de entrada.
std::istream& operator>>(std::istream& input, std::vector<std::string>& vector_chains) {
    std::string line;
    while (std::getline(input, line)) {
        vector_chains.push_back(line);
    }
    return input;
}

int main(int argc, char** argv) {
  if (argc == 3) {
    /// Comrobación de los formatos de los ficheros de entrada
    std::string automata_file = argv[1];
    std::string chains_file = argv[2];
    std::regex automata__file_regex(".*\\.fa$");
    if (!std::regex_match(automata_file, automata__file_regex)) {
      std::cout << "ERROR: El fichero de entrada de especificación del autómata, no tiene el formato de fichero correcto." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./p06_automata_simulator (-h | --help)" << std::endl;
      return 1;
    }
    std::regex chains_file_regex(".*\\.txt$");
    if (!std::regex_match(chains_file, chains_file_regex)) {
      std::cout << "ERROR: El fichero de entrada de las cadenas a comprobar, no tiene el formato de fichero correcto." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./p06_automata_simulator (-h | --help)" << std::endl;
      return 1;
    }
    /// Lectura del fichero .fa de entrada
    std::ifstream automata_file_content(automata_file);
    std::vector<std::string> automata_file_lines_vector;
    automata_file_content >> automata_file_lines_vector;
    automata_file_content.close();
    /// Control de errores de dicho fichero
    
    /// Creación del objeto automata
    /// Lectura del fichero .txt de entrada
    /// Control de errores de dicho fichero
    /// Creación del objeto cadena
    /// Comprobación de la cadena
  } else if (argc == 2) {
    std::string option = argv[1];
    if ((option == "-h") || (option == "--help")) {
      std::cout << "Usage: ./p06_automata_simulator [file_name.fa] [file_name.txt]" << std::endl;
      return 1; /// Para el caso en el que se produzca un error, se retorna un error de tipo 1.
    } else {
      std::cout << "ERROR: La opción introducida es incorrecta." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./p06_automata_simulator (-h | --help)" << std::endl;
      return 1;
    }
  } else {
    std::cout << "ERROR: El número de argumentos es inválido." << std::endl;
    std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
    std::cout << "./p06_automata_simulator (-h | --help)" << std::endl;
    return 1;
  }
return 0; /// Se retorna 0 gracias a la correcta ejecución del programa.
}
