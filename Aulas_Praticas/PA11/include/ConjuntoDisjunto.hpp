#pragma once

#include "set.hpp"

class ConjuntoDisjunto {
	private:
		set *head;
		set *tail;

	public:	
		ConjuntoDisjunto();
		~ConjuntoDisjunto();
		void makeSet(long x);
		void unionSet(long x, long y);
		set* findSet(long x);
};
