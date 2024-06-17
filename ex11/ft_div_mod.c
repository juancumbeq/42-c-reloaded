/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:40:08 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/17 12:41:55 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
  *mod = a % b;
}

int main(void)
{
	int x = 10;
  int y = 3;
  int div;
  int mod;

  int *ptr_div = &div;
  int *ptr_mod = &mod;

  ft_div_mod(x, y, ptr_div, ptr_mod);

  printf("%d\n", x);
  printf("%d\n", y);
  printf("%d\n", div);
  printf("%d\n", mod);

}
