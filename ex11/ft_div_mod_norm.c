/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:31 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/19 15:28:42 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	x;
	int	y;
	int	div;
	int	mod;
	int	*ptr_div;
	int	*ptr_mod;

	x = 10;
	y = 3;
	ptr_div = &div;
	ptr_mod = &mod;
	ft_div_mod(x, y, ptr_div, ptr_mod);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", div);
	printf("%d\n", mod);
}*/
