/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:59:20 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/26 19:59:43 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int *ft_range(int min, int max)
{
  int *array_int;
  int len;
  int i;

  if(min>=max)
  {
    return (NULL);
  }

  i = 0;
  len = max - min;
  array_int = malloc(sizeof(int) * len);

  while(min < max)
  {
    array_int[i] = min;
    min++;
    i++;
  }

  return (array_int);
}

int main(void)
{
  int max;
  int min;
  int *res;
  int size;

  max = 10;
  min = 1;

  res = ft_range(min, max);
  size = sizeof(res)/ sizeof(res[0]);
  for(int i = 0; i < size; i++)
  {
    printf("%d, ", res[i]);
    res++;
  }

  free(res);
  return(0);
}