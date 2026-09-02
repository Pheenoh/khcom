.syntax unified
	.align 2, 0
	.global func_08093F1C
	.thumb
	.thumb_func
	.type func_08093F1C, %function
func_08093F1C: @ 08093F1C
	push {r4, lr}
	movs r3, #0x04
	ldr r2, _08093F44 @ =0x0000029D
	adds r1, r0, r2
	movs r2, #0x00
	ldsb r2, [r1, r2]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	movs r4, #0xB4
	lsls r4, r4, #0x02
	adds r2, r0, r4
_08093F32:
	adds r0, r3, r1
	adds r0, r2, r0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08093F48
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	b _08093F56
	.byte 0x00, 0x00
_08093F44: .4byte 0x0000029D
_08093F48:
	subs r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x00
	bne _08093F32
	movs r0, #0x01
	negs r0, r0
_08093F56:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
