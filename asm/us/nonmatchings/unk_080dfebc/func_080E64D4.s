.syntax unified
	.align 2, 0
	.global func_080E64D4
	.thumb
	.thumb_func
	.type func_080E64D4, %function
func_080E64D4: @ 080E64D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r7, r0, #0x0
	adds r4, r7, #0x0
	adds r4, #0x08
	adds r6, r7, #0x0
	adds r6, #0xC4
	ldr r0, [r6, #0x00]
	cmp r0, #0x00
	beq _080E6564
	ldrh r1, [r7, #0x04]
	movs r0, #0x01
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x04
	mov r12, r1
	cmp r0, #0x00
	beq _080E6500
	ldr r2, _080E6570 @ =0x00000801
	mov r12, r2
_080E6500:
	ldr r1, [r4, #0x04]
	asrs r1, r1, #0x08
	lsls r0, r1, #0x02
	ldr r2, _080E6574 @ =0xFFFFEFFC
	adds r5, r2, #0x0
	subs r5, r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, [r4, #0x0C]
	str r0, [r4, #0x3C]
	adds r0, r5, #0x1
	movs r2, #0x00
	mov r8, r2
	strh r0, [r4, #0x3A]
	ldr r0, [r7, #0x08]
	asrs r0, r0, #0x08
	ldr r2, _080E6578 @ =0x02039BA0
	ldr r3, [r2, #0x00]
	ldr r2, [r3, #0x00]
	asrs r2, r2, #0x08
	subs r0, r0, r2
	ldr r2, [r4, #0x08]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, [r3, #0x04]
	asrs r2, r2, #0x08
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x00]
	adds r3, r7, #0x0
	adds r3, #0xBC
	ldr r3, [r3, #0x00]
	adds r4, r7, #0x0
	adds r4, #0xC0
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r4, r12
	str r4, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
	adds r0, r7, #0x0
	adds r0, #0xE4
	bl func_08000EE0
_080E6564:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E6570: .4byte 0x00000801
_080E6574: .4byte 0xFFFFEFFC
_080E6578: .4byte 0x02039BA0
.syntax divided
