.syntax unified
	.align 2, 0
	.global func_080A40EC
	.thumb
	.thumb_func
	.type func_080A40EC, %function
func_080A40EC: @ 080A40EC
	adds r1, r0, #0x0
	ldr r0, _080A40FC @ =0x02034AFC
	ldr r3, [r0, #0x00]
	cmp r3, #0x00
	bne _080A4100
	movs r0, #0x00
	b _080A4118
	.byte 0x00, 0x00
_080A40FC: .4byte 0x02034AFC
_080A4100:
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r0, r3, r2
	ldr r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	str r2, [r0, #0x04]
	movs r0, #0xA7
	lsls r0, r0, #0x01
	adds r1, r3, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080A4118:
	bx lr
	.byte 0x00, 0x00
.syntax divided
