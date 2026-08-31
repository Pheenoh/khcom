.syntax unified
	.align 2, 0
	.global func_080E0960
	.thumb
	.thumb_func
	.type func_080E0960, %function
func_080E0960: @ 080E0960
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	cmp r6, #0x00
	beq _080E09A6
	ldr r0, _080E09AC @ =0x02034F34
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x18]
	lsls r4, r7, #0x02
	ldr r0, _080E09B0 @ =0x0984D314
	adds r4, r4, r0
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #0x03]
	bl __modsi3
	lsls r0, r0, #0x18
	movs r1, #0xE0
	lsls r1, r1, #0x13
	ands r1, r0
	lsrs r1, r1, #0x18
	ldrb r2, [r4, #0x01]
	adds r1, r1, r2
	lsls r1, r1, #0x02
	lsrs r0, r0, #0x1B
	ldrb r4, [r4, #0x02]
	adds r0, r0, r4
	strb r7, [r6, #0x03]
	lsls r0, r0, #0x06
	adds r0, r0, r1
	lsls r0, r0, #0x01
	adds r5, r5, r0
	str r5, [r6, #0x14]
_080E09A6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E09AC: .4byte 0x02034F34
_080E09B0: .4byte 0x0984D314
.syntax divided
