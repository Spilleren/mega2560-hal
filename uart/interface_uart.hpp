#pragma once
#include <stdint.h>

namespace MEGA2560
{
  namespace UART
  {
    class InterfaceUart
    {
    public:
      virtual void init_uart(uint32_t baudrate, uint8_t data_bits, uint8_t parity) = 0;
      virtual uint8_t receive() = 0;
      virtual void write(uint8_t *data) = 0;
    };

  } // namespace UART
} // namespace MEGA2560
