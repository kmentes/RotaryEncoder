#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>
#include <stdint.h>
#define DIRECTION_NONE 0
#define DIRECTION_CCW 1
#define DIRECTION_CW 2

class RotaryEncoder {
  public:
  /**
   * @brief Instantiate the RotaryEncoder library.
   * 
   * @param[in] pinA The pin number to which pin A of the rotary encoder is connected to.
   * @param[in] pinB The pin number to which pin B of the rotary encoder is connected to.
   */
  RotaryEncoder(uint16_t pinA, uint16_t pinB);
  /**
   * @brief Start the encoder library.
   *
   * @param callback A callback to when an interrupt occurs on either pin A or B.
   *        This function has to call handle_encoder on the RotaryEncoder instance.
   *        @code
   *		void myRotaryEncoderCallback()
   *		{
   *			uint8_t state = myRotaryEncoder.handle_encoder();
   *			swith(state) {
   *				case DIRECTION_NONE:
   *					break;
   *				case DIRECTION_CCW:
   *					count--;
   *					break;
   *				case DIRECTION_CW:
   *					count++;
   *				default:
   *					break;
   *			}
   *		}
   *		@endcode
   *
   */
  void begin(void (*callback)(void)=NULL);
  /**
   * @brief Callback to be called from the user specified callback in begin().
   *
   * This function must be called from supplied user callback function specified in.
   *
   * @return The state of the encoder.
   *               - `DIRECTION_NONE` if the encoder is stationary.
   *               - `DIRECTION_CCW` if the encoder was turned counter clockwise.
   *               - `DIRECTION_CW` if the encoder was turned clockwise.
   *
   */
  uint8_t handle_encoder();
  private:
  void (*_callback)(void);
  uint16_t PINA_IFG;
  uint16_t PINB_IFG;
  uint16_t PINA_MASK;
  uint16_t PINB_MASK;
  uint16_t PINA_BIT;
  uint16_t PINB_BIT;
  uint16_t PINA_SHIFT;
  uint16_t PINB_SHIFT;
  uint16_t PORTA;
  uint16_t PORTB;
  
  uint16_t _pinA;
  uint16_t _pinB;  
};

#endif
