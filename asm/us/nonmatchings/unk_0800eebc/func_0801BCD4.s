.syntax unified
	.align 2, 0
	.global func_0801BCD4
	.thumb
	.thumb_func
	.type func_0801BCD4, %function
func_0801BCD4: @ 0801BCD4
	adds r3, r0, #0x0
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ldr r2, _0801BCF0 @ =0x00007202
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801BCEE
	ldr r0, _0801BCF4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xAC
	str r3, [r0, #0x00]
_0801BCEE:
	bx lr
_0801BCF0: .4byte 0x00007202
_0801BCF4: .4byte 0x02039B84
.syntax divided
