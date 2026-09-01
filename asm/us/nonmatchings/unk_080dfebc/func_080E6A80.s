.syntax unified
	.align 2, 0
	.global func_080E6A80
	.thumb
	.thumb_func
	.type func_080E6A80, %function
func_080E6A80: @ 080E6A80
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r9, r2
	ldr r0, _080E6AE8 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x06]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0x00
	cmp r3, r9
	bge _080E6B0E
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r10, r0
	lsls r7, r4, #0x10
_080E6AB4:
	movs r5, #0x00
	cmp r5, r2
	bge _080E6B02
	str r7, [sp, #0x008]
	movs r0, #0x80
	lsls r0, r0, #0x01
	mov r8, r0
	mov r6, r10
	lsls r4, r6, #0x10
_080E6AC6:
	asrs r1, r4, #0x10
	ldr r6, [sp, #0x008]
	asrs r0, r6, #0x10
	str r2, [sp, #0x000]
	str r3, [sp, #0x004]
	bl func_080E548C
	adds r1, r0, #0x0
	ldrh r0, [r1, #0x00]
	mov r6, r8
	ands r0, r6
	ldr r2, [sp, #0x000]
	ldr r3, [sp, #0x004]
	cmp r0, #0x00
	beq _080E6AEC
	movs r0, #0x00
	b _080E6B10
_080E6AE8: .4byte 0x0203C7AC
_080E6AEC:
	ldrb r0, [r1, #0x02]
	subs r0, #0x07
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bhi _080E6B02
	ldr r0, _080E6B20 @ =0xFFFF0000
	adds r4, r4, r0
	adds r5, #0x01
	cmp r5, r2
	blt _080E6AC6
_080E6B02:
	movs r6, #0x80
	lsls r6, r6, #0x09
	adds r7, r7, r6
	adds r3, #0x01
	cmp r3, r9
	blt _080E6AB4
_080E6B0E:
	movs r0, #0x01
_080E6B10:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080E6B20: .4byte 0xFFFF0000
.syntax divided
