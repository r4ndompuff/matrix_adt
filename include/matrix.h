#ifndef matrix_h
#define matrix_h
#include <exception>
#include <cstring>

class matrix {
private:
    int a, b;
    double **matr;
    static const double EPS;
    double str2double(char *s);
public:
    matrix();                                       // Default
    matrix(const matrix &timed);                    // Copy
    matrix(int n, int m);                           // First
    matrix(double d);                               // Second
    matrix(double*, int m);                         // Third
    matrix(int n, double*);                         // Fourth
    matrix(char*);                                  // Fifth
    static matrix identity(int n);                  // Sixth
    static matrix diagonal(double *vals, int n);    // Seventh
    int rows();                                     // Ninth
    int columns();                                  // Tenth
    void set(int i, int j, double val);             // Eleventh
    matrix operator[](int i);                       // Twelfth (thirteenth)
    friend matrix operator*(matrix &x, double d);   // Fourteenth
    matrix& operator*=(double d);                   // 14
    friend std::ostream &operator<<(std::ostream &out, matrix &x); // Fifteenth
    friend matrix operator+(matrix &x, matrix &y);  // Sixteen
    matrix& operator+=(matrix &x);                  // Seventeen
    friend matrix operator-(matrix &x, matrix &y);  // 18
    matrix& operator-=(matrix &x);                  // 19
    matrix operator* (const matrix &x) const;       // 20
    matrix& operator*=(const matrix &x);            // 21
    matrix operator-() const;                       // 22
    bool operator==(const matrix &x) const;         // 23
    bool operator!=(const matrix &x) const;         // 24
    matrix operator| (const matrix &x) const;       // 25
    matrix operator/ (const matrix &x) const;       // 26
    matrix& operator=(const matrix &x);
    ~matrix();
};

class error_catcher : public std::exception {
private:
    char * error_message;
public:
    error_catcher(const char *s){
        error_message = new char[strlen(s)];
        strcpy(error_message, s);
    }
    virtual const char* what() const _NOEXCEPT {return error_message;}
};

#endif
