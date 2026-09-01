.syntax unified
	.align 2, 0
	.global func_080141FC
	.thumb
	.thumb_func
	.type func_080141FC, %function
func_080141FC: @ 080141FC
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r6, r0, #0x0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08014272
	bl func_08012674
	ldr r5, _0801427C @ =0x02034928
	ldr r4, [r5, #0x00]
	str r6, [r4, #0x44]
	ldr r2, [r6, #0x04]
	str r2, [r4, #0x10]
	ldr r3, [r6, #0x08]
	str r3, [r4, #0x14]
	ldr r1, [r6, #0x0C]
	ldr r0, _08014280 @ =0xFFFFF800
	adds r1, r1, r0
	str r1, [r4, #0x18]
	ldr r0, _08014284 @ =0x00000133
	str r0, [r4, #0x1C]
	str r0, [r4, #0x20]
	mov r4, sp
	adds r4, #0x06
	str r1, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	bl WorldToScreen
	ldr r0, _08014288 @ =0x09EDA768
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	movs r0, #0x04
	bl func_08006B34
	ldr r1, [r5, #0x00]
	ldr r0, _0801428C @ =0x080141D5
	str r0, [r1, #0x04]
	ldr r0, _08014290 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r2, [r5, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08014272:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801427C: .4byte 0x02034928
_08014280: .4byte 0xFFFFF800
_08014284: .4byte 0x00000133
_08014288: .4byte 0x09EDA768
_0801428C: .4byte 0x080141D5
_08014290: .4byte 0x02039B84
.syntax divided
