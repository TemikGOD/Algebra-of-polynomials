#include "OpenHashTable.hpp"
#include <gtest/gtest.h>

TEST(OpenHashTableTest, AddPolynomial)
{
    OpenHashTable table;
    Poly poly(std::list<Monom>{Monom(1.0, {2, 1, 0}), Monom(-1.0, {1, 0, 0})});
    table.addPolynomial("poly1", &poly);
    EXPECT_THROW(table.addPolynomial("poly1", &poly), AddException);
}

TEST(OpenHashTableTest, DeletePolynomial)
{
    OpenHashTable table;
    Poly poly(std::list<Monom>{Monom(1.0, {2, 1, 0}), Monom(-1.0, {1, 0, 0})});
    table.addPolynomial("poly1", &poly);
    EXPECT_THROW(table.deletePolynomial("poly2"), NoPolyException);
    table.deletePolynomial("poly1");
    EXPECT_THROW(table.deletePolynomial("poly1"), NoPolyException);
}

TEST(OpenHashTableTest, SearchPolynomial)
{
    OpenHashTable table;
    Poly poly(std::list<Monom>{Monom(1.0, {2, 1, 0}), Monom(-1.0, {1, 0, 0})});
    table.addPolynomial("poly1", &poly);
    Poly result = table.searchPolynomial("poly1");
    EXPECT_EQ("1x^2*y^1 + -1x^1", result.Print());
    EXPECT_THROW(table.searchPolynomial("poly2"), NothingFoundException);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

