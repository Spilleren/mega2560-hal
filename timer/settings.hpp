#pragma once

namespace MEGA2560
{
  namespace Timer
  {
    enum compare_output_mode
    {
      normal_compare,
      toggle,
      non_inverting,
      inverting,
    };
    enum output_channel
    {
      A,
      B,
      C,
    };

    enum interrupt_type
    {
      input_capture,
      output_compare_c,
      output_compare_b,
      output_compare_a,
      timer_overflow,
    };

    enum waveform_mode
    {
      normal_waveform,
      pwm_phase_correct_8bit,
      pwm_phase_correct_9bit,
      pwm_phase_correct_10bit,
      ctc_compare_top,
      fast_pwm_8bit,
      fast_pwm_9bit,
      fast_pwm_10bit,
      pwm_phase_freq_correct_input_top,
      pwm_phase_freq_correct_compare_top,
      pwm_phase_correct_input_top,
      pwm_phase_correct_compare_top,
      ctc_input_top,
      fast_pwm_input_top,
      fast_pwm_compare_top,
    };

  } // namespace Timer
} // namespace MEGA2560
