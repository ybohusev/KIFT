/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:41:28 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:41:33 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*logs(int fd)
{
	system("osascript -e \'say \"Okey lets see logs\" \
			using \"Victoria\"\'");
	system("open logs");
	return ("Mr. MEESEEKS: Okey lets see logs");
}

char	*mees(int fd)
{
	system("osascript -e \'say \"I'm Mr. Meeseeks! Look at me!\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: I'm Mr. Meeseeks! Look at me!");
}

char	*open_browser(int fd)
{
	system("osascript ./scripts/open_browser.scpt");
	return ("Mr. MEESEEKS: Okey I'll open the browser");
}

char	*nothing(int fd)
{
	system("osascript -e \'say \"Ohhh sorry I dont know how to do it\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Ohhh sorry I dont know how to do it");
}

char	*remove_trash(int fd)
{
	system("osascript ./scripts/remove_trash.scpt 2>/dev/null");
	return ("Mr. MEESEEKS: No more trash, boss.");
}
