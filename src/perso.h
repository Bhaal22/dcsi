#pragma once

class Perso
{

public:
    Perso(const char *name, 
        int age, 
        const char *country, 
        const char *vehicle) : 
        name(name), 
        age(age), 
        country(country), vehicule(vehicle){};
    ~Perso(){};

    const char *GetNom() { return name; }
    int GetAge() { return age; }
    const char *GetPays() { return country; }
    const char *GetVehicule() { return vehicule; }

private:
    const char *name;
    int age;
    const char *country;
    const char *vehicule;
};

