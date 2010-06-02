     /**
      * This file is part of i5/OS Programmer's Toolkit.
      * 
      * Copyright (C) 2010  Junlei Li.
      * 
      * i5/OS Programmer's Toolkit is free software: you can redistribute it and/or modify
      * it under the terms of the GNU General Public License as published by
      * the Free Software Foundation, either version 3 of the License, or
      * (at your option) any later version.
      * 
      * i5/OS Programmer's Toolkit is distributed in the hope that it will be useful,
      * but WITHOUT ANY WARRANTY; without even the implied warranty of
      * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      * GNU General Public License for more details.
      * 
      * You should have received a copy of the GNU General Public License
      * along with i5/OS Programmer's Toolkit.  If not, see <http://www.gnu.org/licenses/>.
      */

     /**
      * @file t076.rpgle
      *
      * Test of instruction MATMATR.
      *  - materialize serial number of the machine 
      *
      */
     h dftactgrp(*no)

      /copy mih52
     d srlnbr          ds                  likeds(matmatr_tmpl_0004_t)
     d mat_attr        s              2a

      /free
           srlnbr.bytes_in = 8 + 8;
           mat_attr = x'0004';  // materialize machine serial number
           matmatr(srlnbr : mat_attr);
           dsply 'Machine Serial Number' '' srlnbr;

           *inlr = *on;
      /end-free
