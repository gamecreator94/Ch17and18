#ifndef MATRIX5_H
#define MATRIX5_H
#include <iostream>
#include <stdexcept>

namespace BigCPlusPlus_Matrix
{

/**
This class describes a matrix with arbitrary rows and columns.
*/
class Matrix
{
    private:
    /**
    Forward reference for classes Row and ConstRow.
    */
    class Row;
    class ConstRow;

    public:
    ...

    /**
    Accesses a matrix row.
    @param i the row index
    @return the row with the given index
    */
    Row operator[](int i);

    /**
    Accesses a matrix row.
    @param i the row index
    @return the row with the given index
    */
    ConstRow operator[](int i) const;
    ...

    /**
    Forward reference for classes MismatchException and IndexException.
    */
    class MismatchException;
    class IndexException;

    private:
    ...
};

/**
This class describes a row in a matrix.
*/
class Matrix::Row
{
...
};

/**
Matrix exception class: Indexing error
*/
class Matrix::IndexException : public std::out_of_range
{
public:
IndexException(int i);
private:
std::string format_message(int i);
};

/**
Matrix exception class: Mismatched Argument error
*/
class Matrix::MismatchException : public std::invalid_argument
{
public:
    MismatchException();
};

...
std::ostream& operator<<(std::ostream& left, const Matrix& right);

inline Matrix::IndexException::IndexException(int idx)
    : out_of_range(format_message(idx)) {}

inline Matrix::MismatchException::MismatchException()
    : invalid_argument("Matrix arguments have incompatible sizes") {}
...
inline Matrix::Row::Row(Matrix* m, int s) : mat(m), i(s) { }

inline double& Matrix::Row::operator[](int j)
{
    return (*mat)(i,j);
}

...
}
#endif
