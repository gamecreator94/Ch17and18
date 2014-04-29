#include <iomanip>
#include <sstream>
#include "matrix5.h"

using namespace std;

namespace BigCPlusPlus_Matrix
{

string Matrix::IndexException::format_message(int n)
{
    ostringstream outstr;
    outstr << "Matrix index " << n << " out of range";
    return outstr.str();
}

...

double& Matrix::operator()(int i, int j)
{
    if (i < 0 || i >= rows)
        throw Matrix::IndexException(i);
    if (j < 0 || j >= columns)
        throw Matrix::IndexException(j);
    return elements[i * get_columns() + j];
}

//...

}
