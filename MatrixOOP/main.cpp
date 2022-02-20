#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Matrix
{
    int rows;
    int cols;
    int** matrix;
public:
    int get_rows()const
    {
        return rows;
    }
    int get_cols()const
    {
        return cols;
    }
    //                Constructors:
    Matrix(int rows = 2, int cols = 2)
    {
        this->rows = rows;
        this->cols = cols;
        this->matrix = new int*[rows] {};
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols] {};
        }
        cout << "Constructor:\t" << this << endl;
    }
    Matrix(int n):Matrix(1, n)
    {
        
    }
    Matrix(const Matrix& other)
    {
        *this = other;
        cout << "CopyConstructor:\t" << this << endl;
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
        rows = 0;
        cols = 0;
        cout << "Destructor:\t" << this << endl;
    }

    //MARK: --   Operators:
    
    Matrix& operator=(const Matrix& other)
    {
        if (this == &other)return *this;
        this->~Matrix();
        this->rows = other.rows;
        this->cols = other.cols;
        this->matrix = new int*[rows] {};
        for (int i = 0; i < rows; i++)
        {
            this->matrix[i] = new int[cols] {};
            memcpy(this->matrix[i], other.matrix[i], cols * sizeof(int));
        }
        cout << "CopyAssignment:\t" << this << endl;
        return *this;
    }
    const int* operator[](int i)const
    {
        return matrix[i];
    }
    int* operator[](int i)
    {
        return matrix[i];
    }

    //MARK: --    Methods:
    
    void print()const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix A(3, 3);
    for (int i = 0; i < A.get_rows(); i++)
    {
        for (int j = 0; j < A.get_cols(); j++)
        {
            A[i][j] = rand() % 100;
        }
    }
    A = A;
    A.print();
    Matrix B(3, 3);
    B = A;
    B.print();
    
    return 0;
}
