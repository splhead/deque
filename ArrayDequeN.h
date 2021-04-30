#ifndef ARRAYDEQUEN_H
#define ARRAYDEQUEN_H


using namespace std;

template <class T> class ArrayDeque {
    private:
        int m_size, m_capacity, m_start, m_end;
        T* m_elements;
        
        bool isFull() {
            bool result = m_size == m_capacity;
            if (result) cout<<"O deque esta cheio"<<endl;
            return result;
        }
    
        void increaseSizeIfNeeded(){
            if  (isFull()) {
                cout<<"Aumentando a capacidade do deque"<<endl;
                int m_old_capacity = m_capacity;
                T* newElements=new T[m_capacity*=2];
                for (int i = 0; i < m_size; i++) {
                    int index = (m_start + i) % m_old_capacity;
                    newElements[i] = m_elements[index];
                }
                
                delete[] m_elements;
                
                m_start = 0;
                
                m_end = m_old_capacity;

                m_elements = newElements;
            }   
        }
        
    public:
        ArrayDeque() {
            m_capacity = 5;
            m_size = 0;
            m_start = 0;
            m_end = 0;
            m_elements=new T[m_capacity];
        }
        
        int size() {
            return m_size;
        }
        
        bool isEmpty() {
            bool result = m_size == 0;
            if (result) cout<<"O deque esta vazio"<<endl;
            return result;
        }
        
        void pushFront(T element) {
            increaseSizeIfNeeded();
            if (isEmpty()) {
                pushBack(element);
            } else if (m_start > 0) {
                m_start--;
                m_elements[m_start] = element;
                m_size++;
            } else {
                m_start = m_capacity - 1;
                m_elements[m_start] = element;
                m_size++;
            }
            
            printFrontBack();
        }

        void pushBack(T element) {
            increaseSizeIfNeeded();
            m_elements[m_end] = element;
            m_end = (m_end + 1) % m_capacity;
            m_size++;
            printBackFront();
        }
        
        void popFront() {
            if (!isEmpty()) {                
                m_start = (m_start + 1) % m_capacity;
                m_size--;
            }
            printFrontBack();
        }
        
        void popBack() {
            if (!isEmpty()) {
                m_end--;
                if (m_end < 0) {
                    m_end = m_capacity - 1;
                }
                m_size--;
            }
            printBackFront();
        }
        
        T front() {
            return m_elements[m_start];
        }
        
        T back() {
            return m_elements[m_end - 1];
        }
        
        void printFrontBack() {
            if (isEmpty()) {
                cout << "Deque is empty\n"<<endl;
            } else {
                cout<<"\nstart: "<<m_start<<"  end: "<<m_end<<"  size: "<<m_size<<" capacity: "<<m_capacity<<endl;
                cout<<"\nfront: "<<front()<<"  back: "<<back()<<endl;
                cout<<"\n<--------Deque front------>"<<endl;
                
                for (int i = 0; i < m_size; i++) {
                    int index = m_start + i;
                    if (index >= m_capacity)
                        index %= m_capacity;
                    cout<<m_elements[index]<<endl;
                }

                cout<<"<--------Deque back--------->"<<endl;
            }
        }
        
        void printBackFront() {
            if (isEmpty()) {
                cout << "Deque is empty\n"<<endl;
            } else {
                cout<<"\nstart:"<<m_start<<" end:"<<m_end<<" size:"<<m_size<<" capacity:"<<m_capacity<<endl;
                cout<<"\nfront:"<<front()<<" back:"<<back()<<endl;
                cout<<"\n<--------Deque back------>"<<endl;
            
                for(int i = 0; i < m_size; i++) {
                    int index = (m_end - 1) - i;
                    if (index < 0)
                        index += m_capacity;
                    cout<<m_elements[index]<<endl;
                }

                cout<<"<--------Deque front--------->"<<endl;
            }
        }
};

#endif /* ARRAYDEQUEN_H */

