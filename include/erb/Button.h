/*****************************************************************************

      Button.h
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/detail/Debounce.h"



namespace erb
{



class Button
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Button (const std::uint8_t & data);
   virtual        ~Button () = default;

   inline bool    idle () const;
   inline bool    pressed () const;
   inline bool    held () const;
   inline bool    released () const;



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   void           impl_notify_audio_buffer_start ();



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

protected:



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:

   const std::uint8_t * const
                  _val_ptr;
   Debounce       _debounce;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Button () = delete;
                  Button (const Button & rhs) = delete;
                  Button (Button && rhs) = delete;
   Button &       operator = (const Button & rhs) = delete;
   Button &       operator = (Button && rhs) = delete;
   bool           operator == (const Button & rhs) const = delete;
   bool           operator != (const Button & rhs) const = delete;



}; // class Button



}  // namespace erb



#include "erb/Button.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
