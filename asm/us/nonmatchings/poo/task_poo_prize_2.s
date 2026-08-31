.syntax unified
	.align 2, 0
	.global task_poo_prize_2
	.thumb
	.thumb_func
	.type task_poo_prize_2, %function
task_poo_prize_2: @ 080D1D90
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	adds r0, #0x96
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D1E6C
	ldr r0, [r5, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080D1DF8 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, [r5, #0x04]
	asrs r1, r1, #0x08
	ldr r2, [r5, #0x08]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080D1DFC @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	lsrs r4, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x08
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D1E6C
	adds r0, r5, #0x0
	adds r0, #0x90
	ldr r2, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	beq _080D1E00
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x00
	bl AllocObjAffine
	adds r6, r0, #0x0
	b _080D1E02
_080D1DF8: .4byte 0x0203C40C
_080D1DFC: .4byte 0x0203C3F8
_080D1E00:
	movs r6, #0x00
_080D1E02:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	mov r9, r0
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x74]
	ldr r3, [r5, #0x6C]
	ldr r0, [r5, #0x70]
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r8, r0
	str r0, [sp, #0x008]
	ldr r4, [r5, #0x04]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r7, _080D1E7C @ =0xFFFFEFFC
	adds r0, r7, #0x0
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	mov r0, r9
	bl DrawSprite
	adds r0, r5, #0x0
	adds r0, #0x97
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D1E6C
	ldr r1, [r5, #0x04]
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x0C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080D1E80 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x78]
	ldr r3, [r5, #0x6C]
	ldr r0, [r5, #0x70]
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	mov r0, r8
	str r0, [sp, #0x008]
	ldr r0, _080D1E84 @ =0x0000FFF0
	str r0, [sp, #0x00C]
	mov r0, r9
	bl DrawSprite
_080D1E6C:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D1E7C: .4byte 0xFFFFEFFC
_080D1E80: .4byte 0x0203C3F8
_080D1E84: .4byte 0x0000FFF0
.syntax divided
