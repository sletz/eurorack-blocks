/*****************************************************************************

      GateOut.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/GateOut.h"

#include "erb/Module.h"

#if defined (__GNUC__)
   #pragma GCC diagnostic push
   #pragma GCC diagnostic ignored "-Wpedantic"
   #pragma GCC diagnostic ignored "-Wignored-qualifiers"
   #pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#include "daisy_seed.h"

#if defined (__GNUC__)
   #pragma GCC diagnostic pop
#endif



namespace erb
{



/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : ctor
==============================================================================
*/

GateOut::GateOut (Module & module, const dsy_gpio_pin & pin)
:  _module (module)
,  _gpio (to_gpio (pin))
{
   _module.add (*this);
}



/*
==============================================================================
Name : on
==============================================================================
*/

void  GateOut::on ()
{
   _mode = Mode::Constant;

   _current = true;
}



/*
==============================================================================
Name : off
==============================================================================
*/

void  GateOut::off ()
{
   _mode = Mode::Constant;

   _current = false;
}



/*
==============================================================================
Name : trigger
==============================================================================
*/

void  GateOut::trigger (std::chrono::milliseconds duration)
{
   _mode = Mode::Pulse;
   _start = _module.now_ms ();
   _duration = uint32_t (duration.count ());

   _current = true;
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : impl_process
==============================================================================
*/

void  GateOut::impl_process ()
{
   if (_mode == Mode::Pulse)
   {
      auto now = _module.now_ms ();
      auto elapsed = now - _start;
      _current = elapsed < _duration;
   }

   dsy_gpio_write (&_gpio, _current);
}



/*
==============================================================================
Name : to_gpio
==============================================================================
*/

dsy_gpio GateOut::to_gpio (const dsy_gpio_pin & pin)
{
   dsy_gpio gpio;
   gpio.pin = pin;
   gpio.mode = DSY_GPIO_MODE_OUTPUT_PP;

   dsy_gpio_init (&gpio);

   return gpio;
}



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/