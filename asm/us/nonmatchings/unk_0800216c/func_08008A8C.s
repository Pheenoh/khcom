.syntax unified
	.align 2, 0
	.global func_08008A8C
	.thumb
	.thumb_func
	.type func_08008A8C, %function
func_08008A8C: @ 08008A8C
	push {r4, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r4, #0x00
	b _08008AA4
_08008A98:
	ldrh r0, [r3, #0x00]
	adds r4, r4, r0
	adds r3, #0x02
	ldr r1, _08008AD0 @ =0xFFFE0000
	adds r0, r2, r1
	lsrs r1, r0, #0x10
_08008AA4:
	lsls r2, r1, #0x10
	asrs r0, r2, #0x10
	cmp r0, #0x01
	bgt _08008A98
	lsls r0, r1, #0x10
	cmp r0, #0x00
	ble _08008AB6
	ldrb r0, [r3, #0x00]
	adds r4, r4, r0
_08008AB6:
	ldr r0, _08008AD4 @ =0x0000FFFF
	ands r0, r4
	lsrs r1, r4, #0x10
	adds r4, r0, r1
	lsrs r0, r4, #0x10
	adds r0, r4, r0
	mvns r0, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08008AD0: .4byte 0xFFFE0000
_08008AD4: .4byte 0x0000FFFF
.syntax divided
