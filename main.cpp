#include <iostream>
#include  "Set.h"
#include "Edge.h"
#include "Graph.h"
#include "Algos.h"
#include "Queue.c"
#include <string.h>

using namespace std;

class printVals{
public:
    void operator()(const Vertex<int>& v) const {
        cout << v.getData() << " ";
    }
};
void init_str(char * src, char * dst){
    printf("%d is an address inside a function before malloc\n", dst);
    dst = (char*)(malloc(strlen(src) + 1));
    printf("%d is an address inside a function after malloc\n", dst);
    strcpy(dst, src);
}
void init(string * dst, string src){
    *dst = (src);
}
//
//
//void GraphTest(){
//    Set<Vertex<int>, printVals> vSet;
//    Vertex<int> v("one", 1);
//    Vertex<int>v1("two", 2);
//    Vertex<int>v2("three,", 3);
//    Vertex<int> Varr [ ] = {v, v1, v2};
//    vSet.add(v); vSet.add(v1); vSet.add(v2);
//
//    Set<Edge<int>, printVals> eSet;
//    Edge<int> e(&v, &v1);
//    Edge<int> e1(&v, &v2);
//    Edge<int> e2(&v2, &v1);
//    Edge<int> Earr [ ] = {e, e1, e2};
//
//    eSet.add(e); eSet.add(e1); eSet.add(e2);
//
//
//    Graph<int, printVals> g(vSet, eSet);
//    for (int i = 0; i < 3; ++i) {
//        g.addVertex(Varr[i]);
//        g.addEdge(Earr[i]);
//
//    }
//    g.print();
//}



int main() {
// dec_to_bin_bits(4);
//    printf("%s",dec_to_mit_arithmetic(4));
//    printf("\n%d", sizeof (uc));
//    printf("%s\n", unsigned_to_signed_arithmetic(-4));
//    printf("%s\n", unsigned_to_signed_arithmetic(4));
//    unsigned_to_signed_bits(-4);

/*********QueueTest********/
//Queue q = createQueue(10);
//enq(q, 2);
//enq(q, 3);
//for(int i = 0; i < q->size; i++){
//    printf("%d ", q->array[i]);
//}
//printf("\n");
//    while(!isEmpty(q)){
//        printf("%d ", deq(q));
//    }
/********END**QueueTest****/

/*********removeDuplicatesTEST*********/
//char pString[] = "silence is a source of great strength";
//char * res;
//res = removeDuplicates(pString);
//printf("%s", res);
/*****END*removeDuplicatesTEST*********/


/*********BalancedBracketsTest*********/
//const char * string = "";
//printf(BalancedBrackets(string) ? "true\n" : "false\n");
/********END***BalancedBracketsTest*********/
char * dst;
char * src  = "MISHA";
//init()
init_str(src, dst);
printf("%d is the address of dst in main\n", dst);
printf("%s", dst);


}

