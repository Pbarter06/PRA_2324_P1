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


            }

            void append(T e) override {
                    //

            }


            void prepend(T e) override {
                    //

            }


            T remove(int pos) override {
                    //

            }

            T get(int pos) override {
                    //
            }

            int search(T e) override {

            }

            bool empty() override {

            }


            int size() override {

            }






};
