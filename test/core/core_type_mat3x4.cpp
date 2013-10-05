///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2008-08-31
// Updated : 2008-08-31
// Licence : This source is under MIT License
// File    : test/core/type_mat3x4.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/core/type_mat3x4.hpp>

static bool test_operators()
{
	glm::mat3x4 l(1.0f);
	glm::mat3x4 m(1.0f);
	glm::vec3 u(1.0f);
	glm::vec4 v(1.0f);
	float x = 1.0f;
	glm::vec4 a = m * u;
	glm::vec3 b = v * m;
	glm::mat3x4 n = x / m;
	glm::mat3x4 o = m / x;
	glm::mat3x4 p = x * m;
	glm::mat3x4 q = m * x;
	bool R = m != q;
	bool S = m == l;

	return (S && !R) ? 0 : 1;
}

int test_ctr()
{
	int Error(0);
	
#if(GLM_HAS_INITIALIZER_LISTS)
	glm::mat3x4 m0(
		glm::vec3(0, 1, 2),
		glm::vec3(3, 4, 5),
		glm::vec3(6, 7, 8),
		glm::vec3(9, 10, 11));
	
	glm::mat3x4 m1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	
	glm::mat3x4 m2{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8}};
	
	for(int i = 0; i < m0.length(); ++i)
		Error += glm::all(glm::equal(m0[i], m2[i])) ? 0 : 1;
	
	for(int i = 0; i < m1.length(); ++i)
		Error += glm::all(glm::equal(m1[i], m2[i])) ? 0 : 1;
	
	std::vector<glm::mat3x4> v1{
		{0, 1, 2, 3, 4, 5, 6, 7, 8},
		{0, 1, 2, 3, 4, 5, 6, 7, 8}
	};
	
	std::vector<glm::mat3x4> v2{
		{
			{ 0, 1, 2},
			{ 4, 5, 6}
		},
		{
			{ 0, 1, 2},
			{ 4, 5, 6}
		}
	};
	
#endif//GLM_HAS_INITIALIZER_LISTS
	
	return Error;
}

int main()
{
	int Error = 0;
	
	Error += test_ctr();
	Error += test_operators();

	return Error;
}

