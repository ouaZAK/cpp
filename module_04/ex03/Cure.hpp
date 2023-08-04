/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:57:02 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/04 18:21:27 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	protected:
		std::string cure;
	public:
		Cure();
		Cure(std::string const & cure);
		Cure(const Cure &cure);
		Cure &operator = (const Cure &cure);
		~Cure();
		std::string const & getType() const;
		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif