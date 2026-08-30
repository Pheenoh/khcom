.syntax unified
	.align 2, 0
	.global func_08115F8C
	.thumb
	.thumb_func
	.type func_08115F8C, %function
func_08115F8C: @ 08115F8C
	push {r4, r5, r6, lr}
	adds r5, r2, #0x0
	adds r6, r3, #0x0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r4, #0x00
	cmp r5, #0x00
	beq _08115FAC
	bl func_08115F34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	bcs _08115FAC
	adds r0, r5, r0
	ldrb r4, [r0, #0x00]
_08115FAC:
	cmp r4, #0x00
	bne _08115FB2
	movs r4, #0x08
_08115FB2:
	adds r0, r4, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
