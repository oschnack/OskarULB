#include <iostream>
#include <locale>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>


using namespace std;

string sanitize(string message){// Sanitize renvoie le message entré en full majuscule
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


string caesar(string message, char sens, int decalage){//s'occupe de l'encrpytage du message
  int trans;
  const char a = 'D';
  string res;
  const char b = 'G';
  const int droite = int(a);
  const int gauche = int(b);
  switch (int(sens))
  {
  case droite:{//cas decalage des lettres vers la droite
    for (char& c : message)
  {
    if (int(c) == 32)
    {
      res += ' ';
      continue;
    }else{
      trans = int(c);
      trans += decalage;
      if (trans > 90)
      {
        trans -= 26;
      }
    }
    res += char(trans);
    
  }
    break;
  }
  case gauche:{//cas decalage des lettres vers la gauche
    for (char& c : message)
  {
    if (int(c) == 32)
    {
      res += ' ';
      continue;
    }else{
      trans = int(c);
      trans -= decalage;
      if (trans < 65)
      {
        trans += 26;
      }
    }
    res += char(trans);
    
  }
    break;
  }
  default:{
    break;
  }
  }
  cout << "Envoie du message: " << res <<endl;
  return res;
}

void send(string message, char sens, int decalage){
  string filename = "test.txt";
  ofstream file(filename, ios_base::app);
if(file.is_open()) {
  file << caesar(sanitize(message), sens, decalage) << endl;
  file.close();
}
else cerr << "Impossible d’ouvrir le fichier " << filename << endl;
}

// TODO implémenter les fonctions sanitize, caesar et send ici

int main(int argc, char *argv[]) {
    // Les arguments à fournir: G|D n fichier
    string message;
    char sens;
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
    cout <<"test " << argv[1] <<  " " << shift <<" via " << filename << endl;
    cout << "Communication chiffrée avec César " << argv[1] <<  " " << shift <<" via " << filename << endl;
    cout << "Votre message: ";
    getline(cin, message);
    cout << message << sens << shift << endl;
    send(message, sens, shift);
    return 0;
}
