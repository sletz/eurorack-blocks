/*****************************************************************************

      main_daisy.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "../%module.name%.h"

#include "erb/module_init.h"

#include "erb/def.h"

erb_DISABLE_WARNINGS_DAISY
#include "daisy.h"
erb_RESTORE_WARNINGS



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : main
==============================================================================
*/

int main ()
{
   // Enable FZ (flush-to-zero) denormal behavior
   uint32_t fpscr = __get_FPSCR ();
   fpscr |= 0x01000000; // FZ bit
   __set_FPSCR (fpscr);

   // Init system
   daisy::System system;
   daisy::System::Config config;

   config.Boost ();
   system.Init (config);

   // Init SDRAM
   dsy_sdram_handle sdram;

   sdram.state = DSY_SDRAM_STATE_ENABLE;
   sdram.pin_config [DSY_SDRAM_PIN_SDNWE] = {DSY_GPIOH, 5};

   dsy_sdram_init (&sdram);

   // Init QSPI
   daisy::QSPIHandle qspi;

   erb_DISABLE_WARNINGS_DAISY

   using namespace daisy;

   qspi.Init (QSPIHandle::Config {
      .pin_config = {
         .io0 = {DSY_GPIOF, 8},
         .io1 = {DSY_GPIOF, 9},
         .io2 = {DSY_GPIOF, 7},
         .io3 = {DSY_GPIOF, 6},
         .clk = {DSY_GPIOF, 10},
         .ncs = {DSY_GPIOG, 6}
      },
      .device = QSPIHandle::Config::Device::IS25LP064A,
      .mode = QSPIHandle::Config::Mode::MEMORY_MAPPED
   });

   erb_RESTORE_WARNINGS

   //-------------------------------------------------------------------------

   %module.name% module;

   // The Daisy Seed stack, sitting on SRAM is 512K only.
   // When more memory is needed, move the big buffers like
   // delay lines or samples to the SDRAM, which is 64M.
   // Since we have some heap allocations, we keep a bit of margin
   // and complain when we reach 384K of stack space.

   static_assert (sizeof (module) < 384 * 1024 /* 384K */, "");

   // The SDRAM is compararively slow compared to the SRAM,
   // So try to keep all memory that is accessed often in SRAM.

   // Check 'erb::make_sdram_object' to put your buffers in
   // SDRAM.

   erb::module_init (module);

   module.ui.board.run ([&](){
      using BoardType = decltype (module.ui.board);

      module.ui.board.impl_preprocess ();

%     board_preprocess%
%     controls_preprocess%
      module.process ();

%     controls_postprocess%
%     board_postprocess%
      module.ui.board.impl_postprocess ();
   });
}
