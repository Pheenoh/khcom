.syntax unified
	.align 2, 0
	.global func_0807B3E0
	.thumb
	.thumb_func
	.type func_0807B3E0, %function
func_0807B3E0: @ 0807B3E0
	ldr r0, _0807B3EC @ =0x02039DD4
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0807B3F0
	movs r0, #0x00
	b _0807B3F4
_0807B3EC: .4byte 0x02039DD4
_0807B3F0:
	adds r0, #0xD3
	ldrb r0, [r0, #0x00]
_0807B3F4:
	bx lr
	.byte 0x00, 0x00
.syntax divided
