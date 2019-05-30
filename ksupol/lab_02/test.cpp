#include <QtTest/QTest>

#include "matrix.hpp"
#include "miterator.hpp"

class MatrixTest: public QObject
{   Q_OBJECT
    private slots:
        void createTest();
        void listCreateTest();
        void iterTest();
        void iterTest_02();
};

void MatrixTest::createTest()
{
    size_t row = 3;
    size_t col = 3;
    double init = 3;

    Matrix<double> mtr(row, col, init);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            QCOMPARE(mtr[i][j], init);
        }
    }
}

void MatrixTest::listCreateTest()
{
    size_t row = 3;
    size_t col = 3;

    Matrix<double> mtr
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            QCOMPARE(mtr[i][j], double(i * col + j + 1));
        }
    }

}

void MatrixTest::iterTest()
{
    Matrix<double> mtr
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    size_t j = 1;
    for (auto i = mtr.cbegin(); i != mtr.cend(); i++)
    {
        QCOMPARE(size_t(*i), j);
        j++;
    }
}

void MatrixTest::iterTest_02()
{
    const size_t row = 5, col = 3;
    Matrix<double> mtr(row, col);
    auto iter = mtr.begin();
    int j = 1;

    while (iter != mtr.end())
    {
        *iter = j;
        iter++;
        j++;
    }

    Matrix<double> mtr2(row, col);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            mtr2[i][j] = i * col + j + 1;
        }
    }

    QVERIFY(mtr == mtr2);
}

QTEST_MAIN(MatrixTest);
#include <test.moc>
