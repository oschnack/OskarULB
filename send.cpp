#include <iostream>
#include <locale>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include "enigma.hpp" 



using namespace std;

string sanitize(string message){// Sanitize renvoie le message entré en majuscule
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


string caesar(string message, int sens, int decalage){//s'occupe de l'encrpytage du message
  const int ALPHA_len = 26;
  int trans;
  string res;
  switch (sens)
  {
  case 1:{//cas decalage des lettres vers la droite
    for (char& c : message)//boucle qui passe chasue charactere du message par C
  {
    if (int(c) == 32)// gestion d'un espace si le message est une phrase
    {
      res += ' ';
      continue;
    }else{
      trans = int(c);
      trans += decalage;
      if (trans > 90)
      {
        trans -= ALPHA_len;
      }
    }
    res += char(trans);
    
  }
    break;
  }
  case 0:{//cas decalage des lettres vers la gauche
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
        trans += ALPHA_len;
      }
    }
    res += char(trans);
    
  }
    break;
  }
  }
   return res;
}

void send(string message, string filename){//fonciton qui s'occupe d'écrire le message dans le fichier donner par l'utilisateur
  cout <<"Envoie du message: " << message << endl;
  ofstream file(filename, ios_base::app);
if(file.is_open()) {
  file << message << endl;
  file.close();
}
else cerr << "Impossible d’ouvrir le fichier " << filename << endl;
}



int main(int argc, char *argv[]) {
  string filename;
  string message;
  char cond = 'y';
  int shift;
  int sens;
  bool rightShift;




  if (strcmp(argv[1], "Enigma") == 0){
    cout << "Communication chiffrée avec Enigma via " << argv[2] <<endl;
    filename = argv[2];


    while (cond == 'y')//Boucle while qui permettera l'envoie de plusieurs message
  {
    cout << "Votre message: ";
    getline(cin, message);
    char* code = const_cast<char*>(sanitize(message).c_str());//Adaptation au bon type pour passer dans Enigma apres le passage dans sanitize
    string encrypted(enigma(code));
    send(encrypted,filename);//Envoie le message encrypter dans la fct send pour l'écrire dans le fichier txt
    cin.clear();
    cout << "Voulez - vous continuer à envoyer des messages? " << "y ou n" << endl;//condition qui arretera le programme si jamais on ne veut plus envoyer de message
    cin>> cond;
    cin.ignore();
  }
      return 0;


  
  if (argc < 4) {
    cout << "Utilisation: ./send G|D décalage fichier." << endl;
      return 1;
  }
  if (strcmp(argv[1], "G") != 0 && strcmp(argv[1], "D") != 0){
    cout << "Le premier argument doit être G ou D, " << argv[1] << " est incorrect." << endl;
      return 1;
  }
    
  }else{
  rightShift = strcmp(argv[1], "D") == 0;//Initialisation des variables necessaires à caesar
  shift = atoi(argv[2]);
  filename = argv[3];
  sens = rightShift;
  
  cout << "Communication chiffrée avec César " << argv[1] <<  " " << shift <<" via " << filename << endl;
  while (cond == 'y')//Utilisation de la meme boucle wwhile et de la meme condition d'arret que pour Enigma
  { 
    cout << "Votre message: ";
    getline(cin, message);  //Entrée du message par l'utilisateur
    send(caesar(sanitize(message), sens, shift), filename);//Envoie du message apres le passage successif dans sanitize puis dans caesar
    cin.clear();
    cout << "Voulez - vous continuer à envoyer des messages? " << "y ou n" << endl;//Condition de sortie du programme
    cin>> cond;
    cin.ignore();
  }
  }
  return 0;
}