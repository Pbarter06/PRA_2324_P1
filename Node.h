#include <ostream>
using namespace std; 

template <typename T> 
class Node {
    public:

        //Atributos 
        T data; 
        Node<T>* next; 

        //Métodos
        Node(T data, Node<T>* next=nullptr){
            this->data = data;
            this->next = next;
        }


        friend ostream&operator<<(ostream &out, const Node<T> &node){
            out << node.data; 
            return out;
        }

    
};