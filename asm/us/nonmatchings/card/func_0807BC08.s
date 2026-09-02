.syntax unified
	.align 2, 0
	.global func_0807BC08
	.thumb
	.thumb_func
	.type func_0807BC08, %function
func_0807BC08: @ 0807BC08
	ldr r0, _0807BC20 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x32
	bne _0807BC1E
	adds r1, #0xF8
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_0807BC1E:
	bx lr
_0807BC20: .4byte 0x02039B84
.syntax divided
