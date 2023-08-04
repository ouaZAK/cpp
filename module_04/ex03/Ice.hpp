/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:53:40 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/04 10:32:40 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:
	
	public:
		Ice();
		Ice(std::string const & ice);
		Ice(const Ice &ice);
		Ice &operator = (const Ice &ice);
		~Ice();
		std::string const & getType() const;
		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

#endif