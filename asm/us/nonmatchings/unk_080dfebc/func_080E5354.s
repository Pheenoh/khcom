.syntax unified
	.align 2, 0
	.global func_080E5354
	.thumb
	.thumb_func
	.type func_080E5354, %function
func_080E5354: @ 080E5354
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x06
	mov r10, r0
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x06
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x08
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r1, #0x00
	str r1, [sp, #0x008]
_080E5390:
	ldr r0, _080E5434 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x04]
	cmp r0, #0x00
	bge _080E539C
	adds r0, #0x0F
_080E539C:
	asrs r0, r0, #0x0C
	adds r0, #0x02
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x00
	mov r8, r0
	cmp r8, r10
	bge _080E5456
	lsls r0, r6, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x04
	adds r1, r1, r0
	mov r9, r1
_080E53B8:
	ldr r0, _080E5434 @ =0x02039BA0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bge _080E53C4
	adds r0, #0x1F
_080E53C4:
	asrs r0, r0, #0x0D
	adds r0, #0x01
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r3, r1, #0x0
	adds r3, #0x18
	lsls r2, r4, #0x05
	adds r0, r2, #0x0
	adds r0, #0x50
	lsls r0, r0, #0x08
	ldr r1, [r1, #0x18]
	cmp r1, r0
	bge _080E5402
	adds r0, r2, #0x0
	subs r0, #0x30
	lsls r0, r0, #0x08
	cmp r1, r0
	ble _080E5402
	lsls r2, r6, #0x04
	adds r0, r2, #0x0
	adds r0, #0x28
	lsls r0, r0, #0x08
	ldr r1, [r3, #0x04]
	cmp r1, r0
	bge _080E5402
	adds r0, r2, #0x0
	subs r0, #0x18
	lsls r0, r0, #0x08
	cmp r1, r0
	bgt _080E544E
_080E5402:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	cmp r0, #0x00
	beq _080E543C
	ldr r0, [r0, #0x00]
	ldr r1, _080E5438 @ =0x00FF0340
	ands r0, r1
	cmp r0, #0x00
	bne _080E543C
	lsls r0, r4, #0x0D
	movs r1, #0x80
	lsls r1, r1, #0x05
	adds r0, r0, r1
	ldr r1, [sp, #0x000]
	str r0, [r1, #0x00]
	mov r0, r9
	ldr r1, [sp, #0x004]
	str r0, [r1, #0x00]
	movs r0, #0x01
	b _080E547C
	.byte 0x00, 0x00
_080E5434: .4byte 0x02039BA0
_080E5438: .4byte 0x00FF0340
_080E543C:
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0x0
	mov r1, r10
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_080E544E:
	movs r0, #0x01
	add r8, r0
	cmp r8, r10
	blt _080E53B8
_080E5456:
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r7, #0x0
	movs r1, #0x08
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, [sp, #0x008]
	adds r1, #0x01
	str r1, [sp, #0x008]
	cmp r1, #0x08
	blt _080E5390
	ldr r0, [sp, #0x000]
	ldr r1, [sp, #0x004]
	bl func_080E524C
	movs r0, #0x00
_080E547C:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
