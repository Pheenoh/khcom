	.include "gba_constants.inc"

	.syntax unified
	.arm
	.section .text

	.global EntryPoint
EntryPoint:
	mov r0, #PSR_IRQ_MODE
	msr cpsr_fc, r0
	ldr sp, sp_irq
	mov r0, #PSR_SYS_MODE
	msr cpsr_fc, r0
	ldr sp, sp_sys
	ldr r1, intr_vector
	adr r0, IrqHandler
	str r0, [r1]
	ldr r1, agb_main
	mov lr, pc
	bx r1
	b EntryPoint

sp_sys:
	.word IWRAM_END - 0x1A0
sp_irq:
	.word IWRAM_END - 0x60

	.global IrqHandler
IrqHandler:
	mov r3, #REG_BASE
	add r3, r3, #OFFSET_REG_IE
	ldr r2, [r3]
	ldrh r1, [r3, #OFFSET_REG_IME - OFFSET_REG_IE]
	mrs r0, spsr
	stmfd sp!, {r0-r3, lr}
	mov r0, #1
	strh r0, [r3, #OFFSET_REG_IME - OFFSET_REG_IE]
	and r1, r2, r2, lsr #16
	mov ip, #0
	ands r0, r1, #INTR_FLAG_SERIAL
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_VBLANK
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_HBLANK
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_VCOUNT
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_TIMER0
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_TIMER1
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_TIMER2
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_TIMER3
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_DMA0
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_DMA1
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_DMA2
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_DMA3
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_KEYPAD
	bne IrqHandler_Dispatch
	add ip, ip, #4
	ands r0, r1, #INTR_FLAG_GAMEPAK
	strbne r0, [r3, #OFFSET_REG_SOUNDCNT_X - OFFSET_REG_IE]
IrqHandler_Hang:
	bne IrqHandler_Hang

IrqHandler_Dispatch:
	strh r0, [r3, #OFFSET_REG_IF - OFFSET_REG_IE]
	ldr r1, intr_nest_mask
	bic r2, r2, r0
	and r1, r1, r2
	strh r1, [r3]
	mrs r3, cpsr
	bic r3, r3, #PSR_MODE_MASK
	orr r3, r3, #PSR_SYS_MODE
	msr cpsr_fc, r3
	ldr r1, intr_table
	add r1, r1, ip
	ldr r0, [r1]
	stmfd sp!, {lr}
	adr lr, IrqHandler_Return
	bx r0
IrqHandler_Return:
	ldmfd sp!, {lr}
	mrs r3, cpsr
	bic r3, r3, #PSR_MODE_MASK
	orr r3, r3, #PSR_I_BIT | PSR_IRQ_MODE
	msr cpsr_fc, r3
	ldmfd sp!, {r0-r3, lr}
	strh r2, [r3]
	strh r1, [r3, #OFFSET_REG_IME - OFFSET_REG_IE]
	msr spsr_fc, r0
	bx lr

intr_vector:
	.word INTR_VECTOR
agb_main:
	.word AgbMain + 1
intr_nest_mask:
	.word INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL | INTR_FLAG_GAMEPAK
intr_table:
	.word INTR_TABLE
