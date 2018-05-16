#ifndef COMMON_MACROS
#define COMMON_MACROS

/* set certain bit to one */
#define SET_BIT(REG,BIT)( (REG) = (REG) | ( 1<<(BIT) ) )

/* clear certain bit */
#define CLEAR_BIT(REG,BIT) ( (REG) = ~( (REG) & ( 1<<(BIT) )  )

/* Toggle bit */
#define TOGGLE_BIT(REG,BIT) ( (REG) = (REG) ^ (1<<(REG)) )

/* rotate 8_bit number right */
#define ROTATE_RIGHT(REG,BIT) ( (REG) = ( (REG)>>(BIT) ) | ( (REG)<<(8-BIT) )  )

/* rotate 8_bit number left */
#define ROTATE_LEFT(REG,BIT) ( (REG) = ( (REG)<<(BIT) ) | ( (BIT)<<(8-BIT) )  )

/* check if specific bit is set to one
 * return true if yes
 */
#define BIT_IS_SET(REG,BIT) ( (REG) & ( 1<<(BIT) ) )

/* check if specific bit is cleared
 * return true if yes
 */
#define BIT_IS_CLEARED(REG,BIT) ( !( (REG) & (1<<(BIT)) ) )

#endif
