/**
 * This file is part of i5/OS Programmer's Toolkit.
 * 
 * Copyright (C) 2010, 2011  Junlei Li (李君磊).
 * 
 * i5/OS Programmer's Toolkit is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * i5/OS Programmer's Toolkit is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with i5/OS Programmer's Toolkit.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/**
 * @file inst-tmpl.h
 *
 * Declarations of instruction templates used by MIPORTAL are placed in this file.
 */

# ifndef __miportal_inst_tmpl_h__
# define __miportal_inst_tmpl_h__

/**
 * Creation template of CRTS. (96 bytes)
 */
typedef _Packed struct tag_crts {
  int bytes_in;
  int bytes_out;
  // object ID
  char obj_type[2];
  char obj_name[30];
  // creation options
  char crt_opt[4];
  // recovery options
  char filler1[2];
  unsigned short asp_num;
  // space-size, initial value
  int spc_size;
  char init_val[1];
  // performance class
  char perf_cls[4];
  char filler2[1];
  // public auth
  char pub_auth[2];
  // template extension offset
  int ext_tmpl_off;
  // context
  void *ctx;
  // acess group
  void *ag;
} crts_t;

/**
 * Template extension of CRTS. (64 bytes)
 */
typedef _Packed struct tag_crts_ext {
  void *owner;  // SYP to the created space object's owner USRPRF
  int largest_size_needed;
  char domain[2];
  char filler[42];
} crts_ext_t;

/**
 * Creation template of CRTINX (176 bytes)
 */
typedef _Packed struct tag_crtinx {
  int bytes_in;
  int bytes_out;
  // object ID
  char obj_type[2];
  char obj_name[30];
  char crt_opt[4];         // creation options
  // recovery options
  char filler1[2];
  unsigned short asp_num;
  int spc_size;            // space-size, initial value
  char init_val[1];        // initial value of space
  char perf_cls[4];        // performance class
  char filler2[3];
  int ext_tmpl_off;        // template extension offset
  void *ctx;               // context
  void *ag;                // acess group
  char attr[1];            // index attributes
  unsigned short arg_len;  // argument length
  unsigned short key_len;  // key length
  // the following are fields belong to the longer creation template
  char filler3[12];
  char tmpl_ver[1]; // template version, must be hex 00
  char inx_fmt[1];  // index format. hex 00=max object size of 4GB, hex 01=max object size of 1TB
  char filler4[61];
} crtinx_t;

/**
 * Option list of index managment instructions
 */
typedef _Packed struct tag_inx_oplist {
  char rule[2];
  unsigned short arg_len;  // argument length
  short arg_off;           // argument offset
  short occ_cnt;           // occurance count
  short rtn_cnt;           // returned count
  /* entries */
  unsigned short ent_len;
  short ent_off;
} inx_oplist_t;

/**
 * Instruction template for GENUUID
 */
typedef _Packed struct tag_genuuid {
  unsigned bytes_in;
  unsigned bytes_out;
  char filler1[8];
  char uuid[16];
} genuuid_t;

// MATPTR
/**
 * Materialization template for space pointers (88 bytes).
 */
typedef _Packed struct tag_matptr_spp {
  unsigned bytes_in;
  unsigned bytes_out;
  char type[1];
  char ctx_type[2];
  char ctx_name[30];
  char obj_type[2];
  char obj_name[30];
  int offset;  // offset into space
  char info[2]; // pointer info
                //  bit 0. Pointer target accessible from user state
                //  bit 1. Pointer target is teraspace
  char filler[1];
  char ext_off[8]; // extended offset into space
} matptr_spp_t;

# pragma linkage (_SETSPPFP, builtin)
void* _SETSPPFP(void* /* source pointer */);

# pragma linkage (_CPYBWP, builtin)
void _CPYBWP(void*, void*, int);

# pragma linkage (_CRTS, builtin)
void _CRTS(void*, void*);

# pragma linkage (_ENQ, builtin)
void _ENQ(void**,  // address of SYP to target queue object
          void*,   // message prefix
          void*);  // message text

# pragma linkage (_DEQWAIT, builtin)
void _DEQWAIT(void *prefix, void *msg, void **q);

# pragma linkage(_CMPPTRT, builtin)
int _CMPPTRT(char /* pointer type */, void * /* pointer */);

# pragma linkage(_SETSPFP, builtin)
void *_SETSPFP(void * /* source pointer */);

# pragma linkage(_CALLPGMV, builtin)
void _CALLPGMV(void **, // addr of syp
               void **, // arg-ptr-arry[]
               unsigned // number of arguments
               );

# pragma linkage(_DESS, builtin)
void _DESS(void**);

# pragma linkage(_MATS, builtin)
void _MATS(void*, void**);

# pragma linkage(_MODS1, builtin)
void _MODS1(void**, void*);

# pragma linkage(_MODS2, builtin)
void _MODS2(void**, void*);

# pragma linkage(_MATPTR, builtin)
void _MATPTR(void *, /* materialization template */
             void ** /* address of pointer */
             );

# define _CRTS_TMPL_LEN 160

# pragma linkage(_CPYBWP, builtin)
void _CPYBWP(void *, // target address
             void *, // source address
             int     // bytes to copy
             );

# pragma linkage(_ALCHSS, builtin)
void *_ALCHSS (int,  // Heap ID
               int   // Number of bytes to allocate
               );

# pragma linkage (_CRTHS, builtin)
void _CRTHS (void *, // address of returned heap ID
             void *  // heap creation template
             );

# pragma linkage (_DESHS, builtin)
void _DESHS (void *); // address of returned heap ID

# pragma linkage (_FREHSS, builtin)
void _FREHSS (void *); // space pointer

# pragma linkage(_REALCHSS, builtin)
void *_REALCHSS (void*, // input space pointer
                 int    // Number of bytes to allocate
                 );

# pragma linkage (_SETHSSMK, builtin)
void _SETHSSMK (void **,  // address of mark ID pointer
                int *     // address of heap ID
                );

# pragma linkage (_FREHSSMK, builtin)
void _FREHSSMK (void **);  // address of mark ID pointer

# pragma linkage (_MATHSAT, builtin)
void _MATHSAT (void *,  // materialization template
               void *,  // heap ID
               void *   // attribute selection option
               );

// for QusMaterializeContext()
# include <qusmiapi.h>

# pragma linkage (_QTEMPPTR, builtin)
void *_QTEMPPTR (void);

// Pointer-based mutex management instructions
# pragma linkage (_CRTMTX, builtin)
int _CRTMTX (void *,  // mutex
             void *   // creation options
             );
# pragma linkage (_DESMTX, builtin)
int _DESMTX (void *,  // mutex
             void *   // destroy options
             );
# pragma linkage (_LOCKMTX, builtin)
int _LOCKMTX (void *, // mutex
              void *  // lock request template
              );
# pragma linkage (_UNLKMTX, builtin)
int _UNLKMTX (void *  // mutex
              );

# pragma linkage(_CRTINX, builtin)
void _CRTINX(void** /* address of SYP to inx */,
             void* /* creation template */);

# define _CRTINX_TMPL_LEN 176  // length of the longer tmpl

# pragma linkage(_DESINX, builtin)
void _DESINX(void**); /* address of SYP to inx */

# pragma linkage(_INSINXEN, builtin)
void _INSINXEN(void**, // address of SYP to target index object
               void*,  // arguemnt
               void*   // option list
               );

# pragma linkage(_FNDINXEN, builtin)
void _FNDINXEN(void *,  // returned index entry
               void **, // address of SYP to target index object
               void *,  // option list
               void *   // search key
               );

# pragma linkage(_RMVINXEN1, builtin)
void _RMVINXEN1(void *,  // returned index entry
                void **, // address of SYP to target index object
                void *,  // option list
                void *   // search key
                );

# endif // !defined __miportal_inst_tmpl_h__
