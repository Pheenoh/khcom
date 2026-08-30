.syntax unified
	.align 2, 0
	.global task_evt_shadow_2
	.thumb
	.thumb_func
	.type task_evt_shadow_2, %function
task_evt_shadow_2: @ 0801D050
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r4, [r5, #0x04]
	ldrh r1, [r4, #0x14]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _0801D0FC
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0801D074
	ldr r7, _0801D070 @ =0x08B22EE4
	ldr r6, [r5, #0x0C]
	b _0801D08C
_0801D070: .4byte 0x08B22EE4
_0801D074:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _0801D088
	ldr r7, _0801D084 @ =0x08B22CBC
	ldr r6, [r5, #0x10]
	b _0801D08C
	.byte 0x00, 0x00
_0801D084: .4byte 0x08B22CBC
_0801D088:
	ldr r7, _0801D098 @ =0x08B22BA8
	ldr r6, [r5, #0x08]
_0801D08C:
	ldr r0, [r4, #0x0C]
	ldr r1, [r4, #0x10]
	cmp r0, r1
	blt _0801D09C
	movs r0, #0x00
	b _0801D0BC
_0801D098: .4byte 0x08B22BA8
_0801D09C:
	subs r1, r1, r0
	cmp r1, #0x00
	bge _0801D0A4
	adds r1, #0x7F
_0801D0A4:
	asrs r1, r1, #0x07
	movs r0, #0x80
	lsls r0, r0, #0x01
	subs r2, r0, r1
	cmp r2, #0x18
	bgt _0801D0B2
	movs r2, #0x19
_0801D0B2:
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x00
	bl func_08002CB4
_0801D0BC:
	mov r12, r0
	ldr r0, [r4, #0x04]
	asrs r0, r0, #0x08
	ldr r1, _0801D104 @ =0x02039DC8
	ldr r3, [r1, #0x00]
	ldr r1, [r3, #0x58]
	asrs r1, r1, #0x08
	subs r0, r0, r1
	ldr r1, [r4, #0x08]
	asrs r1, r1, #0x08
	ldr r2, [r4, #0x10]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, [r3, #0x5C]
	asrs r2, r2, #0x08
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x00]
	str r2, [sp, #0x000]
	mov r2, r12
	str r2, [sp, #0x004]
	ldrh r2, [r4, #0x16]
	str r2, [sp, #0x008]
	ldr r2, _0801D108 @ =0x0000FFF0
	str r2, [sp, #0x00C]
	adds r2, r7, #0x0
	adds r3, r6, #0x0
	bl func_080023E0
_0801D0FC:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801D104: .4byte 0x02039DC8
_0801D108: .4byte 0x0000FFF0
.syntax divided
