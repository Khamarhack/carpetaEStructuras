/***********************************************
* Fecha: 29 enero 2025
* autor: Santiago Camargo Trujillo
* materia: Estructura de Datos
* Tópico:
* PONTIFICIA UNIVERSIDAD JAVERIANA
*
***********************************************/
#include <iostream>

using namespace std;

// Variable global que mantiene el conteo de nodos activos
int numb_inst = 0;

// Definición de la clase Node (Nodo) que forma parte de la lista vinculada
template <class T>
class Node {
public:
  // Constructor que inicializa el valor y el siguiente nodo (opcionalmente)
  Node (const T &value, Node<T> *next = 0) {
    value_ = value;   // Asigna el valor al nodo
    next_ = next;     // Asigna el puntero al siguiente nodo
    cout << "Creating Node, "
         << ++numb_inst   // Incrementa el contador de nodos activos
         << " are in existence right now" << endl;
  }

  // Destructor que elimina el nodo y decrece el contador de nodos activos
  ~Node () {
    cout << "Destroying Node, "
         << --numb_inst   // Decrementa el contador de nodos activos
         << " are in existence right now" << endl;
    next_ = 0; // Se asegura de que el puntero al siguiente nodo sea nulo
  }

  // Método que devuelve el puntero al siguiente nodo
  Node<T>* next () const { 
    return next_; 
  }

  // Método que establece un nuevo puntero al siguiente nodo
  void next (Node<T> *new_next) { 
    next_ = new_next; 
  }

  // Método que devuelve el valor almacenado en el nodo
  const T& value () const { 
    return value_; 
  }

  // Método que establece un nuevo valor en el nodo
  void value (const T &value) { 
    value_ = value; 
  }

private:
  Node (); // Constructor privado para evitar su uso por fuera de la clase
  T value_;   // Valor almacenado en el nodo
  Node<T> *next_; // Puntero al siguiente nodo en la lista
};

// Definición de la clase LinkedList (Lista vinculada)
template <class T>
class LinkedList {
public:
  // Constructor que inicializa la lista vacía (head_ apunta a nullptr)
  LinkedList () : head_(0) {};

  // Destructor que elimina todos los nodos de la lista
  ~LinkedList () { delete_nodes (); };

  // Método para insertar un nuevo elemento al principio de la lista
  // Devuelve 0 si la inserción fue exitosa, -1 si hubo un fallo
  int insert (const T &new_item) {
    return ((head_ = new Node<T>(new_item, head_)) != 0) ? 0 : -1;
  }

  // Método para eliminar un elemento de la lista
  // Devuelve 0 si la eliminación fue exitosa, -1 si no se encontró el elemento
  int remove (const T &item_to_remove) {
    Node<T> *marker = head_; // Puntero que recorre la lista
    Node<T> *temp = 0; // Puntero que se usa para apuntar al nodo previo

    // Recorre la lista buscando el nodo con el valor a eliminar
    while (marker != 0) {
      if (marker->value() == item_to_remove) { // Nodo encontrado
        if (temp == 0) { // Si el nodo a eliminar es el primero
          if (marker->next() == 0) { // Si solo hay un nodo en la lista
            head_ = 0;  // La lista queda vacía
            delete marker; // Eliminar el único nodo
            marker = 0;
          } else {  // Si hay más nodos
            head_ = new Node<T>(marker->value(), marker->next()); // Mover el head a siguiente nodo
            delete marker; // Eliminar el nodo actual
            marker = 0;
          }
          return 0;
        } else { // Si el nodo a eliminar no es el primero
          temp->next(marker->next()); // Se salta el nodo a eliminar
          delete temp; // Eliminar el nodo previo
          temp = 0;
          return 0;
        }
      }
      marker = marker->next(); // Avanza al siguiente nodo
    }

    return -1; // Si el nodo no se encuentra, retorna -1 (fallo)
  }

  // Método que imprime todos los valores de la lista
  void print (void) {
    Node<T> *marker = head_; // Empieza desde el primer nodo
    while (marker != 0) {
      cout << marker->value() << endl;  // Imprime el valor del nodo
      marker = marker->next(); // Avanza al siguiente nodo
    }
  }

private:
  // Método privado que elimina todos los nodos de la lista
  void delete_nodes (void) {
    Node<T> *marker = head_; // Empieza desde el primer nodo
    while (marker != 0) {
      Node<T> *temp = marker; // Guarda el nodo actual
      delete marker;  // Elimina el nodo
      marker = temp->next();  // Avanza al siguiente nodo
    }
  }

  Node<T> *head_; // Puntero al primer nodo de la lista
};

int main (int argc, char **argv) {
  LinkedList<int> *list = new LinkedList<int>(); // Crea una lista vacía de enteros

  // Insertamos algunos elementos en la lista
  list->insert(1);  
  list->insert(2);  
  list->insert(3);  
  list->insert(4);

  cout << "The fully created list is:" << endl;
  list->print(); // Imprime la lista

  cout << endl << "Now removing elements:" << endl;
  list->remove(4);  // Elimina el nodo con valor 4
  list->print();    // Imprime la lista después de la eliminación
  cout << endl;

  list->remove(1);  // Elimina el nodo con valor 1
  list->print();    // Imprime la lista después de la eliminación
  cout << endl;

  list->remove(2);  // Elimina el nodo con valor 2
  list->print();    // Imprime la lista después de la eliminación
  cout << endl;

  list->remove(3);  // Elimina el nodo con valor 3
  list->print();    // Imprime la lista después de la eliminación

  delete list;  // Elimina la lista y libera la memoria

  return 0;  // Fin de la ejecución del programa
}
