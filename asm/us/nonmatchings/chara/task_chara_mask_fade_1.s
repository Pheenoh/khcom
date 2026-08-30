.syntax unified
	.align 2, 0
	.global task_chara_mask_fade_1
	.thumb
	.thumb_func
	.type task_chara_mask_fade_1, %function
task_chara_mask_fade_1: @ 080C5204
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	ldrh r0, [r6, #0x0A]
	adds r0, #0x01
	strh r0, [r6, #0x0A]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r6, #0x06]
	cmp r0, r1
	ble _080C52B8
	movs r0, #0x00
	strh r0, [r6, #0x0A]
	movs r7, #0x00
	ldrh r0, [r6, #0x04]
	cmp r7, r0
	bge _080C529E
	movs r1, #0x0C
	adds r1, r1, r6
	mov r10, r1
	movs r0, #0x2C
	adds r0, r0, r6
	mov r9, r0
	adds r1, r6, #0x0
	adds r1, #0x4C
	str r1, [sp, #0x000]
_080C5240:
	lsls r4, r7, #0x05
	ldr r0, [r6, #0x00]
	adds r0, r0, r4
	adds r1, r6, #0x0
	adds r1, #0x0C
	movs r2, #0x08
	bl func_08117FE4
	movs r5, #0x00
	mov r12, r4
	adds r0, r7, #0x1
	mov r8, r0
	ldr r1, [sp, #0x000]
	adds r7, r1, r7
_080C525C:
	mov r0, r9
	adds r4, r0, r5
	mov r1, r10
	adds r3, r1, r5
	movs r0, #0x08
	ldsh r2, [r6, r0]
	lsls r2, r2, #0x05
	adds r2, r5, r2
	movs r1, #0x00
	ldsb r1, [r7, r1]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x05
	adds r2, r2, r0
	ldr r1, _080C52B4 @ =0x09EF2F08
	adds r2, r2, r1
	ldrb r1, [r3, #0x00]
	ldrb r0, [r2, #0x00]
	ands r0, r1
	strb r0, [r4, #0x00]
	adds r5, #0x01
	cmp r5, #0x1F
	ble _080C525C
	ldr r1, [r6, #0x00]
	add r1, r12
	mov r0, r9
	movs r2, #0x08
	bl func_08117FE4
	mov r7, r8
	ldrh r0, [r6, #0x04]
	cmp r7, r0
	blt _080C5240
_080C529E:
	ldrh r0, [r6, #0x08]
	adds r0, #0x01
	strh r0, [r6, #0x08]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x08
	ble _080C52B8
	movs r0, #0x00
	strh r0, [r6, #0x08]
	b _080C52BA
	.byte 0x00, 0x00
_080C52B4: .4byte 0x09EF2F08
_080C52B8:
	movs r0, #0x01
_080C52BA:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
