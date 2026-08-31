.syntax unified
	.align 2, 0
	.global func_08104FA4
	.thumb
	.thumb_func
	.type func_08104FA4, %function
func_08104FA4: @ 08104FA4
	push {r4, r5, lr}
	add sp, #-0x004
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	adds r2, #0xC0
	ldr r0, _08104FEC @ =0x02035C38
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r5, _08104FF0 @ =0x09A1DB9C
	movs r4, #0x03
	str r4, [sp, #0x000]
	adds r1, r5, #0x0
	movs r3, #0x20
	bl func_08101588
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	movs r0, #0x90
	lsls r0, r0, #0x01
	adds r2, r2, r0
	ldr r0, _08104FF4 @ =0x02035C3C
	ldrh r0, [r0, #0x00]
	str r4, [sp, #0x000]
	adds r1, r5, #0x0
	movs r3, #0x20
	bl func_08101588
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08104FEC: .4byte 0x02035C38
_08104FF0: .4byte 0x09A1DB9C
_08104FF4: .4byte 0x02035C3C
.syntax divided
