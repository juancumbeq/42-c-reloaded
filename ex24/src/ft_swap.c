/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:18:23 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/17 12:25:50 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	num;

	num = *b;
	*b = *a;
	*a = num;
}

int	main(void)
{
	int	x;
	int	y;
	int	*ptr_x;
	int	*ptr_y;

	ptr_x = &x;
	ptr_y = &y;
	x = 10;
	y = 5;
	printf("Before SWAP\n");
	printf("%d\n", x);
	printf("%d\n", y);
	ft_swap(ptr_x, ptr_y);
	printf("After SWAP\n");
	printf("%d\n", x);
	printf("%d\n", y);
}
