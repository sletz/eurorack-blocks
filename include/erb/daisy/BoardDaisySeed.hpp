/*****************************************************************************

      BoardDaisySeed.hpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/AudioIn.h"
#include "erb/AudioOut.h"
#include "erb/Button.h"
#include "erb/CvIn.h"
#include "erb/CvOut.h"
#include "erb/GateIn.h"
#include "erb/GateOut.h"
#include "erb/Led.h"
#include "erb/LedBi.h"
#include "erb/LedRgb.h"
#include "erb/Pot.h"
#include "erb/Switch.h"
#include "erb/detail/fnc.h"

#include <algorithm>



namespace erb
{



/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : impl_preprocess
==============================================================================
*/

void  BoardDaisySeed::impl_preprocess (GpiPin pin)
{
   _digital_inputs [pin.index] = _gpio_inputs [pin.index].read ();
}



/*
==============================================================================
Name : impl_preprocess
==============================================================================
*/

void  BoardDaisySeed::impl_preprocess (AdcPin pin)
{
   _analog_inputs [pin.index] = to_float_norm (_adc.read (pin.index));
}



/*
==============================================================================
Name : impl_preprocess
==============================================================================
*/

void  BoardDaisySeed::impl_preprocess (AudioInPin pin)
{
   scale (
      _audio_inputs [pin.index],
      _submodule.raw_audio_inputs [pin.index],
      _submodule.gain_input_scaling
   );
}



/*
==============================================================================
Name : impl_postprocess
==============================================================================
*/

void  BoardDaisySeed::impl_postprocess (GpoPin pin)
{
   _gpio_outputs [pin.index].write (_digital_outputs [pin.index]);
}



/*
==============================================================================
Name : impl_postprocess
==============================================================================
*/

void  BoardDaisySeed::impl_postprocess (DacPin pin)
{
   _dac.write (pin.index, norm_to_u12 (_analog_outputs [pin.index]));
}



/*
==============================================================================
Name : impl_postprocess
==============================================================================
*/

void  BoardDaisySeed::impl_postprocess (AudioOutPin pin)
{
   scale (
      _submodule.raw_audio_outputs [pin.index],
      _audio_outputs [pin.index],
      _submodule.gain_input_scaling
   );
}



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
