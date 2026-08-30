.syntax unified
	.align 2, 0
	.global func_08065B08
	.thumb
	.thumb_func
	.type func_08065B08, %function
func_08065B08: @ 08065B08
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r3, #0x00
	movs r5, #0x00
	cmp r3, r4
	bge _08065B48
	movs r6, #0x01
	negs r6, r6
	adds r2, r0, #0x0
_08065B1C:
	ldr r0, [r2, #0x00]
	cmp r0, #0x00
	beq _08065B48
	movs r0, #0x05
	ldsb r0, [r2, r0]
	cmp r0, r6
	bne _08065B34
	lsls r0, r3, #0x10
	movs r1, #0xC0
	lsls r1, r1, #0x0A
	adds r0, r0, r1
	b _08065B3E
_08065B34:
	adds r1, r0, #0x0
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
_08065B3E:
	lsrs r3, r0, #0x10
	adds r2, #0x08
	adds r5, #0x01
	cmp r5, r4
	blt _08065B1C
_08065B48:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
