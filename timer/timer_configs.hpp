#pragma once

#include <stdint.h>
#include <avr/io.h>

namespace MEGA2560
{
  namespace Timer
  {
    struct Timer1Config
    {
      static volatile uint8_t *TCCRA;
      static volatile uint8_t *TCCRB;
      static volatile uint16_t *OCRA;
      static volatile uint16_t *OCRB;
      static volatile uint16_t *OCRC;
      static volatile uint16_t *ICR;
      static volatile uint8_t *TIMSK;
      static volatile uint8_t *DDR;
      static uint8_t CHANNEL_A;
      static uint8_t CHANNEL_B;
      static uint8_t CHANNEL_C;
    };
    volatile uint8_t *Timer1Config::TCCRA = &TCCR1A;
    volatile uint8_t *Timer1Config::TCCRB = &TCCR1B;
    volatile uint16_t *Timer1Config::OCRA = &OCR1A;
    volatile uint16_t *Timer1Config::OCRB = &OCR1B;
    volatile uint16_t *Timer1Config::OCRC = &OCR1C;
    volatile uint16_t *Timer1Config::ICR = &ICR1;
    volatile uint8_t *Timer1Config::TIMSK = &TIMSK1;
    volatile uint8_t *Timer1Config::DDR = &DDRB;
    uint8_t Timer1Config::CHANNEL_A = (1 << 5);
    uint8_t Timer1Config::CHANNEL_B = (1 << 6);
    uint8_t Timer1Config::CHANNEL_C = (1 << 7);

    struct Timer3Config
    {
      static volatile uint8_t *TCCRA;
      static volatile uint8_t *TCCRB;
      static volatile uint16_t *OCRA;
      static volatile uint16_t *OCRB;
      static volatile uint16_t *OCRC;
      static volatile uint16_t *ICR;
      static volatile uint8_t *TIMSK;
      static volatile uint8_t *DDR;
      static uint8_t CHANNEL_A;
      static uint8_t CHANNEL_B;
      static uint8_t CHANNEL_C;
    };
    volatile uint8_t *Timer3Config::TCCRA = &TCCR3A;
    volatile uint8_t *Timer3Config::TCCRB = &TCCR3B;
    volatile uint16_t *Timer3Config::OCRA = &OCR3A;
    volatile uint16_t *Timer3Config::OCRB = &OCR3B;
    volatile uint16_t *Timer3Config::OCRC = &OCR3C;
    volatile uint16_t *Timer3Config::ICR = &ICR3;
    volatile uint8_t *Timer3Config::TIMSK = &TIMSK3;
    volatile uint8_t *Timer3Config::DDR = &DDRE;
    uint8_t Timer3Config::CHANNEL_A = (1 << 3);
    uint8_t Timer3Config::CHANNEL_B = (1 << 4);
    uint8_t Timer3Config::CHANNEL_C = (1 << 5);

    struct Timer4Config
    {
      static volatile uint8_t *TCCRA;
      static volatile uint8_t *TCCRB;
      static volatile uint16_t *OCRA;
      static volatile uint16_t *OCRB;
      static volatile uint16_t *OCRC;
      static volatile uint16_t *ICR;
      static volatile uint8_t *TIMSK;
      static volatile uint8_t *DDR;
      static uint8_t CHANNEL_A;
      static uint8_t CHANNEL_B;
      static uint8_t CHANNEL_C;
    };
    volatile uint8_t *Timer4Config::TCCRA = &TCCR4A;
    volatile uint8_t *Timer4Config::TCCRB = &TCCR4B;
    volatile uint16_t *Timer4Config::OCRA = &OCR4A;
    volatile uint16_t *Timer4Config::OCRB = &OCR4B;
    volatile uint16_t *Timer4Config::OCRC = &OCR4C;
    volatile uint16_t *Timer4Config::ICR = &ICR4;
    volatile uint8_t *Timer4Config::TIMSK = &TIMSK4;
    volatile uint8_t *Timer4Config::DDR = &DDRH;
    uint8_t Timer4Config::CHANNEL_A = (1 << 3);
    uint8_t Timer4Config::CHANNEL_B = (1 << 4);
    uint8_t Timer4Config::CHANNEL_C = (1 << 5);

    struct Timer5Config
    {
      static volatile uint8_t *TCCRA;
      static volatile uint8_t *TCCRB;
      static volatile uint16_t *OCRA;
      static volatile uint16_t *OCRB;
      static volatile uint16_t *OCRC;
      static volatile uint16_t *ICR;
      static volatile uint8_t *TIMSK;
      static volatile uint8_t *DDR;
      static uint8_t CHANNEL_A;
      static uint8_t CHANNEL_B;
      static uint8_t CHANNEL_C;
    };
    volatile uint8_t *Timer5Config::TCCRA = &TCCR5A;
    volatile uint8_t *Timer5Config::TCCRB = &TCCR5B;
    volatile uint16_t *Timer5Config::OCRA = &OCR5A;
    volatile uint16_t *Timer5Config::OCRB = &OCR5B;
    volatile uint16_t *Timer5Config::OCRC = &OCR5C;
    volatile uint16_t *Timer5Config::ICR = &ICR5;
    volatile uint8_t *Timer5Config::TIMSK = &TIMSK5;
    volatile uint8_t *Timer5Config::DDR = &DDRL;
    uint8_t Timer5Config::CHANNEL_A = (1 << 3);
    uint8_t Timer5Config::CHANNEL_B = (1 << 4);
    uint8_t Timer5Config::CHANNEL_C = (1 << 5);

  } // namespace Timer

}