#pragma once

#include<iostream>

namespace Adina {

	struct vec
	{
		float* v;
		int dim = 0;
		vec();
		vec(int dim);
		~vec();
		///
		void set(const float v[]);
		/// operators
		vec &operator+(const vec &b);
		vec &operator-(const vec &b);
		vec &operator*(const float &b);
		bool operator==(const vec &b);
		friend std::ostream &operator<<(std::ostream &output, const vec& m);
	};

}
