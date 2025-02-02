/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 07:55:52 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/27 17:56:18 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(char *av)
{
	line = static_cast<std::string>(av);
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN	&RPN::operator=(const RPN &rpn)
{
	if (this != &rpn)
	{
		v = rpn.v;
		line = rpn.line;
		str = rpn.str;
		d = rpn.d;
	}
	return (*this);
}

RPN::~RPN()
{
}

void	checkError(std::string &line)
{
	if (line.empty())
		throw (std::invalid_argument("Error: empty argument"));
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
	{
		if (std::isdigit(*it) && std::isdigit(*(it + 1)))
			throw (std::invalid_argument("Error: invalid input"));
		if (*it == '-')
			if (*(it + 1) && std::isdigit(*(it + 1)))
				throw (std::invalid_argument("Error: invalid input"));
		if (*it != '+' && *it != '-' && *it != '*' && *it != '/' && *it != ' ')
			if (!std::isdigit(*it))
				throw (std::invalid_argument("Error: invalid input"));
	}
}

double	RPN::whichSign(std::string::iterator &it, std::vector<double>::iterator vit)
{
	--vit;//vit == v.end()
	d = *(--vit);//1 2 end() in v now d is 1
	switch (*it)//*it is char of sign
	{
		case '+':
			return (d + v.back());
		case '-':
			return (d - v.back());
		case '*':
			return (d * v.back());
		case '/':
			return (d / v.back());
		default:
			return (0);
	}
}

void	RPN::readLine()
{
	bool	sign = false;
	int		countSpace = 0;
	for (std::string::iterator it = line.begin(); it != line.end(); ++it)
	{
		while (*it == ' ')
		{
			++countSpace;
			++it;
		}
		if (it == line.end())
			break;
		if (*it == '-' || *it == '+' || *it == '*' || *it == '/')
		{
			
			sign = true;
			if (v.size() < 2)
				throw (std::invalid_argument("Error: bad input"));
			d = whichSign(it, v.end());
			v.pop_back();
			v.pop_back();
			v.push_back(d);
			++countSpace;
			continue;
		}
		str = line.substr(countSpace, line.find(' ', countSpace) - countSpace);
		v.push_back(std::strtod(str.c_str(), NULL));
		++countSpace;
	}
	if (v.size() != 1 || (v.size() == 1 && !sign))
		throw (std::invalid_argument("Error: bad input"));
}

void	RPN::calculate()
{
	try
	{
		checkError(line);
		readLine();
		
		std::cout << v.back() << '\n';
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}