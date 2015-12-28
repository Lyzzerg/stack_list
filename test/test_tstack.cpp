#include "../include/TStack.h"

#include "../gtest/gtest.h"
TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> st);
}