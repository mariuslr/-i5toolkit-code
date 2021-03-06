/*
 * This file is part of i5/OS Programmer's Toolkit.
 * 
 * Copyright (C) 2010, 2011  Junlei Li (李君磊).
 * 
 * i5/OS Programmer's Toolkit is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * i5/OS Programmer's Toolkit is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with i5/OS Programmer's Toolkit.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/**
 * @file unlink.c
 */

# include <unistd.h>

/**
 * @param [in] null-terminated stream file path name.
 * @param [out] optional return value, 0 if successful.
 */
int main(int argc, char *argv[]) {

  int r = 0;

  if(argc < 2)
    return -1;

  r = unlink(argv[1]);
  if(argc >= 3)
    *((int*)argv[2]) = r;

  return 0;
}
