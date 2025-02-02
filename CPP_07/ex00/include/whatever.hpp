#pragma once

#include <iostream>

template <typename M>
const M	&max(const M &x ,const M &y)
{
	return (x > y ? x : y);
}

template <typename W>
const W &min(const W &x, const W &y)
{
	return(x < y ? x : y);
}

template <typename S>
void swap(S &x, S &y)
{
	S	temp = x;
	x = y;
	y = temp;
}