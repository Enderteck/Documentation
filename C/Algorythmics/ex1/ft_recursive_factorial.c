/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouffre <ajouffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:55:59 by ajouffre          #+#    #+#             */
/*   Updated: 2026/07/05 17:39:45 by ajouffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long	number;

	number = nb;
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
	}
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number %= 10;
	}
	ft_putchar(number + 48);
}

int ft_recursive_factorial(int nb)
{
	static int	i = 0;
	int	a;

	i++;
	a = i;
    if (nb < 0)
	{
		return (0);
	}
	if (i <= nb)
	{
        return (a * ft_recursive_factorial(nb));
    }
	return (1);
}

int	main(void)
{
	ft_putnbr(ft_recursive_factorial(4));
	return (0);
}
