.syntax unified
	.align 2, 0
	.global func_08000B6C
	.thumb
	.thumb_func
	.type func_08000B6C, %function
func_08000B6C: @ 08000B6C
	push {r4, lr}
	adds r4, r1, #0x0
	ldr r3, [r0, #0x04]
	cmp r3, #0x00
	bne _08000B8A
	ldr r1, [r0, #0x08]
	cmp r1, #0x00
	bne _08000B82
	str r3, [r4, #0x00]
	str r3, [r2, #0x00]
	b _08000B9E
_08000B82:
	str r3, [r1, #0x04]
	ldr r0, [r0, #0x08]
	str r0, [r4, #0x00]
	b _08000B9E
_08000B8A:
	ldr r1, [r0, #0x08]
	cmp r1, #0x00
	bne _08000B96
	str r3, [r2, #0x00]
	str r1, [r3, #0x08]
	b _08000B9E
_08000B96:
	str r3, [r1, #0x04]
	ldr r1, [r0, #0x04]
	ldr r0, [r0, #0x08]
	str r0, [r1, #0x08]
_08000B9E:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
