.syntax unified
	.align 2, 0
	.global func_08013A68
	.thumb
	.thumb_func
	.type func_08013A68, %function
func_08013A68: @ 08013A68
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r4, r2, #0x0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08013AE0
	bl func_08012674
	ldr r5, _08013AE8 @ =0x02034928
	ldr r1, [r5, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x4C
	movs r0, #0x14
	strh r0, [r2, #0x00]
	str r6, [r1, #0x10]
	str r7, [r1, #0x14]
	ldr r2, _08013AEC @ =0xFFFFD000
	adds r0, r4, r2
	str r0, [r1, #0x18]
	mov r4, sp
	adds r4, #0x06
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r6, #0x0
	adds r3, r7, #0x0
	bl WorldToScreen
	ldr r0, _08013AF0 @ =0x09EDA6C0
	add r1, sp, #0x004
	movs r3, #0x00
	ldsh r1, [r1, r3]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r0, _08013AF4 @ =0x00000207
	bl m4aSongNumStart
	ldr r1, [r5, #0x00]
	ldr r0, _08013AF8 @ =0x08012909
	str r0, [r1, #0x04]
	ldr r0, _08013AFC @ =0x02039B84
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
_08013AE0:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08013AE8: .4byte 0x02034928
_08013AEC: .4byte 0xFFFFD000
_08013AF0: .4byte 0x09EDA6C0
_08013AF4: .4byte 0x00000207
_08013AF8: .4byte func_08012908
_08013AFC: .4byte 0x02039B84
.syntax divided
