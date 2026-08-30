.syntax unified
	.align 2, 0
	.global func_080E8D00
	.thumb
	.thumb_func
	.type func_080E8D00, %function
func_080E8D00: @ 080E8D00
	ldr r0, _080E8D14 @ =0x02034F7C
	ldr r2, [r0, #0x00]
	ldr r0, _080E8D18 @ =0x02034F84
	ldr r1, [r0, #0x00]
	ldrb r0, [r2, #0x00]
	ldrb r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bx lr
_080E8D14: .4byte 0x02034F7C
_080E8D18: .4byte 0x02034F84
.syntax divided
