/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:51:10 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/27 16:52:15 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abs.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	num;
	int	abs;

	num = -5;
	abs = ABS(num);
	printf("ABS: %d\n", abs);
}
