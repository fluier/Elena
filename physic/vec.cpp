#include "vec.h"

#include<stdarg.h>


namespace Adina {
	vec::vec():dim(0)
	{
		v = 0;
	}

	vec::vec(int dim):dim(dim)
	{
		v = new float[dim];
		for (int i = 0; i < dim; i++) {
			v[i] = 0;
		}
	}

	vec::~vec()
	{
		if (dim > 0) {
			delete[] v;
			dim = 0;
		}
	}
	void vec::set(const float v[])
	{
		for (int i = 0; i < dim; i++) {
			this->v[i] = v[i];
		}
	}
	vec &vec::operator+(const vec & b)
	{
		vec* rez = new vec(dim);
		for (int i = 0; i < dim; i++) {
			rez->v[i] = v[i] + b.v[i];
		}
		return *rez;
	}
	vec &vec::operator-(const vec & b)
	{
		vec* rez = new vec(dim);
		for (int i = 0; i < dim; i++) {
			rez->v[i] = v[i] - b.v[i];
		}
		return *rez;
	}
	vec &vec::operator*(const float & b)
	{
		vec* rez = new vec(dim);
		for (int i = 0; i < dim; i++) {
			rez->v[i] = this->v[i] * b;
		}
		return *rez;
	}
	bool vec::operator==(const vec & b)
	{
		for (int i = 0; i < dim; i++) {
			if (v[i] != b.v[i]) {
				return false;
			}
		}
		return true;
	}
	std::ostream & operator<<(std::ostream & output, const vec & m)
	{
		for (int i = 0; i < m.dim; i++) {
			output << m.v[i]<< "  ";
		}
		return output;
	}
}
