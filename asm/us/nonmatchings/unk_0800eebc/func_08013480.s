.syntax unified
	.align 2, 0
	.global func_08013480
	.thumb
	.thumb_func
	.type func_08013480, %function
func_08013480: @ 08013480
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r7, r0, #0x0
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	movs r0, #0x03
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x00
	bne _080134F2
	bl func_08012674
	ldr r1, _080134FC @ =0x02034928
	ldr r0, [r1, #0x00]
	str r7, [r0, #0x10]
	str r4, [r0, #0x14]
	ldr r2, _08013500 @ =0xFFFFF000
	adds r1, r5, r2
	str r1, [r0, #0x18]
	mov r5, sp
	adds r5, #0x06
	str r1, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r5, #0x0
	adds r2, r7, #0x0
	adds r3, r4, #0x0
	bl WorldToScreen
	ldr r3, _080134FC @ =0x02034928
	ldr r0, [r3, #0x00]
	movs r1, #0x4C
	str r1, [r0, #0x1C]
	str r1, [r0, #0x20]
	adds r0, #0x24
	strb r6, [r0, #0x00]
	ldr r1, [r3, #0x00]
	movs r0, #0x19
	str r0, [r1, #0x28]
	str r0, [r1, #0x2C]
	ldr r0, _08013504 @ =0x09EDA618
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r5, r3]
	bl func_08006778
	movs r0, #0x00
	bl func_08006B34
	ldr r0, _080134FC @ =0x02034928
	ldr r1, [r0, #0x00]
	ldr r0, _08013508 @ =0x08013421
	str r0, [r1, #0x04]
	strh r6, [r1, #0x08]
_080134F2:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080134FC: .4byte 0x02034928
_08013500: .4byte 0xFFFFF000
_08013504: .4byte 0x09EDA618
_08013508: .4byte 0x08013421
.syntax divided
