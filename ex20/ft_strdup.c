/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:32:01 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/25 20:33:27 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
  char *copy;
  int i;

  i = 0;
  while(*src != '\0')
  {
    i++;
  }

  copy = malloc(i * sizeof(char));

  if(copy == NULL)
  {
    fprintf(stderr, "Failed to duplicate string\n");
  }
  return(copy);
}

int main(void)
{
  char *src;
  char *copy;

  src = "Hello world!";
  copy = ft_strdup(src);

  printf("Original: %s\n", src);
  printf("Copy: %s\n", copy);

  free(copy);

  return (0);
}