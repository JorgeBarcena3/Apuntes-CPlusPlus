#include <iostream>
#include <cstdint> //Incluye: size_t, nullptr_t, ptrdiff_t, byte...
#include <cstddef>//Incluye: int8_t, int16_t... y uint8_t, uint16_t...

typedef unsigned int size_t; // Renombrar los tipos de datos con otro nombre

decltype(2 + 3) nombre_de_la_variable;//En este caso equivale a int. Selecciona el tipo de dato que se encuentra entre parentesis (Expresion, dato de plantilla)

using namespace std;

#pragma region Enumeraciones

enum ColorEnum { //Define un tipo de dato nuevo, que podemos utilizar directamente. Fuera del scope (ColorEnum a = RED)
    RED,            // 0
    GREEN,          // 1
    BLUE,           //2
    ORANGE = 5,     //5
    YELLOW,         //6
    WHITE           // 7
};

enum class ColorClassEnum { //Define un tipo de dato nuevo, que podemos utilizar directamente. En el scope (ColorClassEnum a = ColorClassEnum::RED)
    RED,
    GREEN,
    BLUE
};

enum { //Define una enumeracion que solamente se guarda en la variable EnumAnonima
    LOADING,
    RUNNING,
    FINISHED
} EnumAnonima;

#pragma endregion

#pragma region Estructuras

//Struct y class son lo mismo. Excepeto que por defecto struct es publico y class privado
struct MyStruct //Nuevo tipo de dato, que contiene miembros (De cualquier tipo)
{
    struct  estructura {}; //Estructura
    typedef char T;//Redefinimos el tipo de dato
    bool done;//Variables
    void reset() {};//Funciones
    enum enumeracion {};//Enumeraciones
};


#pragma endregion

#pragma region Static

//SCOPE GLOBAL
static int x = 1; //Es accesible en la unidad de compilacion que contenga esa declaración. Solo se puede acceder desde el mismo .cpp

//SCOPE FUNCION
void f() {
    static int x = 1; //No se destruye cuando se acaba la funcion, y es accesible fuera de ella
}

//SCOPE CLASE
class Clase1 {
    static bool done; //Esta variable la comparten todos los objetos del tipo Clase1
};

//Se declara en el cpp como "bool Clase1::done = false;"


#pragma endregion

#pragma region Sobrecarga de funciones

//Funcion que recibe un puntero
void sobreCargaPuntero(int* a) {

    cout << "Puntero inicializado\n";
}

//Sobrecarga de funcion que recibe un nullptr
void sobreCargaPuntero(nullptr_t a) {

    cout << "Puntero no incializado\n";
}

#pragma endregion

#pragma region Union

//Guarda en la misma direccion de memoria las variables 'x' e 'w'
//El sizeOf() de una union es el tamaño de la variable mas grande que contenga la union
union Color32 {

    uint32_t value;
    uint8_t components[4];
    struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

};

#pragma endregion

#pragma region POD (Plane Object Data)
//Un dato POD es un tipo de dato que se puede copiar solamente copiando sus bits

#pragma endregion

#pragma region "NEW"

//int* a = new int[2];
//delete a;

#pragma endregion

#pragma region Singleton

class Singleton {

private:

    Singleton() = default;
    Singleton(const Singleton&) = default;
    ~Singleton() = default;

public:

    static Singleton& get_instance() {
        static Singleton object;
        return object;
    }


};
#pragma endregion

int main()
{

    Color32 A;
    
    A.value = 0;
    cout << A.value << endl;    
    
    
    A.r = 255;
    A.g = 255;
    A.b = 255;
    cout << A.value << endl;
    
    A.value = 0;
    cout << A.value << endl;
    
    A.components[0] = 255;
    A.components[1] = 255;
    A.components[2] = 255;
    cout << A.value << endl;

}
