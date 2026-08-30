.syntax unified
	.align 2, 0
	.global task_smn_dumbo_0
	.thumb
	.thumb_func
	.type task_smn_dumbo_0, %function
task_smn_dumbo_0: @ 08043D3C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	adds r7, r6, #0x0
	adds r7, #0x38
	ldrb r1, [r5, #0x02]
	cmp r1, #0x00
	beq _08043D84
	ldr r0, _08043D74 @ =0x00000155
	adds r1, r6, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08043D78 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08043D7C @ =0x00200000
	ldr r3, _08043D80 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r1, [r4, #0x7C]
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r4, r4, r2
	b _08043DA4
	.byte 0x00, 0x00
_08043D74: .4byte 0x00000155
_08043D78: .4byte 0x02039B84
_08043D7C: .4byte 0x00200000
_08043D80: .4byte 0x00000000
_08043D84:
	ldr r2, _08043DD0 @ =0x00000155
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _08043DD4 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08043DD8 @ =0x00200000
	ldr r3, _08043DDC @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r1, [r4, #0x7C]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r4, r4, r0
_08043DA4:
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
	beq _08043DE8
	ldr r0, _08043DE0 @ =0x00020004
	ldr r1, _08043DE4 @ =0x00000000
	b _08043DEC
	.byte 0x00, 0x00
_08043DD0: .4byte 0x00000155
_08043DD4: .4byte 0x02039B9C
_08043DD8: .4byte 0x00200000
_08043DDC: .4byte 0x00000000
_08043DE0: .4byte 0x00020004
_08043DE4: .4byte 0x00000000
_08043DE8:
	ldr r1, _08043E70 @ =0x00000000
	ldr r0, _08043E6C @ =0x00020000
_08043DEC:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r1, [r5, #0x00]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r6, r2
	movs r4, #0x00
	strb r1, [r0, #0x00]
	ldr r0, _08043E74 @ =0x09617F98
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	adds r5, r6, #0x0
	adds r5, #0x08
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _08043E78 @ =0x0813EADC
	ldr r1, [r6, #0x00]
	str r1, [sp, #0x000]
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	str r4, [r6, #0x34]
	movs r1, #0xA4
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r2, #0x00
	strh r4, [r0, #0x00]
	adds r1, #0x02
	adds r0, r6, r1
	strh r4, [r0, #0x00]
	adds r1, #0x02
	adds r0, r6, r1
	strh r4, [r0, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x0A
	str r0, [r1, #0x00]
	movs r1, #0xAB
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strb r2, [r0, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x20
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _08043E7C @ =0x09EDAE88
	adds r0, r4, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08043E6C: .4byte 0x00020000
_08043E70: .4byte 0x00000000
_08043E74: .4byte 0x09617F98
_08043E78: .4byte 0x0813EADC
_08043E7C: .4byte 0x09EDAE88
.syntax divided
