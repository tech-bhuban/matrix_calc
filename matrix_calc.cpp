
#include <iostream>
#include <vector>
#include <iomanip>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows, cols;
    
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<double>(cols, 0));
    }
    
    void input() {
        std::cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                std::cin >> data[i][j];
            }
        }
    }
    
    void display() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                std::cout << std::setw(8) << std::fixed 
                          << std::setprecision(2) << data[i][j];
            }
            std::cout << "\n";
        }
    }
    
    Matrix add(const Matrix& other) {
        Matrix result(rows, cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    Matrix subtract(const Matrix& other) {
        Matrix result(rows, cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    
    Matrix multiply(const Matrix& other) {
        Matrix result(rows, other.cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < other.cols; j++) {
                for(int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    
    Matrix transpose() {
        Matrix result(cols, rows);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
    
    double determinant() {
        if(rows != cols || rows != 2) return 0;
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }
};

int main() {
    Matrix a(2, 2), b(2, 2);
    
    std::cout << "Matrix A:\n";
    a.input();
    std::cout << "Matrix B:\n";
    b.input();
    
    std::cout << "\nA + B:\n";
    a.add(b).display();
    
    std::cout << "\nA * B:\n";
    a.multiply(b).display();
    
    std::cout << "\nTranspose of A:\n";
    a.transpose().display();
    
    std::cout << "\nDeterminant of A: " << a.determinant() << "\n";
    
    return 0;
}
