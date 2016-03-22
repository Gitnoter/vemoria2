/// \file
/// \brief	Vemoria audio metadata implementation.
/// There is nothing special in here except the (empty) virtual destructor.
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#include "audio.h"

/// The destructor is virtual, so it can't be inlined, and we place
/// it in the *.cpp even it's empty and could easily been placed in *.h.
Audio::~Audio()
{
}
