#include <iostream>
#include <cstring>
#include <cstdlib>
#include "../include/matrix.h"

const double matrix::EPS = 0.5;

matrix::matrix() {
    matr = NULL;
    a = -1;
    b = -1;
}

matrix::matrix(const matrix &timed): a(timed.a), b(timed.b), matr(timed.matr) {
        std::cout << "Copy success!\n";
}

matrix::matrix(int n, int m): a(n), b(m) {
    if ((n <= 0) or (m <= 0))
        throw error_catcher("Error code: -2");
    matr = new double *[a];
    for (int i = 0; i < a; i++) {
        matr[i] = new double[b];
        for (int j = 0; j < b; j++)
            matr[i][j] = 0.0;
    }
}

matrix::matrix(double d): a(1), b(1) {
    matr = new double *[a];
    for (int i = 0; i < a; i++) {
        matr[i] = new double[b];
        for (int j = 0; j < b; j++)
            matr[i][j] = d;
    }
}

matrix::matrix(double *d, int m): a(1), b(m) {
    if ((d == NULL) || (d[0] == '\0'))
        throw error_catcher("Error code: -1");
    matr = new double *[a];
    matr[0] = new double[b];
    for (int i = 0; i < m; i++)
        matr[0][i] = d[i];
}

matrix::matrix(int n, double* d): a(n), b(1) {
    if ((d == NULL) || (d[0] == '\0'))
        throw error_catcher("Error code: 0");
    matr = new double *[a];
    matr[0] = new double[b];
    for (int i = 0; i < n; i++)
        matr[i][0] = d[i];
}

matrix::matrix(char *s) {
    if ((s == NULL) || (s[0] == '\0'))
        throw error_catcher("Error code: 1");
    int len = (int)strlen(s);
    int w = 1, h = 0;
    for (int i = 1; i < len; i++)
        if (s[i] == '{') h++;
    for (int i = 1; s[i] != '}'; i++)
        if (s[i] == ',') w++;
    if (h == 0)
        throw error_catcher("Error code: 2");
    a = h;
    b = w;
    matr = new double *[h];
    for (int i = 0; i < h; i++)
        matr[i] = new double[w];
    bool in_digit = false;
    int i = 0, j = 0, tmp_index = 0;
    char tmp[100];
    for (int k = 1; k < len; k++) {
        if (not (((s[k] >= '0') && (s[k] <= '9')) || (s[k] == '{') || (s[k] == '}') || (s[k] == ',') || (s[k] == '.') || (s[k] == 'E') || (s[k] == 'e') || (s[k] == '+') || (s[k] == '-')))
            throw error_catcher("Error code: 3");
        if (s[k] == '{') {
            if (in_digit)
                throw error_catcher("Error code: 4");
            j = 0;
            continue;
        }
        if (((s[k] >= '0') && (s[k] <= '9')) || (s[k] == '.') || (s[k] == 'E') || (s[k] == 'e') || (s[k] == '+') || (s[k] == '-')) {
            if (not in_digit) in_digit = true;
            tmp[tmp_index++] = s[k];
            continue;
        }
        if (s[k] == ',') {
            if (not in_digit)
                throw error_catcher("Error code: 5");
            in_digit = false;
            matr[i][j] = str2double(tmp);
            for (int tmp_i = 0; tmp_i < 100; tmp_i++)
                tmp[tmp_i] = '\0';
            tmp_index = 0;
            j++;
            continue;
        }
        if (s[k] == '}') {
            if ((not in_digit) && (k != len - 1))
                throw error_catcher("Error code: 6");
            if (in_digit) {
                matr[i][j] = str2double(tmp);
                for (int tmp_i = 0; tmp_i < 100; tmp_i++)
                    tmp[tmp_i] = '\0';
                tmp_index = 0;
                k++;
                in_digit = false;
                i++;
                if (j != w - 1)
                    throw error_catcher("Error code: 7");
            }
        }
    }
}

matrix matrix::identity(int n) {
    if (n <= 0)
        throw error_catcher("Error code: 8");
    matrix x(n,n);
    for (int i = 0; i < n; i++)
        x.set(i, i, 1);
    return x;
}

matrix matrix::diagonal(double *vals, int n) {
    if (n <= 0)
        throw error_catcher("Error code: 9");
    matrix x(n,n);
    for (int i = 0; i < n; i++) {
        if (vals[i] == '\0')
            throw error_catcher("Error code: 10");
        x.set(i, i, vals[i]);
    }
    return x;
}

int matrix::rows(){
    return a;
}

int matrix::columns(){
    return b;
}

void matrix::set(int i, int j, double val) {
    if (matr == NULL)
         throw error_catcher("Error code: 11");
    if ((i >= a) || (j >= b))
        throw error_catcher("Error code: 12");
    matr[i][j] = val;
}

matrix matrix::operator[](int i) {
    if (i < 0)
        throw error_catcher("Error code: 13");
    if ((a > i) && (a != 1)) {
        matrix x(matr[i], b);
        return x;
    }
    else if (b > i) {
        double tmp[a];
        for (int j = 0; j < a; j++)
        tmp[j] = matr[j][i];
        matrix x(a, tmp);
        return x;
    }
    else throw error_catcher("Error code: 14");
}


matrix operator*(matrix &x, double d) {
    if (x.matr == NULL)
        throw error_catcher("Error code: 15");
    matrix res(x.a, x.b);
    for (int i = 0; i < x.a; i++)
        for (int j = 0; j < x.b; j++)
            res.set(i, j, x.matr[i][j] * d);
    return res;
}

matrix& matrix::operator*=(double d) {
    if (matr == NULL)
        throw error_catcher("Error code: 16");
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            matr[i][j] *= d;
    return *this;
}

std::ostream& operator<<(std::ostream &out, matrix &x) {
    if (x.matr == NULL)
        out << "Nothing to show." << std::endl;
    for (int i = 0; i < x.a; i++) {
        for (int j = 0; j < x.b; j++) {
            out << " ";
            out.width(5);
            out << x.matr[i][j];
        }
        out << std::endl;
    }
    return out;
}

matrix operator+(matrix &x, matrix &y) {
    if ((x.matr == NULL) || (y.matr == NULL))
        throw error_catcher("Error code: 17");
    matrix res(x.a, x.b);
    for (int i = 0; i < x.a; i++)
        for (int j = 0; j < x.b; j++)
            res.set(i, j, x.matr[i][j] + y.matr[i][j]);
    return res;
}

matrix& matrix::operator+=(matrix &x) {
    if (matr == NULL)
        throw error_catcher("Error code: 18");
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            matr[i][j] += x.matr[i][j];
    return *this;
}

matrix operator-(matrix &x, matrix &y) {
    if ((x.matr == NULL) || (y.matr == NULL))
        throw error_catcher("Error code: 19");
    matrix res(x.a, x.b);
    for (int i = 0; i < x.a; i++)
        for (int j = 0; j < x.b; j++)
            res.set(i, j, x.matr[i][j] - y.matr[i][j]);
    return res;
}

matrix& matrix::operator-=(matrix &x) {
    if (matr == NULL)
        throw error_catcher("Error code: 20");
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            matr[i][j] -= x.matr[i][j];
    return *this;
}

matrix matrix::operator-() const {
    if (matr == NULL)
        throw error_catcher("Error code: 21");
    matrix n(a, b);
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            n.set(i, j, -matr[i][j]);
    return n;
}

bool matrix::operator==(const matrix &x) const {
    if ((matr == NULL) || (x.matr == NULL))
        throw error_catcher("Error code: 21");
    if ((a != x.a) || (b != x.b))
        throw error_catcher("Error code: 22");
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (x.matr[i][j] - matr[i][j] > EPS)
                return false;
        }
    }
    return true;
}

bool matrix::operator!=(const matrix &x) const {
    if ((matr == NULL) || (x.matr == NULL))
        throw error_catcher("Error code: 23");
    if ((a != x.a) || (b != x.b))
        throw error_catcher("Error code: 24");
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (x.matr[i][j] - matr[i][j] > EPS)
                return true;
        }
    }
    return false;
}

matrix matrix::operator*(const matrix &x) const {
    if (b != x.a)
        throw error_catcher("Error code: 25");
    matrix new_matrix(a, x.b);
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < x.b; ++j) {
            for (int k = 0; k < b; ++k) {
                //the new matrix was fill with 0
                new_matrix.matr[i][j] += matr[i][k] * x.matr[k][j];
            }
        }
    }
    return new_matrix;
}

matrix& matrix::operator*=(const matrix &x) {
    *this = *this * x;
    return *this;
} 

matrix matrix::operator|(const matrix &x) const {
    if ((x.matr == NULL) || (matr == NULL))
        throw error_catcher("Error code: 26");
    if (x.a != a)
        throw error_catcher("Error code: 27");
    matrix new_matrix(a, x.b + b);
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < x.b + b; ++j) {
            if (j < x.b)
                new_matrix.matr[i][j] = matr[i][j];
            else
                new_matrix.matr[i][j] = x.matr[i][j-x.b];
        }
    }
    return new_matrix;
}

matrix matrix::operator/(const matrix &x) const {
    if ((x.matr == NULL) || (matr == NULL))
        throw error_catcher("Error code: 28");
    if (x.b != b)
        throw error_catcher("Error code: 29");
    matrix new_matrix(a + x.a, b);
    for (int i = 0; i < x.a + a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (i < a)
                new_matrix.matr[i][j] = matr[i][j];
            else
                new_matrix.matr[i][j] = x.matr[i-x.a][j];
        }
    }
    return new_matrix;
}

matrix &matrix::operator=(const matrix &x) {
    a = x.a;
    b = x.b;
    if (matr != NULL) {
        for (int i = 0; i < a; i++)
            delete[] matr[i];
        delete[] matr;
    }
    if (x.matr == NULL)
        matr = NULL;
    else {
        matr = new double *[a];
        for (int i = 0; i < a; i++) {
            matr[i] = new double[b];
            for (int j = 0; j < b; j++)
                matr[i][j] = x.matr[i][j];
        }
    }
    return *this;
}

matrix::~matrix(){
    for (int i = 0; i < a; i++)
        delete[] matr[i];
    delete[] matr;
}

double matrix::str2double(char *s){ // Internet function
    double res = 0.0;
    int i = 0;
    int e = 0;
    while ((*(s + i) != '\0') && (*(s + i) >= '0') && (*(s + i) <= '9')) {
        res = res * 10.0 + *(s + i) - '0';
        i++;
    }
    if (*(s + i) == '.'){
        i++;
        while ((*(s + i) != '\0') && (*(s + i) >= '0') && (*(s + i) <= '9')) {
            res = res * 10.0 + *(s + i) - '0';
            e--;
            i++;
        }
    }
    if ((*(s + i) == 'e') || (*(s + i) == 'E')) {
        int k = 0;
        i++;
        if (*(s + i) == '-') {
            i++;
            while ((*(s + i) != '\0') && (*(s + i) >= '0') && (*(s + i) <= '9')) {
                k = k * 10.0 + *(s + i) - '0';
                i++;
            }
            e -= k;
        }
        else {
            if (*(s + i) == '+') i++;
            while ((*(s + i) != '\0') && (*(s + i) >= '0') && (*(s + i) <= '9')) {
                k = k * 10.0 + *(s + i) - '0';
                i++;
            }
            e += k;
        }
    }
    while (e > 0) {
        res *= 10.0;
        e--;
    }
    while (e < 0) {
        res *= 0.1;
        e++;
    }
    return res;
}