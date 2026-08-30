.syntax unified
	.align 2, 0
	.global func_08041FCC
	.thumb
	.thumb_func
	.type func_08041FCC, %function
func_08041FCC: @ 08041FCC
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x38
	movs r6, #0x00
	str r6, [r5, #0x10]
	adds r0, #0x3C
	adds r1, r4, #0x0
	adds r1, #0x40
	adds r2, r4, #0x0
	adds r2, #0x44
	adds r3, r4, #0x0
	adds r3, #0x48
	bl func_0801C6D4
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r5, #0x0C]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldr r0, [r2, #0x00]
	adds r0, #0x33
	str r0, [r2, #0x00]
	ldr r0, [r5, #0x0C]
	ldr r1, [r5, #0x10]
	cmp r0, r1
	bgt _0804200A
	movs r0, #0x00
	b _08042010
_0804200A:
	str r1, [r5, #0x0C]
	str r6, [r2, #0x00]
	movs r0, #0x01
_08042010:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
