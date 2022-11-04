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


int main(int argc, char** argv) {
  if (argc == 3) {
    std::cout << "Accede de manera correcta" << std::endl;
    /// Lectura del fichero .fa de entrada
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
