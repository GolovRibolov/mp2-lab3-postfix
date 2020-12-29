#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_get_infix)
{
	TPostfix p;
	string infix = "( a + b ) * c";
	p.ToPostfix(infix);
	ASSERT_NO_THROW(p.GetInfix());
	EXPECT_EQ(infix, p.GetInfix());
}

TEST(TPostfix, can_get_postfix)
{
	TPostfix p;
	string infix = "( a + b ) * c";
	string postfix = "a b + c *";
	p.ToPostfix(infix);
	ASSERT_NO_THROW(p.GetPostfix());
	EXPECT_EQ(postfix, p.GetPostfix());
}

TEST(TPostfix, can_transform_infix_to_postfix)
{
	TPostfix p;
	string infix = "a * b + ( ( p + b ) - ( a + b ) * c )";
	string postfix = "a b * p b + a b + c * - +";
	ASSERT_NO_THROW(p.ToPostfix(infix));
	EXPECT_EQ(postfix, p.GetPostfix());
}