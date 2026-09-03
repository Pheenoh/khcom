.syntax unified
	.align 2, 0
	.global func_080E5AC8
	.thumb
	.thumb_func
	.type func_080E5AC8, %function
func_080E5AC8: @ 080E5AC8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r5, r0, #0x0
	adds r5, #0x08
	movs r0, #0x00
	bl func_080E54A0
	mov r9, r0
	ldrh r0, [r0, #0x02]
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r0, r0, r1
	subs r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, _080E5B68 @ =0x0203C7AC
	ldr r1, [r0, #0x00]
	ldrh r0, [r1, #0x0A]
	ldrh r1, [r1, #0x08]
	subs r0, r0, r1
	subs r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r10, r0
	movs r3, #0x00
	cmp r3, r10
	bge _080E5B7C
_080E5B08:
	ldr r0, _080E5B68 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x08]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r6, #0x00
	cmp r6, r8
	bge _080E5B76
	lsls r0, r0, #0x10
	asrs r7, r0, #0x10
	lsls r2, r7, #0x0C
_080E5B20:
	mov r1, r9
	ldrh r0, [r1, #0x00]
	adds r0, r0, r6
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	str r2, [sp, #0x000]
	str r3, [sp, #0x004]
	bl func_080E548C
	ldrh r1, [r0, #0x00]
	movs r0, #0x80
	ands r0, r1
	ldr r2, [sp, #0x000]
	ldr r3, [sp, #0x004]
	cmp r0, #0x00
	beq _080E5B70
	lsls r0, r4, #0x0D
	str r0, [r5, #0x00]
	str r2, [r5, #0x04]
	movs r0, #0x00
	str r0, [r5, #0x08]
	adds r0, r5, #0x0
	bl func_080DFF30
	str r0, [r5, #0x0C]
	ldr r1, [r5, #0x04]
	subs r1, r1, r0
	str r1, [r5, #0x04]
	ldr r2, _080E5B6C @ =0xFFFFE000
	adds r0, r0, r2
	str r0, [r5, #0x08]
	movs r0, #0x01
	b _080E5B7E
	.byte 0x00, 0x00
_080E5B68: .4byte 0x0203C7AC
_080E5B6C: .4byte 0xFFFFE000
_080E5B70:
	adds r6, #0x01
	cmp r6, r8
	blt _080E5B20
_080E5B76:
	adds r3, #0x01
	cmp r3, r10
	blt _080E5B08
_080E5B7C:
	movs r0, #0x00
_080E5B7E:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
