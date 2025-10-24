#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> matrixMultiply(const vector<vector<int>> &A,const vector<vector<int>> &B)
{
    if (A[0].size()!=B.size())
    {
        cout << "Matrix error" << endl;
        vector<vector<int>> v;
        return v;
    }
    size_t row = A.size(),col = B[0].size();
    vector<vector<int>> result(row,vector<int>(col,0));
    for(size_t i=0;i<row;++i)
    {
        for(size_t j=0;j<col;++j)
        {
            for(size_t k=0;k<A[0].size();++k)
            {
                result[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return result;
}
void printMatrix(const vector<vector<int>> &matrix)
{
    for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[0].size();++j)
            {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    cout << flush;
}
vector<vector<int>> powerMatrix(vector<vector<int>> A,int n)
{
    vector<vector<int>> B = A;
    for(int i=1;i<n;++i)
    {
        B = matrixMultiply(A,B);
    }
    return B;
}
int main()
{
        cout << "请输入第一个矩阵的行数和列数: " << flush;
        int i1{},j1{},i2{},j2{};
        cin >> i1 >> j1;
        cout << "请输入第二个矩阵的行数和列数: " << flush;
        cin >> i2 >> j2;
        if (j1!=i2)
        {
            cerr << "请输入可相乘的矩阵" << endl;
            return 0;
        }
    vector<vector<int>> m1 (i1,vector<int>(j1));
    vector<vector<int>> m2 (i2,vector<int>(j2));
    for(int ii=0;ii<i1;++ii)
    {   
        cout << "请输入第一个矩阵的第" << ii+1 << "行";
        for(int i=0;i<j1;++i)
        {
            int n;
            cin >> n;
            m1[ii][i] = n;
        }
    }
    for(int ii=0;ii<i2;++ii)
    {   
        cout << "请输入第二个矩阵的第" << ii+1 << "行";
        for(int i=0;i<j2;++i)
        {
            int n;
            cin >> n;
            m2[ii][i] = n;
        }
    }
    cout << "结果如下:" << endl;
    printMatrix(matrixMultiply(m1,m2));
    system("pause");
}