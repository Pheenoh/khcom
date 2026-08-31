.syntax unified
	.align 2, 0
	.global task_poo_freeballoon_2
	.thumb
	.thumb_func
	.type task_poo_freeballoon_2, %function
task_poo_freeballoon_2: @ 080CC3D8
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r6, [r5, #0x50]
	cmp r6, #0x00
	beq _080CC41A
	adds r0, #0x8C
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r1, r5, #0x0
	adds r1, #0x8E
	movs r2, #0x00
	ldsh r1, [r1, r2]
	ldr r3, [r5, #0x48]
	ldr r2, [r5, #0x4C]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	movs r2, #0x80
	lsls r2, r2, #0x04
	str r2, [sp, #0x008]
	ldr r4, [r5, #0x70]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r7, _080CC460 @ =0xFFFFEFFC
	adds r2, r7, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r6, #0x0
	bl DrawSprite
_080CC41A:
	ldr r6, [r5, #0x08]
	cmp r6, #0x00
	beq _080CC458
	adds r0, r5, #0x0
	adds r0, #0x44
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r1, r5, #0x0
	adds r1, #0x46
	movs r2, #0x00
	ldsh r1, [r1, r2]
	ldr r3, [r5, #0x00]
	ldr r2, [r5, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	movs r2, #0x80
	lsls r2, r2, #0x04
	str r2, [sp, #0x008]
	ldr r4, [r5, #0x28]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _080CC460 @ =0xFFFFEFFC
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r6, #0x0
	bl DrawSprite
_080CC458:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CC460: .4byte 0xFFFFEFFC
.syntax divided
