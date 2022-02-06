#pragma once
#include <stdint.h>
#include <stddef.h>
#include "interface_uart.hpp"
#include "uart_configs.hpp"
#include "uart_status.hpp"
#include <util/delay.h>

namespace MEGA2560
{
  namespace UART
  {
    constexpr uint32_t f_cpu = 16000000;
    template <typename config>
    class Device
    {
    public:
      static Device &instance()
      {
        static Device instance;
        return instance;
      }
      // disable copy/move -- this is a Singleton
      Device(const Device &) = delete;
      Device(Device &&) = delete;
      Device &operator=(const Device &) = delete;
      Device &operator=(Device &&) = delete;

      void init_uart(uint32_t baudrate, uint8_t data_bits, uint8_t parity)
      {
        if ((baudrate >= 300) && (baudrate <= 115200) && (data_bits >= 5) && (data_bits <= 8))
        {
          *config::UCSRA = 0b00100000;
          *config::UCSRB = 0b00011000;
          // Asynchronous operation, 1 stop bit
          *config::UCSRC = (data_bits - 5) << 1;
          // Set parity bits (if parity used)
          if (parity == 0)
            *config::UCSRC |= 0b00000000;
          else if (parity == 1)
            *config::UCSRC |= 0b00010000;
          else if (parity == 2)
            *config::UCSRC |= 0b00100000;
          else if (parity == 3)
            *config::UCSRC |= 0b00110000;

          // Set Baud Rate according to the parameter baudrate:
          // Adding (8*baudrate) ensures correct rounding (up/down)
          *config::UBRR = (f_cpu / (16 * baudrate) - 1);
        }
      }

      uint8_t receive(uint32_t timeout)
      {
        // non optimal timeout - but it works for now
        for (size_t i = 0; i < timeout; i++)
        {
          while ((*config::UCSRA & (1 << 7)))
          {
            return *config::UDR;
          }
          _delay_us(1000);
        }
        return 0;
      };
      void write(uint8_t data)
      {
        // Wait for transmitter register empty (ready for new character)
        while (!(*config::UCSRA & (1 << 5)))
        {
        }
        // Then send the character
        *config::UDR = data;
      };

    private:
      Device() {}
      ~Device() {}
    };

  } // namespace UART
} // namespace MEGA2560
