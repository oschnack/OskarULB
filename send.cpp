#include <iostream>
#include <locale>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>


using namespace std;

string sanitize(string message){
  string res;
  int i = 0;
  vector<char> test;
  char c;
  
  for (char& c : message)
  {
    test.push_back(c);
  }
  test.shrink_to_fit(); 
  while (test.data()[i])
  {
    res += toupper(test.data()[i]);
    i++;
  }
    return res;
    
}
// TODO implémenter les fonctions sanitize, caesar et send ici

int main(int argc, char *argv[]) {
    // Les arguments à fournir: G|D n fichier
    if (argc < 4) {
        cout << "Utilisation: ./send G|D décalage fichier." << endl;
        return 1;
    }
    if (strcmp(argv[1], "G") != 0 && strcmp(argv[1], "D") != 0){
        cout << "Le premier argument doit être G ou D, " << argv[1] << " est incorrect." << endl;
        return 1;
    }
    bool rightShift = strcmp(argv[1], "D") == 0;
    // atoi: conversion d'un string vers un entier
    int shift = atoi(argv[2]);
    string filename = argv[3];
    // TODO Votre programme commence ici
    cout << "Communication chiffrée avec César " << argv[1] <<  " " << shift <<" via " << filename << endl;
    return 0;
}
