.syntax unified
	.align 2, 0
	.global ClearModM
	.thumb
	.thumb_func
	.type ClearModM, %function
ClearModM: @ 0812103C
	push {lr}
	adds r2, r0, #0x0
	movs r1, #0x00
	movs r0, #0x00
	strb r0, [r2, #0x1A]
	strb r0, [r2, #0x16]
	ldrb r0, [r2, #0x18]
	cmp r0, #0x00
	bne _08121054
	ldrb r0, [r2, #0x00]
	movs r1, #0x0C
	b _08121058
_08121054:
	ldrb r0, [r2, #0x00]
	movs r1, #0x03
_08121058:
	orrs r0, r1
	strb r0, [r2, #0x00]
	pop {r0}
	bx r0
.syntax divided
