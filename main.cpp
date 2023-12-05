/*
* Autor: Juan Antonio Ramírez Aguilar
* Fecha de Creacion: 04 / 12 / 2023
* Descripcion: Este scriptfue creado especialmente para las personas que quieren iniciar un programa en c++
* pero estan cansados de escribir lo mismo una y otra vez.
*/

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include <fstream>
#include <filesystem>

#define COLORORIGINAL "\x1b[0m"
#define AZULREYBAJO "\x1b[1;34m"
#define AZULREYFUERTE "\x1b[0;34m"
#define ROJOBAJO "\x1b[1;31m"
#define VERDEBAJO "\x1b[1;32m"
#define VERDEFUERTE "\x1b[0;32m"
#define SUBRAYADOGRIS "\x1b[1;37;47m"

using namespace std;
namespace fs = filesystem;

int main () {
    
    fstream archivoSalida;
    fs::path ruteFile;
    string nameFile, ruteFileStr;

    system(CLEAR);
    cout << SUBRAYADOGRIS << ROJOBAJO << "Dame la ruta de la carpeta donde crearlo: " << COLORORIGINAL;
    cin.clear(); cin.sync();
    cout << AZULREYBAJO; getline(cin, ruteFileStr);  cout << COLORORIGINAL;
    ruteFile = fs::path(ruteFileStr);

    if (ruteFile.is_relative()) {
        ruteFile = fs::current_path() / ruteFile;
    }

    cout << SUBRAYADOGRIS << ROJOBAJO << "Dame el nombre del archivo: " << COLORORIGINAL;
    cin.clear(); cin.sync();
    cout << AZULREYBAJO; getline(cin, nameFile); cout << COLORORIGINAL;

    fs::path allRute = ruteFile / (nameFile + ".cpp");


    archivoSalida.open(allRute, ios_base::out | ios_base::trunc);
    if (!archivoSalida.is_open()) {
        cout << ROJOBAJO;
        cerr << "Error al abrir el archivo: " << allRute << endl;
        cout << COLORORIGINAL;
        return 1;
    }


    cout << VERDEBAJO << "Creando Archivo..." << COLORORIGINAL <<endl;

    archivoSalida << "#include <iostream>" << endl << endl;
    archivoSalida << "using namespace std;" <<endl << endl;
    archivoSalida << "int main () {" <<endl << endl;
    archivoSalida << '\t' << "return 0;" << endl;
    archivoSalida << "}" << endl;
    archivoSalida.close();
    
    
    cout << VERDEFUERTE << "Archivo creado exitosamente: " << ROJOBAJO << allRute << COLORORIGINAL << endl;
    cin.clear(); cin.sync(); cin.ignore();
    
    return 0;
}