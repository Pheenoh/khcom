.syntax unified
	.align 2, 0
	.global task_pc_acddmg_1
	.thumb
	.thumb_func
	.type task_pc_acddmg_1, %function
task_pc_acddmg_1: @ 08049DDC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r3, _08049E34 @ =0x02039B84
	ldr r0, [r3, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x0D
	ands r0, r2
	movs r1, #0x00
	orrs r1, r0
	cmp r1, #0x00
	bne _08049E68
	ldr r5, [r4, #0x04]
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _08049E44
	movs r0, #0x01
	strb r0, [r4, #0x08]
	ldrh r1, [r4, #0x00]
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	bgt _08049E40
	movs r1, #0x02
	ldsh r0, [r4, r1]
	movs r1, #0x3C
	bl func_0811D684
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _08049E2A
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	ldr r2, _08049E38 @ =0x20000000
	ldr r3, _08049E3C @ =0x00000000
	orrs r0, r2
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_08049E2A:
	ldrh r0, [r4, #0x02]
	adds r0, #0x01
	strh r0, [r4, #0x02]
	b _08049E68
	.byte 0x00, 0x00
_08049E34: .4byte 0x02039B84
_08049E38: .4byte 0x20000000
_08049E3C: .4byte 0x00000000
_08049E40:
	subs r0, r1, #0x1
	b _08049E66
_08049E44:
	ldrb r0, [r4, #0x08]
	cmp r0, #0x00
	beq _08049E50
	strb r1, [r4, #0x08]
	strh r1, [r4, #0x02]
	strh r1, [r4, #0x00]
_08049E50:
	ldr r0, [r3, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08049E68
	movs r0, #0x28
_08049E66:
	strh r0, [r4, #0x00]
_08049E68:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
