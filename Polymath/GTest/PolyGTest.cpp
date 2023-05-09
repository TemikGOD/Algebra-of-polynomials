#include "poly.hpp"
#include <gtest/gtest.h>

TEST(PolyTest, DefaultConstructor)
{
    Poly poly;
    EXPECT_TRUE(poly.isZero());
}

TEST(PolyTest, CopyConstructor)
{
    std::list<Monom> monoms = {Monom(2.0, {3, 2, 1}), Monom(1.0, {1, 0, 0})};
    Poly p1(monoms);
    Poly p2(p1);
    EXPECT_EQ(p1, p2);
}

TEST(PolyTest, OperatorAssign)
{
    std::list<Monom> monoms1 = {Monom(2.0, {3, 2, 1}), Monom(1.0, {1, 0, 0})};
    Poly p1(monoms1);
    std::list<Monom> monoms2 = {Monom(3.0, {4, 3, 2}), Monom(1.0, {2, 1, 0})};
    Poly p2(monoms2);
    p1 = p2;
    EXPECT_EQ(p1, p2);
}

TEST(PolyTest, OperatorAddPoly)
{
    std::list<Monom> monoms1 = {Monom(2.0, {3, 2, 1}), Monom(1.0, {1, 0, 0})};
    Poly p1(monoms1);
    std::list<Monom> monoms2 = {Monom(3.0, {3, 2, 1}), Monom(1.0, {2, 1, 0})};
    Poly p2(monoms2);
    std::list<Monom> monoms_res = {Monom(5.0, {3, 2, 1}), Monom(1.0, {2, 1, 0}), Monom(1.0, {1, 0, 0})};
    Poly p_res(monoms_res);
    EXPECT_EQ(p1 + p2, p_res);
}

TEST(PolyTest, OperatorAddDouble)
{
    std::list<Monom> monoms = {Monom(2.0, {3, 2, 1}), Monom(1.0, {1, 0, 0})};
    Poly p(monoms);
    std::list<Monom> monoms_res = {Monom(3.0, {0, 0, 0}), Monom(2.0, {3, 2, 1}), Monom(1.0, {1, 0, 0})};
    Poly p_res(monoms_res);
    EXPECT_EQ(p + 1.0, p_res);
}

TEST(PolyTest, OperatorSubPoly)
{
    std::list<Monom> monoms1 = {Monom(2.0, {3, 2, 1}), Monom(1.0, {1, 0, 0})};
    Poly p1(monoms1);
    std::list<Monom> monoms2 = {Monom(3.0, {3, 2, 1}), Monom(1.0, {2, 1, 0})};
    Poly p2(monoms2);
    std::list<Monom> monoms_res = {Monom(-1.0, {1, 0, 0})};
    Poly p_res(monoms_res);
    EXPECT_EQ(p1 - p2, p_res);
}

TEST(PolyTest, OperatorDivision)
{
    Poly dividend(std::list<Monom>{Monom(1.0, {2, 1, 0}), Monom(2.0, {0, 2, 1}), Monom(-1.0, {1, 0, 0})});
    Poly divisor(std::list<Monom>{Monom(1.0, {1, 0, 0}), Monom(1.0, {0, 1, 0})});
    Poly quotient = dividend / divisor;
    EXPECT_EQ("1x^1*y^1 + 1z^1", quotient.Print());
}

TEST(PolyTest, OperatorDivisionByZero)
{
    Poly dividend(std::list<Monom>{Monom(1.0, {2, 1, 0}), Monom(2.0, {0, 2, 1}), Monom(-1.0, {1, 0, 0})});
    Poly divisor;
    EXPECT_THROW(dividend / divisor, std::runtime_error);
}

TEST(PolyTest, Point)
{
    Poly poly(std::list<Monom>{Monom(2.0, {2, 1, 0}), Monom(-1.0, {1, 0, 0})});
    double result = poly.Point(2.0, 1.0, 0.0);
    EXPECT_DOUBLE_EQ(8.0, result);
}

TEST(PolyTest, Derivative)
{
    Poly poly(std::list<Monom>{Monom(2.0, {2, 1, 0}), Monom(-1.0, {1, 0, 0})});
    Poly result = poly.Derivative();
    EXPECT_EQ("4x^1*y^1 + -1", result.Print());
}

TEST(PolyTest, DerivativeZero)
{
    Poly poly;
    Poly result = poly.Derivative();
    EXPECT_EQ("0", result.Print());
}

TEST(PolyTest, Print)
{
    Poly poly(std::list<Monom>{Monom(2.0, {2, 1, 0}), Monom(-1.0, {1, 0, 0})});
    EXPECT_EQ("2x^2*y^1 + -1x^1", poly.Print());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
