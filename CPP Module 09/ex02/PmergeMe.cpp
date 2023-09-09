#include "PmergeMe.hpp"

void mergeVector(std::vector<std::size_t> &v,std::vector<std::size_t> &left,std::vector<std::size_t> &right)
{
    int leftSize = left.size();
    int rightSize = right.size();
    int i=0,j=0,k=0;

    while(i<leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
            v[k]=left[i++];
        else
            v[k]=right[j++];
        k++;
    }
    while(i<leftSize)
        v[k++]=left[i++];
    while(j<rightSize)
        v[k++]=right[j++];
}

void mergeSortVector(std::vector<std::size_t> &v)
{
    int size = (int)v.size();
    if (size < 8)
        return;
    int midIndex = size/2;
    std::vector<std::size_t> left(v.begin(),v.begin()+midIndex);
    std::vector<std::size_t> right(v.begin()+midIndex,v.end());
    mergeSortVector(left);
    mergeSortVector(right);
    mergeVector(v,left,right);

}

void insertionSortVector(std::vector<std::size_t> &v)
{
    for (int i =1;i < (int)v.size();i++)
    {
        std::size_t curVal = v[i];
        int j = i-1;
        while(j>=0 && v[j] > curVal)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1]=curVal;
    }
}

std::clock_t mergeInsertionSortVector(std::vector<std::size_t> &v)
{
    std::clock_t timeAtStart = clock();
    
    mergeSortVector(v);
    insertionSortVector(v);
    
    return clock() - timeAtStart;
}



void insert(std::deque <std::size_t> &dq)
{
    for (size_t i = 0; i < dq.size(); i++)
	{
		size_t key = dq[i];
		int j = i - 1;
		while (j >= 0 && dq[j] > key)
		{
			dq[j + 1] = dq[j];
			j--;
		}
		dq[j + 1] = key;
	}
    
}

void merge(std::deque <std::size_t> &dq, std::deque <std::size_t> &left, std::deque <std::size_t> &right)
{
    while (left.size() && right.size())
    {
        if (left.front() < right.front())
        {
            dq.push_back(left.front());
            left.pop_front();
        }
        else
        {
            dq.push_back(right.front());
            right.pop_front();
        }
    }
    while(left.size())
    {
        dq.push_back(left.front());
        left.pop_front();
    }
    while(right.size())
    {
        dq.push_back(right.front());
        right.pop_front();
    }
}


std::clock_t    deque_sorted(std::deque <std::size_t> &dq, size_t k)
{
    std::clock_t timeAtStart = clock();
    
    if (k < 1)
    {
        deque_sorted(dq, 2);
        return clock() - timeAtStart;
    }
    if (dq.size() < k)
    {
        insert(dq);
        return clock() - timeAtStart;
    }
    size_t size = dq.size();
    std::deque <std::size_t> left(dq.begin(), dq.begin() + size/2);
    std::deque <std::size_t> right(dq.begin() + size/2 , dq.end());
    dq.clear();
    deque_sorted(left, k);
    deque_sorted(right, k);
    merge(dq,left,right);

    return clock() - timeAtStart;
}


