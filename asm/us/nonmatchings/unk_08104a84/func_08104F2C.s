.syntax unified
	.align 2, 0
	.global func_08104F2C
	.thumb
	.thumb_func
	.type func_08104F2C, %function
func_08104F2C: @ 08104F2C
	push {r4, lr}
	add sp, #-0x004
	bl func_08101518
	adds r4, r0, #0x0
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	adds r2, #0x20
	ldr r1, _08104F70 @ =0x09A1DB9C
	movs r0, #0x05
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r3, #0x20
	bl func_08101588
	ldr r0, _08104F74 @ =0x02035C16
	ldrh r0, [r0, #0x00]
	subs r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bhi _08104F78
	bl func_08104AEC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_08104ED8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08104F7A
	.byte 0x00, 0x00
_08104F70: .4byte 0x09A1DB9C
_08104F74: .4byte 0x02035C16
_08104F78:
	movs r4, #0x00
_08104F7A:
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r2, r2, r0
	ldr r1, _08104FA0 @ =0x09A1DCDC
	movs r0, #0x02
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r3, #0x20
	bl func_08101588
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08104FA0: .4byte 0x09A1DCDC
.syntax divided
