#include "../timer/timer.hpp"
#include "../uart/uart.hpp"

using namespace MEGA2560;

using Timer1 = Timer::Device<Timer::Timer1Config>;

int main()
{
  /*
    Creating a reference to the instance of the Timer or Uart objects is done so
    It is possible to define a timer using the c++ 'using' keyword as seen above
    or simply parse the right config as the template parameter
   */
  auto &timer1 = Timer1::instance();
  auto &timer2 = Timer::Device<Timer::Timer3Config>::instance();
  auto &uart0 = UART::Device<UART::Uart0Config>::instance();

  uart0.init_uart(115200, 8, 0);
  timer1.init();
  timer1.enable_pwm_pin(Timer::A);
  uint8_t data = uart0.receive(10);
  uart0.write(data);

  return 0;
}