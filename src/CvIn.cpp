/*****************************************************************************

      CvIn.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/CvIn.h"

#include "erb/def.h"



namespace erb
{



/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : set_mode
==============================================================================
*/

void  CvIn::set_mode (Mode mode)
{
   _mode = mode;
}



/*
==============================================================================
Name : operator float
==============================================================================
*/

CvIn::operator float () const
{
   switch (_mode)
   {
   case Mode::Normalized:
#if erb_GNUC_SWITCH_COVERAGE_FIX
   default:
#endif
      return *_norm_val_ptr;

   case Mode::Bipolar:
      return *_norm_val_ptr * 2.f - 1.f;
   }
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : impl_bind_data
==============================================================================
*/

void  CvIn::impl_bind_data (const float & norm_val)
{
   _norm_val_ptr = &norm_val;
}



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
