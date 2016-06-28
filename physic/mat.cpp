#include"mat.h"
#include<math.h>
#include<stdarg.h>
#include<iostream>

namespace Adina {
	mat::mat() {
		dim = 0;
		m = 0;
	}
	mat::mat(int dim)
	{
		this->dim = dim;
		m = new float*[dim];
		for (int i = 0; i < dim; i++) {
			m[i] = new float[dim];
		}
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				m[i][j] = 0;
			}
		}
	}
	mat::~mat() {
		if (dim > 0) {
			for (int i = 0; i < dim; i++) {
				delete m[i];
			}
			delete m;
		}
	}
	void mat::setIdentity()
	{
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if( i == j) m[i][j] = 1;
				else m[i][j] = 0;
			}
		}
	}
	void mat::setM(float** v)
	{
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				this->m[i][j] = v[i][j];
			}
		}
	}
	void mat::setM(int dim, float ** v)
	{
		this->dim = dim;
		m = new float*[dim];
		for (int i = 0; i < dim; i++) {
			m[i] = new float[dim];
		}
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				m[i][j] = v[i][j];
			}
		}
	}
	mat & mat::operator=(const mat & b)
	{
		this->dim = b.dim;
		m = new float*[dim];
		for (int i = 0; i < dim; i++) {
			m[i] = new float[dim];
		}
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				m[i][j] = b.m[i][j];
			}
		}
		return *this;
	}
	mat mat::operator+(const mat & b)const
	{
		mat* rez = new mat(dim);
		if (dim == b.dim) {
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					rez->m[i][j] = m[i][j] + b.m[i][j];
				}
			}
		}
		return *rez;
	}
	mat mat::operator-(const mat & b)const
	{
		mat* rez = new mat(dim);
		if (dim == b.dim) {
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					rez->m[i][j] = m[i][j] - b.m[i][j];
				}
			}
		}
		return *rez;
	}
	mat mat::operator*(const mat & b)const
	{
		float sum = 0;
		mat* rez = new mat(dim);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				for (int k = 0; k < dim; k++) {
					sum = sum + m[i][k] * b.m[k][j];
				}
				rez->m[i][j] = sum;
				sum = 0;
			}
		}

		return *rez;
	}
	bool mat::operator==(const mat & b)const
	{
		if (dim != b.dim) {
			return false;
		}
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if (m[i][j] != b.m[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	mat mat::transpose()const
	{
		mat* rez = new mat(dim);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				rez->m[i][j] = m[j][i];
			}
		}
		return *rez;
	}
	mat mat::minorPrincipal(int idim)const
	{
		if (idim <= 0) { /// only a check for some safty
			idim = 1;
		}
		mat* rez = new mat(idim);
		for (int i = 0; i < idim; i++) {
			for (int j = 0; j < idim; j++) {
				rez->m[i][j] = m[i][j];
			}
		}
		return *rez;
	}
	mat mat::getMat(int jr) const
	{
		mat* rez = new mat(dim - 1);

		for (int i = 0; i < rez->dim; i++) {
			for (int j = 0; j < rez->dim; j++) {
				if (j < jr) {
					rez->m[i][j] = m[i + 1][j];
				}else{
					rez->m[i][j] = m[i + 1][j + 1];
				}
			}
		}
		return *rez;
	}
	mat mat::getMat(int ic,int jc) const
	{
		mat* rez = new mat(dim - 1);

		for (int i = 0; i < rez->dim; i++) {
			for (int j = 0; j < rez->dim; j++) {
				if (i < ic && j < jc) { 
					rez->m[i][j] = m[i][j]; 
				}
				else if (i >= ic && j < jc) { 
					rez->m[i][j] = m[i + 1][j]; 
				}
				else {
					if (i >= ic && j >= jc) {
						rez->m[i][j] = m[i + 1][j + 1];
					}
					else {
						rez->m[i][j] = m[i][j + 1];
					}
				}
			}
		}
		return *rez;
	}
	float mat::det2x(const mat & b)const
	{
		float rez = b.m[0][0] * b.m[1][1] - b.m[0][1] * b.m[1][0];
		return rez;
	}
	float mat::det(const mat & b)const
	{
		float rez = 0;
		if (b.dim == 2) {
			rez += det2x(b);
		}else{
			for (int i = 0; i < b.dim; i++) {
				mat aux = b.getMat(i);
				if ((i + 1) % 2 == 0) {
					rez += +b.m[0][i] * det(aux);
				}
				else {
					rez -= +b.m[0][i] * det(aux);
				}
			}
		}
		return rez;
	}
	mat mat::cofactor()
	{
		mat* rez = new mat(dim);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				mat aux_mat = getMat(i, j);
				float aux_det = det(aux_mat);
				rez->m[i][j] = m[i][j] * pow(-1, i + j) * aux_det;
			}
		}
		return *rez;
	}
	mat mat::inverse()
	{
		return mat();
	}
	std::ostream & operator<<(std::ostream & output, const mat & m)
	{
		for (int i = 0; i < m.dim; i++) {
			output << std::endl;
			for (int j = 0; j < m.dim; j++) {
				output << m.m[i][j] << ", ";
			}
		}
		return output;
	}
}