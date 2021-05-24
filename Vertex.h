//
// Created by misha on 2/13/2021.
//

#ifndef PRACTICE_VERTEX_H
#define PRACTICE_VERTEX_H
using namespace std;

#include <string>
#include <set>
#include <iterator>


template<class S>
class Vertex {
private:
    S data;
    string name;
public:
    const S & getData() const  {return data;}
    Vertex(string name , const S & val ){
        this->name.assign(name);
        this->data = val;
    }
    Vertex(Vertex & rfs){
        this->data = rfs.data;
        this->name.assign(rfs.name);
    }
    Vertex(){
        name = "NULL";
        data = 0;
    }

    const string & getName() const{
        return name;
    };


    friend ostream &operator<<(ostream &os, Vertex<S> &v) {
        os << v.name;
        return os;
    }

    bool operator==(const Vertex<S> & other) {
        return other.name == this->name;
    }

    bool operator !=(const Vertex<S> & other){
        return !Vertex::operator==(other);
    }

};
#endif