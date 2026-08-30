.syntax unified
	.align 2, 0
	.global task_fld_shadow_2
	.thumb
	.thumb_func
	.type task_fld_shadow_2, %function
task_fld_shadow_2: @ 08036B4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r6, [r4, #0x10]
	ldrh r0, [r6, #0x3A]
	cmp r0, #0x00
	beq _08036BD2
	adds r0, r4, #0x0
	adds r0, #0x14
	bl func_08005A64
	mov r8, r0
	ldr r5, [r6, #0x3C]
	ldr r1, [r6, #0x08]
	cmp r1, r5
	blt _08036B74
	movs r7, #0x00
	b _08036B96
_08036B74:
	subs r1, r5, r1
	cmp r1, #0x00
	bge _08036B7C
	adds r1, #0x7F
_08036B7C:
	asrs r1, r1, #0x07
	movs r0, #0x80
	lsls r0, r0, #0x01
	subs r2, r0, r1
	cmp r2, #0x18
	bgt _08036B8A
	movs r2, #0x19
_08036B8A:
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x00
	bl func_08002CB4
	adds r7, r0, #0x0
_08036B96:
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _08036BE0 @ =0x02039BA0
	ldr r3, [r1, #0x00]
	ldr r1, [r3, #0x00]
	asrs r1, r1, #0x08
	subs r0, r0, r1
	ldr r1, [r4, #0x04]
	asrs r1, r1, #0x08
	asrs r2, r5, #0x08
	adds r1, r1, r2
	ldr r2, [r3, #0x04]
	asrs r2, r2, #0x08
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	str r2, [sp, #0x000]
	str r7, [sp, #0x004]
	movs r2, #0x80
	lsls r2, r2, #0x04
	str r2, [sp, #0x008]
	ldrh r2, [r6, #0x3A]
	str r2, [sp, #0x00C]
	mov r2, r8
	bl func_080023E0
_08036BD2:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08036BE0: .4byte 0x02039BA0
.syntax divided
