/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:40:41 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/22 15:17:48 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*events(int fd)
{
	system("osascript ./scripts/events.scpt &>/dev/null");
	system("osascript -e \'say \"I\'ll check your events\"\
									using \"Victoria\"\'");
	return ("Mr. MEESEEKS: I'll check your events");
}

char	*weather(int fd)
{
	system("osascript ./scripts/weather.scpt");
	system("osascript -e \'say \"I\'ll check weather in your region\" \
								using \"Victoria\"\'");
	return ("Mr. MEESEEKS: I'll check weather in your region");
}

char	*who_connected(int fd)
{
	system("osascript -e \'say \"ybohusev is connected\" \
				using \"Victoria\"\'");
	return ("Mr. MEESEEKS: ybohusev is connected");
}

char	*where_connected(int fd)
{
	system("osascript ./scripts/where_connected.scpt &>/dev/null\
				-e \'say \"Lets see where we connected\" \
				using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Lets see where we connected");
}
