/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:56 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 22:18:20 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort(t_stacks **stacks)
{
	const int	len = (*stacks)->a->size;

	if(is_sorted((*stacks)->a))
		return ;

	if (len <= 5)
		sort_tiny(stacks);
	else
		sort_large(stacks);
}
