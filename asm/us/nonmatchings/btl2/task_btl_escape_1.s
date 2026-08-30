.syntax unified
	.align 2, 0
	.global task_btl_escape_1
	.thumb
	.thumb_func
	.type task_btl_escape_1, %function
task_btl_escape_1: @ 08030990
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	ldr r0, _080309D8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	mov r8, r0
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x11
	movs r0, #0x00
	adds r1, r4, #0x0
	ands r1, r2
	adds r7, r1, #0x0
	orrs r7, r0
	cmp r7, #0x00
	bne _08030A56
	movs r0, #0x08
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _080309DC
	adds r1, r5, #0x0
	adds r1, #0x22
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08030A54
	str r7, [r5, #0x1C]
	strb r7, [r1, #0x00]
	strh r7, [r5, #0x20]
	b _08030A54
_080309D8: .4byte 0x02039B84
_080309DC:
	ldrh r1, [r5, #0x20]
	movs r2, #0x20
	ldsh r0, [r5, r2]
	cmp r0, #0x0F
	bgt _080309F4
	adds r0, r1, #0x1
	movs r1, #0x00
	strh r0, [r5, #0x20]
	adds r0, r5, #0x0
	adds r0, #0x22
	strb r1, [r0, #0x00]
	b _08030A54
_080309F4:
	movs r0, #0x22
	adds r0, r0, r5
	mov r9, r0
	movs r0, #0x01
	mov r1, r9
	strb r0, [r1, #0x00]
	ldr r6, [r5, #0x1C]
	lsls r0, r6, #0x08
	ldr r4, [r5, #0x18]
	adds r1, r4, #0x0
	bl func_0811D5EC
	str r0, [r5, #0x14]
	cmp r6, r4
	blt _08030A4C
	ldr r2, _08030A40 @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x40
	orrs r0, r1
	str r0, [r2, #0x08]
	mov r0, r8
	ldr r2, [r0, #0x68]
	ldr r3, [r0, #0x6C]
	movs r0, #0x10
	movs r1, #0x00
	orrs r2, r0
	ldr r4, _08030A44 @ =0x00000000
	ldr r5, _08030A48 @ =0x00000002
	adds r0, r2, #0x0
	adds r1, r3, #0x0
	orrs r1, r5
	mov r2, r8
	str r0, [r2, #0x68]
	str r1, [r2, #0x6C]
	mov r0, r9
	strb r7, [r0, #0x00]
	b _08030A54
	.byte 0x00, 0x00
_08030A40: .4byte 0x02039BB0
_08030A44: .4byte 0x00000000
_08030A48: .4byte 0x00000002
_08030A4C:
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r6, r1
	str r0, [r5, #0x1C]
_08030A54:
	movs r0, #0x01
_08030A56:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
