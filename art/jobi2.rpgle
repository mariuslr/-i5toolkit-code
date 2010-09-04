     /**
      * @file jobi2.rpgle
      *
      * Retrieve job ID of the current job via instructions MATPRATR
      * (with option hex 25) and MATPTR.  Time used on a 525 mahcine:
      * 128000 microseconds.
      */
     h dftactgrp(*no)

      /copy mih52
     d pcs_tmpl        ds                  likeds(matpratr_ptr_tmpl_t)
     d matpratr_opt    s              1a   inz(x'25')
     d syp_attr        ds                  likeds(matptr_sysptr_info_t)
     d i               s             10i 0
     d start           s               z
     d end             s               z
     d dur             s             20i 0
     d COUNT           c                   100000

      /free

           start = %timestamp();

           for i = 1 to COUNT;
               // retrieve the PCS pointer of the current MI process
               pcs_tmpl.bytes_in = %size(pcs_tmpl);
               matpratr1(pcs_tmpl : matpratr_opt);

               // retrieve the name of the PCS ptr, aka job ID
               syp_attr.bytes_in = %size(syp_attr);
               matptr(syp_attr : pcs_tmpl.ptr);
                 // syp_attr.obj_name;
           endfor;
           end = %timestamp();

           dur = %diff(end : start : *ms);
           dsply 'microseconds' '' dur;

           *inlr = *on;
      /end-free
