#include <ostream>
#include <stdexcept>
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

        //heredados

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Fuera de rango1");
            }

            if (pos == 0) {
                Node<T>* node = new Node<T>(e, first);
                first = node;
            } else {
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) prev = prev->next;
                Node<T>* node = new Node<T>(e, prev->next);
                prev->next = node;
            }
            n++;
        }

        void prepend(T e) override {
            insert(0, e);
        }

        void append(T e) override {
            insert(n, e);
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Fuera de rango2");
            }

            T value;
            if (pos == 0) {
                Node<T>* node = first;
                value = node->data;
                first = first->next;
                delete node;
            } else {
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) prev = prev->next;
                Node<T>* node = prev->next;
                value = node->data;
                prev->next = node->next;
                delete node;
            }

            n--;
            return value;
        }

        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Fuera de rango3");
            }
            Node<T>* cur = first;
            for (int i = 0; i < pos; i++) cur = cur->next;
            return cur->data;
        }

        int search(T e) override {
            Node<T>* cur = first;
            for (int i = 0; i < n; i++) {
                if (cur->data == e) return i;
                cur = cur->next;
            }
            return -1;
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }

        //fin heredados

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