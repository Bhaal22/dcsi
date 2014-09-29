#ifndef _PERSOH___
#define _PERSOH__

class Perso{
  
  public :
    Perso(char *sonnom,int sonage,char* sonpays,char * sonve): nom(sonnom),age(sonage),pays(sonpays),vehicule(sonve)
    {};
  ~Perso(){};
    
  /* Modificateurs */
  char* GetNom(void){return nom;}
  int GetAge(void){return age;}
  char* GetPays(void){return pays;}
  char* GetVehicule(void){return vehicule;}
    
    private :
    char* nom;
  int age;
  char* pays;
  char* vehicule;

};

#endif
