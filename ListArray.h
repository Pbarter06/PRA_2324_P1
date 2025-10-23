#include <iostream>
#include <ostream>
#include <stdexcept>
#include "List.h"
using namespace std; 

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	
	    T* arr; 
	    int max; 
	    int n; 
	    static const int MINSIZE = 2; 

            void resize(int new_size){
		   T* new_arr = new T[new_size]; 
                   for (int i = 0; i < n; i++) {
                        new_arr[i] = arr[i];
                   }
                   
                   delete[] arr; 

                   arr = new_arr; 

                   max = new_size; 
		   
	   }

    public:
        // miembros públicos, incluidos los heredados de List<T>
    
	 
	    //Nuevos

	    ListArray(){
		   arr = new T[MINSIZE]; //Reservar memoria
                   max = MINSIZE; 
                   n = 0; 


	    } 

	    ~ListArray(){
		   delete[] arr; 
	 
 	    }


	   T operator[] (int pos){
                if(pos < 0 || pos >= n){
                        throw out_of_range("Posición fuera de rango"); 

                }

                return arr[pos]; 
           }
	


	   friend ostream& operator<<(ostream &out, const ListArray<T> &list){
                out << "["; 
		     for (int i = 0; i < list.n; i++) {
                        out << list.arr[i];
                        if (i < list.n - 1) {
                                out << ", ";
                        }
                }
                out << "]";
                return out;
        }  



	//heredados
            void insert(int pos, T e) override {
                if (pos < 0 || pos >= n){
                        throw out_of_range ("Fuera de rango"); 
                }

                if (n >= max){
                        resize(max *2); 
                }

                for(int i = n; i < pos; i--){
                        arr[i] = arr[i - 1];
                }

                arr[pos] = e; 

                n++; 

            }

            void prepend(T e) override {
                if (n >= max){
                        resize(max *2); 
                }
                for(int i = n; i < 0; i--){
                        arr[i] = arr[i - 1];
                }

                arr[0] = e; 

                n++; 
            }


            void append(T e) override {
                if (n >= max){
                        resize(max *2); 
                }
                
                arr[n] = e; 

                n++; 

            }


            T remove(int pos) override {
                if (pos < 0 || pos >= n){
                        throw out_of_range ("Fuera de rango"); 
                }

                T element = arr[pos]; 

                for(int i = pos; i < n - 1; i++){
                        arr[i] = arr[i - 1];
                }

                n--; 

                return element; 
            }

            T get(int pos) override {
                 if (pos < 0 || pos >= n){
                        throw out_of_range ("Fuera de rango"); 
                }

                return arr[pos]; 
            }

            int search(T e) override {
                for(int i = 0; i < n; i++){
                        if(arr[i] == e){
                                return i + 1; 
                        }
                }
                return -1; 
            }

            bool empty() override {
                if (n == 0) return true; 
                else return false; 
            }


            int size() override {
                return n; 
            }






};
