#pragma once

#include <stdint.h>
#include <avr/io.h>

namespace MEGA2560
{
  namespace UART
  {
    struct Uart0Config
    {
      static volatile uint8_t *UCSRA;
      static volatile uint8_t *UCSRB;
      static volatile uint8_t *UCSRC;
      static volatile uint16_t *UBRR;
      static volatile uint8_t *UDR;
    };
    volatile uint8_t *Uart0Config::UCSRA = &UCSR0A;
    volatile uint8_t *Uart0Config::UCSRB = &UCSR0B;
    volatile uint8_t *Uart0Config::UCSRC = &UCSR0C;
    volatile uint16_t *Uart0Config::UBRR = &UBRR0;
    volatile uint8_t *Uart0Config::UDR = &UDR0;

    struct Uart1Config
    {
      static volatile uint8_t *UCSRA;
      static volatile uint8_t *UCSRB;
      static volatile uint8_t *UCSRC;
      static volatile uint16_t *UBRR;
      static volatile uint8_t *UDR;
    };
    volatile uint8_t *Uart1Config::UCSRA = &UCSR1A;
    volatile uint8_t *Uart1Config::UCSRB = &UCSR1B;
    volatile uint8_t *Uart1Config::UCSRC = &UCSR1C;
    volatile uint16_t *Uart1Config::UBRR = &UBRR1;
    volatile uint8_t *Uart1Config::UDR = &UDR1;

    struct Uart2Config
    {
      static volatile uint8_t *UCSRA;
      static volatile uint8_t *UCSRB;
      static volatile uint8_t *UCSRC;
      static volatile uint16_t *UBRR;
      static volatile uint8_t *UDR;
    };
    volatile uint8_t *Uart2Config::UCSRA = &UCSR2A;
    volatile uint8_t *Uart2Config::UCSRB = &UCSR2B;
    volatile uint8_t *Uart2Config::UCSRC = &UCSR2C;
    volatile uint16_t *Uart2Config::UBRR = &UBRR2;
    volatile uint8_t *Uart2Config::UDR = &UDR2;

    struct Uart3Config
    {
      static volatile uint8_t *UCSRA;
      static volatile uint8_t *UCSRB;
      static volatile uint8_t *UCSRC;
      static volatile uint16_t *UBRR;
      static volatile uint8_t *UDR;
    };
    volatile uint8_t *Uart3Config::UCSRA = &UCSR3A;
    volatile uint8_t *Uart3Config::UCSRB = &UCSR3B;
    volatile uint8_t *Uart3Config::UCSRC = &UCSR3C;
    volatile uint16_t *Uart3Config::UBRR = &UBRR3;
    volatile uint8_t *Uart3Config::UDR = &UDR3;

  } // namespace UART
} // namespace MEGA2560
