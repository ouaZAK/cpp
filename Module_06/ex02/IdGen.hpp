/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdGen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:53:51 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/20 09:59:19 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime> 

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);
