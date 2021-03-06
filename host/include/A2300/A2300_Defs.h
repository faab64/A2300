/************************************************************************
 * Name:  A2300_Defs.h
 * 
 * This module is the proprietary property of Loctronix Corporation
 * Copyright (C) 2013 Loctronix Corporation
 * All Rights Reserved
 * 
 ***************************************************************************/
#ifndef A2300_DEFS_H_
#define A2300_DEFS_H_

#include <string>
#include <list>


// Loctronix System Defaults
#define A2300_DEFAULT_FREQ      (1.946e9)   	// gHz -> mHz -> kHz
#define A2300_DEFAULT_GAIN		(0.0)
#define A2300_DEFAULT_TICK_RATE (32e6)		// 32-MHz.

#define A2300_RFFREQ_MIN        (0.3e9)         // 0.3 GHz.
#define A2300_RFFREQ_MAX	    (3.8e9)		// 3.8 GHz.
#define A2300_RFFREQ_STEP		(1000)
#define A2300_SAMPFREQ_MAX		(32e6)
#define A2300_SAMPFREQ_MIN      (7812.5)
#define A2300_DDUC_FREQ_MAX     (14e6)
#define A2300_DDUC_FREQ_MIN		(-14e6)
#define A2300_DDUC_FREQ_STEP	(0.0149011611938)

#define A2300_MIN_BW			(0.75e6 * 2.0)	// 0.75 MHz.
#define A2300_MAX_BW 			(14.0e6 * 2.0)	// 14.0 MHz.

#define A2300_RXGAIN_MIN			(0)
#define A2300_RXGAIN_MAX			(30)
#define A2300_RXGAIN_STEP			(3)

#define A2300_TXGAIN_MIN			(0)
#define A2300_TXGAIN_MAX			(56)
#define A2300_TXGAIN_STEP			(1)


#define A2300_MAX_SAMPLING_FREQ (32.0e6) // 32-MHz.
#define A2300_MIN_CLOCK   		(A2300_MAX_SAMPLING_FREQ/4096.0)
#define A2300_MAX_CLOCK   		(A2300_MAX_SAMPLING_FREQ/1.0)
#define A2300_SYSTEM_CLOCK		(100e6)

#define A2300_WAIT_TIME 		(0.1)


/**
 * Interface implemented components supporting device configuration
 * api.
 */
struct IConfigComponent
{
	virtual std::string name() = 0;
	virtual int  componentId() = 0;
	virtual void Reset()= 0;
	virtual void Synch() = 0;
};

#endif /* A2300_DEFS_H_ */
