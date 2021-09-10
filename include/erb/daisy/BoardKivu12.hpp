/*****************************************************************************

      BoardKivu12.hpp
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

void  BoardKivu12::impl_preprocess ()
{
   // address was already set 1ms or so, read from gpios

   // GI: BJT => inverted
   _digital_inputs [_b_mux_addr] = !_gpio_inputs [0].read ();
   _digital_inputs [8 + _b_mux_addr] = !_gpio_inputs [1].read ();
}



/*
==============================================================================
Name : impl_preprocess
==============================================================================
*/

void  BoardKivu12::impl_preprocess (GpiPin /* pin */)
{
   // nothing
   // BX are preprocessed in the board level preprocess above
}



/*
==============================================================================
Name : impl_preprocess
==============================================================================
*/

void  BoardKivu12::impl_preprocess (AdcPin pin)
{
   const auto norm_val = to_float_norm (_adc.read (pin.index));

   if ((pin.index >= CI1.index) && (pin.index <= CI8.index))
   {
      // OpAmp in inverter adder with voltage reference
      _analog_inputs [pin.index] = 1.f - norm_val;
   }
   else
   {
      _analog_inputs [pin.index] = norm_val;
   }
}



/*
==============================================================================
Name : impl_preprocess
==============================================================================
*/

void  BoardKivu12::impl_preprocess (AudioInPin pin)
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

void  BoardKivu12::impl_postprocess (GpoPin pin)
{
   _gpio_outputs [pin.index].write (_digital_outputs [pin.index]);
}



/*
==============================================================================
Name : impl_postprocess
==============================================================================
*/

void  BoardKivu12::impl_postprocess (DacPin pin)
{
   if (pin.index <= CO2.index)
   {
      _dac.write (pin.index, norm_to_u12 (_analog_outputs [pin.index]));
   }
   else
   {
      // The PCA9685 is made so that the anode is connected to 3V3,
      // not to the pin. Similarly, cathode is connected to the pin, not
      // GND.
      // For this reason, the logic is inverted, and we need to adapt
      // the gamma too.

      auto val = _analog_outputs [pin.index];
      auto linear = 1.f - val * val * val;
      auto linear_u12 = norm_to_u12 (linear);

      _led_driver.SetLedRaw (
         pin.index - L1.index, linear_u12
      );
   }
}



/*
==============================================================================
Name : impl_postprocess
==============================================================================
*/

void  BoardKivu12::impl_postprocess (AudioOutPin pin)
{
   scale (
      _submodule.raw_audio_outputs [pin.index],
      _audio_outputs [pin.index],
      _submodule.gain_output_scaling
   );
}



/*
==============================================================================
Name : impl_postprocess
==============================================================================
*/

void  BoardKivu12::impl_postprocess ()
{
   _led_driver.SwapBuffersAndTransmit ();

   // set address for next read in next preprocess
   _b_mux_addr = (_b_mux_addr + 1) % 8;
   set_b_mux_addr ();

   // a full cycle has a length of 8, which represent at worst a 8ms latency
   // with the default 48 sample buffer and 48kHz sample rate.
}



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : set_b_mux_addr
==============================================================================
*/

void  BoardKivu12::set_b_mux_addr ()
{
   _gpio_b_mux [0].write ((_b_mux_addr & 1) != 0);
   _gpio_b_mux [1].write ((_b_mux_addr & 2) != 0);
   _gpio_b_mux [2].write ((_b_mux_addr & 4) != 0);
}



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
