/*******************************************************************************
* File Name: remlicht.h  
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

#if !defined(CY_PINS_remlicht_H) /* Pins remlicht_H */
#define CY_PINS_remlicht_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "remlicht_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 remlicht__PORT == 15 && ((remlicht__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    remlicht_Write(uint8 value);
void    remlicht_SetDriveMode(uint8 mode);
uint8   remlicht_ReadDataReg(void);
uint8   remlicht_Read(void);
void    remlicht_SetInterruptMode(uint16 position, uint16 mode);
uint8   remlicht_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the remlicht_SetDriveMode() function.
     *  @{
     */
        #define remlicht_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define remlicht_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define remlicht_DM_RES_UP          PIN_DM_RES_UP
        #define remlicht_DM_RES_DWN         PIN_DM_RES_DWN
        #define remlicht_DM_OD_LO           PIN_DM_OD_LO
        #define remlicht_DM_OD_HI           PIN_DM_OD_HI
        #define remlicht_DM_STRONG          PIN_DM_STRONG
        #define remlicht_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define remlicht_MASK               remlicht__MASK
#define remlicht_SHIFT              remlicht__SHIFT
#define remlicht_WIDTH              1u

/* Interrupt constants */
#if defined(remlicht__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in remlicht_SetInterruptMode() function.
     *  @{
     */
        #define remlicht_INTR_NONE      (uint16)(0x0000u)
        #define remlicht_INTR_RISING    (uint16)(0x0001u)
        #define remlicht_INTR_FALLING   (uint16)(0x0002u)
        #define remlicht_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define remlicht_INTR_MASK      (0x01u) 
#endif /* (remlicht__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define remlicht_PS                     (* (reg8 *) remlicht__PS)
/* Data Register */
#define remlicht_DR                     (* (reg8 *) remlicht__DR)
/* Port Number */
#define remlicht_PRT_NUM                (* (reg8 *) remlicht__PRT) 
/* Connect to Analog Globals */                                                  
#define remlicht_AG                     (* (reg8 *) remlicht__AG)                       
/* Analog MUX bux enable */
#define remlicht_AMUX                   (* (reg8 *) remlicht__AMUX) 
/* Bidirectional Enable */                                                        
#define remlicht_BIE                    (* (reg8 *) remlicht__BIE)
/* Bit-mask for Aliased Register Access */
#define remlicht_BIT_MASK               (* (reg8 *) remlicht__BIT_MASK)
/* Bypass Enable */
#define remlicht_BYP                    (* (reg8 *) remlicht__BYP)
/* Port wide control signals */                                                   
#define remlicht_CTL                    (* (reg8 *) remlicht__CTL)
/* Drive Modes */
#define remlicht_DM0                    (* (reg8 *) remlicht__DM0) 
#define remlicht_DM1                    (* (reg8 *) remlicht__DM1)
#define remlicht_DM2                    (* (reg8 *) remlicht__DM2) 
/* Input Buffer Disable Override */
#define remlicht_INP_DIS                (* (reg8 *) remlicht__INP_DIS)
/* LCD Common or Segment Drive */
#define remlicht_LCD_COM_SEG            (* (reg8 *) remlicht__LCD_COM_SEG)
/* Enable Segment LCD */
#define remlicht_LCD_EN                 (* (reg8 *) remlicht__LCD_EN)
/* Slew Rate Control */
#define remlicht_SLW                    (* (reg8 *) remlicht__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define remlicht_PRTDSI__CAPS_SEL       (* (reg8 *) remlicht__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define remlicht_PRTDSI__DBL_SYNC_IN    (* (reg8 *) remlicht__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define remlicht_PRTDSI__OE_SEL0        (* (reg8 *) remlicht__PRTDSI__OE_SEL0) 
#define remlicht_PRTDSI__OE_SEL1        (* (reg8 *) remlicht__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define remlicht_PRTDSI__OUT_SEL0       (* (reg8 *) remlicht__PRTDSI__OUT_SEL0) 
#define remlicht_PRTDSI__OUT_SEL1       (* (reg8 *) remlicht__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define remlicht_PRTDSI__SYNC_OUT       (* (reg8 *) remlicht__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(remlicht__SIO_CFG)
    #define remlicht_SIO_HYST_EN        (* (reg8 *) remlicht__SIO_HYST_EN)
    #define remlicht_SIO_REG_HIFREQ     (* (reg8 *) remlicht__SIO_REG_HIFREQ)
    #define remlicht_SIO_CFG            (* (reg8 *) remlicht__SIO_CFG)
    #define remlicht_SIO_DIFF           (* (reg8 *) remlicht__SIO_DIFF)
#endif /* (remlicht__SIO_CFG) */

/* Interrupt Registers */
#if defined(remlicht__INTSTAT)
    #define remlicht_INTSTAT            (* (reg8 *) remlicht__INTSTAT)
    #define remlicht_SNAP               (* (reg8 *) remlicht__SNAP)
    
	#define remlicht_0_INTTYPE_REG 		(* (reg8 *) remlicht__0__INTTYPE)
#endif /* (remlicht__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_remlicht_H */


/* [] END OF FILE */
