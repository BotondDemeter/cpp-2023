//
// Created by Boti on 10/30/2023.
//

#include "Matrix.h"

// Default constructor
Matrix::Matrix(int rows, int cols) : mRows(rows), mCols(cols) {
    mElements = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        mElements[i] = new double[cols];
    }
}

// Copy constructor
Matrix::Matrix(const Matrix& other) : mRows(other.mRows), mCols(other.mCols) {
    mElements = new double*[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = other.mElements[i][j];
        }
    }
}

// Move constructor
Matrix::Matrix(Matrix&& other) : mRows(other.mRows), mCols(other.mCols), mElements(other.mElements) {
    other.mElements = nullptr;
    other.mRows = 0;
    other.mCols = 0;
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;
}

// Fills the matrix with identical elements
void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

// Fills the matrix with random real numbers in the range [a, b)
void Matrix::randomMatrix(int a, int b) {
    random_device rd;   // Used to obtain a random seed
    mt19937 gen(rd());  // Standard mersenne_twister_engine
    uniform_real_distribution<double> dis(a, b);
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = dis(gen); // Generate a random real number in [a, b)
        }
    }
}

// Prints the matrix
void Matrix::printMatrix(ostream& os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << "\t"; // Print each element separated by a tab
        }
        os << endl; // Start a new line for the next row
    }
}

// Checks whether this matrix is a square one
bool Matrix::isSquare() const {
    return mRows == mCols;
}

// Overload the + operator for matrix addition
Matrix operator+(const Matrix& x, const Matrix& y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw out_of_range("Matrix dimensions do not match for addition");
    }
    Matrix result(x.mRows, x.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < x.mCols; ++j) {
            result.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return result;
}

// Overload the * operator for matrix multiplication
Matrix operator*(const Matrix& x, const Matrix& y) {
    if (x.mCols != y.mRows) {
        throw std::out_of_range("Matrix dimensions are not suitable for multiplication");
    }
    Matrix result(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            result.mElements[i][j] = 0;
            for (int k = 0; k < x.mCols; ++k) {
                result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return result;
}

// Overload the >> operator for reading a Matrix from an input stream
istream & operator>>(std::istream& is, Matrix& mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

// Overload the << operator for outputting a Matrix to an output stream
ostream & operator<<(ostream& os, const class Matrix& mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << "\t"; // Print each element separated by a tab
        }
        os << std::endl; // Start a new line for the next row
    }
    return os;
}

// Index operator for non-constant access
double* Matrix::operator[] (int index) {
    if (index < 0 || index >= mRows) {
        throw std::out_of_range("Index out of range");
    }
    return mElements[index];
}

// Index operator for constant access
double* Matrix::operator[] (int index) const {
    if (index < 0 || index >= mRows) {
        throw std::out_of_range("Index out of range");
    }
    return mElements[index];
}

// Copy assignment operator
Matrix& Matrix::operator=(const Matrix& mat) {
    if (this == &mat) {
        // Self-assignment, no need to do anything
        return *this;
    }

    if (mRows != mat.mRows || mCols != mat.mCols) {
        throw std::out_of_range("Matrix dimensions do not match for assignment");
    }

    // Copy the matrix elements
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = mat.mElements[i][j];
        }
    }

    return *this;
}

// Move assignment operator
Matrix& Matrix::operator=(Matrix&& mat) {
    if (this == &mat) {
        // Self-assignment, no need to do anything
        return *this;
    }

    // Release the resources owned by the current object
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;

    // Move the contents of 'mat' into the current object
    mRows = mat.mRows;
    mCols = mat.mCols;
    mElements = mat.mElements;

    // Nullify 'mat' to prevent it from releasing resources when destroyed
    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;

    return *this;
}



