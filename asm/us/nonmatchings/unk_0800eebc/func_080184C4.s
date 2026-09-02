.syntax unified
	.align 2, 0
	.global func_080184C4
	.thumb
	.thumb_func
	.type func_080184C4, %function
func_080184C4: @ 080184C4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r4, r2, #0x0
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	movs r0, #0x03
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08018526
	bl func_08012674
	ldr r1, _08018530 @ =0x02034928
	ldr r0, [r1, #0x00]
	str r6, [r0, #0x10]
	str r7, [r0, #0x14]
	str r4, [r0, #0x18]
	adds r0, #0x24
	strb r5, [r0, #0x00]
	mov r5, sp
	adds r5, #0x06
	ldr r0, [r1, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r5, #0x0
	bl WorldToScreen
	ldr r0, _08018534 @ =0x09EDACA8
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r5, r3]
	bl func_08006778
	ldr r0, _08018530 @ =0x02034928
	ldr r1, [r0, #0x00]
	ldrh r2, [r1, #0x34]
	movs r0, #0x20
	orrs r0, r2
	strh r0, [r1, #0x34]
	ldr r0, _08018538 @ =0x0801848D
	str r0, [r1, #0x04]
_08018526:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08018530: .4byte 0x02034928
_08018534: .4byte 0x09EDACA8
_08018538: .4byte 0x0801848D
.syntax divided
