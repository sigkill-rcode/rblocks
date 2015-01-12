/*
	common.c - utility functions for rblocks.
	Copyright (C) 2015 Adam Richardson

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define _COMMON_C_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>

#include "common.h"

void die(const char *msg)
{
	prftime(stderr);
	fputs("Fatal error: ", stderr);
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void sdl_errdie(const char *msg)
{
	const char *foo;

	foo = SDL_GetError();
	if(foo && *foo)
		die(msg);
}

void prtime(void)
{
	prftime(stdout);
}

void prftime(FILE *f)
{
	time_t now;
	char buffer[10 + 1 + 1]; /* "[xx:xx:xx] " */

	now = time(NULL);

	strftime(buffer, 12, "[%T] ", localtime(&now));
	fputs(buffer, f);
}
