.syntax unified
	.align 2, 0
	.global task_bos_dsd_rock_2
	.thumb
	.thumb_func
	.type task_bos_dsd_rock_2, %function
task_bos_dsd_rock_2: @ 080C4638
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r0, #0x20
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C4656
	movs r7, #0x00
	movs r0, #0x0A
	mov r8, r0
	movs r6, #0x80
	lsls r6, r6, #0x03
	b _080C466C
_080C4656:
	movs r0, #0x00
	movs r1, #0x59
	movs r2, #0x59
	movs r3, #0x00
	bl AllocObjAffine
	adds r7, r0, #0x0
	ldr r1, _080C46B8 @ =0x0000FFF5
	mov r8, r1
	movs r6, #0xC0
	lsls r6, r6, #0x04
_080C466C:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r5, #0x1C]
	ldr r4, [r5, #0x00]
	movs r5, #0xDA
	lsls r5, r5, #0x02
	adds r3, r4, r5
	ldr r3, [r3, #0x00]
	adds r5, #0x04
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r6, [sp, #0x008]
	mov r4, r8
	str r4, [sp, #0x00C]
	bl DrawSprite
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C46B8: .4byte 0x0000FFF5
.syntax divided
