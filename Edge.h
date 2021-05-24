//
// Created by misha on 2/14/2021.
//

#ifndef PRACTICE_EDGE_H
#define PRACTICE_EDGE_H
#import "Vertex.h"
template <class T>
class Edge{
private:
    Vertex<T> * source;
    Vertex<T> * target;

public:
    Edge(){
        source = 0;
        target = 0;
    }
    Edge(Vertex<T> * source, Vertex<T> * target){
        this->source = source;
        this->target = target;
    }

    const Vertex<T> getSourse(){
        return source;
    };
    const Vertex<T> getDest(){
        return target;
    }

    bool operator ==(const Edge<T> & rhs){
        return source == rhs.source && target == rhs.target;
    }
    bool operator !=(const Edge<T> & rhs){
        return !operator==(rhs);
    }
    friend ostream & operator<<(ostream & os, const Edge & e){
        os << "(" << *e.source << "," << *e.target << ")";
        return os;
    }
};
#endif //PRACTICE_EDGE_H
