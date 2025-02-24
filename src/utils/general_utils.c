/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:13:51 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/25 18:55:55 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief converts an integer in a string to integer.
 * @note characters to skip 
 * 			1. ' ', '\t', '\n', '\v', '\f', '\r (9-13)
 * 			2. '-' and '+'
 **/
int	ft_atoi(const char *str)
{
	int		is_minus;
	long	result;

	is_minus = 1;
	result = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * is_minus > INT_MAX || result * is_minus < INT_MIN)
			error_exit();
		str++;
	}
	if (*str != '\0')
		error_exit();
	return (is_minus * result);
}

void	same_number_checker(t_stack *stack)
{
	t_node	*base_node;
	t_node	*compare_node;

	base_node = stack->top_node;
	while (base_node)
	{
		compare_node = base_node->next_node;
		while (compare_node)
		{
			if (base_node->stored_number == compare_node->stored_number)
				error_exit();
			compare_node = compare_node->next_node;
		}
		base_node = base_node->next_node;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current_node;

	current_node = stack->top_node;
	while (current_node && current_node->next_node)
	{
		if (current_node->stored_number > \
			current_node->next_node->stored_number)
			return (0);
		current_node = current_node->next_node;
	}
	return (1);
}
