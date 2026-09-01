.syntax unified
	.align 2, 0
	.global func_08087B98
	.thumb
	.thumb_func
	.type func_08087B98, %function
func_08087B98: @ 08087B98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r6, r1
	bl func_08000C8C
	adds r5, r0, #0x0
	movs r7, #0x00
	ldr r2, _08087C20 @ =0x000004D4
	adds r2, r2, r6
	mov r8, r2
	movs r3, #0x88
	lsls r3, r3, #0x04
	adds r4, r6, r3
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x05
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	ldr r0, [r0, #0x1C]
	bl EwramFree
	ldrh r0, [r4, #0x00]
	mov r2, r8
	ldr r1, [r2, #0x00]
	lsls r0, r0, #0x05
	adds r0, r0, r1
	str r7, [r0, #0x1C]
	ldrh r7, [r4, #0x00]
	ldr r3, _08087C24 @ =0x00000898
	adds r1, r6, r3
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	cmp r7, r0
	bge _08087C0A
	mov r12, r8
	mov r8, r1
_08087BE6:
	mov r4, r12
	ldr r0, [r4, #0x00]
	lsls r1, r7, #0x05
	adds r1, r1, r0
	adds r0, r1, #0x0
	adds r0, #0x20
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	adds r7, #0x01
	mov r4, r8
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	cmp r7, r0
	blt _08087BE6
_08087C0A:
	ldr r0, _08087C24 @ =0x00000898
	adds r1, r6, r0
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r2, _08087C28 @ =0x000008D4
	adds r1, r6, r2
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	b _08087C36
_08087C20: .4byte 0x000004D4
_08087C24: .4byte 0x00000898
_08087C28: .4byte 0x000008D4
_08087C2C:
	adds r0, r5, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r5, r0, #0x0
_08087C36:
	cmp r5, #0x00
	beq _08087C5E
	ldr r3, _08087CC8 @ =0x000008B5
	adds r0, r6, r3
	movs r4, #0x22
	ldsh r1, [r5, r4]
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _08087C2C
	ldr r1, _08087CCC @ =0x000008B6
	adds r0, r6, r1
	movs r2, #0x24
	ldsh r1, [r5, r2]
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _08087C2C
_08087C5E:
	adds r0, r5, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r1, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x4A
	cmp r1, #0x00
	beq _08087C94
_08087C70:
	ldrh r0, [r1, #0x22]
	subs r0, #0x01
	strh r0, [r1, #0x22]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _08087C86
	movs r0, #0x02
	strh r0, [r1, #0x22]
	ldrh r0, [r1, #0x24]
	subs r0, #0x01
	strh r0, [r1, #0x24]
_08087C86:
	adds r0, r1, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r1, r0, #0x0
	cmp r1, #0x00
	bne _08087C70
_08087C94:
	movs r0, #0x01
	strb r0, [r4, #0x00]
	movs r3, #0xF9
	lsls r3, r3, #0x03
	adds r0, r6, r3
	bl TaskPoolUpdate
	adds r0, r6, #0x0
	bl func_0808D828
	ldr r4, _08087CD0 @ =0x00000898
	adds r0, r6, r4
	movs r2, #0x00
	ldsh r1, [r0, r2]
	adds r0, r6, #0x0
	bl func_0808C940
	adds r0, r6, #0x0
	bl func_0808C974
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08087CC8: .4byte 0x000008B5
_08087CCC: .4byte 0x000008B6
_08087CD0: .4byte 0x00000898
.syntax divided
