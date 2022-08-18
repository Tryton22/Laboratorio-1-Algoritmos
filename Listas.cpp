#include<iostream>
#include<string>

using namespace std;

class Estudiante{
    private: 
        string nombre;
        int edad;

    public:
        Estudiante(string nombre, int edad){
            this->nombre = nombre;
            this->edad = edad;
        }

        Estudiante(){
            this->nombre = "";
            this->edad = 0;
        }

        string getNombre(){
            return nombre;
        }

        void setNombre(string nombre){
            this->nombre = nombre;
        }   

        int getEdad(){
            return edad;
        }

        void setEdad(int edad){
            this->edad = edad;
        }
};


//Por comodidad, es mejor definir la clase "Nodo" para luego definir la lista
//(cada nodo esta formado por los datos y por su "apuntador" al siguiente)
class NodoEstudiante{
    private:
        Estudiante valor;
        NodoEstudiante *vecino;

    public:
        NodoEstudiante(){
            this->vecino = NULL;
        }

        NodoEstudiante(Estudiante nuevo){
            this->valor.setNombre(nuevo.getNombre());
            this->valor.setEdad(nuevo.getEdad());

            this->vecino = NULL;
        }

        void setVecino(NodoEstudiante *vec){
            this->vecino = vec;
        }
                
        NodoEstudiante *getVecino(){
            return(this->vecino);
        }

        Estudiante *getEstudiante(){
            return(&this->valor);
        }

};

class ListaEstudiantes{
    private:
        NodoEstudiante *primero, *ultimo;

    public:
        ListaEstudiantes(){
            primero = ultimo = NULL;
        }

        void insertarNodo(NodoEstudiante *nuevo){
            if (ultimo == NULL){
                primero = ultimo = nuevo;
            }else{
                ultimo->setVecino(nuevo);
                ultimo = nuevo;
            }            
        }

        void insertarPrimero(NodoEstudiante *nuevo){
                nuevo->setVecino(primero);
                primero = NULL;
                primero = nuevo;
        }

        void quitarPrimero(){
            NodoEstudiante *recorrer;
            recorrer = primero;
            recorrer = recorrer->getVecino();
            delete primero;
            primero = recorrer;
                        
        }

        void quitarUltimo(){
            NodoEstudiante *recorrer;
            NodoEstudiante *previo;
            NodoEstudiante *nulo;
            
            nulo = NULL;
            recorrer = primero;

            while(recorrer->getVecino()!=NULL){
                previo = recorrer;
                recorrer = recorrer->getVecino();
            }
            
            delete ultimo;
            previo->setVecino(nulo);
            ultimo = previo;
        
            
        }

        void mostrarLista(){
            NodoEstudiante *recorrer;

            recorrer = primero;

            while(recorrer!=NULL){
                Estudiante *estudiante;
                estudiante = recorrer->getEstudiante();

                cout <<"Estudiante" << endl;
                cout <<"-- Nombre: " << estudiante->getNombre()  << endl;;
                cout <<"-- Edad: " << estudiante->getEdad() << endl;

                recorrer = recorrer->getVecino();
           }
        }

        void buscarEstudiante(string nombre){
            NodoEstudiante *recorrer;
            recorrer = primero;

            while(recorrer!=NULL){
                Estudiante *estudiante;
                estudiante = recorrer->getEstudiante();
                
                if (nombre == estudiante->getNombre()){
                    cout <<"Verdadero" << endl;
                    return;
                }
                recorrer = recorrer->getVecino();
           }
           
           cout <<"Falso" << endl;

        }
};

int main(){
    int decision;

    ListaEstudiantes lista;
    Estudiante p("Estudiante 1", 20);
    NodoEstudiante *nuevo= new NodoEstudiante(p);

    lista.insertarNodo(nuevo);

    Estudiante q("Estudiante 2", 30);
    NodoEstudiante *nuevo2= new NodoEstudiante(q);

    lista.insertarNodo(nuevo2);
    lista.mostrarLista();

    lista.buscarEstudiante("Estudiante 3");

    Estudiante r("Estudiante 3", 25);
    NodoEstudiante *nuevo3= new NodoEstudiante(r);

    lista.insertarPrimero(nuevo3);
    lista.mostrarLista();

    lista.buscarEstudiante("Estudiante 3");

    lista.quitarPrimero();
    lista.mostrarLista();

    lista.quitarUltimo();
    lista.mostrarLista();

    return 0;
}