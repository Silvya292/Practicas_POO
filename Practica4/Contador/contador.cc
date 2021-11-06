//contador.cc
//Body of class Contador

#include "contador.h"
#include <iostream>

using namespace std;

Contador::Contador(int valor, int min, int max){
    if(valor<min || valor>max || min>max){
        valor=0;
        min=0;
        max=1000;
    }
    valor_=valor;
    min_=min;
    max_=max;
    list_.push_back(*this);
}

void Contador::control(){
    if(valor_<min_){
        valor_=min_;
    }
    else if(valor_>max_){
        valor_=max_;
    }
    list_.push_back(*this);
}

Contador Contador::operator=(const int &valor){
    valor_=valor;
    control();
    return *this;
}

Contador Contador::operator=(const Contador &cont){
    valor_=cont.valor_;
    min_=cont.min_;
    max_=cont.max_;
    control();
    return *this;
}

Contador Contador::operator++(void){ //Prefijo ++c
    ++valor_;
    control();
    return *this;
}

Contador Contador::operator++(int){ //Postfijo c++
    Contador cont=*this;
    ++valor_;
    control();
    return cont;
}

Contador Contador::operator--(void){ //Prefijo --c
    --valor_;
    control();
    return *this;
}

Contador Contador::operator--(int){ //Postfijo c++
    Contador cont=*this;
    --valor_;
    control();
    return cont;
}

Contador Contador::operator+(const int &n){
    valor_=valor_+n;
    control();
    return *this;
}

Contador operator+(const int &n,const Contador &cont){
    Contador aux;
    aux.valor_=n+cont.valor_;
    aux.min_=cont.min_;
    aux.max_=cont.max_;
    aux.control();
    return aux;
}

Contador Contador::operator-(const int &n){
    valor_=valor_-n;
    control();
    return *this;
}

Contador operator-(const int &n,const Contador &cont){
    Contador aux;
    aux.valor_=n-cont.valor_;
    aux.min_=cont.min_;
    aux.max_=cont.max_;
    aux.control();
    return aux;
}

bool Contador::undo(const int &n){
    if(n>=(int) list_.size() || n<1){
        return false;
    }
    for(int i=0;i<n;i++){
        list_.pop_back();
    }
    *this=list_.back();
    return true;
}