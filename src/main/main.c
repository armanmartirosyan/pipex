/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:13 by armartir          #+#    #+#             */
/*   Updated: 2023/03/14 18:19:10 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


// void    validation(int *ac, char ***av)
// {
// 	if (!(ft_strncmp("here_doc", av[1], ft_strlen(av[1]))))
		
// }

int main(int argc, char **argv, char **envp)
{
	(void)envp;
	(void)argc;
	// if (argc < 5)
	// 	return (1);
	// validation(&argc, &argv);
    printf ("stea:   %d \n",access(argv[1], F_OK));
	
	return 0;
}
