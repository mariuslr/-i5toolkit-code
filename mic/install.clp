/* This file is part of i5/OS Programmer's Toolkit. */

/* Copyright (C) 2010  Junlei Li (李君磊). */

/* i5/OS Programmer's Toolkit is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* i5/OS Programmer's Toolkit is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with i5/OS Programmer's Toolkit.  If not, see <http://www.gnu.org/licenses/>. */

/* @file INSTALL.CLP */
/* Create IFS symbol links for MIC */
             PGM
MIC:
             RMVLNK     OBJLNK('/usr/bin/mic')
             MONMSG     MSGID(CPF0000)
             ADDLNK     OBJ('/qsys.lib/i5toolkit.lib/runmic.pgm') +
                          NEWLNK('/usr/bin/mic')
QSH:
             /* qsh utilities */
             RMVLNK     OBJLNK('/usr/bin/exobjtype')
             MONMSG     MSGID(CPF0000)
             ADDLNK     OBJ('/qsys.lib/i5toolkit.lib/exobjtype.pgm') +
                          NEWLNK('/usr/bin/exobjtype')

             RMVLNK     OBJLNK('/usr/bin/miobjtype')
             MONMSG     MSGID(CPF0000)
             ADDLNK     OBJ('/qsys.lib/i5toolkit.lib/miobjtype.pgm') +
                          NEWLNK('/usr/bin/miobjtype')

             RMVLNK     OBJLNK('/usr/bin/readlink')
             MONMSG     MSGID(CPF0000)
             ADDLNK     OBJ('/qsys.lib/i5toolkit.lib/rlink.pgm') +
                          NEWLNK('/usr/bin/readlink')

             /* RMFLNK */
             RMVLNK     OBJLNK('/usr/bin/rmflnk')
             MONMSG     MSGID(CPF0000)
             ADDLNK     OBJ('/usr/local/bin/i5toolkit/rmflnk') +
                          NEWLNK('/usr/bin/rmflnk')

             /* QOBJNAME */
             RMVLNK     OBJLNK('/usr/bin/qobjname')
             MONMSG     MSGID(CPF0000)
             ADDLNK     OBJ('/usr/local/bin/i5toolkit/qobjname') +
                          NEWLNK('/usr/bin/qobjname')

             ENDPGM
