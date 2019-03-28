#include <iostream>
#include "../include/matrix.h"

std::string help(
                "                           \\MAKE --------- Create matrix\n"
                "                           \\DIAG --------- Create diagonal matrix\n"
                "                           \\I    --------- Create matrix by 1's\n"
                "                           \\ROWS --------- Rows number\n"
                "                           \\COLS --------- Columns number\n"
                "                           \\INV  --------- 0 - matrix\n"
                "                           \\SET  --------- Set cell\n"
                "                           \\MULT --------- Multiply double\n"
                "                           \\MUMA --------- Multiply matrix\n"
                "                           \\SUM  --------- Matrix sum\n"
                "                           \\CONC| -------- Matrix|Matrix\n"
                "                           \\CONC/ -------- Matrix/Matrix\n"
                "                           \\SHOW --------- Print\n"
                "                           \\HELP --------- Help\n"
                "                           \\EXIT --------- Leave\n\n> "
);

void newline() {
    std::cout << "\n";
}

int main() {
    matrix X;
    bool flag = true;
    std::cout << "Use '\\HELP' for more information\n\n> ";
    while (true) {
        std::string s;
        std::getline(std::cin, s);  
        if (s == "\\HELP") {
            std::cout << help;
        }
        else if (s == "\\SHOW") {
            std::cout << X << "\n> ";
        }
        else if (s == "\\ROWS") {
            std::cout << X.rows() << "\n\n> ";
        }
        else if (s == "\\COLS") {
            std::cout << X.columns() << "\n\n> ";
        }
        else if (s == "\\MAKE") {
            std::cout << "Enter matrix as a string (Format: {{a1,..,a3},..,{z1,...,z3}}):\n>>> ";
            std::string buf;
            std::getline(std::cin, buf);
            int i = 0;
            char str[1000];
            for (int k = 0; k<1000; k++)
                str[k] = '\0';
            while ((buf[i] != '\0') && (i != 1024)) {
                str[i] = buf[i];
                i++;
            }
            if (i == 1000) {
                std::cout << "Error. Max symbols is 1000.\n\n> ";
                continue;
            }
            try {
                matrix m(str);
                X = m;
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
        }
        else if (s == "\\I") {
            flag = false;
            int sz = 1;
            std::cout << "Enter size: ";
            std::cin >> sz;
            try {
                matrix m;
                X = m.identity(sz);
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
        }
        else if (s == "\\DIAG") {
            flag = false;
            int sz = 1;
            std::cout << "Enter size: ";
            std::cin >> sz;
            double val[sz];
            for (int i = 0; i < sz; i++) {
                std::cout << "Enter value[" << i << "] :";
                std::cin >> val[i];
            }
            try {
                matrix m;
                X = m.diagonal(val, sz);
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
        }
        else if (s == "\\SET") {
            flag = false;
            int row = 1;
            int col = 1;
            double dble = 0;
            std::cout << "Enter row: ";
            std::cin >> row;
            newline();
            std::cout << "Enter column: ";
            std::cin >> col;
            newline();
            std::cout << "Enter value: ";
            std::cin >> dble;
            try {
                matrix m;
                m = X;
                m.set(row, col, dble);
                X = m;
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
            continue;

        }
        else if (s == "\\INV") {
            try {
                matrix m;
                m = -X;
                X = m;
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
            continue;

        }
        else if (s == "\\MUMA") {
            std::cout << "Enter matrix as a string (Format: {{a1,..,a3},..,{z1,...,z3}}):\n>>> ";
            std::string buf;
            std::getline(std::cin, buf);
            int i = 0;
            char str[1000];
            for (int k = 0; k<1000; k++)
                str[k] = '\0';
            while ((buf[i] != '\0') && (i != 1024)) {
                str[i] = buf[i];
                i++;
            }
            if (i == 1000) {
                std::cout << "Error. Max symbols is 1000.\n\n> ";
                continue;
            }
            try {
                matrix m(str);
                X *= m;
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
        }
        else if (s == "\\CONC|") {
            std::cout << "Enter matrix as a string (Format: {{a1,..,a3},..,{z1,...,z3}}):\n>>> ";
            std::string buf;
            std::getline(std::cin, buf);
            int i = 0;
            char str[1000];
            for (int k = 0; k<1000; k++)
                str[k] = '\0';
            while ((buf[i] != '\0') && (i != 1024)) {
                str[i] = buf[i];
                i++;
            }
            if (i == 1000) {
                std::cout << "Error. Max symbols is 1000.\n\n> ";
                continue;
            }
            try {
                matrix m(str);
                matrix n = X|m;
                X = n;
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
        }
        else if (s == "\\CONC/") {
            std::cout << "Enter matrix as a string (Format: {{a1,..,a3},..,{z1,...,z3}}):\n>>> ";
            std::string buf;
            std::getline(std::cin, buf);
            int i = 0;
            char str[1000];
            for (int k = 0; k<1000; k++)
                str[k] = '\0';
            while ((buf[i] != '\0') && (i != 1024)) {
                str[i] = buf[i];
                i++;
            }
            if (i == 1000) {
                std::cout << "Error. Max symbols is 1000.\n\n> ";
                continue;
            }
            try {
                matrix m(str);
                matrix n = X/m;
                X = n;
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
        }
        else if (s == "\\MULT") {
            std::cout << "Enter a number: ";
            flag = false;
            double dble;
            std::cin >> dble;
            try {
                X *= dble;
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
            continue;
        }
        else if (s == "\\SUM") {
            std::cout << "Enter matrix as a string (Format: {{a1,..,a3},..,{z1,...,z3}}):\n>>> ";
            std::string buf;
            std::getline(std::cin, buf);
            int i = 0;
            char str[1000];
            for (int k = 0; k<1000; k++)
                str[k] = '\0';
            while ((buf[i] != '\0') && (i != 1024)) {
                str[i] = buf[i];
                i++;
            }
            if (i == 1000) {
                std::cout << "Error. Max symbols is 1000.\n\n> ";
                continue;
            }
            try {
                matrix m(str);
                X += m;
                std::cout << "Success!\n\n> ";
            }
            catch (error_catcher error) {
                std::cerr << error.what();
            }
        }
        else if (s == "\\EXIT") {
            break;
        }
        else if (flag)
            std::cout << "No such command.\n\n> ";
        else {
            flag = true;
            std::cout << "\n> ";
        }
    }
    return 0;
}
