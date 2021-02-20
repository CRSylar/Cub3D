/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:57:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 16:52:57 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*out;

	if (!(out = (t_list*)malloc(sizeof(t_list))))
		return (0);
	out->content = content;
	out->next = 0;
	return (out);
}
