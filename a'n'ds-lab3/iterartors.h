#pragma once
#ifndef iterators_H

class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
	virtual ~Iterator() {};
};
#endif // !iterators_H