
#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

using namespace std;

template <class T> class ArrayDeque {
    private:
        int m_size, m_capacity, m_start, m_end;
        T* m_elements;
        
        bool isFull() {
            return m_size == m_capacity;
        }
    
        void increaseSizeIfNeeded(){
            if  (isFull()) {
                int m_old_capacity = m_capacity;
                T* newElements=new T[m_capacity*=2];
                for (int i = 0; i < m_size; i++) {
                    int index = m_start + i;
                    if (index >= m_old_capacity) {
                        index %= m_old_capacity;
                    }
                    int new_index = m_capacity - (m_old_capacity - index);
                    if (index < m_start)
                        new_index = index;
                    newElements[new_index]=m_elements[index];
                }
                
                delete[] m_elements;
                
                m_start = (m_capacity - 1) - m_start;

                m_elements=newElements;
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
            return m_size == 0;
        }
        
        void pushFront(T element) {
            increaseSizeIfNeeded();
            m_start--;
            if (m_start < 0) {
                m_start = m_capacity - 1;
            }
            m_elements[m_start] = element;
            m_size++;
        }

        void pushBack(T element) {
            increaseSizeIfNeeded();
            m_elements[m_end] = element;
            m_end = (m_end + 1) % m_capacity;
            m_size++;
        }
        
        void popFront() {
            if (!isEmpty()) {                
                m_start = (m_start + 1) % m_capacity;
                m_size--;
            }
        }
        
        void popBack() {
            if (!isEmpty()) {
                m_end--;
                if (m_end < 0) {
                    m_end = m_capacity - 1;
                }
                m_size--;
            }
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
                cout<<"\nstart:"<<m_start<<" end:"<<m_end<<" size:"<<m_size<<" capacity:"<<m_capacity<<endl;
                cout<<"\nfront:"<<front()<<" back:"<<back()<<endl;
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

#endif /* ARRAYDEQUE_H */

