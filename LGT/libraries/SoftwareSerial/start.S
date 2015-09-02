
#if __AVR_MEGA__
  #define XJMP jmp
  #define XCALL call
#else
  #define XJMP rjmp
  #define XCALL rcall
#endif

.section .vectors,"ax",@progbits
	.weak __vector_26
	;.set __vector_17, __bad_interrupt
	XJMP  __vector_26
	.weak __vector_27
	;.set __vector_18, __bad_interrupt
	XJMP  __vector_27
	.weak __vector_28
	;.set __vector_17, __bad_interrupt
	XJMP  __vector_28
	.weak __vector_29
	;.set __vector_18, __bad_interrupt
	XJMP  __vector_29
 
