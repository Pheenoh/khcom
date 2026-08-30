.syntax unified
	.align 2, 0
	.global func_080E68E4
	.thumb
	.thumb_func
	.type func_080E68E4, %function
func_080E68E4: @ 080E68E4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	ldr r4, [sp, #0x028]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r10, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r9, r4
	movs r3, #0x00
	cmp r3, r10
	bge _080E6956
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsls r7, r5, #0x10
_080E691A:
	movs r5, #0x00
	cmp r5, r8
	bge _080E694A
	adds r6, r7, #0x0
	ldr r0, [sp, #0x000]
	lsls r4, r0, #0x10
_080E6926:
	asrs r1, r4, #0x10
	asrs r0, r6, #0x10
	mov r2, r9
	str r3, [sp, #0x004]
	bl func_080E68A4
	lsls r0, r0, #0x18
	ldr r3, [sp, #0x004]
	cmp r0, #0x00
	bne _080E693E
	movs r0, #0x00
	b _080E6958
_080E693E:
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r4, r4, r0
	adds r5, #0x01
	cmp r5, r8
	blt _080E6926
_080E694A:
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r7, r7, r0
	adds r3, #0x01
	cmp r3, r10
	blt _080E691A
_080E6956:
	movs r0, #0x01
_080E6958:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
