#include "Relacao.hpp"

Relacao::Relacao(long x){
	this->p = x / 2;
}

Relacao::~Relacao(){}	

bool Relacao::temRelacao(long x, long y){
	return (x>=0) && (y >=0) && ((x % this->p) == (y % this->p));
}
