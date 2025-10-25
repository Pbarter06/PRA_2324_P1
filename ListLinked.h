#include <ostream>
#include "List.h"
#include "Node.h"
using namespace std; 

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first; 
        int n; 

    public:

        ListLinked(){
            first = nullptr; 
            n = 0;
        }

        ~ListLinked(){
            // estrategia: aux = first->next; delete first; first = aux; repetir
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }

        }

        T operator[](int pos){

            if (pos < 0 || pos >= n) {
                throw out_of_range("Posición fuera de rango");
            }

            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }

            return aux->data;
        }

        friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
            out << "[";
            Node<T>* cur = list.first;
            while (cur != nullptr) {
                out << cur->data;
                if (cur->next != nullptr) out << ", ";
                cur = cur->next;
            }
            out << "]";
            return out;
        }

};