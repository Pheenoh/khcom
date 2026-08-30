.syntax unified
	.align 2, 0
	.global func_080E02C0
	.thumb
	.thumb_func
	.type func_080E02C0, %function
func_080E02C0: @ 080E02C0
	push {r4, r5, lr}
	ldr r5, _080E02DC @ =0x0203C7AC
	ldr r3, [r5, #0x00]
	adds r3, #0x20
	movs r4, #0x01
	strb r4, [r3, #0x00]
	ldr r3, [r5, #0x00]
	str r0, [r3, #0x24]
	str r1, [r3, #0x28]
	str r2, [r3, #0x2C]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E02DC: .4byte 0x0203C7AC
.syntax divided
