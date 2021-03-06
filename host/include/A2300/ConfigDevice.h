// Name:  ConfigDevice.h
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

#ifndef CONFIGDEVICE_H_
#define CONFIGDEVICE_H_

#include <A2300/UsbDevice.h>
#include <A2300/BulkDataPort.h>
#include <A2300/TransportDci.h>
#include <A2300/A2300InterfaceDefs.h>
#include <A2300/A2300_Defs.h>
#include <A2300/ConfigRf.h>


namespace A2300 {



typedef std::list<IConfigComponent*> ConfigComponentList;

/**
 * Class implements configuration accessors for the ASR-2300 Device.  This is
 * the root object for working with the ASR 2300 configuration.
 */
class ConfigDevice {
public:
	static const int FindFirstDevice = -1;

public:
	ConfigDevice()
		: m_bCreated(false), m_pDevice( NULL),
		  m_dci0(A2300_DciIdc0_EpIn, A2300_DciIdc0_EpOut),
		  m_timeoutDefault(A2300_WAIT_TIME ),
		  m_rf0( WCACOMP_RF0, "RF0"),
		  m_rf1( WCACOMP_RF1, "RF1")
	{}
	virtual ~ConfigDevice();

	/**
	 * Returns a reference to the attached ASR-2300 UsbDevice object.
	 */
	UsbDevice&  Device() { return *m_pDevice;}

	ConfigRf&   RF0()	 { return m_rf0;}
	ConfigRf&   RF1()	 { return m_rf1;}


	/**
	 * Property gets the DCI Conversation ID 0 transport.  Use to communicate
	 * with the ASR-2300 device controller.
	 */
	TransportDci& Dci0Transport() { return m_dci0.transport;}

	std::string IdentifyDevice();
	std::string FirmwareVersion( int idWhich);
	uint16 FpgaId();
	uint16 FpgaVersion();


	/**
	 * Attach ASR-2300 device by finding the device specified by address, if not defined,
	 * the first device found is selected.  Override to use specialized VID, PID values.
	 */
	int Attach( int addr = FindFirstDevice, int vid = A2300_VENDOR_ID, int pid = A2300_PRODUCT_ID);

	/**
	 * Attach to existing ASR-2300 device.   Device assumed to be initialized and started
	 * prior to attach.
	 */
	void Attach( UsbDevice* pdevice);

	/**
	 * Detachs configuration object from ASR-2300 does appropriate cleanup.  If profived
	 * external UsbDevice object, stop and termination operations are left for the calling software.
	 */
	void Detach();

	/**
	 * Initializes device to the current configuration state.
	 */
	void Synchronize();

	/**
	 * Resets the device to its default state.
	 */
	void Reset();


	ConfigComponentList& Components() { return m_listComponents;}

protected:
	struct DciCtrl
	{
		BulkDataPort	 port;
		Dci_Conversation conversation;
		TransportDci  	 transport;

		DciCtrl( byte epidIn, byte epidOut)
		: port( epidIn, epidOut) {}

		void Init( UsbDevice& device, int idc, double timeout);
		void Term();
	};
private:
	bool 				m_bCreated;
	UsbDevice*			m_pDevice;
	DciCtrl	 			m_dci0;
	double				m_timeoutDefault;

	ConfigRf			m_rf0;
	ConfigRf			m_rf1;
	ConfigComponentList m_listComponents;
};

} /* namespace A2300 */
#endif /* CONFIGDEVICE_H_ */
