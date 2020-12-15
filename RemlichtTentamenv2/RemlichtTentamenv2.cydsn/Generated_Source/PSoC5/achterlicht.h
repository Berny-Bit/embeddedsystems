/*******************************************************************************
* File Name: achterlicht.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_achterlicht_H) /* Pins achterlicht_H */
#define CY_PINS_achterlicht_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "achterlicht_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 achterlicht__PORT == 15 && ((achterlicht__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    achterlicht_Write(uint8 value);
void    achterlicht_SetDriveMode(uint8 mode);
uint8   achterlicht_ReadDataReg(void);
uint8   achterlicht_Read(void);
void    achterlicht_SetInterruptMode(uint16 position, uint16 mode);
uint8   achterlicht_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the achterlicht_SetDriveMode() function.
     *  @{
     */
        #define achterlicht_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define achterlicht_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define achterlicht_DM_RES_UP          PIN_DM_RES_UP
        #define achterlicht_DM_RES_DWN         PIN_DM_RES_DWN
        #define achterlicht_DM_OD_LO           PIN_DM_OD_LO
        #define achterlicht_DM_OD_HI           PIN_DM_OD_HI
        #define achterlicht_DM_STRONG          PIN_DM_STRONG
        #define achterlicht_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define achterlicht_MASK               achterlicht__MASK
#define achterlicht_SHIFT              achterlicht__SHIFT
#define achterlicht_WIDTH              1u

/* Interrupt constants */
#if defined(achterlicht__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in achterlicht_SetInterruptMode() function.
     *  @{
     */
        #define achterlicht_INTR_NONE      (uint16)(0x0000u)
        #define achterlicht_INTR_RISING    (uint16)(0x0001u)
        #define achterlicht_INTR_FALLING   (uint16)(0x0002u)
        #define achterlicht_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define achterlicht_INTR_MASK      (0x01u) 
#endif /* (achterlicht__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define achterlicht_PS                     (* (reg8 *) achterlicht__PS)
/* Data Register */
#define achterlicht_DR                     (* (reg8 *) achterlicht__DR)
/* Port Number */
#define achterlicht_PRT_NUM                (* (reg8 *) achterlicht__PRT) 
/* Connect to Analog Globals */                                                  
#define achterlicht_AG                     (* (reg8 *) achterlicht__AG)                       
/* Analog MUX bux enable */
#define achterlicht_AMUX                   (* (reg8 *) achterlicht__AMUX) 
/* Bidirectional Enable */                                                        
#define achterlicht_BIE                    (* (reg8 *) achterlicht__BIE)
/* Bit-mask for Aliased Register Access */
#define achterlicht_BIT_MASK               (* (reg8 *) achterlicht__BIT_MASK)
/* Bypass Enable */
#define achterlicht_BYP                    (* (reg8 *) achterlicht__BYP)
/* Port wide control signals */                                                   
#define achterlicht_CTL                    (* (reg8 *) achterlicht__CTL)
/* Drive Modes */
#define achterlicht_DM0                    (* (reg8 *) achterlicht__DM0) 
#define achterlicht_DM1                    (* (reg8 *) achterlicht__DM1)
#define achterlicht_DM2                    (* (reg8 *) achterlicht__DM2) 
/* Input Buffer Disable Override */
#define achterlicht_INP_DIS                (* (reg8 *) achterlicht__INP_DIS)
/* LCD Common or Segment Drive */
#define achterlicht_LCD_COM_SEG            (* (reg8 *) achterlicht__LCD_COM_SEG)
/* Enable Segment LCD */
#define achterlicht_LCD_EN                 (* (reg8 *) achterlicht__LCD_EN)
/* Slew Rate Control */
#define achterlicht_SLW                    (* (reg8 *) achterlicht__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define achterlicht_PRTDSI__CAPS_SEL       (* (reg8 *) achterlicht__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define achterlicht_PRTDSI__DBL_SYNC_IN    (* (reg8 *) achterlicht__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define achterlicht_PRTDSI__OE_SEL0        (* (reg8 *) achterlicht__PRTDSI__OE_SEL0) 
#define achterlicht_PRTDSI__OE_SEL1        (* (reg8 *) achterlicht__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define achterlicht_PRTDSI__OUT_SEL0       (* (reg8 *) achterlicht__PRTDSI__OUT_SEL0) 
#define achterlicht_PRTDSI__OUT_SEL1       (* (reg8 *) achterlicht__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define achterlicht_PRTDSI__SYNC_OUT       (* (reg8 *) achterlicht__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(achterlicht__SIO_CFG)
    #define achterlicht_SIO_HYST_EN        (* (reg8 *) achterlicht__SIO_HYST_EN)
    #define achterlicht_SIO_REG_HIFREQ     (* (reg8 *) achterlicht__SIO_REG_HIFREQ)
    #define achterlicht_SIO_CFG            (* (reg8 *) achterlicht__SIO_CFG)
    #define achterlicht_SIO_DIFF           (* (reg8 *) achterlicht__SIO_DIFF)
#endif /* (achterlicht__SIO_CFG) */

/* Interrupt Registers */
#if defined(achterlicht__INTSTAT)
    #define achterlicht_INTSTAT            (* (reg8 *) achterlicht__INTSTAT)
    #define achterlicht_SNAP               (* (reg8 *) achterlicht__SNAP)
    
	#define achterlicht_0_INTTYPE_REG 		(* (reg8 *) achterlicht__0__INTTYPE)
#endif /* (achterlicht__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_achterlicht_H */


/* [] END OF FILE */
