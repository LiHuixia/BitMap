#pragma once
#include<vector>
#include<iostream>
using namespace std;

class BitMap
{
public:
	BitMap(size_t size)
	{
		_bm.resize((size /32) + 1);  //需+1例：100/32=3,可以表示96个数，其余4个无法表示
		_size = 0;
	}
	BitMap()
		:_size(0)
	{}
	void set(size_t num)
	{
		size_t index = num >> 5;
		if ((_bm[index] & 1 << (num % 32)) == 0) //<<优先级高于&
		{
			_bm[index] |= 1 << (num % 32);
			++_size;
		}
	}
	void Reset(size_t num)
	{
		size_t index = num >> 5;
		if ((_bm[index] & (1 << (num % 32))) == 1 << (num % 32))
		{
			_bm[index] &= ~(1 << (num % 32));
			--_size;
		}
	}

	bool test(size_t num)
	{
		size_t index = num >> 5;
		if ((_bm[index] & (1 << (num % 32))) == 1 << (num % 32))
		{
			return true;
		}
		return false;
	}
protected:
	vector<unsigned int> _bm;
	size_t _size;
};


void test()
{
	//BitMap b(100); //2^32
	//b.set(33);
	//cout << b.test(33) << endl;
	BitMap b(-1); //2^32
	b.set(3999999);
	cout << b.test(3999999) << endl;
	b.Reset(3999999);
	cout << b.test(3999999) << endl;
	cout << b.test(40000) << endl;
}