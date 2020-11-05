/*
 * main.cpp
 *
 *  Created on: 6 maj 2020
 *      Author: Wiktor Springer
 */


#include "GLOBAL.h"
#include "LCD_HD44780.h"
uint8_t GetKey()
{
	uint8_t i,j;
	for(i=0; i<4; i++)
	{
		cbi(PORTC,i);
		for(j=0; j<4; j++)
		{
			if(bit_is_clear(PINC,j+4))
			{
				sbi(PORTC,i);
				if(i==0)
				{
					return j;
				}
				if(i==1)
				{
					return (j+4);
				}
				if(i==2)
				{
					return (j+8);
				}
				if(i==3)
				{
					return (j+12);
				}
			}
		}
		sbi(PORTC,i);
	}

	cbi(PORTA,0);
	if(bit_is_clear(PINA,1))
	{
		sbi(PORTA,0);
		return 20;
	}
	sbi(PORTA,0);
	return 99;

}
int main()
{
	int32_t k,i,liczba1=0,liczba2=0,liczba3=0,wynik=0;
	bool czy_wprowadzono=false;
	bool licznik=false;
	bool doda=false, odej=false, mnoz=false, dziel=false;
	char tekst[]="kalkulator:";
	char tekst2[]="opcja:+";
	char tekst3[]="opcja:-";
	char tekst4[]="opcja:*";
	char tekst5[]="opcja:/ ";
	char tekst6[]="Wiktor S";

	cbi(DDRA, 1);
	sbi(PORTA,1);
	sbi(DDRA, 0);
	sbi(PORTA,0);


	for(i=0; i<8; i++)
	{
		if(i<4)
		{
			sbi(DDRC,i);
			sbi(PORTC,i);

		}
		else
		{
			cbi(DDRC,i);
			sbi(PORTC,i);
		}

	}
	DDRD=0xff;


	LCD_HD44780::init();
	LCD_HD44780::writeText(tekst);
	LCD_HD44780::goTo(0,1);
	LCD_HD44780::writeText(tekst6);
	LCD_HD44780::home();





	while(1)
	{
		while(1)
		{
			switch(k=GetKey())
			{

				case 0:
					if(licznik==false)
					{
						liczba1=7;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+7;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 1:
					if(licznik==false)
					{
						liczba1=4;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+4;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 2:
					if(licznik==false)
					{
						liczba1=1;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+1;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 3:

					liczba3=liczba1;
					odej=false;
					doda=false;
					mnoz=true;
					dziel=false;
					licznik=false;
					LCD_HD44780::goTo(0,1);
					LCD_HD44780::writeText(tekst4);
				break;
				case 4:
					if(licznik==false)
					{
						liczba1=8;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+8;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 5:
					if(licznik==false)
					{
						liczba1=5;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+5;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 6:
					if(licznik==false)
					{
						liczba1=2;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+2;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 7:
					if(licznik==false)
					{
					    liczba1=0;
					    czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+0;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 8:
					if(licznik==false)
					{
						liczba1=9;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+9;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 9:
					if(licznik==false)
					{
						liczba1=6;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=10*liczba1+6;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 10:
					if(licznik==false)
					{
						liczba1=3;
						czy_wprowadzono=true;
						licznik=true;
					}
					else
					{
						liczba2=liczba1*10+3;
						liczba1=liczba2;
						czy_wprowadzono=true;
					}
				break;

				case 11:
					liczba3=liczba1;
					odej=false;
					doda=false;
					mnoz=false;
					dziel=true;
					licznik=false;
					LCD_HD44780::goTo(0,1);
					LCD_HD44780::writeText(tekst5);
				break;

				case 12:
					liczba3=liczba1;
					odej=true;
					doda=false;
					mnoz=false;
					dziel=false;
					licznik=false;
					LCD_HD44780::goTo(0,1);
					LCD_HD44780::writeText(tekst3);
				break;

				case 13:
					liczba3=liczba1;
					odej=false;
                    doda=true;
					mnoz=false;
					dziel=false;
					licznik=false;
					LCD_HD44780::goTo(0,1);
					LCD_HD44780::writeText(tekst2);


				break;

				case 14:
					LCD_HD44780::clear();
					licznik=false;
				break;

				case 15:
					if(doda)
					{
						wynik=liczba3+liczba1;
						liczba1=wynik;
						doda=false;
						czy_wprowadzono=true;
						licznik=false;
					}
					if(odej)
					{
						wynik=liczba3-liczba1;
						liczba1=wynik;
						odej=false;
						czy_wprowadzono=true;
						licznik=false;
					}
					if(mnoz)
					{
						wynik=liczba3*liczba1;
						liczba1=wynik;
						mnoz=false;
						czy_wprowadzono=true;
						licznik=false;
					}
					if(dziel)
					{
						wynik=liczba3/liczba1;
						liczba1=wynik;
						dziel=false;
						czy_wprowadzono=true;
						licznik=false;
					}

				break;

				case 20:

						liczba2=liczba1/10;
						if(liczba2!=0)
						{
							liczba1=liczba2;
							czy_wprowadzono=true;
						}
						else
						{
							licznik=false;
							LCD_HD44780::clear();
						}


				break;

				default:
				break;
			}
			_delay_ms(100);
			if(czy_wprowadzono)
			{

				LCD_HD44780::showNumber(liczba1);
				czy_wprowadzono=false;
				break;
			}
		}





	}

}
