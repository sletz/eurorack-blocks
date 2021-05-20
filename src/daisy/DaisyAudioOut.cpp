/*****************************************************************************

      DaisyAudioOut.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/daisy/DaisyAudioOut.h"

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

DaisyAudioOut::DaisyAudioOut (DaisyModule & module, AudioOutPin pin)
:  _module (module)
,  _channel (pin.pin)
{
   module.add (*this);
}



/*
==============================================================================
Name : operator =
==============================================================================
*/

DaisyAudioOut &   DaisyAudioOut::operator = (const Buffer & buffer)
{
   _buffer = buffer;

   return *this;
}



/*
==============================================================================
Name : size
==============================================================================
*/

size_t   DaisyAudioOut::size () const
{
   return _buffer.size ();
}



/*
==============================================================================
Name : operator []
==============================================================================
*/

float &  DaisyAudioOut::operator [] (size_t index)
{
   return _buffer [index];
}



/*
==============================================================================
Name : fill
==============================================================================
*/

void  DaisyAudioOut::fill (float val)
{
   _buffer.fill (val);
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : impl_notify_audio_buffer_start
==============================================================================
*/

void  DaisyAudioOut::impl_notify_audio_buffer_start ()
{
   // nothing
}



/*
==============================================================================
Name : impl_notify_audio_buffer_end
==============================================================================
*/

void  DaisyAudioOut::impl_notify_audio_buffer_end ()
{
   auto & buffer = _module.impl_onboard_codec_buffer_output ();

   buffer [_channel] = _buffer;
}



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/