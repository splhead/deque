#include <cstdlib>
#include <iostream>
#include "ArrayDeque.h"
#include "Aluno.h"

using namespace std;

int main() {
    ArrayDeque<Aluno> deque = ArrayDeque<Aluno>();
    
    deque.printFrontBack();
    
    deque.pushFront(Aluno("Jesus"));    
    deque.pushFront(Aluno("Maria"));
    deque.pushBack(Aluno("Marco"));
    deque.pushBack(Aluno("Aline"));
    deque.pushFront(Aluno("José"));
    deque.pushBack(Aluno("Paulo"));
    deque.pushFront(Aluno("João"));
    
   
    
//    deque.popFront();
//    deque.popBack();
    
    
    
//    
//    
//    
//    
//    
//    deque.pushFront(Aluno("Joe"));
//    deque.pushFront(Aluno("Jonh"));
//    
//    deque.printFrontBack();
//    deque.printBackFront();
//    
//    
//    
//    
//    deque.pushBack(Aluno("Bea"));
//    deque.pushBack(Aluno("Lucas"));
//    deque.pushBack(Aluno("Daniel"));
//    
//    deque.printFrontBack();
//    deque.printBackFront();

    return 0;
}

