#include "monom.hpp"
#include <gtest/gtest.h>

TEST(MonomTest, DefaultConstructor)
{
    Monom m;
    EXPECT_EQ(0.0, m.getCoeff());
    EXPECT_EQ(0, m.getDegree(0));
    EXPECT_EQ(0, m.getDegree(1));
    EXPECT_EQ(0, m.getDegree(2));
}

TEST(MonomTest, CopyConstructor)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2(m1);
    EXPECT_EQ(2.0, m2.getCoeff());
    EXPECT_EQ(2, m2.getDegree(0));
    EXPECT_EQ(1, m2.getDegree(1));
    EXPECT_EQ(0, m2.getDegree(2));
}

TEST(MonomTest, ConstructorWithArray)
{
    Monom m(2.0, new int[3]{2, 1, 0});
    EXPECT_EQ(2.0, m.getCoeff());
    EXPECT_EQ(2, m.getDegree(0));
    EXPECT_EQ(1, m.getDegree(1));
    EXPECT_EQ(0, m.getDegree(2));
}

TEST(MonomTest, ConstructorWithDegreeArray)
{
    Monom m(2.0, {2, 1, 0});
    EXPECT_EQ(2.0, m.getCoeff());
    EXPECT_EQ(2, m.getDegree(0));
    EXPECT_EQ(1, m.getDegree(1));
    EXPECT_EQ(0, m.getDegree(2));
}

TEST(MonomTest, GetCoeff)
{
    Monom m(2.0, {2, 1, 0});
    EXPECT_EQ(2.0, m.getCoeff());
}

TEST(MonomTest, GetDegree)
{
    Monom m(2.0, {2, 1, 0});
    EXPECT_EQ(2, m.getDegree(0));
    EXPECT_EQ(1, m.getDegree(1));
    EXPECT_EQ(0, m.getDegree(2));
}

TEST(MonomTest, OperatorPlus)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2(3.0, {2, 1, 0});
    Monom m3 = m1 + m2;
    EXPECT_EQ(5.0, m3.getCoeff());
    EXPECT_EQ(2, m3.getDegree(0));
    EXPECT_EQ(1, m3.getDegree(1));
    EXPECT_EQ(0, m3.getDegree(2));
}

TEST(MonomTest, OperatorPlusThrows)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2(3.0, {2, 2, 0});
    EXPECT_THROW(m1 + m2, std::invalid_argument);
}

TEST(MonomTest, OperatorMinus)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2(3.0, {2, 1, 0});
    Monom m3 = m1 - m2;
    EXPECT_EQ(-1.0, m3.getCoeff());
    EXPECT_EQ(2, m3.getDegree(0));
    EXPECT_EQ(1, m3.getDegree(1));
    EXPECT_EQ(0, m3.getDegree(2));
}

TEST(MonomTest, OperatorMinusThrows)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2(3.0, {2, 2, 0});
    EXPECT_THROW(m1 - m2, std::invalid_argument);
}

TEST(MonomTest, OperatorMultiply)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2(3.0, {1, 2, 0});
    Monom m3 = m1 * m2;
    EXPECT_EQ(6.0, m3.getCoeff());
    EXPECT_EQ(3, m3.getDegree(0));
    EXPECT_EQ(3, m3.getDegree(1));
    EXPECT_EQ(0, m3.getDegree(2));
}

TEST(MonomTest, OperatorDivide)
{
    Monom m1(6.0, {3, 3, 0});
    Monom m2(2.0, {1, 1, 0});
    Monom m3 = m1 / m2;
    EXPECT_EQ(3.0, m3.getCoeff());
    EXPECT_EQ(2, m3.getDegree(0));
    EXPECT_EQ(2, m3.getDegree(1));
    EXPECT_EQ(0, m3.getDegree(2));
}

TEST(MonomTest, OperatorDivideThrows)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2(0.0, {1, 1, 0});
    EXPECT_THROW(m1 / m2, std::invalid_argument);
}

TEST(MonomTest, DerX)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2 = m1.DerX();
    EXPECT_EQ(4.0, m2.getCoeff());
    EXPECT_EQ(1, m2.getDegree(0));
    EXPECT_EQ(1, m2.getDegree(1));
    EXPECT_EQ(0, m2.getDegree(2));
}

TEST(MonomTest, DerXThrows)
{
    Monom m1(2.0, {0, 1, 0});
    EXPECT_THROW(m1.DerX(), std::invalid_argument);
}

TEST(MonomTest, DerY)
{
    Monom m1(2.0, {2, 1, 0});
    Monom m2 = m1.DerY();
    EXPECT_EQ(2.0, m2.getCoeff());
    EXPECT_EQ(2, m2.getDegree(0));
    EXPECT_EQ(0, m2.getDegree(1));
    EXPECT_EQ(0, m2.getDegree(2));
}

TEST(MonomTest, DerYThrows)
{
    Monom m1(2.0, {2, 0, 0});
    EXPECT_THROW(m1.DerY(), std::invalid_argument);
}

TEST(MonomTest, DerZ)
{
    Monom m1(2.0, {2, 1, 3});
    Monom m2 = m1.DerZ();
    EXPECT_EQ(6.0, m2.getCoeff());
    EXPECT_EQ(2, m2.getDegree(0));
    EXPECT_EQ(1, m2.getDegree(1));
    EXPECT_EQ(2, m2.getDegree(2));
}

TEST(MonomTest, DerZThrows)
{
    Monom m1(2.0, {2, 1, 0});
    EXPECT_THROW(m1.DerZ(), std::invalid_argument);
}

TEST(MonomTest, Print)
{
    Monom m(2.0, {2, 1, 0});
    EXPECT_EQ("2x^2*y^1", m.Print());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
