.syntax unified
	.align 2, 0
	.global func_08013DB8
	.thumb
	.thumb_func
	.type func_08013DB8, %function
func_08013DB8: @ 08013DB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r5, r0, #0x0
	mov r8, r1
	adds r7, r2, #0x0
	adds r4, r3, #0x0
	movs r0, #0x01
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x00
	bne _08013E30
	bl func_08012674
	ldr r1, _08013E3C @ =0x02034928
	ldr r0, [r1, #0x00]
	str r4, [r0, #0x1C]
	str r4, [r0, #0x20]
	ldr r0, [r0, #0x00]
	movs r1, #0x00
	movs r2, #0x10
	bl SetBgBlend
	ldr r2, _08013E3C @ =0x02034928
	ldr r0, [r2, #0x00]
	str r5, [r0, #0x10]
	mov r3, r8
	str r3, [r0, #0x14]
	str r7, [r0, #0x18]
	mov r4, sp
	adds r4, #0x06
	str r7, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl WorldToScreen
	ldr r0, _08013E40 @ =0x09EDA7F8
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	movs r0, #0x04
	bl func_08006B34
	ldr r0, _08013E44 @ =0x00000209
	bl m4aSongNumStart
	ldr r1, _08013E3C @ =0x02034928
	ldr r0, [r1, #0x00]
	ldr r1, _08013E48 @ =0x08013D61
	str r1, [r0, #0x04]
	str r6, [r0, #0x2C]
	strh r6, [r0, #0x08]
_08013E30:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08013E3C: .4byte 0x02034928
_08013E40: .4byte 0x09EDA7F8
_08013E44: .4byte 0x00000209
_08013E48: .4byte 0x08013D61
.syntax divided
