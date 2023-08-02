/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:15:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 18:02:12 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl a;

	a.complain("INFO");
	a.complain("DEBUG");
	a.complain("WARNING");
	a.complain("ERROR");
	return (0);
}