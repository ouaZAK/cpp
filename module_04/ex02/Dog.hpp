/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:43:38 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/03 19:39:49 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *b;
	public:
		Dog();
		Dog(const Dog &dog);
		Dog &operator=(const Dog &dog);
		~Dog();
		virtual void	makeSound(void) const;
		std::string getType(void) const;
};

#endif