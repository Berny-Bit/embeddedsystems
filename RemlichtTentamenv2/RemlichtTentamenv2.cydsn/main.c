/* ========================================

Tentamen Embedded Systems 2
Datum: 6 november
Tijd: 14:30 - 17:00


Inleiding
=========
In deze tentamenopgave ga je aan de slag met een systeem om de rem- en
achterlichten van een auto aan te sturen. De remlichten worden hierbij
voorgesteld met het blauwe LEDje die op het PSoC bordje zit ingebouwd.
Het rempedaal is de button die op het bordje zit. Voor de normale
achterlichten van de auto moet je een extra LED aansluiten op het bordje.

BELANGRIJK: LEVER ALS JE KLAAR BENT EEN ZIP FILE IN VAN JE COMPLETE PROJECT!!

Verpak dus de directory jouwproject.cysdn in een zipfile en lever die in op moodle.

Succes!


Opgaven:

Opgave 1: Getting started
========
1a:
Maak een nieuw (leeg) project aan voor je bordje. Let op dat je de
correcte target hardware gebruikt (jouw type bordje). Noem dit project
"RemlichtTentamen" en kijk goed waar dit opgeslagen wordt. Kopieer de inhoud
van deze opgavefile in de main.c file van je project. Bouw het project en
kijk of je het kunt runnen en debuggen.

1b:
Vul je naam en studentnummer in.
NOGMAALS: Lever aan het eind een zip-file in van je complete project!
Dus "RemlichtTentamen.cydsn.zip"

Naam: Bernward 
Studentnummer:

Opgave 2: Remlicht
==================
In deze opgave ga je het basis-remlicht implementeren.

2a:
Maak in je topdesign een outputpin en een inputpin aan. De outputpin link
je aan het blauwe ledje op je bordje en de input pin aan de button op je bordje
(neem de SW1 button die middenop je bordje zit en niet de SW3 (reset)button die
aan de rand van je bordje zit!). Configureer de inputpin als "resistive pull-up".

2b:
Wat betekent het dat de input pin als "resistive pull-up" is geconigureerd?


Antwoord: Dat betekend dat de input pin bij de rust stand een 1 heeft, en als ie ingedukt wordt,
krijgt ie een 0.

2c:
Vul onderstaande code aan zodat het ledje functioneert als remlicht: bij het
indrukken van de button (het rempedaal) moet het ledje (je remlicht) aangaan en
bij het loslaten weer uit.

Opgave 3: Knipperen
===================
We willen nu een extra functionaliteit toevoegen om wat meer aandacht te trekken
als er geremd wordt. Voordat de remlichten constant gaan branden willen we ze daarom
eerst één seconde lang laten knipperen.

3a:
Pas de code aan zodat bij het indrukken van het rempedaal het remlicht eerst een aantal
milliseconden (duration) met een bepaalde frequentie (BLINK_FREQUENCY) knippert. Gebruik
hiervoor een for-loop en een delay functie.
Test het uit door BLINK_FREQUENCY bijvoorbeeld op 5 te zetten en dan de functie aan te roepen
met 1000 waardoor de led precies één seconde lang 5 keer aan en uit moet gaan.

3b:
De oplossing voor het knipperen bij opgave 3a met een loopje en de delay functie is niet de beste
oplossing. Wat voor andere oplossing zou er mogelijk zijn? Leg uit waarom dat een betere zou zijn.

Antwoord: Een pwm gebruiken waardoor je de dutycyle mee kan aanpassen.


Opgave 4: Achterlicht
=====================
Naast een remlicht willen we ook een gewoon achterlicht hebben. Deze moet natuurlijk wel
minder fel branden dan een remlicht. Hiervoor ga je een PWM gebruiken.

4a:
Sluit zelf nog een led aan op je bordje. Configureer een outputpin in je topdesign voor dit
ledje en teken daar ook in hoe je het ledje hebt aangesloten.

4b:
Configureer een PWM in je topdesign, inclusief een ingaande clock. Sluit de uitgang van de PWM
aan op de outputpin voor je ledje.

4c:
We willen het ledje op ongeveer halve sterkte laten branden zonder dat we een flikkering in
het ledje zien. Configureer hiervoor de clock en PWM. Geef de waardes van de volgende parameters
die je hebt geconfigureerd met een korte toelichting:

Frequentie ingaande clock: 15khz
Resolution PWM:8-bit
Period PWM:255
CMP value PWM:80

Toelichting: 15khz/255 =...hertz. Met 8 bits kan ik van 0 tot 255 tellen. De compare value wordt vergeleken met
de resolutie, als de resolutie hoger is dan de compare value, dan krijgt ie een 1, als het minder is een 0.
Er wordt dan van 255 tot 0 geteld en iedere keer word die vergelijking gemaakt. Daarmee kan ik mijn duty cycle
toepassen.

4d:
Pas de code aan zodat de achterlichten aangezet worden (op halve kracht).


Opgave 5: Automatisch achterlicht
=================================
We willen nu het systeem zo aanpassen dat de achterlichten automatisch aan en uitgezet worden
al naar gelang het buiten licht of donker is. Hiertoe gaan we de LDR (light-dependent resistor)
gebruiken die in het kitje zit (een klein rond schijfje waar een soort spiraaltje op getekend lijkt).
Als je deze LDR niet hebt of niet aan de praat krijgt kun je ook de met de hand regelbare weerstand
gebruiken (levert wel minder punten op).

5a:
Sluit de LDR aan tussen de 5 volt en een analoge inputpin. Teken dit ook in je topdesign. Plaats en
configureer ook een AD converter (ADC_SAR) om de waardes van de LDR in een digitale waarde om te kunnen
zetten. Gebruik voor de ADC_SAR de volgende settings:

Input range: Vssa to Vdda (Single Ended)
Reference: Internal Vref

Alternatief: sluit niet de LDR maar de regelbare weesrtand aan.

5b:
Vul de functie XXXX aan met code zodat de ADC uitgelezen wordt. Bepaal bijvoorbeeld
met behulp van de debugger wat de waarden zijn die worden uitgelezen als de LDR wordt
afgedekt en als deze wel licht vangt.

Afgedekt: 1
Onafgedekt: 0

Alternatief: geef de min en max die je uit de regelbare weerstand leest.

5c:
Pas nu de code aan zodat de achterlichten automtisch aangaan als het donker(der) wordt
en weer uitgaan als het weer licht(er) wordt. Welke grenswaarde heb je hiervoor gebruikt
en waarom?

Grenswaarde:1, want als ie afgedekt wordt, dan krijgt de variabele de waarde 1, als ie niet
afgedekt is, heeft ie een waarde van 0.

Toelichting:

5d:
Niet iedere auto is voorzien van een lichtsensor om automatisch te bepalen of de achterlichten aan
of uit moeten. We willen de code daarom aanpassen zodat we eenvoudig deze functionaliteit wel
of niet meenemen in ons programma. Pas de code zo aan dat we door middel van macros voor
voorwaardelijke compilatie de code wel of niet meenemen in ons programma.

Opgave 6: Theorie vragen
========================
6a Leg uit wat de volatile modifier doet en wanneer je deze gebruikt.
antwoord: De compiler die haalt elke variabele die niet van waarde verandert weg. Met volatile modifier geef
je aan dat de compiler de variabele niet moet verwijderen bij optimalisatie omdat de waarde nog kan veranderen.

6b Leg uit wat de const modifier doet en wanneer je deze gebruikt.
antwoord: Met de const modifier geef je aan dat de compiler de variabele die niet van waarde verandert niet weg moet
optimaliseren.

6c Gebruikt de Arm processor de stack of registers voor lokale variabelen?
antwoord: de stack

6d Wat is een dangling pointer?
antwoord: een pointer die niet geinitialiseerd is.

6e Wordt een C enumerate type opgeslagen als tekst, integer of floating point?
antwoord: Als tekst.

* ========================================
*/
#include "project.h"

#ifdef LIGHT_SENSOR_PRESENT
    int DaylightIsOn(void);
    #endif

#define LIGHT_SENSOR_PRESENT        /* Voor opgave 5d */
#define DAYLIGHT_THRESHOLD 0x01   /* Voor opgave 5c */

#define BUTTON_RELEASED 0
#define BUTTON_PRESSED  1

#define BRAKE_OFF 0
#define BRAKE_BLINK 1
#define BRAKE_ON 2

#define REAR_OFF 0
#define REAR_ON 1

#define BLINK_FREQUENCY 5        /* Voor opgave 3a */

int button_mode = BUTTON_RELEASED;
int brake_mode = BRAKE_OFF;
int rear_mode = REAR_OFF;

int ButtonIsPressed(void)
{
    /* bepaal of de knop is ingedrukt of niet en retourneer dat */
    /* TODO opgave 2
    return XXXX */
    if(rempedaal_Read()==1){
     return 0;
    }else if(rempedaal_Read()==0){
     return 1;
    }

    return 1; /* tijdelijke returnwaarde */
}

void SetButtonMode(int mode)
{
	button_mode = mode;
}

int GetButtonMode(void)
{
	return button_mode;
}

void SetBrakeMode(int mode)
{
	brake_mode = mode;
}

int GetBrakeMode(void)
{
	return brake_mode;
}

void SwitchBrakeLights(int mode)
{
    /* Zet de remlichten aan of uit afhankelijk van de mode */

    /* TODO Opgave 2 */
    if(mode == BRAKE_ON){
     remlicht_Write(1);
    }else if(mode == BRAKE_OFF){
     remlicht_Write(0);
    }
}

void FlashBrakeLights(int duration)
{
    /* Knipper de remlichten aan/uit voor duration ms op BLINK_FREQUENCY frequentie */

    // TODO opgave 3
	for (int i=0; i<BLINK_FREQUENCY; i++)
	{
        remlicht_Write(1);
        CyDelay(duration);
        remlicht_Write(0);
        CyDelay(duration);
	}

}

void SetRearMode(int mode)
{
	rear_mode = mode;
}

int GetRearMode(void)
{
	return rear_mode;
}

volatile int value;

int DaylightIsOn(void)
{
    /* bepaal of het licht of donker is en retourneer dat */
    value = ADC_SAR_1_GetResult8();
    // TODO Opgave 5 uitlezen licht sensor
    if(value < DAYLIGHT_THRESHOLD){
    return 0;
    }else if(value > DAYLIGHT_THRESHOLD){
    return 1;
    }
	//return (value > DAYLIGHT_THRESHOLD);

    return 1; /* tijdelijke returnwaarde */
}

void SwitchRearLights(int mode)
{
    /* set de achterlichten (half) aan of uit afhankelijk van mode */

    /* TODO opgave 4 */
    if(mode == REAR_ON){
    achterlicht_Write(1);
    PWM_achterlicht_WriteCompare(50);
    }else if(mode == REAR_OFF){
    achterlicht_Write(0);
    PWM_achterlicht_WriteCompare(0);
    }
}

int main(void)
{
	CyGlobalIntEnable; /* Enable global interrupts. */

	/* Plaats hier je initialisatiecode (e.g. MyInst_Start()) */
    PWM_achterlicht_Start();
    Clock_achterlicht_Start();
    ADC_SAR_1_Start();

	for(;;)
	{
	/* Plaats hier je main code */
       SetRearMode(REAR_ON);
       SwitchRearLights(REAR_ON);
        if (ButtonIsPressed()) /* Check of de User Button is ingedrukt */
        {
            if (GetButtonMode() == BUTTON_RELEASED) /* button was net nog niet ingedrukt */
            {
                SetButtonMode(BUTTON_PRESSED);
				SetBrakeMode(BRAKE_ON);
				FlashBrakeLights(100); //Voor opgave 3:
				SwitchBrakeLights(BRAKE_ON);

            }
        }
        else
        {
            if (GetButtonMode() == BUTTON_PRESSED) /* button was net nog ingedrukt */
            {
                SetButtonMode(BUTTON_RELEASED);
				SetBrakeMode(BRAKE_OFF);
                SwitchBrakeLights(BRAKE_OFF);
            }
        }
		if ((!DaylightIsOn()) && GetRearMode() == REAR_OFF)
		{
			SwitchRearLights(REAR_ON);
			SetRearMode(REAR_ON);
		}
		else if (DaylightIsOn() && GetRearMode() == REAR_ON)
		{
			SwitchRearLights(REAR_OFF);
			SetRearMode(REAR_OFF);
		}
	}
}

/* [] END OF FILE */
