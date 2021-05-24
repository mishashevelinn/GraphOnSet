//
// Created by misha on 2/14/2021.
//

#ifndef PRACTICE_GRAPH_H
#define PRACTICE_GRAPH_H
#import "Edge.h"
#import "Set.h"
using namespace DS;

class Print{
public:
    void operator()(const Vertex<int>& v) const {
        cout << v.getData() << " ";
    }
};


template<class T, class F>
class Graph{
public:
    Graph():V("vertex"), E("edge"){}
    Graph(const Set<Vertex<T>, F> & Vert, const Set<Edge<T>, F> & Ed){
        V = Vert;
        E = Ed;
    }

    void addVertex(Vertex<T> v) {
        V.add(v);
    }
    void addEdge(Edge<T> & e){
        E.add(e);
    }
    void remoeVertex(Vertex<T> & v){
        //TODO add remove to a set...
    }
    Set<Vertex<int>, Print > * getNeighbours(const Vertex<int> & v){
        Set<Vertex<int>, Print> * set = new Set<Vertex<int>, Print >();
        if( *find(v).getName == "null" ){
            return set;
        }
        Set<Edge<int>, Print >::Iterator it;
        for(it = E.begin(); it != E.end(); ++it)
        {
            if(it.getCurr()->getSourse().getName() == v.getName())
            {
                int temp = 0;
                Vertex<int> n(it.getCurr()->getDest().getName(), temp);
                set->add(n);
            }

        }



    };

    Set<Vertex<int>, Print >:: Iterator begin(){
        return V.begin();
    }
    Set<Vertex<int>, Print >::Iterator end(){
        return V.end();
    }
    Set<Vertex<int>, Print >::Iterator find(const Vertex<T> & elem){
        return V.find(begin(), end(), elem);
    }
    friend ostream & operator<<(ostream & os, Graph< T, F > g){

    }

    void print(){
        cout << "vertex set: " << endl;
        V.print(V.begin(), V.end());
        cout << endl;
        cout << "edge set: " << endl;
        E.print(E.begin(), E.end());
    }

    Set<Vertex<T>, F> & vertexes(){
        return V;
    }
    Set<Edge<T>, F> & edges(){
        return E;
    }

private:
    Set<Vertex<T>, F> V;
    Set<Edge<T>, F> E;
};
#endif //PRACTICE_GRAPH_H
