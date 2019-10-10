#include <iostream>

/** Implementacion de la clase de Vector2 con sus respectivos operandos
*/
template <class T>
class vec2
{

public:
    union {
        struct
        {
            T x;
            T y;
        };
        T v[2];
    };

public:

    /** Implementacion del constructor por defecto
    */
    inline vec2()
    {
        x = 0;
        y = 0;
    };

    /** Implementacion del constructor con parametros
    */
    inline vec2(T a_X, T a_Y) : x(a_X), y(a_Y){
    };

    /** Operacion de igualacion
    */
    inline vec2& operator=(const vec2& rhs) {

        x = rhs.x;
        y = rhs.y;
        return *this;
    };

    /** Operacion de suma
    */
    inline vec2& operator+=(const vec2& a_Rhs) {

        x += a_Rhs.x;
        y += a_Rhs.y;
        return *this;
    };

    /** Operacion de resta
    */
    inline vec2& operator-=(const vec2& a_Rhs) {

        x += (a_Rhs.x * -1);
        y += (a_Rhs.y * -1);
        return *this;
    };

    /** Operacion de multiplicacion
    */
    inline vec2& operator*=(T a_Rhs) {

        x *= a_Rhs;
        y *= a_Rhs;
        return *this;
    };

    /** Operacion de division
    */
    inline vec2& operator/=(T a_Rhs) {

        x *= (1 / a_Rhs);
        y *= (1 / a_Rhs);
        return *this;
    };

    /** Operacion de corchetes
    */
    inline T operator[](size_t a_Index) const {

        if (a_Index <= 1)
            return v[a_Index];
        else
            throw std::out_of_range("Error with the index " + a_Index);

    };

    /** Operacion de corchetes
    */
    inline T& operator[](size_t a_Index) {

        if (a_Index <= 1)
            return v[a_Index];
        else
            throw std::out_of_range("Error with the index " + a_Index);

    };

    /** Operacion de la normal
    */
    inline T dot(vec2 const& a_Rhs) const {

        return (x * a_Rhs.x + y * a_Rhs.y);

    };

    /** Nomaliza
    */
    inline vec2& normalize() {

        float magnitude = length();
        x = x / magnitude;
        y = y / magnitude;
        return *this;

    };

    /** Longitud del vector
    */
    inline T length() const {

        return sqrt((x * x) + (y * y));

    };
};


/** Operacion de suma 
*/
template <class T>
vec2<T> operator+(const vec2<T>& a_Lhs, const vec2<T> a_Rhs) {
    vec2<T> newVec;
    newVec.x = a_Lhs.x + a_Rhs.x;
    newVec.y = a_Lhs.y + a_Rhs.y;
    return newVec;
}

/** Operacion de resta
*/
template <class T>
vec2<T>  operator-(const vec2<T>& a_Lhs, const vec2<T>& a_Rhs) {

    vec2<T> newVec;
    newVec.x = a_Lhs.x + (-1 * a_Rhs.x);
    newVec.y = a_Lhs.y + (-1 * a_Rhs.y);
    return newVec;

};

/** Operacion de multiplicacion
*/
template <class T>
vec2<T>  operator*(const vec2<T>& a_Lhs, float a_Rhs) {
    vec2<T> newVec;
    newVec.x = a_Lhs.x * a_Rhs;
    newVec.y = a_Lhs.y * a_Rhs;
    return newVec;
};

/** Operacion de division
*/
template <class T>
vec2<T>  operator/(const vec2<T>& a_Lhs, float a_Rhs) {
    vec2<T> newVec;
    newVec.x = a_Lhs.x * (1 / a_Rhs);
    newVec.y = a_Lhs.y * (1 / a_Rhs);
    return newVec;
};

/** Operacion de comparacion
*/
template <class T>
bool operator==(const vec2<T>& a_Lhs, const vec2<T>& a_Rhs) {
    return (a_Lhs.x == a_Rhs.x && a_Lhs.y == a_Rhs.y)
};

/** Operacion de distinto de 
*/
template <class T>
bool operator!=(const vec2<T>& a_Lhs, const vec2<T>& a_Rhs) {
    return (a_Lhs.x != a_Rhs.x || a_Lhs.y != a_Rhs.y)
};

/** Clase para almacenar vectores de 3 dimensiones
*/
template <class T>
class vec3 {

public:

    union {
        struct
        {
            T x;
            T y;
            T z;
        };
        T v[3];
        struct
        {
            T r;
            T g;
            T b;

        };
    };

public:

    /** Constructor por defecto
    */
    inline vec3() {

        x = z = y = 0;
    };

    /** Constructor con parametros
    */
    inline vec3(T a_X, T a_Y, T a_Z) : x(a_X), y(a_Y), z(a_Z){
    };

    /** Operador de igualacion
    */
    inline vec3& operator=(const vec3& rhs) {

        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    };

    /** Operador de suma
    */
    inline vec3& operator+=(const vec3& a_Rhs) {

        x += a_Rhs.x;
        y += a_Rhs.y;
        z += a_Rhs.z;
        return *this;
    };

    /** Operador de resta
    */
    inline vec3& operator-=(const vec3& a_Rhs) {

        x -= a_Rhs.x;
        y -= a_Rhs.y;
        z -= a_Rhs.z;
        return *this;
    };

    /** Operador de multiplicacion
    */
    inline vec3& operator*=(T a_Rhs) {

        x *= a_Rhs;
        y *= a_Rhs;
        z *= a_Rhs;
        return *this;

    };

    /** Operador de division
    */
    inline vec3& operator/=(T a_Rhs) {

        x *= (1 / a_Rhs);
        y *= (1 / a_Rhs);
        z *= (1 / a_Rhs);
        return *this;
    };

    /** Operador de corchetes
    */
    inline  T operator[](size_t a_Index) const {

        if (a_Index <= 2)
            return v[a_Index];
        else
            throw std::out_of_range("Error with the index " + a_Index);

    };

    /** Operador de corchetes
    */
    inline  T& operator[](size_t a_Index) {

        if (a_Index <= 2)
            return v[a_Index];
        else
            throw std::out_of_range("Error with the index " + a_Index);

    };

    /** Operacion de dot
    */
    inline T dot(vec3 const& a_Rhs) const {

        return (x * a_Rhs.x + y * a_Rhs.y + z * a_Rhs.z);

    };

    /** Operacion de cross
    */
    inline vec3 cross(vec3 const& a_Rhs) const {

        return vec3((y * a_Rhs.z) - (z * a_Rhs.y), (z * a_Rhs.x) - (x * a_Rhs.z), (x * a_Rhs.y) - (y * a_Rhs.x));

    };

    /** Operacion de normalizacion
    */
    inline vec3& normalize() {

        float magnitude = length();
        x = x / magnitude;
        y = y / magnitude;
        z = z / magnitude;

        return *this;

    };

    /** Longitud del vector
    */
    inline T length() const {

        return sqrt((x * x) + (y * y) + (z * z));

    };
};

/** Operador de suma
*/
template <class T>
vec3<T> operator+(const vec3<T>& a_Lhs, const vec3<T>& a_Rhs) {
    vec3<T> newVec;
    newVec.x = a_Lhs.x + a_Rhs.x;
    newVec.y = a_Lhs.y + a_Rhs.y;
    newVec.z = a_Lhs.z + a_Rhs.z;
    return newVec;
};

/** Operador de resta
*/
template <class T>
vec3<T> operator-(const vec3<T>& a_Lhs, const vec3<T>& a_Rhs) {
    vec3<T> newVec;
    newVec.x = a_Lhs.x - a_Rhs.x;
    newVec.y = a_Lhs.y - a_Rhs.y;
    newVec.z = a_Lhs.z - a_Rhs.z;
    return newVec;
};

/** Operador de multiplicacion
*/
template <class T>
vec3<T> operator*(const vec3<T>& a_Lhs, float a_Rhs) {
    vec3<T> newVec;
    newVec.x = a_Lhs.x * a_Rhs;
    newVec.y = a_Lhs.y * a_Rhs;
    newVec.z = a_Lhs.z * a_Rhs;
    return newVec;
};

/** Operador de division
*/
template <class T>
vec3<T> operator/(const vec3<T>& a_Lhs, float a_Rhs) {
    vec3<T> newVec;
    newVec.x = a_Lhs.x * (1 / a_Rhs);
    newVec.y = a_Lhs.y * (1 / a_Rhs);
    newVec.z = a_Lhs.z * (1 / a_Rhs);
    return newVec;
};

/** Operador de comparacion
*/
template <class T>
bool operator==(const vec3<T>& a_Lhs, const vec3<T>& a_Rhs) {
    return (a_Lhs.x == a_Rhs.x && a_Lhs.y == a_Rhs.y && a_Lhs.z == a_Rhs.z)
};

/** Operador de distinto de 
*/
template <class T>
bool operator!=(const vec3<T>& a_Lhs, const vec3<T>& a_Rhs) {
    return (a_Lhs.x == a_Rhs.x && a_Lhs.y == a_Rhs.y && a_Lhs.z == a_Rhs.z)
};

/** Operacion de Dot
*/
template <class T>
float dot(const vec3<T>& a_Lhs, const vec3<T>& a_Rhs) { return (a_Lhs.x * a_Rhs.x + a_Lhs.y * a_Rhs.y + a_Lhs.z * a_Rhs.z); }
