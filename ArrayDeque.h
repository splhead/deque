#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

using namespace std;

template <class T> class ArrayDeque {
    private:
        int count, lowestCount, capacity;
        T* items;
        
        void increaseSizeIfNeeded(){
            if  (isFull()) {
                cout<<"Aumentando a capacidade do deque"<<endl;
                T* newElements=new T[capacity*=2];
                for (int i=0;i<size();i++) 
                    newElements[i]=items[i];
                delete[] items;
                items = newElements;
            }   
        }
        
    public:
        ArrayDeque() {
            count = 0;
            lowestCount = 0;            
            capacity = 5;            
            items = new T[capacity];
        }
        
        int size() {
            return count - lowestCount;
        }
        
        bool isEmpty() {
            bool result = size() == 0;
            if (result) {
                cout<<"O deque esta vazio"<<endl;
            }
            return result;
        }
        
        bool isFull() {
            bool result = size() == capacity;
            if (result) {
                cout<<"O deque esta cheio"<<endl;
            }
            return result;
        }
        
        void pushFront(T element) {
            increaseSizeIfNeeded();
            if (isEmpty()) {
                pushBack(element);
            } else if (lowestCount > 0) {
                lowestCount--;
                items[lowestCount] = element; 
            } else {
                for (int i = count; i > 0; i--) {
                    items[i] = items[i - 1];
                }
                count++;
                items[0] = element;
            }
            printFrontBack();
        }
        
        void pushBack(T element) {
            increaseSizeIfNeeded();
            items[count] = element;
            count++;
            printBackFront();
        }
        
        void popFront() {
            if (!isEmpty()) {
                lowestCount++;
            }
        }
        
        void popBack() {
            if (!isEmpty()) {
                count--;
            }
        }
        
        T front() {
            if (!isEmpty()) {
                return items[lowestCount];
            }
        }
        
        T back() {
            if (!isEmpty()) {
                return items[count - 1];
            }
        }
        
        void printFrontBack() {
            if(!isEmpty()) {
                cout<<"\n<--------Deque front------>"<<endl;
                for (int i = lowestCount; i < count; i++){
                    cout<<items[i]<<endl;
                }
                cout<<"<--------Deque back--------->"<<endl;
            }
        }
        
        void printBackFront() {
            if(!isEmpty()) {
                cout<<"\n<--------Deque back------>"<<endl;
                for (int i = count - 1; i >= lowestCount; i--){
                    cout<<items[i]<<endl;
                }
                cout<<"<--------Deque front--------->"<<endl;
            }
        }
        
        void clear() {
            count = 0;
            lowestCount = 0;
            delete[] items;
            items = new T[capacity];
        }
        
        
};


#endif /* ARRAYDEQUE_H */

