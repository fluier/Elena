#pragma once

#include<iostream>

namespace Adina {
	struct mat {
		int dim;
		float **m;

		mat();
		mat(int dim);
		~mat();
		void setIdentity();
		void setM(float** v);
		void setM(int dim, float** v);
		/// operators
		mat &operator=(const mat &b);
		mat operator+(const mat &b)const;
		mat operator-(const mat &b)const;
		mat operator*(const mat &b)const;
		bool operator==(const mat&b)const;
		/// functions on matrix
		mat transpose()const;
		mat minorPrincipal(int dim)const;
		mat getMat(int ic) const;
		mat getMat(int ic,int jl) const;
		float det2x(const mat& b)const;
		float det(const mat& b)const;
		mat cofactor();
		mat inverse();
		friend std::ostream &operator<<(std::ostream &output, const mat& m);
	};
}