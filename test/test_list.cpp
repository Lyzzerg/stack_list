#include "../include/THeadList.h"

#include "../gtest/gtest.h"

TEST(THeadList, can_create_stack)
{
	ASSERT_NO_THROW(THeadList<int> list);
}