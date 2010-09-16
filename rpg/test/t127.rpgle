     /**
      * @file t127.rpgle
      *
      * Test of MATRMD -- MPL information
      */

     h dftactgrp(*no)

      /copy mih52

     d mpl             ds                  likeds(matrmd_tmpl0a_t)
     d                                     based(buf_ptr)
     d buf_ptr         s               *
     d opt             ds                  likeds(matrmd_option_t)
     d mpl_cls         ds                  likeds(mpl_class_info_t)
     d                                     based(pos)
     d pos             s               *
     d len             s             10u 0
     d i               s             10i 0
     d msg             s             30a

      /free
           opt = *allx'00';

           buf_ptr = modasa(%size(mpl));
           mpl.bytes_in = %size(mpl);
           opt.val = x'0A';
           matrmd(mpl : opt);
             // MPL.MACHINE_MAXIMUM_NUMBER_OF_MPL_CLASSES = 64
             // MPL.MACHINE_CURRENT_NUMBER_OF_MPL_CLASSES = 64
             // MPL.MPL_MAX = 32767                           
             // MPL.INELIGIBLE_EVENT_THRESHOLD = 32767        
             // MPL.MPL_CURRENT = 14                          
             // MPL.NUMBER_OF_THREADS_IN_INELIGIBLE_STATE = 0 

           len = mpl.bytes_out;
           buf_ptr = modasa(len);
           mpl.bytes_in = len;
           matrmd(mpl : opt);

           pos = buf_ptr + %size(mpl);
           for i = 1 to mpl.machine_current_number_of_mpl_classes;
               if mpl_cls.mpl_max > 0;
                   // check mpl_class
                   msg = %char(mpl_cls.current_mpl)
                         + '/'
                         + %char(mpl_cls.number_of_threads_assigned_to_class);
                   dsply 'MPL/Threads in MPL' '' msg;
               endif;

               pos += %size(mpl_class_info_t);
           endfor;

           *inlr = *on;
      /end-free