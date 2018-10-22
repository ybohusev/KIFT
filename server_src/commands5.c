/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:41:37 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/22 15:16:10 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*check_browser_history(int fd)
{
	system("osascript ./scripts/check_browser_history.scpt &>/dev/null");
	return ("Mr. MEESEEKS: Here is the history, MY LORD.");
}

char	*check_traffic(int fd)
{
	system("osascript ./scripts/check_traffic.scpt &>/dev/null");
	system("osascript -e \'say \"Here is the road situation, MY KING!\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Here is the road situation, MY KING!");
}

char	*quiet_mode(int fd)
{
	g_mode = QUIET;
	system("osascript -e \'say \"quiet mode is on\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: quiet mode is on");
}

char	*default_mode(int fd)
{
	g_mode = DEFAULT;
	system("osascript -e \'say \"default mode is on\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: default mode is on");
}
