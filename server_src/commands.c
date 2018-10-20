/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:03:56 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:04:03 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*set_alarm(int fd)
{
	system("osascript ./scripts/set_alarm.scpt 2>/dev/null");
	system("osascript -e \'say \"Alarm is ready to set\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Alarm is ready to set");
}

char	*set_timer(int fd)
{
	system("osascript ./scripts/set_timer.scpt &2>/dev/null \
		\'say\"The timer for 20 seconds is set\" using \"Victoria\"\'");
	system("osascript -e \'say \"Timer is ready to set\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Timer is ready to set");
}

char	*lights_on(int fd)
{
	system("osascript ./scripts/lights_on.scpt;");
	system("osascript -e \'say \"Lights is on\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Lights is on");
}

char	*lights_off(int fd)
{
	system("osascript ./scripts/lights_off.scpt");
	system("osascript -e \'say \"Lights is of\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Lights is off");
}

char	*email(int fd)
{
	system("osascript ./scripts/email.scpt");
	system("osascript -e \'say \"Lets send an email\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Lets send an email");
}
