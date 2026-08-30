.syntax unified
	.align 2, 0
	.global func_081055E8
	.thumb
	.thumb_func
	.type func_081055E8, %function
func_081055E8: @ 081055E8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	movs r1, #0x00
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	cmp r1, r2
	bge _08105632
	ldr r0, _08105620 @ =0x02035C10
	ldr r5, [r0, #0x00]
	adds r4, r2, #0x0
_08105602:
	lsls r1, r1, #0x10
	asrs r2, r1, #0x10
	movs r0, #0x34
	muls r0, r2
	adds r3, r0, r5
	ldrh r0, [r3, #0x00]
	cmp r0, r7
	bne _08105624
	adds r0, r3, #0x0
	adds r0, #0x2E
	ldrb r0, [r0, #0x00]
	cmp r0, r6
	bne _08105624
	adds r0, r2, #0x0
	b _08105636
_08105620: .4byte 0x02035C10
_08105624:
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r1, r2
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r4
	blt _08105602
_08105632:
	movs r0, #0x01
	negs r0, r0
_08105636:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
