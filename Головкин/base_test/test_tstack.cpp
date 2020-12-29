#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_too_large_length)
{
	ASSERT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}

TEST(TStack, can_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; ++i)
		st.push(i);
	TStack<int> st1(st);
	for (int i = 0; i < 5; ++i)
		EXPECT_EQ(st.pop(), st1.pop());
}

TEST(TStack, can_get_boolean_if_the_stack_is_full)
{
	TStack<int> st(MaxStackSize);
	EXPECT_EQ(false, st.full());
	for (int i = 0; i < MaxStackSize; ++i)
		st.push(i);
	EXPECT_EQ(true, st.full());
}

TEST(TStack, can_get_boolean_if_the_stack_is_empty)
{
	TStack<int> st;
	EXPECT_EQ(true, st.empty());
	st.push(0);
	EXPECT_EQ(false, st.empty());
}

TEST(TStack, can_push_and_pop_element)
{
	TStack<int> st;
	ASSERT_NO_THROW(st.push(10));
	EXPECT_EQ(10, st.pop());
}

TEST(TStack, can_peek_element)
{
	TStack<int> st;
	ASSERT_NO_THROW(st.push(10));
	EXPECT_EQ(10, st.peek());
}

TEST(TStack, cant_push_element_when_stack_is_overflow)
{
	TStack<int> st(MaxStackSize);
	for (int i = 0; i < MaxStackSize; ++i)
		st.push(i);
	ASSERT_ANY_THROW(st.push(10));
}

TEST(TStack, cant_pop_element_when_stack_is_underflow)
{
	TStack<int> st;
	ASSERT_ANY_THROW(st.pop());
}