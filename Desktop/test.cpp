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
  const int gauche = int(b); // cest moche faut essayer de faire mieux 
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
  cout << "Envoie du message: " << res << endl;
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



int main ()
{
  string message;
  int decalage;
  char sens;
  cout << "Entrez votre message: ";
  getline(cin, message);
  while (true)
  {
    cout << "Entrez le sens du décalage: ";
    cin >> sens;
    if (sens == 'D')
    {
      break;

    }else{if (sens == 'G')
    {
      break;

    }else{
      cout << "Mauvaise entrée" << endl;
    }

    }
    
  }
  cout <<"Entrez le nombre du décalage: ";
  cin >> decalage;
  send(message, sens, decalage);
    
}