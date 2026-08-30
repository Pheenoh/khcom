.syntax unified
	.align 2, 0
	.global func_080791C0
	.thumb
	.thumb_func
	.type func_080791C0, %function
func_080791C0: @ 080791C0
	ldr r0, _08079208 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x90
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08079206
	ldr r1, _0807920C @ =0x02039B9C
	ldr r0, [r1, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x30
	bne _08079206
	ldr r0, _08079210 @ =0x02034A98
	ldr r0, [r0, #0x00]
	adds r3, r0, #0x0
	adds r3, #0xA5
	ldrb r2, [r3, #0x00]
	cmp r2, #0x00
	beq _080791FC
	ldr r0, _08079214 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xC2
	ldrb r0, [r0, #0x00]
	subs r0, r2, r0
	strb r0, [r3, #0x00]
_080791FC:
	ldr r1, [r1, #0x00]
	adds r1, #0xF8
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_08079206:
	bx lr
_08079208: .4byte 0x02039B84
_0807920C: .4byte 0x02039B9C
_08079210: .4byte 0x02034A98
_08079214: .4byte 0x02039DD4
.syntax divided
