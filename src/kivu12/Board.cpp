/*****************************************************************************

      Board.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/kivu12/Board.h"



namespace erb
{
namespace kivu12
{



/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : ctor
==============================================================================
*/

Board::Board ()
{
   init_adc_channels ();
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : do_notify_audio_buffer_start
==============================================================================
*/

void  Board::do_notify_audio_buffer_start ()
{
}



/*
==============================================================================
Name : do_notify_audio_buffer_end
==============================================================================
*/

void  Board::do_notify_audio_buffer_end ()
{
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : init_adc_channels
==============================================================================
*/

void  Board::init_adc_channels ()
{
   // 8 CVs, 2 Multiplexers = 10 ADC channels
   std::array <AdcChannelConfig, 10> configs;
}



}  // namespace kivu12
}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
