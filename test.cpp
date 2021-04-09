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
    cout << res << "test sanitize" << endl;
    return res;
    
}


string caesar(string message, char sens, int decalage){//s'occupe de l'encrpytage du message
  int trans;
  const char a = 'D';
  string res;
  const char b = 'G';
  const int droite = int(a);
  const int gauche = int(b); // cest moche faut essayer de faire mieux 
  cout << message << "test entree de caesar" << endl;
  switch (int(sens))
  {
  case droite:{//cas decalage des lettres vers la droite
    for (char& c : message)
  {
    if (int(c) == 32)// Voir si ya pas moyen de mieux faire que ça
    {
      res += ' ';
    }else{
      trans = int(c);
      trans += decalage;
      if (trans > 90)
      {
        trans -= 26;/* code */
      }
      //reste des conditions à mettre ici
    }
    res += char(trans);
    
  }
    break;
  }
  case gauche:{//cas decalage des lettres vers la gauche
    for (char& c : message)
  {
    if (int(c) == 32)// Voir si ya pas moyen de mieux faire que ça
    {
      res += ' ';
    }else{
      trans = int(c);
      trans -= decalage;
      if (trans < 65)
      {
        trans += 26;/
      }
      //reste des conditions à mettre ici
    }
    res += char(trans);
    
  }
    break;
  }
  default:{
    break;
  }
  }
  return res;
}

int main ()
{
  string message = "langages de programmation";
  char decalage = 'G';
  int nbr = 3;
  cout << caesar(sanitize(message), decalage, nbr) << endl;
  //cout << b << endl;
}