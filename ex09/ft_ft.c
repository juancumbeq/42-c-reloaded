/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:46:34 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/16 18:10:16 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Create a function that takes a pointer to int as a parameter, and sets the value "42" to that int.
 */

#include <stdio.h>
#include <unistd.h>

void ft_ft(int *nbr)
{
	*nbr = 42;
	printf("%d\n", *nbr);
}

int main(void)
{
	int value;
	int *pointer = &value;

	ft_ft(pointer);
	return(0);
}
