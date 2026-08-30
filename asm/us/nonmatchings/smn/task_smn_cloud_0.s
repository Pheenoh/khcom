.syntax unified
	.align 2, 0
	.global task_smn_cloud_0
	.thumb
	.thumb_func
	.type task_smn_cloud_0, %function
task_smn_cloud_0: @ 08040E28
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	adds r7, r6, #0x0
	adds r7, #0x38
	ldrb r1, [r5, #0x02]
	cmp r1, #0x00
	beq _08040E70
	ldr r0, _08040E60 @ =0x00000163
	adds r1, r6, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08040E64 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08040E68 @ =0x00200000
	ldr r3, _08040E6C @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r1, [r4, #0x7C]
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r4, r4, r2
	b _08040E90
	.byte 0x00, 0x00
_08040E60: .4byte 0x00000163
_08040E64: .4byte 0x02039B84
_08040E68: .4byte 0x00200000
_08040E6C: .4byte 0x00000000
_08040E70:
	ldr r3, _08040EBC @ =0x00000163
	adds r0, r6, r3
	strb r1, [r0, #0x00]
	ldr r0, _08040EC0 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08040EC4 @ =0x00200000
	ldr r3, _08040EC8 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r1, [r4, #0x7C]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r4, r4, r0
_08040E90:
	ldr r0, [r4, #0x00]
	str r0, [r6, #0x00]
	ldr r0, [r1, #0x14]
	str r0, [r7, #0x04]
	ldr r0, [r1, #0x18]
	str r0, [r7, #0x08]
	ldr r0, [r1, #0x1C]
	str r0, [r7, #0x0C]
	ldr r0, [r1, #0x1C]
	str r0, [r7, #0x10]
	ldr r0, [r1, #0x34]
	ldr r1, [r1, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08040ECC
	movs r0, #0x04
	movs r1, #0x00
	b _08040ED0
	.byte 0x00, 0x00
_08040EBC: .4byte 0x00000163
_08040EC0: .4byte 0x02039B9C
_08040EC4: .4byte 0x00200000
_08040EC8: .4byte 0x00000000
_08040ECC:
	movs r0, #0x00
	movs r1, #0x00
_08040ED0:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r5, #0x00]
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r2, r6, r1
	movs r4, #0x00
	strb r0, [r2, #0x00]
	ldr r0, _08040F78 @ =0x08F6DC24
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r0, r6, r2
	str r4, [r0, #0x00]
	adds r5, r6, #0x0
	adds r5, #0x08
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _08040F7C @ =0x0813E958
	ldr r1, [r6, #0x00]
	str r1, [sp, #0x000]
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	str r4, [r6, #0x34]
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r0, r6, r3
	movs r2, #0x00
	strh r4, [r0, #0x00]
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	str r4, [r0, #0x00]
	adds r3, #0x10
	adds r0, r6, r3
	strb r2, [r0, #0x00]
	adds r1, #0x04
	adds r0, r6, r1
	movs r1, #0x0A
	str r1, [r0, #0x00]
	subs r3, #0x04
	adds r0, r6, r3
	str r1, [r0, #0x00]
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strb r2, [r0, #0x00]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r4, [r0, #0x00]
	adds r3, #0x14
	adds r0, r6, r3
	str r4, [r0, #0x00]
	adds r1, #0x18
	adds r0, r6, r1
	strh r4, [r0, #0x00]
	adds r2, #0x0C
	adds r0, r6, r2
	strh r4, [r0, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x20
	adds r0, r4, #0x0
	movs r1, #0x02
	bl func_08000E64
	ldr r1, _08040F80 @ =0x09EDAE88
	adds r0, r4, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08040F78: .4byte 0x08F6DC24
_08040F7C: .4byte 0x0813E958
_08040F80: .4byte 0x09EDAE88
.syntax divided
