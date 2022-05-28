/*
Proyecto TC1030.301
Clase Usuario
Yuna Chung
A01709043
*/

#ifndef USUARIO_H_
#define USUARIO_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Usuario { //clase usuario
    protected:
    string nombre;
    int id;
    string tipo;

    public:
    Usuario(): id(0), nombre(""), tipo(""){}; //constructor por default
    Usuario(int id_num, string nom, string tip):
    id(id_num), nombre(nom), tipo(tip){};

    int get_id(){
        return id;
    }
    string get_nombre(){
        return nombre;
    }
    string get_tipo(){
        return tipo;
    }
    virtual int verificar_usuario() = 0;
    virtual string to_string() = 0;
};

class Lector: public Usuario { //herencia desde clase usuario a clase lector
    private:
    int libro_rentado;
    public:
    Lector(): Usuario(0, "", "Lector") {};
    Lector(int id, string nombre, int librent):Usuario(id, nombre, "Lector"), libro_rentado(librent){};

    int get_id(){
        return id;
    }
    string get_nombre(){
        return nombre;
    }
    int libro_rentado(){
        return libro_rentado;
    }
    string to_string();
};

/*
to_string convierte a atributos a string.
Conectan todos los valores de los atributos en un string para ser impreso
*/

string Lector::to_string(){
    stringstream aux;
    aux << "Id es: " << id << "rol es: " << tipo << "su nombre es: " << nombre << "usted ha rentado: " << libro_rentado << " libros" << "\n";
    return aux.str();
}

class Staff:public Usuario { //herencia desde clase usuario a clase staff
    private:
    int pin;
    public:
    Staff():Usuario(0,"","Staff"){};
    Staff(int id, string nombre, int _pin):Usuario(id, nombre, "Staff"), pin(_pin){};

    int pin(){
        return pin;
    }
    string to_string();
};

string Staff::to_string(){
    stringstream aux;
    aux << "Id es: " << id << "rol es: " << tipo << "su nombre es: " << nombre << "su PIN es: " << pin << "\n";
    return aux.str();
}

#endif // USUARIO_H_