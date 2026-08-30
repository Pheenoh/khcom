.syntax unified
	.align 2, 0
	.global func_08074DC4
	.thumb
	.thumb_func
	.type func_08074DC4, %function
func_08074DC4: @ 08074DC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	bl func_08074D00
	ldr r6, _08074E00 @ =0x02039DC8
	ldr r2, [r6, #0x00]
	ldr r0, [r2, #0x50]
	ldr r3, _08074E04 @ =0xFFFF8800
	adds r1, r0, r3
	ldr r0, [r2, #0x54]
	ldr r3, _08074E08 @ =0xFFFFB000
	adds r5, r0, r3
	ldrh r0, [r4, #0x10]
	cmp r0, #0x00
	beq _08074E0C
	adds r0, r2, #0x0
	adds r0, #0x48
	ldrh r2, [r4, #0x10]
	bl func_080058FC
	ldr r0, [r6, #0x00]
	adds r0, #0x4C
	ldrh r2, [r4, #0x10]
	adds r1, r5, #0x0
	bl func_080058FC
	ldrh r0, [r4, #0x10]
	subs r0, #0x01
	strh r0, [r4, #0x10]
	b _08074E10
_08074E00: .4byte 0x02039DC8
_08074E04: .4byte 0xFFFF8800
_08074E08: .4byte 0xFFFFB000
_08074E0C:
	str r1, [r2, #0x48]
	str r5, [r2, #0x4C]
_08074E10:
	ldr r0, _08074E3C @ =0x02039DC8
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x68
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r1, r1, #0x08
	ldr r0, [r2, #0x48]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	adds r0, r2, #0x0
	adds r0, #0x6A
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r1, r1, #0x08
	ldr r0, [r2, #0x4C]
	adds r0, r0, r1
	str r0, [r2, #0x5C]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08074E3C: .4byte 0x02039DC8
.syntax divided
