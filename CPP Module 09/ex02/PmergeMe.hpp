#pragma once

# include <iostream>
# include <iomanip>
# include <set>
# include <vector>
# include <deque>
# include <cctype>
# include <climits>
# include <stdlib.h>
# include <ctime>
# include <sys/time.h>

template <class container>
void  mergeSort(container &c, int leftPart, int middle, int rightPart)
{
	int size_leftPart = middle - leftPart + 1;
	int size_rightPart = rightPart - middle;

	container c_left(size_leftPart);
	container c_right(size_rightPart);
	
	for ( int i = 0; i < size_leftPart ; i++ )
		c_left[i] = c[leftPart + i];

	for ( int i = 0 ; i < size_rightPart ; i++ )
		c_right[i] = c[middle + 1 + i];

	int i = 0;
	int j = 0;
	int k = leftPart;

	while (i < size_leftPart && j < size_rightPart)
	{
		if (c_left[i] <= c_right[j])
			c[k++] = c_left[i++];
		else
			c[k++] = c_right[j++];
	}			
	while (i < size_leftPart)
		c[k++] = c_left[i++];
	while (i < size_rightPart)
		c[k++] = c_right[j++];
}

template <class container>
void	insertSort(container &c)
{
	typename container::iterator it;
	typename container::iterator it_tmp;

	for (it = c.begin() + 1 ; it != c.end() ; it++)
	{
		if (*it < *(it - 1))
		{
			int tmp = *it;
			it_tmp = it;
			while (it_tmp != c.begin() && tmp < *(it_tmp - 1))
			{
				*it_tmp = *(it_tmp - 1);
				it_tmp--;
			}
			*it_tmp = tmp;
		}
	}
}


template <class container>
std::clock_t insertMergeSort(container& c, int leftPart, int rightPart)
{
	std::clock_t timeAtStart = clock();

	if (rightPart - leftPart > 10)
	{
		int middle = leftPart + (rightPart - leftPart) / 2;

		insertMergeSort(c, leftPart, middle);
		insertMergeSort(c, middle + 1, rightPart);
		mergeSort(c, leftPart, middle, rightPart);
	}
	else
		insertSort(c);

	return clock() - timeAtStart;
}

