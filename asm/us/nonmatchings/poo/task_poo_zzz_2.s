.syntax unified
	.align 2, 0
	.global task_poo_zzz_2
	.thumb
	.thumb_func
	.type task_poo_zzz_2, %function
task_poo_zzz_2: @ 080D1F20
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r3, [r5, #0x24]
	ldr r2, [r3, #0x00]
	asrs r2, r2, #0x08
	ldr r0, _080D1F98 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r1, [r3, #0x04]
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x08]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080D1F9C @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r6, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r2, r2, r0
	movs r0, #0x98
	lsls r0, r0, #0x11
	cmp r2, r0
	bhi _080D1F90
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	movs r0, #0x20
	negs r0, r0
	cmp r4, r0
	blt _080D1F90
	cmp r4, #0xC0
	bgt _080D1F90
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl func_08005A64
	adds r2, r0, #0x0
	str r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r0, [r5, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x0B
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080023E0
_080D1F90:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D1F98: .4byte 0x0203C40C
_080D1F9C: .4byte 0x0203C3F8
.syntax divided
