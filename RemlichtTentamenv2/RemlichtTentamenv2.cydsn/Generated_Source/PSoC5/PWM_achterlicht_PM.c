/*******************************************************************************
* File Name: PWM_achterlicht_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_achterlicht.h"

static PWM_achterlicht_backupStruct PWM_achterlicht_backup;


/*******************************************************************************
* Function Name: PWM_achterlicht_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_achterlicht_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_achterlicht_SaveConfig(void) 
{

    #if(!PWM_achterlicht_UsingFixedFunction)
        #if(!PWM_achterlicht_PWMModeIsCenterAligned)
            PWM_achterlicht_backup.PWMPeriod = PWM_achterlicht_ReadPeriod();
        #endif /* (!PWM_achterlicht_PWMModeIsCenterAligned) */
        PWM_achterlicht_backup.PWMUdb = PWM_achterlicht_ReadCounter();
        #if (PWM_achterlicht_UseStatus)
            PWM_achterlicht_backup.InterruptMaskValue = PWM_achterlicht_STATUS_MASK;
        #endif /* (PWM_achterlicht_UseStatus) */

        #if(PWM_achterlicht_DeadBandMode == PWM_achterlicht__B_PWM__DBM_256_CLOCKS || \
            PWM_achterlicht_DeadBandMode == PWM_achterlicht__B_PWM__DBM_2_4_CLOCKS)
            PWM_achterlicht_backup.PWMdeadBandValue = PWM_achterlicht_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_achterlicht_KillModeMinTime)
             PWM_achterlicht_backup.PWMKillCounterPeriod = PWM_achterlicht_ReadKillTime();
        #endif /* (PWM_achterlicht_KillModeMinTime) */

        #if(PWM_achterlicht_UseControl)
            PWM_achterlicht_backup.PWMControlRegister = PWM_achterlicht_ReadControlRegister();
        #endif /* (PWM_achterlicht_UseControl) */
    #endif  /* (!PWM_achterlicht_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_achterlicht_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_achterlicht_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_achterlicht_RestoreConfig(void) 
{
        #if(!PWM_achterlicht_UsingFixedFunction)
            #if(!PWM_achterlicht_PWMModeIsCenterAligned)
                PWM_achterlicht_WritePeriod(PWM_achterlicht_backup.PWMPeriod);
            #endif /* (!PWM_achterlicht_PWMModeIsCenterAligned) */

            PWM_achterlicht_WriteCounter(PWM_achterlicht_backup.PWMUdb);

            #if (PWM_achterlicht_UseStatus)
                PWM_achterlicht_STATUS_MASK = PWM_achterlicht_backup.InterruptMaskValue;
            #endif /* (PWM_achterlicht_UseStatus) */

            #if(PWM_achterlicht_DeadBandMode == PWM_achterlicht__B_PWM__DBM_256_CLOCKS || \
                PWM_achterlicht_DeadBandMode == PWM_achterlicht__B_PWM__DBM_2_4_CLOCKS)
                PWM_achterlicht_WriteDeadTime(PWM_achterlicht_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_achterlicht_KillModeMinTime)
                PWM_achterlicht_WriteKillTime(PWM_achterlicht_backup.PWMKillCounterPeriod);
            #endif /* (PWM_achterlicht_KillModeMinTime) */

            #if(PWM_achterlicht_UseControl)
                PWM_achterlicht_WriteControlRegister(PWM_achterlicht_backup.PWMControlRegister);
            #endif /* (PWM_achterlicht_UseControl) */
        #endif  /* (!PWM_achterlicht_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_achterlicht_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_achterlicht_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_achterlicht_Sleep(void) 
{
    #if(PWM_achterlicht_UseControl)
        if(PWM_achterlicht_CTRL_ENABLE == (PWM_achterlicht_CONTROL & PWM_achterlicht_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_achterlicht_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_achterlicht_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_achterlicht_UseControl) */

    /* Stop component */
    PWM_achterlicht_Stop();

    /* Save registers configuration */
    PWM_achterlicht_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_achterlicht_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_achterlicht_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_achterlicht_Wakeup(void) 
{
     /* Restore registers values */
    PWM_achterlicht_RestoreConfig();

    if(PWM_achterlicht_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_achterlicht_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
