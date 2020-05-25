#pragma once

class Perso
{
public:
    Perso(const char *name, 
        int age, 
        const char *country, 
        const char *vehicle) : 
        name_(name), 
        age_(age), 
        country_(country), 
        vehicle_(vehicle)
    {};

    ~Perso(){};

    const char *name() { return this->name_; }
    int age() { return this->age_; }
    const char *country() { return this->country_; }
    const char *vehicle() { return this->vehicle_; }

private:
    const char *name_;
    int age_;
    const char *country_;
    const char *vehicle_;
};

