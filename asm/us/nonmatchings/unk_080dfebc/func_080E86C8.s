.syntax unified
	.align 2, 0
	.global func_080E86C8
	.thumb
	.thumb_func
	.type func_080E86C8, %function
func_080E86C8: @ 080E86C8
	push {r4, r5, lr}
	adds r3, r0, #0x0
	cmp r3, #0x00
	bne _080E86D4
	movs r0, #0x01
	b _080E871C
_080E86D4:
	asrs r1, r1, #0x08
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080E86DE
	adds r0, #0x1F
_080E86DE:
	asrs r0, r0, #0x05
	lsls r0, r0, #0x05
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r2, r2, #0x08
	adds r4, r2, #0x0
	cmp r2, #0x00
	bge _080E86F2
	adds r4, #0x0F
_080E86F2:
	asrs r4, r4, #0x04
	lsls r4, r4, #0x04
	subs r4, r2, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r3, #0x10]
	adds r1, r5, #0x0
	adds r2, r4, #0x0
	bl func_080E8644
	movs r1, #0x07
	adds r2, r5, #0x0
	ands r2, r1
	ands r4, r1
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	movs r1, #0x07
	subs r1, r1, r2
	asrs r0, r1
	movs r1, #0x01
	ands r0, r1
_080E871C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
