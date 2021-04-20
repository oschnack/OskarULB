#include <iostream>
#include <locale>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>


using namespace std;
struct Rotor
{
    char I[53];
    char II[53];
    char III[53];
    
};

    struct Reflector
{
    char reflector[53];
}reflector;

struct Machine {
      Rotor rotors[3];
      Reflector reflector;
};


extern "C" char* enigma(char* message){
    Machine Enigma;
    vector<char>res_temp; 
    string code(message);//transformation en string pour un maniment plus simple par le programme
    string res;
    int i;// counter pour les boucles
    char rot1[53] = "AEBKCMDFELFGGDHQIVJZKNLTMONWOYPHQXRUSSTPUAVIWBXRYCZJ";// initialisation des rotors 
    char rot2[53] = "AABJCDDKESFIGRHUIXJBKLLHMWNTOMPCQQRGSZTNUPVYWFXVYOZE";
    char rot3[53] = "ABBDCFDHEJFLGCHPIRJTKXLVMZNNOYPEQIRWSGTAUKVMWUXSYQZO";
    char refl[53] = "AYBRCUDHEQFSGLHDIPJXKNLGMONKOMPIQERBSFTZUCVWWVXJYAZT";
    strcpy(Enigma.rotors->I, rot1);//incorporation des rotors dans leurs structures respectivent
    strcpy(Enigma.rotors->II, rot2);
    strcpy(Enigma.rotors->III, rot3);
    strcpy(Enigma.reflector.reflector, refl);


    for (char& c : code)//Passage dans R3 1er for qui permet de passer chaque character de code par c
  {
      if (int(c) == 32)
    {
      res_temp.push_back(' ');
    }
      for (i = 0; i <= 52; i++)//boucle qui va passer dans tout le rotor et tester chaque lettre
      {
          if (i%2 == 0)
          {   
              if (c == Enigma.rotors->III[i]){
                  res_temp.push_back(Enigma.rotors->III[i+1]);
                  break;
              }
              continue;
          }
          continue;
      }
    }
    
    code = res_temp.data();
    res_temp.clear();



    for (char& c : code)// PASSAGE R2
  {
      if (int(c) == 32)
    {
      res_temp.push_back(' ');
    }
      for (i = 0; i <= 52; i++)
      {
          if (i%2 == 0)
          {   
              if (c == Enigma.rotors->II[i]){
                  res_temp.push_back(Enigma.rotors->II[i+1]);
                  break;
              }
              continue;
          }
          continue;
      }
    }
    code = res_temp.data();
    res_temp.clear();


    for (char& c : code)//PASSAGE R1
    {
        if (int(c) == 32)
    {
      res_temp.push_back(' ');
    }
      for (i = 0; i <= 52; i++)
      {
          if (i%2 == 0)
          {   
              if (c == Enigma.rotors->I[i]){
                  res_temp.push_back(Enigma.rotors->I[i+1]);
                  break;
              }
              continue;
          }
          continue;
      }
    }
    code = res_temp.data();
    res_temp.clear();


    for (char& c : code)//PASSAGE REFLECTOR
    {
        if (int(c) == 32)
    {
      res_temp.push_back(' ');
    }
      for (i = 0; i <= 52; i++)
      {
          if (i%2 == 0)
          {   
              if (c == Enigma.reflector.reflector[i]){
                  res_temp.push_back(Enigma.reflector.reflector[i+1]);
                  break;
              }
              continue;
          }
          continue;
      }
    }
    code = res_temp.data();
    res_temp.clear();


    for (char& c : code)//PASSAGE ROTOR 1 mais dans le sens inverse(cad de gauche à droite)
  {
      if (int(c) == 32)
    {
      res_temp.push_back(' ');
    }
      for (i = 0; i <= 52; i++)
      {
          if (i%2 == 1)
          {   
              if (c == Enigma.rotors->I[i]){
                  res_temp.push_back(Enigma.rotors->I[i-1]);
                  break;
              }
              continue;
          }
          continue;
      }
    }
    
    code = res_temp.data();
    res_temp.clear();


    for (char& c : code) //PASSAGE ROTOR 2
  {
      if (int(c) == 32)
    {
        res_temp.push_back(' ');
    }
      for (i = 0; i <= 52; i++)
      {
          if (i%2 == 1)
          {   
              if (c == Enigma.rotors->II[i]){
                  res_temp.push_back(Enigma.rotors->II[i-1]);
                  break;
              }
              continue;
          }
          continue;
      }
    }
    code = res_temp.data();
    res_temp.clear();


    for (char& c : code)// PASSAGE ROTOR 3
  {
      if (int(c) == 32)
    {
      res_temp.push_back(' ');
    }
      for (i = 0; i <= 52; i++)
      {
          if (i%2 == 1)
          {   
              if (c == Enigma.rotors->III[i]){
                  res_temp.push_back(Enigma.rotors->III[i-1]);
                  break;
              }
              continue;
          }
          continue;
      }
    }
    
  res = res_temp.data();
  res_temp.clear();

  char* c = const_cast<char*>(res.c_str());//conversion en char* pour respecter le type de la fonction
  
    return c;
}


