.syntax unified
	.align 2, 0
	.global func_080E893C
	.thumb
	.thumb_func
	.type func_080E893C, %function
func_080E893C: @ 080E893C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r5, r2, #0x0
	mov r9, r3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl func_0811D7CC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080E896A
_080E8968:
	adds r5, #0x08
_080E896A:
	ldrb r1, [r5, #0x00]
	cmp r0, r1
	bcs _080E8968
	movs r7, #0x00
	ldrb r0, [r5, #0x03]
	cmp r7, r0
	bge _080E89D4
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	mov r10, r0
_080E8984:
	movs r6, #0x00
	adds r1, r7, #0x1
	mov r8, r1
	ldrb r0, [r5, #0x04]
	cmp r6, r0
	bge _080E89CC
	mov r1, r10
	adds r0, r1, r7
	lsls r3, r0, #0x10
	ldr r0, [sp, #0x000]
	lsls r4, r0, #0x10
_080E899A:
	asrs r1, r4, #0x10
	asrs r0, r3, #0x10
	str r3, [sp, #0x004]
	bl func_080E548C
	ldrb r2, [r5, #0x02]
	adds r2, r2, r6
	lsls r2, r2, #0x06
	ldrb r1, [r5, #0x01]
	adds r1, r1, r7
	lsls r1, r1, #0x02
	adds r2, r2, r1
	movs r1, #0x26
	strb r1, [r0, #0x05]
	lsls r2, r2, #0x01
	add r2, r9
	str r2, [r0, #0x1C]
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r4, r4, r1
	adds r6, #0x01
	ldr r3, [sp, #0x004]
	ldrb r0, [r5, #0x04]
	cmp r6, r0
	blt _080E899A
_080E89CC:
	mov r7, r8
	ldrb r1, [r5, #0x03]
	cmp r7, r1
	blt _080E8984
_080E89D4:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
