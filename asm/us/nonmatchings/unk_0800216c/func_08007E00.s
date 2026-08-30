.syntax unified
	.align 2, 0
	.global func_08007E00
	.thumb
	.thumb_func
	.type func_08007E00, %function
func_08007E00: @ 08007E00
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r6, r2, #0x0
	ldr r1, _08007E24 @ =0x03007570
	ldrh r3, [r1, #0x00]
	movs r7, #0x00
	ldsh r0, [r1, r7]
	cmp r0, #0x00
	bne _08007E28
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_08007D74
	b _08007E48
	.byte 0x00, 0x00
_08007E24: .4byte 0x03007570
_08007E28:
	cmp r0, #0x00
	blt _08007E38
	ldrh r3, [r1, #0x00]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_08007C50
	b _08007E48
_08007E38:
	negs r3, r3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_08007A10
_08007E48:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
