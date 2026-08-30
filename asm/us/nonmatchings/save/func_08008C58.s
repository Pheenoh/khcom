.syntax unified
	.align 2, 0
	.global func_08008C58
	.thumb
	.thumb_func
	.type func_08008C58, %function
func_08008C58: @ 08008C58
	push {r4, r5, r6, lr}
	movs r6, #0x00
	movs r0, #0x40
	bl func_08000918
	adds r5, r0, #0x0
	movs r0, #0x00
	b _08008C6E
_08008C68:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_08008C6E:
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x01
	bgt _08008C94
	lsls r0, r4, #0x06
	ldr r1, _08008CA4 @ =0x0E000010
	adds r0, r0, r1
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	movs r3, #0x40
	bl func_08008AD8
	adds r6, r0, #0x0
	cmp r6, #0x02
	bne _08008C68
	adds r0, r5, #0x0
	adds r0, #0x1C
	bl func_0805A104
_08008C94:
	adds r0, r5, #0x0
	bl func_080009C4
	adds r0, r6, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08008CA4: .4byte 0x0E000010
.syntax divided
