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

    const char *name() const { return this->name_; }
    int age() const { return this->age_; }
    const char *country() const { return this->country_; }
    const char *vehicle() const { return this->vehicle_; }

private:
    const char *name_;
    int age_;
    const char *country_;
    const char *vehicle_;
};

