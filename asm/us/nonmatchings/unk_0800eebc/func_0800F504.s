.syntax unified
	.align 2, 0
	.global func_0800F504
	.thumb
	.thumb_func
	.type func_0800F504, %function
func_0800F504: @ 0800F504
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r4, r3, #0x0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r5, r0, #0x0
	adds r5, #0x40
	ldr r0, _0800F544 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r6, [r0, #0x7C]
	add r2, sp, #0x004
	adds r0, r5, #0x0
	mov r1, sp
	movs r3, #0x00
	bl func_0801C700
	lsls r4, r4, #0x08
	ldr r2, [r5, #0x08]
	ldr r0, [sp, #0x004]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _0800F548
	cmp r1, r4
	bgt _0800F578
	b _0800F54E
_0800F544: .4byte 0x02039B84
_0800F548:
	subs r0, r0, r2
	cmp r0, r4
	bgt _0800F578
_0800F54E:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800F57C
	lsls r0, r7, #0x10
	asrs r0, r0, #0x08
	ldr r1, [sp, #0x000]
	subs r2, r1, r0
	mov r0, r8
	lsls r1, r0, #0x08
	subs r0, r2, r1
	ldr r3, [r5, #0x04]
	cmp r0, r3
	bgt _0800F578
	adds r0, r2, r1
	cmp r0, r3
	bge _0800F596
_0800F578:
	movs r0, #0x00
	b _0800F598
_0800F57C:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x08
	ldr r1, [sp, #0x000]
	adds r2, r1, r0
	mov r0, r8
	lsls r1, r0, #0x08
	adds r0, r2, r1
	ldr r3, [r5, #0x04]
	cmp r0, r3
	blt _0800F578
	subs r0, r2, r1
	cmp r0, r3
	bgt _0800F578
_0800F596:
	movs r0, #0x01
_0800F598:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
