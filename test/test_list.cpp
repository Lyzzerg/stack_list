#include "../include/THeadList.h"

#include "../gtest/gtest.h"

TEST(THeadList, can_create_list)
{
	ASSERT_NO_THROW(THeadList<int> list);
}