// Name:  DciProperty.h
//
// Copyright 2013 Loctronix Corporation
// http://www.loctronix.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DCIPROPERTY_H_
#define DCIPROPERTY_H_


#include "Dci/DciMsg.h"
#include "Dci/DciConversation.h"
#include "Dci/InfrastructureMsgs.h"
#include "Dci/WcaMsgs.h"
#include "Dci/StandardMsgs.h"

#include "a2300_iface.hpp"

/**
 * Helper class takes the pain out of setting and getting component properties.
 */
class DciProperty
{
public:
	DciProperty(byte idComponent, A2300_iface::sptr piface, double timeout)
	:	 m_idComponent( idComponent), m_piface(piface ), m_timeout( timeout)
	{
	}
	~DciProperty() {}

	template< typename T> int GetProperty( int idProp, T& value)
	{
		throw std::runtime_error("DCI Property type not supported");
	}

	template< typename T> int SetProperty( int idProp, T value)
	{
		throw std::runtime_error("DCI Property type not supported");
	}

	int GetProperty( Dci_Property& prop, double timeout);
	int SetProperty( Dci_Property& prop, double timeout);

private:
	byte			  m_idComponent;
	A2300_iface::sptr m_piface;
	double			  m_timeout;
};


template <> int DciProperty::GetProperty( int idProp, byte& value);

template <> int DciProperty::GetProperty( int idProp, uint16& value);

template <> int DciProperty::GetProperty( int idProp, int16& value);

template <> int DciProperty::GetProperty( int idProp, uint32& value);

template <> int DciProperty::GetProperty( int idProp, int32& value);

template <> int DciProperty::GetProperty( int idProp, float& value);

template <> int DciProperty::GetProperty( int idProp, double& value);

/*
template <> int DciProperty::GetProperty( int idProp, uint64& value);

template <> int DciProperty::GetProperty( int idProp, int64& value);
*/



template <> int DciProperty::SetProperty( int idProp, byte value);

template <> int DciProperty::SetProperty( int idProp, uint16 value);

template <> int DciProperty::SetProperty( int idProp, int16 value);

template <> int DciProperty::SetProperty( int idProp, uint32 value);

template <> int DciProperty::SetProperty( int idProp, int32 value);

template <> int DciProperty::SetProperty( int idProp, float value);

template <> int DciProperty::SetProperty( int idProp, double value);

/*
template <> int DciProperty::SetProperty( int idProp, uint64 value);

template <> int DciProperty::SetProperty( int idProp, int64 value);
*/


#endif /* DCIPROPERTY_H_ */
