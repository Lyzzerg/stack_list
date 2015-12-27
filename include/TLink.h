#pragma once
#define _USE_MATH_DEFINES
#include <stdio.h>
template <class LinkType>
class TLink
{
public:
	LinkType value;
	TLink *NextLink;
};
