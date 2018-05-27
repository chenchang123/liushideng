#include "LPC11XX.H"                            
#define LED1_ON()  (LPC_GPIO2->DATA &= ~(1<<0))     
#define LED1_OFF() (LPC_GPIO2->DATA |= (1<<0))     
#define LED2_ON()  (LPC_GPIO2->DATA &= ~(1<<1))     
#define LED2_OFF() (LPC_GPIO2->DATA |= (1<<1))      
static volatile unsigned int ticks;
/********************************************************************************
* FunctionName   : Delay()
* Description    : ????
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/
void Delay()
{
    uint16_t i,j;
    for(i=0;i<5000;i++)
        for(j=0;j<200;j++);
}

/********************************************************************************
* FunctionName   : LedInit()
* Description    : ???LED??
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/
void LedInit(void)
{
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); 
    LPC_IOCON->PIO2_0 &= ~0x07;    
    LPC_IOCON->PIO2_0 |= 0x00; 
    LPC_IOCON->PIO2_1 &= ~0x07;   
    LPC_IOCON->PIO2_1 |= 0x00; 
    LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);
    LPC_SYSCON->SYSAHBCLKCTRL |= ~(1<<6);    	
    LPC_GPIO2->DIR |= (1<<0); 
    LPC_GPIO2->DATA |= (1<<0); 
    LPC_GPIO2->DIR |= (1<<1); 
    LPC_GPIO2->DATA |= (1<<1); 
}
/********************************************************************************
* FunctionName   : main()
* Description    : ???
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/
int main(void) 
{   
    LedInit();
    while(1)
    {
        Delay();
        LED1_ON();
        LED2_OFF();
        Delay();
        LED1_OFF();
        LED2_ON();
    } 
}

