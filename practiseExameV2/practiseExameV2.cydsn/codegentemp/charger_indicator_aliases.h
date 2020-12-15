/*******************************************************************************
* File Name: charger_indicator.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_charger_indicator_ALIASES_H) /* Pins charger_indicator_ALIASES_H */
#define CY_PINS_charger_indicator_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define charger_indicator_0			(charger_indicator__0__PC)
#define charger_indicator_0_INTR	((uint16)((uint16)0x0001u << charger_indicator__0__SHIFT))

#define charger_indicator_INTR_ALL	 ((uint16)(charger_indicator_0_INTR))

#endif /* End Pins charger_indicator_ALIASES_H */


/* [] END OF FILE */
