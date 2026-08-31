.syntax unified
	.align 2, 0
	.global func_080188E4
	.thumb
	.thumb_func
	.type func_080188E4, %function
func_080188E4: @ 080188E4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r7, r1, #0x0
	adds r5, r2, #0x0
	adds r6, r3, #0x0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08018958
	bl func_08012674
	ldr r1, _08018960 @ =0x02034928
	ldr r0, [r1, #0x00]
	str r7, [r0, #0x10]
	str r5, [r0, #0x14]
	str r6, [r0, #0x18]
	ldr r1, [sp, #0x01C]
	str r1, [r0, #0x48]
	strh r4, [r0, #0x26]
	mov r4, sp
	adds r4, #0x06
	str r6, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	adds r3, r5, #0x0
	bl WorldToScreen
	ldr r0, _08018964 @ =0x09EDAD20
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r0, _08018960 @ =0x02034928
	ldr r1, [r0, #0x00]
	ldr r0, _08018968 @ =0x0801884D
	str r0, [r1, #0x04]
	ldr r0, _0801896C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r1, _08018960 @ =0x02034928
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08018958:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08018960: .4byte 0x02034928
_08018964: .4byte 0x09EDAD20
_08018968: .4byte 0x0801884D
_0801896C: .4byte 0x02039B84
.syntax divided
