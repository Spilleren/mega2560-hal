#pragma once

#include <stdint.h>
#include "settings.hpp"
#include "timer_configs.hpp"
namespace MEGA2560
{
  namespace Timer
  {
    class InterfaceTimer
    {
    public:
      virtual void init() = 0;
      virtual void set_compare_output_mode(compare_output_mode mode, output_channel value) = 0;
      virtual void set_waveform_generation_mode(waveform_mode mode) = 0;
      virtual void set_prescaler(uint16_t prescaler) = 0;
      virtual void set_compare(uint16_t value, output_channel output) = 0;
      virtual void set_compare(uint16_t value) = 0;
      virtual void set_input_capture(uint16_t value) = 0;
      virtual void interrupt_type_enable(interrupt_type value) = 0;
      virtual void interrupt_type_disable(interrupt_type value) = 0;
      virtual void enable_pwm_pin(output_channel output) = 0;
    };
  } // namespace Timer
} // namespace MEGA2560