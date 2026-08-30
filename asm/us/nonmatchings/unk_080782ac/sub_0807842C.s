.syntax unified
	.align 2, 0
	.global sub_0807842C
	.thumb
	.thumb_func
	.type sub_0807842C, %function
sub_0807842C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	mov r9, r0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	movs r0, #0x00
	mov r10, r0
	cmp r10, r6
	bcs _080784AC
	add r1, sp, #0x00C
	mov r8, r1
_0807844A:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0x0
	bl func_0811D684
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0x0
	bl func_0811D684
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r5, r4
	beq _0807849E
	lsls r3, r5, #0x01
	adds r3, r3, r5
	lsls r3, r3, #0x02
	add r3, r9
	mov r1, sp
	adds r0, r3, #0x0
	ldm r0!, {r2, r5, r7}
	stm r1!, {r2, r5, r7}
	lsls r2, r4, #0x01
	adds r2, r2, r4
	lsls r2, r2, #0x02
	add r2, r9
	mov r1, r8
	adds r0, r2, #0x0
	ldm r0!, {r4, r5, r7}
	stm r1!, {r4, r5, r7}
	mov r0, r8
	ldm r0!, {r1, r4, r5}
	stm r3!, {r1, r4, r5}
	mov r0, sp
	ldm r0!, {r1, r3, r7}
	stm r2!, {r1, r3, r7}
_0807849E:
	mov r0, r10
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r10, r0
	cmp r10, r6
	bcc _0807844A
_080784AC:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
