#include "../../include/TQueue.h"

#include "../../gtest/gtest.h"

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> queue);
}