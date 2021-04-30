#include <cstdlib>
#include <iostream>
#include "ArrayDequeN.h"
#include "Aluno.h"

using namespace std;

int main() {
    ArrayDeque<Aluno> deque = ArrayDeque<Aluno>();
        
    deque.pushFront(Aluno("Jesus"));    
    deque.pushFront(Aluno("Maria"));
    deque.pushBack(Aluno("Marco"));
    deque.pushBack(Aluno("Aline"));
    deque.pushFront(Aluno("José"));
    deque.pushBack(Aluno("Paulo"));
    deque.pushFront(Aluno("João"));
    
   
    
    deque.popFront();
    deque.popBack();
    

    return 0;
}

