#pragma once
#include "interface_timer.hpp"
#include "timer_configs.hpp"
#include <stdint.h>

namespace MEGA2560
{
  namespace Timer
  {
    template <typename config>
    class Device : public InterfaceTimer
    {
    public:
      static Device &instance()
      {
        static Device instance;
        return instance;
      }
      /*
      Timer created as a singleton object
       */
      Device(const Device &) = delete;
      Device(Device &&) = delete;
      Device &operator=(const Device &) = delete;
      Device &operator=(Device &&) = delete;

      /*
        Initiate timer with default values
         - fast pwm
         - input_capture 40000
         - prescaler 8
         - compare value 1500
         - non-inverting compare mode
       */
      void init()
      {
        set_waveform_generation_mode(fast_pwm_input_top);
        set_input_capture(40000);
        set_prescaler(8);
        set_compare(1500);
        set_compare_output_mode(non_inverting);
      }
      /*
        Set compare output for all channels
       */

      void set_compare_output_mode(compare_output_mode mode)
      {
        set_compare_output_mode(mode, output_channel::A);
        set_compare_output_mode(mode, output_channel::B);
        set_compare_output_mode(mode, output_channel::C);
      }
      /*
        Set compare output for specific channel
       */
      void set_compare_output_mode(compare_output_mode mode, output_channel channel)
      {
        if (channel == A)
        {
          switch (mode)
          {
          case normal_compare:
            *config::TCCRA |= (0 << COM1A1) | (0 << COM1A0);
            break;
          case toggle:
            *config::TCCRA |= (0 << COM1A1) | (1 << COM1A0);
            break;
          case non_inverting:
            *config::TCCRA |= (1 << COM1A1) | (0 << COM1A0);
            break;
          case inverting:
            *config::TCCRA |= (1 << COM1A1) | (1 << COM1A0);
            break;
          default:
            *config::TCCRA |= (0 << COM1A1) | (0 << COM1A0);
            break;
          }
        }
        if (channel == B)
        {
          switch (mode)
          {
          case normal_compare:
            *config::TCCRA |= (0 << COM1B1) | (0 << COM1B0);
            break;
          case toggle:
            *config::TCCRA |= (0 << COM1B1) | (1 << COM1B0);
            break;
          case non_inverting:
            *config::TCCRA |= (1 << COM1B1) | (0 << COM1B0);
            break;
          case inverting:
            *config::TCCRA |= (1 << COM1B1) | (1 << COM1B0);
            break;
          default:
            *config::TCCRA |= (0 << COM1B1) | (0 << COM1B0);
            break;
          }
        }
        if (channel == C)
        {
          switch (mode)
          {
          case normal_compare:
            *config::TCCRA |= (0 << COM1C1) | (0 << COM1C0);
            break;
          case toggle:
            *config::TCCRA |= (0 << COM1C1) | (1 << COM1C0);
            break;
          case non_inverting:
            *config::TCCRA |= (1 << COM1C1) | (0 << COM1C0);
            break;
          case inverting:
            *config::TCCRA |= (1 << COM1C1) | (1 << COM1C0);
            break;
          default:
            *config::TCCRA |= (0 << COM1C1) | (0 << COM1C0);
            break;
          }
        }
      }
      /*
        Set waveform generation mode
       */

      void set_waveform_generation_mode(waveform_mode mode)
      {
        switch (mode)
        {
        case normal_waveform:
          *config::TCCRA |= (0 << WGM11) | (0 << WGM10);
          *config::TCCRB |= (0 << WGM13) | (0 << WGM12);
          break;
        case pwm_phase_correct_8bit:
          *config::TCCRA |= (0 << WGM11) | (1 << WGM10);
          *config::TCCRB |= (0 << WGM13) | (0 << WGM12);
          break;
        case pwm_phase_correct_9bit:
          *config::TCCRA |= (1 << WGM11) | (0 << WGM10);
          *config::TCCRB |= (0 << WGM13) | (0 << WGM12);
          break;
        case pwm_phase_correct_10bit:
          *config::TCCRA |= (1 << WGM11) | (1 << WGM10);
          *config::TCCRB |= (0 << WGM13) | (0 << WGM12);
          break;
        case ctc_compare_top:
          *config::TCCRA |= (0 << WGM11) | (0 << WGM10);
          *config::TCCRB |= (0 << WGM13) | (1 << WGM12);
          break;
        case fast_pwm_8bit:
          *config::TCCRA |= (0 << WGM11) | (1 << WGM10);
          *config::TCCRB |= (0 << WGM13) | (1 << WGM12);
          break;
        case fast_pwm_9bit:
          *config::TCCRA |= (1 << WGM11) | (0 << WGM10);
          *config::TCCRB |= (0 << WGM13) | (1 << WGM12);
          break;
        case fast_pwm_10bit:
          *config::TCCRA |= (1 << WGM11) | (1 << WGM10);
          *config::TCCRB |= (0 << WGM13) | (1 << WGM12);
          break;
        case pwm_phase_freq_correct_input_top:
          *config::TCCRA |= (0 << WGM11) | (0 << WGM10);
          *config::TCCRB |= (1 << WGM13) | (0 << WGM12);
          break;
        case pwm_phase_freq_correct_compare_top:
          *config::TCCRA |= (0 << WGM11) | (1 << WGM10);
          *config::TCCRB |= (1 << WGM13) | (0 << WGM12);
          break;
        case pwm_phase_correct_input_top:
          *config::TCCRA |= (0 << WGM11) | (1 << WGM10);
          *config::TCCRB |= (1 << WGM13) | (0 << WGM12);
          break;
        case pwm_phase_correct_compare_top:
          *config::TCCRA |= (1 << WGM11) | (1 << WGM10);
          *config::TCCRB |= (1 << WGM13) | (0 << WGM12);
          break;
        case ctc_input_top:
          *config::TCCRA |= (0 << WGM11) | (0 << WGM10);
          *config::TCCRB |= (1 << WGM13) | (1 << WGM12);
          break;
        case fast_pwm_input_top:
          *config::TCCRA |= (1 << WGM11) | (0 << WGM10);
          *config::TCCRB |= (1 << WGM13) | (1 << WGM12);
          break;
        case fast_pwm_compare_top:
          *config::TCCRA |= (1 << WGM11) | (1 << WGM10);
          *config::TCCRB |= (1 << WGM13) | (1 << WGM12);
          break;
        default:
          break;
        }
      }

      /*
         Set prescaler to prefered value
         Input options are 0, 1, 8, 64, 256 and 1024
       */
      void set_prescaler(uint16_t prescaler)
      {
        switch (prescaler)
        {
        case 0:
          *config::TCCRB |= (0 << CS12) | (0 << CS11) | (0 << CS10);
          break;
        case 1:
          *config::TCCRB |= (0 << CS12) | (0 << CS11) | (1 << CS10);
          break;
        case 8:
          *config::TCCRB |= (0 << CS12) | (1 << CS11) | (0 << CS10);
          break;
        case 64:
          *config::TCCRB |= (0 << CS12) | (1 << CS11) | (1 << CS10);
          break;
        case 256:
          *config::TCCRB |= (1 << CS12) | (0 << CS11) | (0 << CS10);
          break;
        case 1024:
          *config::TCCRB |= (1 << CS12) | (0 << CS11) | (1 << CS10);
          break;

        default:
          *config::TCCRB |= (0 << CS12) | (0 << CS11) | (0 << CS10);
          break;
        }
      }
      /*
        Set compare value for specfic channel
       */
      void set_compare(uint16_t value, output_channel output)
      {
        switch (output)
        {
        case A:
          *config::OCRA = value;
          break;
        case B:
          *config::OCRB = value;
          break;
        case C:
          *config::OCRC = value;
          break;

        default:
          break;
        }
      }
      /*
        Set compare value for all channels
        */
      void set_compare(uint16_t value)
      {
        set_compare(value, output_channel::A);
        set_compare(value, output_channel::B);
        set_compare(value, output_channel::C);
      }

      void set_input_capture(uint16_t value)
      {
        *config::ICR |= value;
      }
      /*
        Enable interrupt type
        Input options are
         - input_capture
         - output_compare_c
         - output_compare_b
         - output_compare_a
         - timer_overflow

       */
      void interrupt_type_enable(interrupt_type value)
      {
        // sei();
        switch (value)
        {
        case input_capture:
          *config::TIMSK |= (1 << ICIE1);
          break;
        case output_compare_c:
          *config::TIMSK |= (1 << OCIE1C);
          break;
        case output_compare_b:
          *config::TIMSK |= (1 << OCIE1B);
          break;
        case output_compare_a:
          *config::TIMSK |= (1 << OCIE1A);
          break;
        case timer_overflow:
          *config::TIMSK |= (1 << TOIE1);
          break;
        default:
          break;
        }
      }
      /*
       Disable interrupt type
       Input options are
        - input_capture
        - output_compare_c
        - output_compare_b
        - output_compare_a
        - timer_overflow

      */
      void interrupt_type_disable(interrupt_type type)
      {
        switch (type)
        {
        case input_capture:
          *config::TIMSK |= (0 << ICIE1);
          break;
        case output_compare_c:
          *config::TIMSK |= (0 << OCIE1C);
          break;
        case output_compare_b:
          *config::TIMSK |= (0 << OCIE1B);
          break;
        case output_compare_a:
          *config::TIMSK |= (0 << OCIE1A);
          break;
        case timer_overflow:
          *config::TIMSK |= (0 << TOIE1);
          break;
        default:
          break;
        }
      }

      /* Timer enable pwm channel A, B or C*/
      void enable_pwm_pin(output_channel output)
      {
        switch (output)
        {
        case A:
          *config::DDR |= config::CHANNEL_A;
          break;
        case B:
          *config::DDR |= config::CHANNEL_B;
          break;
        case C:
          *config::DDR |= config::CHANNEL_C;
          break;

        default:
          break;
        }
      }

    private:
      Device() {}  // no one else can create one
      ~Device() {} // prevent accidental deletion
    };

  } // namespace Time
} // namespace MEGA2560