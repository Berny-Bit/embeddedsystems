/*******************************************************************************
* File Name: remlicht.h  
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

#if !defined(CY_PINS_remlicht_ALIASES_H) /* Pins remlicht_ALIASES_H */
#define CY_PINS_remlicht_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define remlicht_0			(remlicht__0__PC)
#define remlicht_0_INTR	((uint16)((uint16)0x0001u << remlicht__0__SHIFT))

#define remlicht_INTR_ALL	 ((uint16)(remlicht_0_INTR))

#endif /* End Pins remlicht_ALIASES_H */


/* [] END OF FILE */
