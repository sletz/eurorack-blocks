/*****************************************************************************

      DaisyButton.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/daisy/DaisyButton.h"

#include "erb/daisy/DaisyModule.h"

#include "per/gpio.h"



namespace erb
{



/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : ctor
==============================================================================
*/

DaisyButton::DaisyButton (DaisyModule & module, const Pin & pin)
:  _gpio (to_gpio (pin))
{
   module.add (*this);
}



/*
==============================================================================
Name : pressed
==============================================================================
*/

bool  DaisyButton::pressed () const
{
   return _state == 0x80;
}



/*
==============================================================================
Name : held
==============================================================================
*/

bool  DaisyButton::held () const
{
   return _state == 0x00;
}



/*
==============================================================================
Name : released
==============================================================================
*/

bool  DaisyButton::released () const
{
   return _state == 0x7f;
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : impl_notify_audio_buffer_start
==============================================================================
*/

void  DaisyButton::impl_notify_audio_buffer_start ()
{
   _state = uint8_t (_state << 1) | dsy_gpio_read (&_gpio);
}



/*
==============================================================================
Name : to_gpio
==============================================================================
*/

dsy_gpio DaisyButton::to_gpio (const Pin & pin)
{
   dsy_gpio gpio;
   gpio.pin = pin;
   gpio.mode = DSY_GPIO_MODE_INPUT;
   gpio.pull = DSY_GPIO_PULLUP;

   dsy_gpio_init (&gpio);

   return gpio;
}



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/